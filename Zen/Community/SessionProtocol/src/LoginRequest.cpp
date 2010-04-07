//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Community Framework
//
// Copyright (C) 2001 - 2010 Tony Richards
// Copyright (C) 2008 - 2010 Matthew Alan Gray
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
// This is generated by the Zen Protocol Code Generator.  Do not modify!
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#include "Message.hpp"        
#include "LoginRequest.hpp"
#include "MessageFactory.hpp"

#include <Zen/Enterprise/Networking/I_Endpoint.hpp>

#include <Zen/Enterprise/AppServer/I_ResourceLocation.hpp>
#include <Zen/Enterprise/AppServer/I_MessageHeader.hpp>
#include <Zen/Enterprise/AppServer/I_MessageFactory.hpp>
#include <Zen/Enterprise/AppServer/I_ApplicationServer.hpp>
#include <Zen/Enterprise/AppServer/I_ApplicationServerManager.hpp>
#include <Zen/Enterprise/AppServer/I_NumericTypeMessageRegistry.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Protocol {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
LoginRequest::pMessageType_type LoginRequest::sm_pType;
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Enterprise::AppServer::I_MessageRegistry* LoginRequest::sm_pMessageRegistry = NULL;
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
LoginRequest::LoginRequest(pEndpoint_type _pSourceEndpoint,
                           pEndpoint_type _pDestinationEndpoint)
:   Request(LoginRequest::createMessageHeader(getNewMessageId()), _pSourceEndpoint, _pDestinationEndpoint)        
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
LoginRequest::LoginRequest(pMessageHeader_type _pMessageHeader,
                             pEndpoint_type _pSourceEndpoint,
                             pEndpoint_type _pDestinationEndpoint)            
:   Request(_pMessageHeader, _pSourceEndpoint, _pDestinationEndpoint) 
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
LoginRequest::~LoginRequest()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
LoginRequest::serialize(pMessageHeader_type _pHeader, boost::archive::polymorphic_iarchive& _archive, const int _version)
{
    _archive & m_userId;
    _archive & m_password;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
LoginRequest::serialize(boost::archive::polymorphic_oarchive& _archive, const int _version)
{
    _archive & m_userId;
    _archive & m_password;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
LoginRequest::getUserId() const
{
    return m_userId;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
LoginRequest::setUserId(const std::string& _userId)
{
    m_userId = _userId;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
LoginRequest::getPassword() const
{
    return m_password;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
LoginRequest::setPassword(const std::string& _password)
{
    m_password = _password;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
LoginRequest::registerMessage(Zen::Enterprise::AppServer::I_ApplicationServer& _appServer)
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
LoginRequest::pMessageHeader_type
LoginRequest::createMessageHeader(boost::uint32_t _messageId)
{
    return sm_pMessageRegistry->createMessageHeader(sm_pType, _messageId,0);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
LoginRequest::destroy(wpRequest_type _wpResponse)
{
    LoginRequest* pRequest = dynamic_cast<LoginRequest*>(_wpResponse.get());

    if( pRequest != NULL )
    {
        delete pRequest;
    }
    else
    {
        throw Zen::Utility::runtime_exception("LoginRequest::destroy() : Invalid type.");
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static Message::pResourceLocation_type  sm_pResourceLocation;
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
LoginRequest::pResourceLocation_type
LoginRequest::getDestinationLocation()
{
    if(!sm_pResourceLocation.isValid())
    {
        sm_pResourceLocation = Zen::Enterprise::AppServer::I_ApplicationServerManager::getSingleton().createLocation("/loginServer");
    }
    return sm_pResourceLocation;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
LoginRequest::pMessageType_type
LoginRequest::getStaticMessageType()
{
    return sm_pType;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Protocol
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
