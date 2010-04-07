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
#ifndef ZEN_COMMUNITY_PROTOCOL_I_UPDATEGROUP_RESPONSE_HPP_INCLUDED
#define ZEN_COMMUNITY_PROTOCOL_I_UPDATEGROUP_RESPONSE_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <Zen/Community/AccountProtocol/I_Message.hpp>

#include <Zen/Enterprise/AppServer/I_Response.hpp>

#include <boost/cstdint.hpp>
#include <boost/serialization/string.hpp>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Protocol {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class ACCOUNTPROTOCOL_DLL_LINK I_UpdateGroupResponse
:   public virtual Zen::Enterprise::AppServer::I_Response
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<Zen::Enterprise::AppServer::I_Response>   pResponse_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the groupDescription element.
    virtual const std::string& getGroupDescription() const = 0;
    
    /// Set the groupDescription element value.
    virtual void setGroupDescription(const std::string& _groupDescription) = 0;

    /// Get the groupName element.
    virtual const std::string& getGroupName() const = 0;
    
    /// Set the groupName element value.
    virtual void setGroupName(const std::string& _groupName) = 0;

    /// Get the groupId element.
    virtual const boost::uint64_t& getGroupId() const = 0;
    
    /// Set the groupId element value.
    virtual void setGroupId(const boost::uint64_t& _groupId) = 0;
    /// @}

    /// @name Static methods
    /// @{
public:
    static pResponse_type create(pEndpoint_type _pSourceEndpoint,
                                pEndpoint_type _pDestinationEndpoint, boost::uint32_t _requestMessageId);

    static pMessageType_type getStaticMessageType();
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_UpdateGroupResponse();
    virtual ~I_UpdateGroupResponse();
    /// @}

};  // interface I_UpdateGroupResponse

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Protocol
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Memory {
    // I_UpdateGroupResponse is managed by factory
    template<>
    struct is_managed_by_factory<Zen::Community::Protocol::I_UpdateGroupResponse> : public boost::true_type{};
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_PROTOCOL_I_UPDATEGROUP_RESPONSE_HPP_INCLUDED
