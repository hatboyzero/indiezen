//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Community Framework
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
#ifndef ZEN_COMMUNITY_CHAT_PROTOCOL_I_CHANNEL_LIST_REQUEST_HPP_INCLUDED
#define ZEN_COMMUNITY_CHAT_PROTOCOL_I_CHANNEL_LIST_REQUEST_HPP_INCLUDED

#include <Zen/Community/ChatProtocol/I_ChatRequest.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
    namespace Networking {
        class I_Endpoint;
    }   // namespace Networking
namespace Community {
namespace Chat {
    namespace Common {
        class I_ChatSession;
    }   // namespace Common
namespace Protocol {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ChannelListRequest
:   public I_ChatRequest
{
    /// @name Types
    /// @{
public:
    typedef Memory::managed_ptr<Enterprise::AppServer::I_Request>   pRequest_type;

    typedef Memory::managed_ptr<Networking::I_Endpoint>             pEndpoint_type;
    
    typedef Memory::managed_ptr<Common::I_ChatSession>              pChatSession_type;
    /// @}

    /// @name I_ChannelListRequest interface
    /// @{
public:
    virtual const pChatSession_type getChatSession() const = 0;
    /// @}

    /// @name Static methods
    /// @{
public:
    static pRequest_type create(pEndpoint_type _pSourceEndpoint,
                                pEndpoint_type _pDestinationEndpoint,
                                pChatSession_type _pChatSession);
    /// @}

    /// @name 'Structors
    /// @{
             I_ChannelListRequest();
    virtual ~I_ChannelListRequest();
    /// @}

};  // interface I_ChannelListRequest

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Protocol
}   // namespace Chat
}   // namespace Community
namespace Memory {
    // I_ChannelListRequest is managed by factory
    template<>
    struct is_managed_by_factory<Community::Chat::Protocol::I_ChannelListRequest> : public boost::true_type{};
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_CHAT_PROTOCOL_I_CHANNEL_LIST_REQUEST_HPP_INCLUDED
