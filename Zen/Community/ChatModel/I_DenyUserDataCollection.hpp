//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Spaces
//
// Copyright (C) 2001 - 2009 Tony Richards
//
// Licensed under the Games by Sarge Publishing License - See your licensing
// agreement for terms and conditions.
//
// Do not redistribute this source code.
//
// Tony Richards trichards@gamesbysarge.com
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// This is generated by the Zen Spaces Code Generator.  Do not modify!
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_COMMUNITY_CHAT_I_DENYUSER_DATA_COLLECTION_HPP_INCLUDED
#define ZEN_COMMUNITY_CHAT_I_DENYUSER_DATA_COLLECTION_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>


#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Chat {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_DenyUserDomainObject;

class CHATMODEL_DLL_LINK I_DenyUserDataCollection
:	public boost::noncopyable
{
    /// @name Types
    /// @{
public:
    typedef Zen::Memory::managed_ptr<I_DenyUserDomainObject>  pDenyUserDomainObject_type;

    /// Declared below
    struct I_CollectionVisitor;
    /// @}

    /// @name I_DenyUserDataCollection interface.
    /// @{
public:
    /// Push a domain object onto the end of the collection.
    /// This is normally only used by the DomainMap implementation.
    virtual void push_back(pDenyUserDomainObject_type _pDomainObject) = 0;
    
    /// Get all of the docmain objects in this collection using a visitor.
    virtual void getAll(I_CollectionVisitor& _visitor) = 0;
    
    /// @return true if this collection is empty.
    virtual bool isEmpty() const = 0;
    /// @}

    /// @name Inner Classes
    /// @{
public:
    struct I_CollectionVisitor
    {
        virtual void begin() = 0;
        virtual void visit(pDenyUserDomainObject_type _pDomainObject) = 0;
        virtual void end() = 0;
    };  // interface I_CollectionVisitor

    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_DenyUserDataCollection();
    virtual ~I_DenyUserDataCollection();
    /// @}

};  // interface I_DenyUserDataCollection

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Chat
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_DenyUserDataCollection is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Community::Chat::I_DenyUserDataCollection> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_CHAT_I_DENYUSER_DATA_COLLECTION_HPP_INCLUDED
