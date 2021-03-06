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
#include "MessageFactory.hpp"
#include "Message.hpp"

#include "UnsubscribeAccountModelRequest.hpp"
#include "UnsubscribeAccountModelResponse.hpp"

#include "UpdateGroupRequest.hpp"
#include "UpdateGroupResponse.hpp"

#include "DeleteAccountRequest.hpp"
#include "DeleteAccountResponse.hpp"

#include "CreateAccountRequest.hpp"
#include "CreateAccountResponse.hpp"

#include "SubscribeGroupModelRequest.hpp"
#include "SubscribeGroupModelResponse.hpp"

#include "UnsubscribeGroupModelRequest.hpp"
#include "UnsubscribeGroupModelResponse.hpp"

#include "ReadAccountRequest.hpp"
#include "ReadAccountResponse.hpp"

#include "UpdateAccountRequest.hpp"
#include "UpdateAccountResponse.hpp"

#include "SubscribeAccountModelRequest.hpp"
#include "SubscribeAccountModelResponse.hpp"

#include "CreateGroupRequest.hpp"
#include "CreateGroupResponse.hpp"

#include "DeleteGroupRequest.hpp"
#include "DeleteGroupResponse.hpp"

#include "ReadGroupRequest.hpp"
#include "ReadGroupResponse.hpp"

#include "GroupModelUpdateMessage.hpp"
#include "AccountModelUpdateMessage.hpp"

#include <Zen/Enterprise/AppServer/I_NumericTypeMessageRegistry.hpp>
#include <Zen/Enterprise/AppServer/I_MessageHeader.hpp>

#include <Zen/Enterprise/Networking/I_Endpoint.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

#include <iostream>

#include <stddef.h>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Account {
namespace Protocol {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
MessageFactory::MessageFactory()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
MessageFactory::~MessageFactory()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
MessageFactory::destroy(MessageFactory::wpMessage_type _pMessage)
{
    Message* pMessage = dynamic_cast<Message*>(_pMessage.get());
    
    if (pMessage != NULL)
    {
        delete pMessage;
    }
    else
    {
        // TODO Error
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
MessageFactory::pMessage_type
MessageFactory::create(pMessageHeader_type _pMessageHeader, pEndpoint_type _pSourceEndpoint, pEndpoint_type _pDestinationEndpoint)
{
    switch(getMessageType(_pMessageHeader))
    {
        case UnsubscribeAccountModelRequest::type:
            return pMessage_type(new UnsubscribeAccountModelRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case UpdateGroupRequest::type:
            return pMessage_type(new UpdateGroupRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case DeleteAccountRequest::type:
            return pMessage_type(new DeleteAccountRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case CreateAccountRequest::type:
            return pMessage_type(new CreateAccountRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case SubscribeGroupModelRequest::type:
            return pMessage_type(new SubscribeGroupModelRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case UnsubscribeGroupModelRequest::type:
            return pMessage_type(new UnsubscribeGroupModelRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case ReadAccountRequest::type:
            return pMessage_type(new ReadAccountRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case UpdateAccountRequest::type:
            return pMessage_type(new UpdateAccountRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case SubscribeAccountModelRequest::type:
            return pMessage_type(new SubscribeAccountModelRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case CreateGroupRequest::type:
            return pMessage_type(new CreateGroupRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case DeleteGroupRequest::type:
            return pMessage_type(new DeleteGroupRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case ReadGroupRequest::type:
            return pMessage_type(new ReadGroupRequest(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case GroupModelUpdateMessage::type:
            return pMessage_type(new GroupModelUpdateMessage(_pMessageHeader,
                    _pSourceEndpoint, _pDestinationEndpoint),
                &destroy);

        case AccountModelUpdateMessage::type:
            return pMessage_type(new AccountModelUpdateMessage(_pMessageHeader,
                    _pSourceEndpoint, _pDestinationEndpoint),
                &destroy);

        case UnsubscribeAccountModelResponse::type:
            return pMessage_type(new UnsubscribeAccountModelResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case UpdateGroupResponse::type:
            return pMessage_type(new UpdateGroupResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case DeleteAccountResponse::type:
            return pMessage_type(new DeleteAccountResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case CreateAccountResponse::type:
            return pMessage_type(new CreateAccountResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case SubscribeGroupModelResponse::type:
            return pMessage_type(new SubscribeGroupModelResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case UnsubscribeGroupModelResponse::type:
            return pMessage_type(new UnsubscribeGroupModelResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case ReadAccountResponse::type:
            return pMessage_type(new ReadAccountResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case UpdateAccountResponse::type:
            return pMessage_type(new UpdateAccountResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case SubscribeAccountModelResponse::type:
            return pMessage_type(new SubscribeAccountModelResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case CreateGroupResponse::type:
            return pMessage_type(new CreateGroupResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case DeleteGroupResponse::type:
            return pMessage_type(new DeleteGroupResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

        case ReadGroupResponse::type:
            return pMessage_type(new ReadGroupResponse(_pMessageHeader,
                                    _pSourceEndpoint, 
                                    _pDestinationEndpoint),
                                 &destroy);

   
    }

    // TODO Throw an exception?
    std::cout << "Zen::Community::Account::ProtocolMessageFactory::getMessageType(): Error, wrong message type - " <<
            getMessageType(_pMessageHeader) << std::endl;

    return pMessage_type();
}
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

boost::uint32_t
MessageFactory::getMessageType(pMessageHeader_type _pMessageHeader)
{
    // Assume this is a numeric type.
    Zen::Enterprise::AppServer::I_NumericTypeMessageRegistry::I_NumericType*
        pType = dynamic_cast<Zen::Enterprise::AppServer::I_NumericTypeMessageRegistry::I_NumericType*>
            (_pMessageHeader->getMessageType().get());

    if (pType != NULL)
    {
        return pType->getType();
    }
    else
    {        
        throw Zen::Utility::runtime_exception("MessageFactory::getMessageType(): Error, invalid message type.");
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Account
}   // namespace Protocol
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
