//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Studio Workbench Framework
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
#include "ChildNodeRequest.hpp"
#include "MessageFactory.hpp"

#include <Zen/Enterprise/Networking/I_Endpoint.hpp>

#include <Zen/Enterprise/AppServer/I_ResourceLocation.hpp>
#include <Zen/Enterprise/AppServer/I_MessageHeader.hpp>
#include <Zen/Enterprise/AppServer/I_MessageFactory.hpp>
#include <Zen/Enterprise/AppServer/I_ApplicationServer.hpp>
#include <Zen/Enterprise/AppServer/I_ApplicationServerManager.hpp>
#include <Zen/Enterprise/AppServer/I_NumericTypeMessageRegistry.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChildNodeRequest::pMessageType_type ChildNodeRequest::sm_pType;
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Enterprise::AppServer::I_MessageRegistry* ChildNodeRequest::sm_pMessageRegistry = NULL;
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChildNodeRequest::ChildNodeRequest(pEndpoint_type _pSourceEndpoint,
                           pEndpoint_type _pDestinationEndpoint)
:   Message(createMessageHeader(), _pSourceEndpoint, _pDestinationEndpoint)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChildNodeRequest::ChildNodeRequest(pMessageHeader_type _pMessageHeader,
                             pEndpoint_type _pSourceEndpoint,
                             pEndpoint_type _pDestinationEndpoint)
:   Message(_pMessageHeader, _pSourceEndpoint, _pDestinationEndpoint)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChildNodeRequest::~ChildNodeRequest()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChildNodeRequest::serialize(pMessageHeader_type _pHeader, boost::archive::polymorphic_iarchive& _archive, const int _version)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChildNodeRequest::serialize(boost::archive::polymorphic_oarchive& _archive, const int _version)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChildNodeRequest::registerMessage(Zen::Enterprise::AppServer::I_ApplicationServer& _appServer)
{
    // Register messages.  Not keeping a managed pointer because it's really a singleton.
    sm_pMessageRegistry = _appServer.getMessageRegistry().get();

    Zen::Enterprise::AppServer::I_NumericTypeMessageRegistry*
        pMessageRegistry = dynamic_cast<Zen::Enterprise::AppServer::I_NumericTypeMessageRegistry*>
            (sm_pMessageRegistry);

    if( !sm_pMessageFactory.isValid() )
    {
        sm_pMessageFactory = pMessageFactory_type(new MessageFactory, destroyMessageFactory);
    }

    if (pMessageRegistry != NULL)
    {
        sm_pType = pMessageRegistry->getMessageType(type);
        sm_pType->setMessageFactory(sm_pMessageFactory);
        sm_pMessageRegistry->registerMessageType(sm_pType);
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChildNodeRequest::pMessageHeader_type
ChildNodeRequest::createMessageHeader()
{
    return sm_pMessageRegistry->createMessageHeader(sm_pType);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChildNodeRequest::destroy(wpRequest_type _wpRequest)
{
    ChildNodeRequest* pRequest = dynamic_cast<ChildNodeRequest*>(_wpRequest.get());

    if( pRequest != NULL )
    {
        delete pRequest;
    }
    else
    {
        throw Zen::Utility::runtime_exception("ChildNodeRequest::destroy() : Invalid type.");
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static Message::pResourceLocation_type  sm_pResourceLocation;
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChildNodeRequest::pResourceLocation_type
ChildNodeRequest::getDestinationLocation()
{
    if(!sm_pResourceLocation.isValid())
    {
        sm_pResourceLocation = Zen::Enterprise::AppServer::I_ApplicationServerManager::getSingleton().createLocation("/loginServer");
    }
    return sm_pResourceLocation;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Workbench
}   // namespace Studio
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~