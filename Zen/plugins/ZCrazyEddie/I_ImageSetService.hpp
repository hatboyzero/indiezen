//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2009 Tony Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
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
//  Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_ZCRAZYEDDIE_I_IMAGE_SET_SERVICE_HPP_INCLUDED
#define ZEN_ENGINE_ZCRAZYEDDIE_I_IMAGE_SET_SERVICE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <boost/noncopyable.hpp>

#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace ZCrazyEddie {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ImageSet;

class ZCRAZYEDDIE_DLL_LINK I_ImageSetService
:   public boost::noncopyable
{
    /// @name Types
    /// @{
public:
    typedef std::string                                     index_type;
    /// These are raw pointers because I_WidgetService
    /// manages the lifetime and nothing outside of I_WidgetService
    /// should retain a reference to I_ImageSetService.
    typedef I_ImageSetService*                              pService_type;
    typedef I_ImageSetService*                              wpService_type;
    /// @}

    /// @name I_ImageSetService interface
    /// @{
public:
    /// Create an image set
    virtual I_ImageSet& createImageSet(const std::string& _imageSet) = 0;
    /// Create an image set from file
    virtual I_ImageSet& createImageSetFromFile(const std::string& _imageSet, const std::string& _filename) = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ImageSetService();
    virtual ~I_ImageSetService();
    /// @}

};  // interface I_ImageSetService

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace ZCrazyEddie
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_ZCRAZYEDDIE_I_IMAGE_SET_SERVICE_HPP_INCLUDED
