//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Engine Game Tutorial
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
// This project is part of the Zen Engine Tutorials
// 
// For more details, click on the link below for the IndieZen.org documentation:
//
// http://www.indiezen.org/wiki/wiki/zoss/Engine/Tutorials
//
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#include "GameClient.hpp"
#include "WidgetManager.hpp"

#include <Zen/Core/Math/Vector3.hpp>
#include <Zen/Core/Math/Quaternion4.hpp>

#include <Zen/Core/Scripting/I_ScriptEngine.hpp>
#include <Zen/Core/Scripting/I_ScriptModule.hpp>
#include <Zen/Core/Scripting/I_ScriptType.hpp>
#include <Zen/Core/Scripting/ObjectReference.hpp>

#include <Zen/Engine/Core/I_GameGroup.hpp>
#include <Zen/Engine/Core/I_ActionMap.hpp>
#include <Zen/Engine/Core/I_GameObjectBehaviors.hpp>

#include <Zen/Engine/Physics/I_PhysicsActor.hpp>
#include <Zen/Engine/Physics/I_PhysicsMaterial.hpp>

#include <Zen/Engine/Rendering/I_RenderingCanvas.hpp>
#include <Zen/Engine/Rendering/I_SceneService.hpp>
#include <Zen/Engine/Rendering/I_SceneNode.hpp>
#include <Zen/Engine/Rendering/I_Light.hpp>
#include <Zen/Engine/Rendering/I_Camera.hpp>

#include <Zen/Engine/Resource/I_ResourceService.hpp>
#include <Zen/Engine/Rendering/I_RenderableResource.hpp>

#include <Zen/Engine/Input/I_InputService.hpp>
#include <Zen/Engine/Input/I_InputMap.hpp>

#include <Zen/Engine/World/I_Sky.hpp>

// Ogre stuff
#include <Zen/plugins/ZOgre/I_OgreRenderingCanvas.hpp>
#include <Ogre.h>

#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>

#include <boost/bind.hpp>

#include <stddef.h>
#include <iostream>


//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Game {
namespace Client {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

GameClient::GameClient(WindowHandle_type _pParent)
:   m_base(Zen::Engine::Base::I_BaseGameClient::getSingleton())
,   m_game(Zen::Engine::Base::I_BaseGame::getSingleton())
,   m_pScriptObject(NULL)
{
    m_base.setWindowHandle(_pParent);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
GameClient::~GameClient()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const GameClient::WindowHandle_type
GameClient::getHandle() const
{
    return m_base.getWindowHandle();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Scripting::I_ObjectReference*
GameClient::getScriptObject()
{
    return m_pScriptObject;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
GameClient::init()
{
    // Initialize Rendering
    initRendering();

    // Initialize Physics
    game().initPhysicsService("ZNewton");
    setupPhysicsMaterials();
    game().initPhysicsResourceService("ZNewton");

    // For some reason the sky service must be initialized after physics
    m_base.initSkyService("ZSky");

    // Initialize the Input service
    // Note: "keyboard" actually initializes the ZInput Keyboard and Mouse 
    // combined input service.
    m_base.initInputService("keyboard");

    // Initialize the widget service
    m_pWidgetManager = new WidgetManager(*this, m_base.getInputService());

    // Initialize resources
    initResources();

    // Create the script types
    createScriptTypes();

    // Possibly the rest of this should be done later and we should show 
    // an initial game screen or splash screens here.

    createActions();
    createDefaultMapping();
    createBehaviors();

    // Normally, createScene() is done after other things like 
    // displaying some splash screens, etc.  But for now lets
    // just do it here.
    createScene();

    return true;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::initRendering()
{
    m_base.initRenderingService("ogre");
    m_base.initSceneService("ogre");
    m_base.initRenderingResourceService("ogre");

    Zen::Engine::Rendering::I_RenderingCanvas& canvas = m_base.getRenderingCanvas();

    // Select the default camera.  No need to create it since it always exists
    Zen::Engine::Rendering::I_Camera& camera = canvas.selectCamera("default");

    // TODO Need to implement something like this
   	//canvas.setBackgroundColour(Zen::Engine::Rendering::ColorValue(0, 0, 0.2f));

    camera.setNearClipDistance(0.01f);
    camera.setAspectRatio((Zen::Math::Real)canvas.getWidth() / (Zen::Math::Real)canvas.getHeight());
    camera.setHorizontalFOV(Zen::Math::Degree(60));
    camera.setPosition(0.0, 200.0, 100.0);

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::initResources()
{
    boost::filesystem::path rootPath = boost::filesystem::system_complete(boost::filesystem::path("resources", boost::filesystem::native)).normalize();
    m_base.getRenderingResourceService().addResourceLocation(rootPath.string(), "FileSystem", "General", true);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::run()
{
    m_base.run();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createScriptTypes()
{
    // TODO Register additional script types here

    // Tell m_base we're done.  After the modules are activated then you cannot
    // modify any script types.
    m_base.activateScriptModules();

    // Create the script object for this game client
    m_pScriptObject = new ScriptObjectReference_type
        (base().getScriptModule(), base().getScriptModule()->getScriptType(getScriptTypeName()), getSelfReference().lock());
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createScene()
{
    // Create a sky box

    Zen::Engine::World::I_SkyService::config_type skyConfig;
    skyConfig["type"] = "skybox";
    skyConfig["resourceName"] = "SteveCube";
    m_pSky = m_base.getSkyService().createSky(skyConfig);

    m_base.getSceneService().setAmbientLight(0.8f, 0.8f, 0.8f, 1.0f);
    Zen::Engine::Rendering::I_SceneService::pLight_type pLight = m_base.getSceneService().createLight("default", "Light");
    pLight->setPosition(500.0f, 500.0f, 500.0f);

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createActions()
{
    // Create some actions
    game().getActionMap().createAction("Quit", boost::bind(&Zen::Engine::Base::I_BaseGameClient::quit, &m_base, _1));

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createDefaultMapping()
{
    // Map some keys to actions
    m_base.getInputMap().mapKeyInput("q", game().getActionMap()["Quit"]);

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::createBehaviors()
{

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::setupPhysicsMaterials()
{
    // TODO - only the default material works, since the objects are made in script
    //   this code needs to be transferred to script and then applied to the
    //   physics shapes after they're created.
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::Base::I_BaseGameClient&
GameClient::base()
{
    return m_base;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Engine::Base::I_BaseGame&
GameClient::game()
{
    return m_game;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
GameClient::beforeRender(double _elapsedTime)
{
    // TODO: Do everything else that needs to be done before the screen is rendered

    // This updates all physics worlds we've created:
    game().getPhysicsService()->stepSimulation(_elapsedTime);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Client
}   // namespace Game
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
