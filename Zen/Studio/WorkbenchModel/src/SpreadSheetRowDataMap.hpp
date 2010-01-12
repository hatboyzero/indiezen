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
#ifndef ZEN_STUDIO_WORKBENCH_SPREADSHEETROW_DATA_MAP_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_SPREADSHEETROW_DATA_MAP_HPP_INCLUDED

#include "../I_SpreadSheetRowDataMap.hpp"

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class SpreadSheetRowDataMap
:	public I_SpreadSheetRowDataMap
{
    /// @name I_SpreadSheetRowDataMap implementation
    /// @{
public:
    virtual pSpreadSheetRowDomainObject_type createNew();
    virtual pFutureSpreadSheetRowDomainObject_type getByKey(boost::uint64_t _primaryKeyValue);
    virtual void deleteByKey(boost::uint64_t _primaryKeyValue);
    virtual pFutureSpreadSheetRowDataCollection_type getByDocumentId(const boost::uint64_t _spreadSheetDocumentId);
    virtual pFutureSpreadSheetRowDataCollection_type getAll();
    virtual Zen::Database::I_DatabaseTransaction::pFutureKey_type update(pSpreadSheetRowDomainObject_type _pSpreadSheetRowDomainObject);
    /// @}

    /// @name SpreadSheetRowDataMap implementation
    /// @{
public:
    /// Escape the string to prevent SQL injection
    std::string escapeString(const std::string& _value) const;

    /// Get a comma separated list of the fields in this table.
    static const std::string& getFieldNames();

    /// Get a comma separated list of the fields in this table
    /// sans the primary key (spreadSheetRowId).
    static const std::string& getNonPKFieldNames();
    
    /// Get the name of the table this class maps.
    static const std::string& getTableName();

	pDatabaseConnection_type getDatabaseConnection() const;
    /// @}

	/// @name Member Variables
	/// @{
public:
	pDatabaseConnection_type			m_pDatabaseConnection;
	/// @}

    /// @name 'Structors
    /// @{
public:
             SpreadSheetRowDataMap(pDatabaseConnection_type _pDatabaseConnection);
    virtual ~SpreadSheetRowDataMap();
    /// @}

};  // class SpreadSheetRowDataMap

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // ZEN_STUDIO_WORKBENCH_SPREADSHEETROW_DATA_MAP_HPP_INCLUDED