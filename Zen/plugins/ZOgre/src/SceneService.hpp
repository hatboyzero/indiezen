//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2008 Tony Richards
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
#ifndef ZEN_ZOGRE_SCENE_SERVICE_HPP_INCLUDED
#define ZEN_ZOGRE_SCENE_SERVICE_HPP_INCLUDED

#include "NullCamera.hpp"

#include <Zen/Engine/Rendering/I_SceneService.hpp>

#include <Zen/Core/Memory/managed_self_ref.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

#include "Ogre.hpp"

#include <map>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace ZOgre {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class SceneService
:   public Zen::Engine::Rendering::I_SceneService
,   public Memory::managed_self_ref<Zen::Engine::Rendering::I_SceneService>
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_weak_ptr<Zen::Engine::Rendering::I_Light>  wpLight_type;
    /// @}

    /// @name I_SceneService implementation
    /// @{
public:
    virtual pLight_type createLight(const std::string& _type, const std::string& _name);
    virtual pSceneNode_type createChildNode(const std::string& _name);
    virtual pParticleSystem_type createParticleSystem(const std::string& _name, const std::string& _resource);
    virtual void setAmbientLight(Math::Real _red, Math::Real _green, Math::Real _blue, Math::Real _alpha);
    /// @}

    /// @name I_ScriptableType implementation
    /// @{
public:
    virtual Scripting::I_ObjectReference* getScriptObject();
    /// @}

    /// @name SceneService implementation
    /// @{
private:
    static void destroySceneNode(wpSceneNode_type _pNode);
    static void destroyParticleSystem(wpParticleSystem_type _pParticleSystem);
    static void onDestroyLight(wpLight_type& _wpLight);
    /// @}

    /// @name 'Structors
    /// @{
public:
             SceneService();
    virtual ~SceneService();
    /// @}

    /// @name Member Variables
    /// @{
private:
    ScriptObjectReference_type*     m_pScriptObject;
    Ogre::SceneManager*             m_pSceneManager;

    typedef std::map<std::string, Engine::Camera::I_Camera*>    cameras_type;
    cameras_type        m_cameras;

    /// @}

};  // class SceneService

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace ZOgre
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ZOGRE_SCENE_SERVICE_HPP_INCLUDED
