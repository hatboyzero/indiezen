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
#ifndef ZEN_STUDIO_WORKBENCH_I_SPREADSHEETDOCUMENT_DATA_MAP_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_I_SPREADSHEETDOCUMENT_DATA_MAP_HPP_INCLUDED

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

class I_SpreadSheetDocumentDomainObject;
class I_SpreadSheetDocumentDataCollection;

class WORKBENCHMODEL_DLL_LINK I_SpreadSheetDocumentDataMap
:	public boost::noncopyable
{

    /// @name Types
    /// @{
public:
//    typedef Zen::Memory::managed_ptr<I_SpreadSheetDocumentDomainObject>   pSpreadSheetDocumentDomainObject_type;
//    typedef Zen::Memory::managed_ptr<I_SpreadSheetDocumentDataCollection>     pSpreadSheetDocumentDataCollection_type;
    typedef Zen::Memory::managed_ptr<I_SpreadSheetDocumentDataMap>        pSpreadSheetDocumentDataMap_type;

    typedef Zen::Database::I_DatabaseService::pDatabaseConnection_type      pDatabaseConnection_type;

    typedef Zen::Memory::managed_ptr<I_SpreadSheetDocumentDataCollection>  pSpreadSheetDocumentDataCollection_type;
    typedef Zen::Event::future_return_value<pSpreadSheetDocumentDataCollection_type>  FutureSpreadSheetDocumentDataCollection_type;
	typedef Zen::Memory::managed_ptr<FutureSpreadSheetDocumentDataCollection_type>    pFutureSpreadSheetDocumentDataCollection_type;
    
    typedef Zen::Memory::managed_ptr<I_SpreadSheetDocumentDomainObject>  pSpreadSheetDocumentDomainObject_type;
    typedef Zen::Event::future_return_value<pSpreadSheetDocumentDomainObject_type>  FutureSpreadSheetDocumentDomainObject_type;
	typedef Zen::Memory::managed_ptr<FutureSpreadSheetDocumentDomainObject_type>    pFutureSpreadSheetDocumentDomainObject_type;
    /// @}

    /// @name I_SpreadSheetDocumentDataMap interface
    /// @{
public:
    /// Create a new SpreadSheetDocumentDomainObject.
    virtual pSpreadSheetDocumentDomainObject_type createNew() = 0;
    
    /// Get an object by primary key.
    virtual pFutureSpreadSheetDocumentDomainObject_type getByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Delete an object by primary key.
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue) = 0;

    /// Get a SpreadSheet document by explorerNodeId.    
    virtual pFutureSpreadSheetDocumentDataCollection_type getByExplorerNodeId(const boost::uint64_t _nodeId) = 0;

    /// Get all of the records.
    virtual pFutureSpreadSheetDocumentDataCollection_type getAll() = 0;

    /// Update a SpreadSheetDocumentDomainObject.
    /// If the SpreadSheetDocumentDomainObject hasn't been inserted yet, it will be inserted.
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pSpreadSheetDocumentDomainObject_type _pSpreadSheetDocumentDomainObject) = 0;
    /// @}

    /// @name Static class factory
    /// @{
public:
    static pSpreadSheetDocumentDataMap_type create(pDatabaseConnection_type _pDatabaseConnection);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             I_SpreadSheetDocumentDataMap();
    virtual ~I_SpreadSheetDocumentDataMap();
    /// @}

};  // interface I_SpreadSheetDocumentDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

namespace Zen {
namespace Memory {
    /// I_SpreadSheetDocumentDataMap is a managed by factory
    template<>
    struct is_managed_by_factory<Zen::Studio::Workbench::I_SpreadSheetDocumentDataMap> : public boost::true_type{};
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Memory
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_STUDIO_WORKBENCH_I_SPREADSHEETDOCUMENT_DATA_MAP_HPP_INCLUDED