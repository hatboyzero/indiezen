//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Game Engine Framework
//
// Copyright (C) 2001 - 2009 Tony Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
// Copyright (C) 2008 - 2009 Walt Collins
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
//  Walt Collins (Arcanor) - wcollins@indiezen.com
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_CAMERA_I_CAMERA_SERVICE_FACTORY_HPP_INCLUDED
#define ZEN_ENGINE_CAMERA_I_CAMERA_SERVICE_FACTORY_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Plugins/I_ClassFactory.hpp>
#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Engine {
    namespace Plugins {
        class I_ConfigurationElement;
    } // namespace Plugins
namespace Camera {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_CameraService;

/// Base Camera Service Factory interface
class CAMERA_DLL_LINK I_CameraServiceFactory
:   public Zen::Plugins::I_ClassFactory
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<I_CameraService>   pCameraService_type;
    typedef Memory::managed_weak_ptr<I_CameraService>   wpCameraService_type;
    typedef std::map<std::string, std::string>          config_type;
    /// @}

    /// @name I_CameraServiceFactory interface
    /// @{
public:
    /// Create the camera service
    virtual pCameraService_type create(const std::string& _type) = 0;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_CameraServiceFactory();
    virtual ~I_CameraServiceFactory();

};  // interface I_CameraServiceFactory

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Camera
}   // namespace Engine
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_CAMERA_I_CAMERA_SERVICE_FACTORY_HPP_INCLUDED