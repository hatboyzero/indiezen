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
#ifndef ZEN_COMMUNITY_ACCOUNT_I_GROUP_DATA_MAP_HPP_INCLUDED
#define ZEN_COMMUNITY_ACCOUNT_I_GROUP_DATA_MAP_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseConnection.hpp>
#include <Zen/Enterprise/Database/I_DatabaseService.hpp>
#include <Zen/Enterprise/Database/I_DatabaseTransaction.hpp>

#include <boost/cstdint.hpp>

#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Account {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_GroupDomainObject;
class I_GroupDataCollection;

class ACCOUNTMODEL_DLL_LINK I_GroupDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_GroupDomainObject>   pGroupDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_GroupDataCollection>     pGroupDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_GroupDataMap>        pGroupDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_GroupDataCollection>  pGroupDataCollection_type;
    typedef Zen::Event::future_return_value<pGroupDataCollection_type>  FutureGroupDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureGroupDataCollection_type>    pFutureGroupDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_GroupDomainObject>  pGroupDomainObject_type;
    typedef Zen::Event::future_return_value<pGroupDomainObject_type>  FutureGroupDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureGroupDomainObject_type>    pFutureGroupDomainObject_type;
    /// @}

    /// @name I_GroupDataMap interface
    /// @{
public:
    /// Create a new GroupDomainObject.
    virtual pGroupDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureGroupDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get a collection of groups by name.    
    virtual pFutureGroupDataCollection_type getByGroupName(const std::string& _groupName) = 0;

    /// Get all of the records.
    virtual pFutureGroupDataCollection_type getAll() = 0;

    /// Update a GroupDomainObject.
    /// If the GroupDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pGroupDomainObject_type _pGroupDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pGroupDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_GroupDataMap();
    virtual ~I_GroupDataMap();
    /// @}

};  // interface I_GroupDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Account
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_GroupDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Community::Account::I_GroupDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_COMMUNITY_ACCOUNT_I_GROUP_DATA_MAP_HPP_INCLUDED