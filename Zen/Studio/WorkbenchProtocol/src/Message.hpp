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
#ifndef ZEN_STUDIO_WORKBENCHPROTOCOL_MESSAGE_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCHPROTOCOL_MESSAGE_HPP_INCLUDED

#include "../I_Message.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <boost/cstdint.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
    namespace Enterprise {
        namespace AppServer {
            class I_MessageFactory;
        }   // namespace AppServer
    }   // namespace Enterprise
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class Message
:   public virtual I_Message
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<Zen::Enterprise::AppServer::I_MessageFactory>      pMessageFactory_type;
    typedef Zen::Memory::managed_weak_ptr<Zen::Enterprise::AppServer::I_MessageFactory> wpMessageFactory_type;
    /// @}

    /// @name Zen::Enterprise::AppServer::I_Message implementation
    /// @{
public:
    virtual pEndpoint_type getSourceEndpoint();
    virtual pEndpoint_type getDestinationEndpoint();
    virtual pMessageHeader_type getMessageHeader() const;
    /// @}

    /// @name I_Message implementation
    /// @{
public:
    virtual unsigned int getMessageId() const;
    /// @}

    /// @name Message implementation
    /// @{
public:
    /// @}

    /// @name Static methods
    /// @{
public:
    static void destroyMessageFactory(wpMessageFactory_type _wpMessageFactory);
    /// @}

    /// @name 'Structors
    /// @{
protected:
    friend class MessageFactory;
             Message(pMessageHeader_type _pMessageHeader,
                     pEndpoint_type _pSourceEndpoint,
                     pEndpoint_type _pDestinationEndpoint);
    virtual ~Message();
    /// @}

    /// @name Member Variables
    /// @{
protected:
    static pMessageFactory_type sm_pMessageFactory;
private:
    pEndpoint_type          m_pSourceEndpoint;
    pEndpoint_type          m_pDestinationEndpoint;
    pMessageHeader_type     m_pMessageHeader;
    /// @}

};  // class Message

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Workbench
}   // namespace Studio
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_STUDIO_WORKBENCHPROTOCOL_MESSAGE_HPP_INCLUDED