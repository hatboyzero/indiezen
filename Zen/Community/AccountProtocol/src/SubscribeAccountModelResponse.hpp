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
#ifndef ZEN_COMMUNITY_PROTOCOL_SUBSCRIBEACCOUNTMODEL_RESPONSE_HPP_INCLUDED
#define ZEN_COMMUNITY_PROTOCOL_SUBSCRIBEACCOUNTMODEL_RESPONSE_HPP_INCLUDED

#include "../I_SubscribeAccountModelResponse.hpp"

#include "Response.hpp"

#include <Zen/Enterprise/AppServer/I_MessageFactory.hpp>
#include <Zen/Enterprise/AppServer/I_MessageType.hpp>

#include <boost/cstdint.hpp>
#include <boost/serialization/string.hpp>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
    namespace Enterprise {
        namespace AppServer {
            class I_ApplicationServer;
            class I_MessageRegistry;
            class I_MessageType;
        }   // namespace AppServer
    }   // namespace Enterprise
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Protocol {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class SubscribeAccountModelResponse
:   public I_SubscribeAccountModelResponse
,   public Response
{
    /// @name Types
    /// @{
public:
    enum { type = 202 };  // TODO Should we be hardcoding this?
    
    typedef Zen::Memory::managed_weak_ptr<Zen::Enterprise::AppServer::I_Response>    wpResponse_type;
    /// @}

    /// @name Zen::Enterprise::AppServer::I_Message implementation
    /// @{
public:
    virtual pEndpoint_type getSourceEndpoint() { return Message::getSourceEndpoint(); }
    virtual pEndpoint_type getDestinationEndpoint() { return Message::getDestinationEndpoint(); }
    virtual pMessageHeader_type getMessageHeader() const { return Message::getMessageHeader(); }

    virtual pResourceLocation_type getDestinationLocation();
    virtual void serialize(pMessageHeader_type _pMessageHeader, boost::archive::polymorphic_iarchive& _archive, const int _version);
    virtual void serialize(boost::archive::polymorphic_oarchive& _archive, const int _version);
    /// @}

    /// @name I_Message implementation
    /// @{
public:
    virtual boost::uint32_t getMessageId() const { return Message::getMessageId(); } 
    virtual pMessageType_type getMessageType() const { return getStaticMessageType(); }
    /// @}

    /// @name Dominance for Response
    /// @{
public:
    virtual unsigned int getRequestMessageId() const { return Response::getRequestMessageId(); }
    /// @}
    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the proxyId element.
    virtual const boost::uint64_t& getProxyId() const;
    
    /// Set the proxyId element value.
    virtual void setProxyId(const boost::uint64_t& _proxyId);
    /// @}

    /// @name Static methods
    /// @{
public:
    static void registerMessage(Zen::Enterprise::AppServer::I_ApplicationServer& _appServer);

    static pMessageHeader_type createMessageHeader(boost::uint32_t _messageId, boost::uint32_t _requestId);

    static void destroy(wpResponse_type _wpResponse);
    
    static pMessageType_type getStaticMessageType();    
    /// @}
    
    /// @name 'Structors
    /// @{
protected:
    friend class I_SubscribeAccountModelResponse;
    friend class MessageFactory;
             /// This constructor is used by the static create
             /// methods for creating outbound messages.
             SubscribeAccountModelResponse(pEndpoint_type _pSourceEndpoint,
                           pEndpoint_type _pDestinationEndpoint, boost::uint32_t _requestMessageId);
             /// This constructor is used by the message factory
             /// for creating inbound messages.
             SubscribeAccountModelResponse(pMessageHeader_type _pMessageHeader,
                           pEndpoint_type _pSourceEndpoint,
                           pEndpoint_type _pDestinationEndpoint);
    virtual ~SubscribeAccountModelResponse();
    /// @}

    /// @name Member Variables
    /// @{
private:
    unsigned int                    m_id;

    static pMessageType_type                                sm_pType;
    static Zen::Enterprise::AppServer::I_MessageRegistry*   sm_pMessageRegistry;
   
    boost::uint64_t m_proxyId;
    
    /// @}

};  // class SubscribeAccountModelResponse

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Protocol
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_PROTOCOL_SUBSCRIBEACCOUNTMODEL_RESPONSE_HPP_INCLUDED
