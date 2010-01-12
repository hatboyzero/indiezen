//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Engine Base Starter Kit
//
// Copyright (C) 2001 - 2009 Tony Richards
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
#include "BaseGame.hpp"

#include "Action.hpp"
#include "GameGroup.hpp"
#include "BehavioredGameObject.hpp"
#include "GameObject.hpp"

#include <Zen/Engine/Rendering/I_RenderingService.hpp>
#include <Zen/Engine/Rendering/I_RenderingServiceFactory.hpp>

#include <Zen/Engine/Rendering/I_RenderingManager.hpp>
#include <Zen/Engine/Rendering/I_View.hpp>
#include <Zen/Engine/Rendering/I_RenderingCanvas.hpp>
#include <Zen/Engine/Rendering/I_SceneManager.hpp>
#include <Zen/Engine/Rendering/I_SceneService.hpp>
#include <Zen/Engine/Rendering/I_SceneServiceFactory.hpp>
#include <Zen/Engine/Rendering/I_Context.hpp>

#include <Zen/Engine/Resource/I_ResourceService.hpp>
#include <Zen/Engine/Resource/I_ResourceManager.hpp>

#include <Zen/Engine/World/I_WorldManager.hpp>
#include <Zen/Engine/World/I_WaterService.hpp>
#include <Zen/Engine/World/I_TerrainService.hpp>
#include <Zen/Engine/World/I_SkyService.hpp>

#include <Zen/Engine/Camera/I_CameraManager.hpp>
#include <Zen/Engine/Camera/I_CameraService.hpp>
#include <Zen/Engine/Camera/I_Camera.hpp>

#include <Zen/Engine/Physics/I_PhysicsManager.hpp>
#include <Zen/Engine/Physics/I_PhysicsService.hpp>
#include <Zen/Engine/Physics/I_PhysicsWorld.hpp>
#include <Zen/Engine/Physics/I_PhysicsShape.hpp>

#include <Zen/Engine/Input/I_InputServiceManager.hpp>
#include <Zen/Engine/Input/I_InputService.hpp>
#include <Zen/Engine/Input/I_InputMap.hpp>
#include <Zen/Engine/Input/I_KeyEvent.hpp>

#include <Zen/Engine/Navigation/I_NavigationManager.hpp>
#include <Zen/Engine/Navigation/I_NavigationService.hpp>

#include <Zen/Engine/Client/I_GameClient.hpp>

#include <Zen/Core/Scripting/I_ScriptingManager.hpp>
#include <Zen/Core/Scripting/I_ScriptEngine.hpp>
#include <Zen/Core/Scripting/I_ScriptModule.hpp>
#include <Zen/Core/Scripting/I_ScriptType.hpp>
#include <Zen/Core/Scripting/ObjectReference.hpp>

#include <Zen/Core/Threading/I_Thread.hpp>

#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/bind.hpp>

#include <iostream>
#include <sstream>

#ifdef WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include <conio.h>
#endif

#include <stddef.h>

#ifdef __GNUG__
#include <stdint.h>
#endif

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Engine {
namespace Base {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::BaseGame()
{
    m_pMainGroup = NULL;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::~BaseGame()
{
    int x = 0;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Core::I_ActionMap&
BaseGame::getActionMap(const std::string& _actionMapName)
{
    ActionMaps_type::iterator iter = m_actionMapMap.find(_actionMapName);
    if (iter != m_actionMapMap.end())
    {
        return *iter->second;
    }
    else
    {
        ActionMap* pActionMap = new ActionMap();
        m_actionMapMap[_actionMapName] = pActionMap;
        return *pActionMap;
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Core::I_BehaviorService&
BaseGame::getBehaviorService()
{
    return m_behaviorService;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Core::I_GameGroup&
BaseGame::getRootGroup()
{
    // TODO Guard?
    if (m_pMainGroup == NULL)
    {
        m_pModule->activate();
        m_pMainGroup = new GameGroup(*this);
    }

    return *m_pMainGroup;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
BaseGame::initScriptModule(pScriptEngine_type _pScriptEngine)
{
    m_pScriptEngine = _pScriptEngine;
    m_pModule = m_pScriptEngine->createScriptModule("BaseGame", "Base Game");
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::pScriptModule_type
BaseGame::getScriptModule()
{
    return m_pModule;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Scripting::I_ObjectReference*
BaseGame::getScriptObject()
{
    return m_pScriptObject;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static Zen::Scripting::I_ObjectReference*
script_getRootGroup(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    return I_BaseGame::getSingleton().getRootGroup().getScriptObject();
}

static Zen::Scripting::I_ObjectReference*
script_getActionMap(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    if (_parms.size() == 0)
    {
        return I_BaseGame::getSingleton().getActionMap().getScriptObject();
    }
    else
    {
        std::string name = boost::any_cast<std::string>(_parms[0]);
        return I_BaseGame::getSingleton().getActionMap(name).getScriptObject();
    }
}

static Zen::Scripting::I_ObjectReference*
script_createObject(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Core::I_GameGroup::ScriptObjectReference_type* pObject = dynamic_cast<Core::I_GameGroup::ScriptObjectReference_type*>(_pObject);

    std::string name = boost::any_cast<std::string>(_parms[0]);

    return pObject->getObject()->createObject(name).getScriptObject();
}

static Zen::Scripting::I_ObjectReference*
script_getGroup(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Core::I_GameGroup::ScriptObjectReference_type* pObject = dynamic_cast<Core::I_GameGroup::ScriptObjectReference_type*>(_pObject);

    std::string name = boost::any_cast<std::string>(_parms[0]);

    return pObject->getObject()->getGroup(name).getScriptObject();
}

static void
script_initBoxShape(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Physics::I_PhysicsZone::ScriptObjectReference_type* pObject = dynamic_cast<Zen::Scripting::ObjectReference<Physics::I_PhysicsZone>*>(_pObject);
}

static void
script_setMass(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Zen::Scripting::ObjectReference<Physics::I_CollisionShape>* pObject = dynamic_cast<Zen::Scripting::ObjectReference<Physics::I_CollisionShape>*>(_pObject);
}

static void
script_setPosition(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Engine::Core::I_BaseGameObject::ScriptObjectReference_type* pObject = dynamic_cast<Engine::Core::I_BaseGameObject::ScriptObjectReference_type*>(_pObject);

    I_BaseGameObject* pGameObject = dynamic_cast<I_BaseGameObject*>(pObject->getObject());

    // Get the parms and set the position
    Math::Real dx = boost::any_cast<Math::Real>(_parms[0]);
    Math::Real dy = boost::any_cast<Math::Real>(_parms[1]);
    Math::Real dz = boost::any_cast<Math::Real>(_parms[2]);

    pGameObject->setPosition(dx, dy, dz, true);
}

static void
script_setScale(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Engine::Core::I_BaseGameObject::ScriptObjectReference_type* pObject = dynamic_cast<Engine::Core::I_BaseGameObject::ScriptObjectReference_type*>(_pObject);

    I_BaseGameObject* pGameObject = dynamic_cast<I_BaseGameObject*>(pObject->getObject());

    // Get the parms and set the position
    Math::Real dx = boost::any_cast<Math::Real>(_parms[0]);
    Math::Real dy = boost::any_cast<Math::Real>(_parms[1]);
    Math::Real dz = boost::any_cast<Math::Real>(_parms[2]);

    pGameObject->setScale(dx, dy, dz);
}

static void
script_setOrientation(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Engine::Core::I_BaseGameObject::ScriptObjectReference_type* pObject = dynamic_cast<Engine::Core::I_BaseGameObject::ScriptObjectReference_type*>(_pObject);

    I_BaseGameObject* pGameObject = dynamic_cast<I_BaseGameObject*>(pObject->getObject());

    if (_parms.size() == 4)
    {
        // Get the parms and set the position
        Math::Real _w = boost::any_cast<Math::Real>(_parms[0]);
        Math::Real _x = boost::any_cast<Math::Real>(_parms[1]);
        Math::Real _y = boost::any_cast<Math::Real>(_parms[2]);
        Math::Real _z = boost::any_cast<Math::Real>(_parms[3]);

        pGameObject->setOrientation(_w, _x, _y, _z, true);
    }
    else
    {
        Math::Quaternion4* pOrientation = boost::any_cast<Math::Quaternion4*>(_parms[0]);
        pGameObject->setOrientation(*pOrientation);
    }
}

static Zen::Scripting::I_ObjectReference*
script_getCollisionShape(Zen::Scripting::I_ObjectReference* _pObject, std::vector<boost::any> _parms)
{
    Engine::Core::I_BaseGameObject::ScriptObjectReference_type* pObject = dynamic_cast<Engine::Core::I_BaseGameObject::ScriptObjectReference_type*>(_pObject);

    I_BaseGameObject* pGameObject = dynamic_cast<I_BaseGameObject*>(pObject->getObject());

    Zen::Engine::Core::I_BaseGameObject::pCollisionShape_type pCollisionShape = pGameObject->getCollisionShape();
    Zen::Scripting::I_ObjectReference* pScriptObject = pCollisionShape->getScriptObject();
    return pScriptObject;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
BaseGame::initScriptTypes()
{
    // Create the Game script type
    m_pGameScriptType = m_pModule->createScriptType("Game", "Game", 0);
    m_pGameScriptType->addMethod("getRootGroup", "Get the root GameGroup",
        &script_getRootGroup);
    m_pGameScriptType->addMethod("getActionMap", "Get the ActionMap",
        &script_getActionMap);

    // Create the GameGroup type
    m_pGameGroupScriptType = m_pModule->createScriptType("GameGroup", "Game Group", 0);
    m_pGameGroupScriptType->addMethod("createObject", "Create a game object",
        &script_createObject);
    m_pGameGroupScriptType->addMethod("getGroup", "Get a sub group",
        &script_getGroup);

    // Create the GameObject script type
    m_pGameObjectScriptType = m_pModule->createScriptType("GameObject", "Game Object", 0);

#if 0 // These have been moved to individual game client implementations of I_GameObject
    m_pGameObjectScriptType->addMethod("loadResource", "Load a rendering resource associated and associate it with this object",
        &script_loadResource);
    m_pGameObjectScriptType->addMethod("setMaterialName", "Set the material name for this object",
        &script_setMaterialName);
#endif // moved

    m_pGameObjectScriptType->addMethod("setPosition", "Set the position of this object",
        &script_setPosition);
    m_pGameObjectScriptType->addMethod("setScale", "Set the scale of this object",
        &script_setScale);
    m_pGameObjectScriptType->addMethod("setOrientation", "Set the orientation of this object",
        &script_setOrientation);
    m_pGameObjectScriptType->addMethod("getCollisionShape", "Get the Physics Shape of this object",
        &script_getCollisionShape);

    // Create the PhysicsZone script type
    m_pPhysicsZoneScriptType = m_pModule->createScriptType("PhysicsZone", "Physics World", 0);

#if 0 // not implemented?
    m_pPhysicsZoneScriptType->addMethod("createShape", "Create a Physics Shape",
        &script_createShape);
#endif

    // Create the CollisionShape script type
    m_pCollisionShapeScriptType = m_pModule->createScriptType("CollisionShape", "Physics Shape", 0);
    m_pCollisionShapeScriptType->addMethod("initBoxShape", "",
        &script_initBoxShape);
    m_pCollisionShapeScriptType->addMethod("setMass", "",
        &script_setMass);

#if 0 // TODO This needs to be implemented to support multiple worlds.
    m_pGameClientScriptType->addMethod("getPhysicsZone", "",
        &script_getPhysicsZone);
#endif

    dynamic_cast<ActionMap*>(&getActionMap())->registerScriptModule(m_pModule);

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::pScriptType_type
BaseGame::getGameGroupScriptType()
{
    return m_pGameGroupScriptType;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::pScriptType_type
BaseGame::getGameObjectScriptType()
{
    return m_pGameObjectScriptType;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
BaseGame::createScriptObjects()
{
    // It's not until after activate() that you can create objects of the new types
    getRootGroup().getScriptObject();

    // Create the script object for this game
    m_pScriptObject = new ScriptObjectReference_type
        (getScriptModule(), getScriptModule()->getScriptType(getScriptTypeName()), this);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
BaseGame::initPhysicsService(const std::string& _type)
{
    // was "ZNewton"
    Zen::Engine::Physics::I_PhysicsManager::config_type config;

    // Create the service
    m_pPhysicsService =
        Zen::Engine::Physics::I_PhysicsManager::getSingleton().create(_type, config);

    if (m_pPhysicsService.isValid())
    {
        std::cout << "Error: couldn't initPhysicsService()" << std::endl;
    }

    // Initialize the first world
    m_pPhysicsZone = getPhysicsService()->createZone();

    // Register the script engine with the Physics Manager
    if (m_pScriptEngine.isValid())
    {
        Zen::Engine::Physics::I_PhysicsManager::getSingleton().registerDefaultScriptEngine(m_pScriptEngine);
    }

    return true;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::pPhysicsZone_type
BaseGame::getCurrentPhysicsZone()
{
    return m_pPhysicsZone;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
BaseGame::initPhysicsResourceService(const std::string& _type)
{
    // Was "ogre"

    // Register the script engine
    if (m_pScriptEngine.isValid())
    {
        Resource::I_ResourceManager::getSingleton().registerDefaultScriptEngine(m_pScriptEngine);
    }

    // TODO Don't hard-code this
    Zen::Engine::Resource::I_ResourceManager::config_type config;

    // Create the service
    m_pPhysicsResourceService =
        Resource::I_ResourceManager::getSingleton().create(_type, config);

    pScriptModule_type const pModule = Resource::I_ResourceManager::getSingleton().getDefaultScriptModule();

    if (pModule.isValid())
    {
        new Scripting::ObjectReference<Resource::I_ResourceService>(pModule,
            pModule->getScriptType(m_pPhysicsResourceService->getScriptTypeName()),
            m_pPhysicsResourceService, "physicsResourceService");
    }

    return true;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::pPhysicsService_type
BaseGame::getPhysicsService()
{
    return m_pPhysicsService;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
BaseGame::pPhysicsResourceService_type
BaseGame::getPhysicsResourceService()
{
    return m_pPhysicsResourceService;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
bool
BaseGame::initNavigationService(const std::string& _type)
{
    m_pNavigationService =
        Zen::Engine::Navigation::I_NavigationManager::getSingleton().create(_type);

    if (m_pNavigationService.isValid())
    {
        std::cout << "Error: couldn't create NavigationService" << std::endl;
        return false;
    }

    return true;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Navigation::I_NavigationService&
BaseGame::getNavigationService()
{
    return *m_pNavigationService;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Base
}   // namespace Engine
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~