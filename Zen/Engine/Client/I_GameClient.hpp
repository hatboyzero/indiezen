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
/// @brief I_GameClient interface
///
/// Declaration of the I_GameClient interface.
///
///
/// @author Tony Richards trichards@indiezen.com
/// @author Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_ENGINE_CLIENT_I_GAME_CLIENT_HPP_INCLUDED
#define ZEN_ENGINE_CLIENT_I_GAME_CLIENT_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Math/Math.hpp>

#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>
#include <Zen/Core/Memory/managed_self_ref.hpp>

#include <Zen/Core/Event/Event.hpp>

#include <Zen/Core/Scripting/I_ScriptableService.hpp>
#include <Zen/Core/Scripting/ObjectReference.hpp>

#include <string>
#include <map>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifdef WIN32
#include <windows.h>
#endif

#include <stddef.h>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Engine {
    namespace Rendering {
        class I_RenderingCanvas;
    }   // namespace Rendering
    namespace Resource {
        class I_ResourceService;
    }   // namespace Resource
    namespace Widgets {
        class I_WidgetService;
    }   // namespace Widgets
    namespace World {
        class I_TerrainService;
        class I_SkyService;
    }   // namespace World
namespace Client {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

/// Basic game client interface
class CLIENT_DLL_LINK I_GameClient
:   public virtual Zen::Scripting::I_ScriptableService
,   public Memory::managed_self_ref<I_GameClient>
{
    /// @name Types
    /// @{
public:
#ifdef _WIN32
    typedef HWND                                        WindowHandle_type;
#else
    typedef const char*                                 WindowHandle_type;
#endif

    typedef std::string                                 index_type;

    typedef Memory::managed_ptr<I_GameClient>           pService_type;
    typedef Memory::managed_weak_ptr<I_GameClient>      wpService_type;

    typedef Event::Event<wpService_type>                serviceEvent_type;
    typedef double                                      frameDelta_type;
    typedef Event::Event<frameDelta_type>               frameEvent_type;

    typedef Memory::managed_ptr<I_GameClient>           pScriptObject_type;
    typedef Scripting::ObjectReference<I_GameClient>    ScriptObjectReference_type;
    typedef ScriptObjectReference_type                  ScriptWrapper_type;
    typedef ScriptWrapper_type*                         pScriptWrapper_type;
    /// @}

    /// @name I_GameClient interface
    /// @{
public:
    /// Get the window handle.
    virtual const WindowHandle_type getHandle() const = 0;

    /// Activate the script module for the game developer
    /// script module.
    virtual void activateGameClientScriptModule() = 0;

    /// Initialize the Game Client.
    virtual bool init() = 0;

    /// Run the Game Client.
    virtual void run() = 0;

    /// Get the widget service.
    virtual Widgets::I_WidgetService& getWidgetService() = 0;

    /// Get the current rendering canvas.
    virtual Rendering::I_RenderingCanvas& getRenderingCanvas() = 0;

    /// Get the current rendering resource service.
    virtual Resource::I_ResourceService& getRenderingResourceService() = 0;

    /// Get the current terrain service.
    virtual World::I_TerrainService& getTerrainService() = 0;

    /// Get the current sky service.
    virtual World::I_SkyService& getSkyService() = 0;

    /// Initialize the rendering service.
    virtual bool initRenderingService(const std::string& _type, const std::string& _title, int _xRes, int _yRes) = 0;

    /// Initialize the rendering resource service.
    virtual bool initRenderingResourceService(const std::string& _type) = 0;

    /// Initialize the terrain service.
    virtual bool initTerrainService(const std::string& _type) = 0;

    /// Initialize the sky service.
    virtual bool initSkyService(const std::string& _type) = 0;

    /// Initialize the input service.
    virtual bool initInputService(const std::string& _type) = 0;

    /// Initialize the widget service.
    virtual bool initWidgetService(const std::string& _type) = 0;
    /// @}

    /// @name I_ScriptableType implementation
    /// @{
public:
    /// This is implemented to return "GameClient"
    /// Override this method if you create a derived type
    virtual const std::string& getScriptTypeName();
    /// @}

    /// @name Static methods
    /// @{
public:
    static const std::string& getNamespace();
    static const std::string& getExtensionPointName();
    /// @}

    /// @name Event
    /// @{
public:
    serviceEvent_type   onDestroyEvent;

    /// This event is fired before every frame is rendered
    /// The payload is the number of elapsed seconds since
    /// the previous frame event.
    frameEvent_type     onBeforeFrameRenderedEvent;

    /// This event is fired after every frame is rendered
    /// The payload is the number of elapsed seconds since
    /// the previous frame event.
    frameEvent_type     onFrameEvent;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_GameClient();
    virtual ~I_GameClient();
    /// @}

};  // interface I_GameClient

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Client
}   // namespace Engine
namespace Memory {
    // I_GameClient is managed by I_GameClientFactory
    template<>
    struct is_managed_by_factory<Engine::Client::I_GameClient> : public boost::true_type{};
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ENGINE_CLIENT_I_GAME_CLIENT_HPP_INCLUDED
