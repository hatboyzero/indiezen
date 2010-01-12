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
#ifndef ZEN_STUDIO_WORKBENCH_I_PROJECT_DATA_MAP_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_I_PROJECT_DATA_MAP_HPP_INCLUDED

#include "Configuration.hpp"

#include <Zen/Core/Memory/managed_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseConnection.hpp>
#include <Zen/Enterprise/Database/I_DatabaseService.hpp>
#include <Zen/Enterprise/Database/I_DatabaseTransaction.hpp>

#include <boost/cstdint.hpp>

#include <boost/noncopyable.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class I_ProjectDomainObject;
class I_ProjectDataCollection;

class WORKBENCHMODEL_DLL_LINK I_ProjectDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_ProjectDomainObject>   pProjectDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_ProjectDataCollection>     pProjectDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_ProjectDataMap>        pProjectDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_ProjectDataCollection>  pProjectDataCollection_type;
    typedef Zen::Event::future_return_value<pProjectDataCollection_type>  FutureProjectDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureProjectDataCollection_type>    pFutureProjectDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_ProjectDomainObject>  pProjectDomainObject_type;
    typedef Zen::Event::future_return_value<pProjectDomainObject_type>  FutureProjectDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureProjectDomainObject_type>    pFutureProjectDomainObject_type;
    /// @}

    /// @name I_ProjectDataMap interface
    /// @{
public:
    /// Create a new ProjectDomainObject.
    virtual pProjectDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureProjectDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get a collection of Projects by name.    
    virtual pFutureProjectDataCollection_type getByProjectName(const std::string& _projectName) = 0;

    /// Get a collection of Projects by type.    
    virtual pFutureProjectDataCollection_type getByProjectType(const std::string& _projectType) = 0;

    /// Get all of the records.
    virtual pFutureProjectDataCollection_type getAll() = 0;

    /// Update a ProjectDomainObject.
    /// If the ProjectDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pProjectDomainObject_type _pProjectDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pProjectDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_ProjectDataMap();
    virtual ~I_ProjectDataMap();
    /// @}

};  // interface I_ProjectDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_ProjectDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Studio::Workbench::I_ProjectDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_STUDIO_WORKBENCH_I_PROJECT_DATA_MAP_HPP_INCLUDED