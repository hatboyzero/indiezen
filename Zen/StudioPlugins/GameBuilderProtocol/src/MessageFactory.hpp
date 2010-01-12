//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Protocol
//
// Copyright (C) 2001 - 2009 Tony Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//
// Licensed under the Games by Sarge Publishing License - See your licensing
// agreement for terms and conditions.
//
// Do not redistribute this source code.
//
// Tony Richards trichards@gamesbysarge.com
// Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// This is generated by the Zen Protocol Code Generator.  Do not modify!
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef GAMEBUILDER_MESSAGE_FACTORY_HPP_INCLUDED
#define GAMEBUILDER_MESSAGE_FACTORY_HPP_INCLUDED

#include <Zen/Enterprise/AppServer/I_MessageFactory.hpp>

#include <boost/cstdint.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace GameBuilder {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class MessageFactory
:   public Zen::Enterprise::AppServer::I_MessageFactory
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<Zen::Enterprise::AppServer::I_MessageFactory>  pMessageFactory_type;
    /// @}

    /// @name I_MessageFactory implementation
    /// @{
public:
    virtual pMessage_type create(pMessageHeader_type _pMessageHeader, pEndpoint_type _pSourceEndpoint, pEndpoint_type _pDestinationEndpoint);
    /// @}

    /// @name MessageFactory implementation
    /// @{
public:
    static void destroy(wpMessage_type _pMessage);
    static boost::uint32_t getMessageType(pMessageHeader_type _pMessageHeader);
    /// @}

    /// @name Static instance
    /// @{
public:
    static pMessageFactory_type instance();
    /// @}

    /// @name 'Structors
    /// @{
public:
             MessageFactory();
    virtual ~MessageFactory();
    /// @}

    /// @name Member Variables
    /// @{
private:
    /// @}

};  // class MessageFactory

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace GameBuilder
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // GAMEBUILDER_MESSAGE_FACTORY_HPP_INCLUDED