//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Core Framework
//
// Copyright (C) 2001 - 2010 Tony Richards
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//  3. This notice may not be removed or altered from any source distribution.
//
//  Tony Richards trichards@indiezen.com
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INCLUDED
#define ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Core/Scripting.hpp>

#include <boost/typeof/typeof.hpp>

#include <string>
#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Scripting {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_ScriptableType;

/// Helper template for defining scriptable types.
template<typename ScriptableClass_type>
class script_type
:   public script_type_interface
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, I_ScriptMethod*>          Methods_type;
    typedef Zen::Memory::managed_ptr<I_ScriptType>          pScriptType_type;
    typedef std::map<std::string, I_ScriptableType*>        GlobalObjects_type;
    /// @}

    /// @name script_type_interface implementation.
    /// @{
private:
    virtual void activate();

    virtual void createGlobals();
    /// @}

    /// @name script_type implementation
    /// @{
public:
    /// Add a method to this script type.
    template<class Method_type>
    script_type<ScriptableClass_type>&
    addMethod(const std::string& _methodName, Method_type _pFunction);

    /// Create a global instance of this script type.
    void createGlobalObject(const std::string& _objectName, I_ScriptableType* _pScriptableObject);
    /// @}

    /// @name 'Structors.
    ///     These methods are only called by script_module.
    /// @{
private:
    friend class script_module;
    /// Create a script type.
    script_type(script_module& _module, const std::string& _typeName, const std::string& _documentation);
    /// @}

    /// @name Member Variables
    /// @{
private:
    /// Script module that contains this script type.
    script_module&      m_module;

    /// Name of this script_type.
    /// This name is the name that is exposed to the script engine.
    std::string         m_typeName;

    /// Documentation for this script type.
    /// This is generally a very short description of the type.
    std::string         m_documentation;

    Methods_type        m_methods;

    pScriptType_type    m_pScriptType;

    GlobalObjects_type  m_globalObjects;
    /// @}

};  // class script_type

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Scripting
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_SCRIPTING_SCRIPT_TYPE_HPP_INCLUDED
