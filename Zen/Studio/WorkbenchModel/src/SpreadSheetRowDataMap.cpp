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
#include "SpreadSheetRowDataMap.hpp"

#include "SpreadSheetRowDomainObject.hpp"
#include "SpreadSheetRowDataCollection.hpp"

#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <Zen/Enterprise/Database/I_DatabaseStaticQuery.hpp>
#include <Zen/Enterprise/Database/I_DatabaseResult.hpp>
#include <Zen/Enterprise/Database/I_DatabaseColumn.hpp>
#include <Zen/Enterprise/Database/I_DatabaseRow.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

SpreadSheetRowDataMap::SpreadSheetRowDataMap(pDatabaseConnection_type _pDatabaseConnection)
:   m_pDatabaseConnection(_pDatabaseConnection)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetRowDataMap::~SpreadSheetRowDataMap()
{
}

static void 
destroyObject(Zen::Memory::managed_weak_ptr<I_SpreadSheetRowDomainObject> _wpObject);

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace {
struct FieldHandler
:   public Zen::Database::I_DatabaseRow::I_FieldVisitor
{
    virtual void begin()    {}

    virtual void visit(const Zen::Database::I_DatabaseColumn& _column, const boost::any& _value)
    {
        m_pValue->getElement(_column.getFieldName()).setAnyValue(_value);
    }

    virtual void end()      {}

    FieldHandler(SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type _pValue)
    : m_pValue(_pValue)
    {
    }

    virtual ~FieldHandler()
    {
    }

private:
    SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type       m_pValue;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
struct RowHandler
:   public Zen::Database::I_DatabaseResult::I_ResultVisitor
{
    virtual void begin()
    {
    }

    virtual void visit(const Zen::Database::I_DatabaseRow& _databaseRow)
    {
        FieldHandler fieldHandler(m_pValue);

        _databaseRow.getFields(fieldHandler);
    }

    virtual void end()
    {
    }

    RowHandler(SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type _pValue)
    : m_pValue(_pValue)
    {
    }

    virtual ~RowHandler()
    {
    }
    
private:
    SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type           m_pValue;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class ResultHandler
:   public Zen::Database::I_DatabaseTransaction::I_QueryResultHandler
{
public:
    virtual void handleResult(pDatabaseResult_type _pResult)
    {
        RowHandler rowHandler(m_pValue);

        _pResult->getResults(rowHandler);

        m_pFutureValue->setValue(m_pValue);

        // Done, so commit the transaction.
        m_pTransaction->commit();
    }

    /// @param _pTransaction - We want to keep a reference to the transaction so it does 
    ///         not go out of scope until the results have been fully handled.
    ResultHandler(Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type _pTransaction,
                 SpreadSheetRowDataMap::pFutureSpreadSheetRowDomainObject_type _pFutureValue,
                 SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type _pValue)
    :   m_pTransaction(_pTransaction)
    ,   m_pFutureValue(_pFutureValue)
    ,   m_pValue(_pValue)
    {
    }

    virtual ~ResultHandler()
    {
    }

private:
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type  m_pTransaction;
    SpreadSheetRowDataMap::pFutureSpreadSheetRowDomainObject_type     m_pFutureValue;
    SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type           m_pValue;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
struct CollectionRowHandler
:   public Zen::Database::I_DatabaseResult::I_ResultVisitor
{
    virtual void begin()
    {
    }

    virtual void visit(const Zen::Database::I_DatabaseRow& _databaseRow)
    {
        SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type pValue(new SpreadSheetRowDomainObject, &destroyObject);
        
        m_pCollection->push_back(pValue);

        FieldHandler fieldHandler(pValue);

        _databaseRow.getFields(fieldHandler);
    }

    virtual void end()
    {
    }

    CollectionRowHandler(SpreadSheetRowDataMap::pSpreadSheetRowDataCollection_type _pCollection)
    : m_pCollection(_pCollection)
    {
    }

    virtual ~CollectionRowHandler()
    {
    }
    
private:
    SpreadSheetRowDataMap::pSpreadSheetRowDataCollection_type     m_pCollection;
};

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class CollectionResultHandler
:   public Zen::Database::I_DatabaseTransaction::I_QueryResultHandler
{
public:
    virtual void handleResult(pDatabaseResult_type _pResult)
    {
        CollectionRowHandler rowHandler(m_pCollection);

        _pResult->getResults(rowHandler);

        m_pFutureCollection->setValue(m_pCollection);

        // Done, so commit the transaction.
        m_pTransaction->commit();
    }

    /// @param _pTransaction - We want to keep a reference to the transaction so it does 
    ///         not go out of scope until the results have been fully handled.
    CollectionResultHandler(Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type _pTransaction,
                 SpreadSheetRowDataMap::pFutureSpreadSheetRowDataCollection_type _pFutureCollection,
                 SpreadSheetRowDataMap::pSpreadSheetRowDataCollection_type _pCollection)
    :   m_pTransaction(_pTransaction)
    ,   m_pFutureCollection(_pFutureCollection)
    ,   m_pCollection(_pCollection)
    {
    }

    virtual ~CollectionResultHandler()
    {
    }

private:
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type  m_pTransaction;
    SpreadSheetRowDataMap::pFutureSpreadSheetRowDataCollection_type     m_pFutureCollection;
    SpreadSheetRowDataMap::pSpreadSheetRowDataCollection_type     m_pCollection;
};

} // namespace
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static void
destroyObject(Zen::Memory::managed_weak_ptr<I_SpreadSheetRowDomainObject> _wpObject)
{
    SpreadSheetRowDomainObject* pObject = dynamic_cast<SpreadSheetRowDomainObject*>(_wpObject.get());
    if (pObject != NULL)
    {
        delete pObject;
    }
    else
    {
        // TODO Error?
    }
}
 
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static void
destroyCollection(Zen::Memory::managed_weak_ptr<I_SpreadSheetRowDataCollection> _wpCollection)
{
    SpreadSheetRowDataCollection* pCollection = dynamic_cast<SpreadSheetRowDataCollection*>(_wpCollection.get());
    if (pCollection != NULL)
    {
        delete pCollection;
    }
    else
    {
        // TODO Error?
    }
}
 
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetRowDataMap::pSpreadSheetRowDomainObject_type 
SpreadSheetRowDataMap::createNew()
{
    return pSpreadSheetRowDomainObject_type(new SpreadSheetRowDomainObject, &destroyObject);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetRowDataMap::pFutureSpreadSheetRowDomainObject_type
SpreadSheetRowDataMap::getByKey(boost::uint64_t _primaryKeyValue)
{
    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

	const boost::uint64_t primaryKeyValue(_primaryKeyValue);

    // Get a record from the SpreadSheetRow.
    std::stringstream query;
    query << "SELECT * FROM SpreadSheetRow WHERE spreadSheetRowId = " << primaryKeyValue;

    pQuery->setQuery(query.str());
    
	pFutureSpreadSheetRowDomainObject_type pReturnValue(new FutureSpreadSheetRowDomainObject_type);
    pSpreadSheetRowDomainObject_type pValue(new SpreadSheetRowDomainObject, &destroyObject);

    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new ResultHandler(pTransaction, pReturnValue, pValue));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);
    
    return pReturnValue;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
SpreadSheetRowDataMap::deleteByKey(boost::uint64_t _primaryKeyValue)
{
    // Don't do anything if the key value is 0.  But should this be an error?
    if (_primaryKeyValue == 0)
    {
        // TODO Throw an exception or return an error?
        return;
    }

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

	const boost::uint64_t primaryKeyValue(_primaryKeyValue);

    // Delete a record in the SpreadSheetRow.
    std::stringstream query;
    query << "DELETE FROM SpreadSheetRow WHERE spreadSheetRowId = " << primaryKeyValue;

    pQuery->setQuery(query.str());

    // Execute the query.  
    pTransaction->executeQuery(pQuery);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Database::I_DatabaseTransaction::pFutureKey_type
SpreadSheetRowDataMap::update(pSpreadSheetRowDomainObject_type _pSpreadSheetRowDomainObject)
{
    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    std::stringstream query;

    if (_pSpreadSheetRowDomainObject->getSpreadSheetRowId().isNull())
    {
        // Construct the query to insert a record into the SpreadSheetRow table.

        query << "INSERT into SpreadSheetRow ( "
            << getNonPKFieldNames() << " ) VALUES ( ";

        // Append all of the values
        std::string escapedStringValue;
        
        escapedStringValue = escapeString(_pSpreadSheetRowDomainObject->getSpreadSheetDocumentId().getStringValue());
        query << "\'" << escapedStringValue << "\'";
        escapedStringValue = escapeString(_pSpreadSheetRowDomainObject->getRowNumber().getStringValue());
        query << ", \'" << escapedStringValue << "\'";
        escapedStringValue = escapeString(_pSpreadSheetRowDomainObject->getRowText().getStringValue());
        query << ", \'" << escapedStringValue << "\'";

        // Final closing parenthesis
        query << ")";

        pQuery->setQuery(query.str());

        // Execute the query.
        Zen::Database::I_DatabaseTransaction::pFutureKey_type 
            pKey(pTransaction->executeInsert(pQuery));

        _pSpreadSheetRowDomainObject->getSpreadSheetRowId() = pKey->getValue();
        
        // Done, so commit the transaction.
        pTransaction->commit();

        return pKey;
    }
    else
    {
        // Construct the query to update a record into the SpreadSheetRow table.

        // Count the number of dirty fields.
        int dirtyFields = 0;

        query << "UPDATE SpreadSheetRow SET ";

        std::string separator("");

        // Append all of the field names and values
        std::string escapedStringValue;

        if (_pSpreadSheetRowDomainObject->getSpreadSheetDocumentId().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetRowDomainObject->getSpreadSheetDocumentId().getStringValue());
            query << separator << "spreadSheetDocumentId = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }
        if (_pSpreadSheetRowDomainObject->getRowNumber().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetRowDomainObject->getRowNumber().getStringValue());
            query << separator << "rowNumber = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }
        if (_pSpreadSheetRowDomainObject->getRowText().isDirty())
        {
            escapedStringValue = escapeString(_pSpreadSheetRowDomainObject->getRowText().getStringValue());
            query << separator << "rowText = \'" 
                << escapedStringValue << "\'";
            separator = ", ";
            dirtyFields++;
        }

        // No need to proceed if none of the fields were dirty.
        if (dirtyFields > 0)
        {
            // WHERE clause to update the record
            query << " WHERE spreadSheetRowId = " << 
                _pSpreadSheetRowDomainObject->getSpreadSheetRowId().getInt64Value();

            pQuery->setQuery(query.str());

            // Execute the query.  
            pTransaction->executeQuery(pQuery);

            // Done, so commit the transaction.
            pTransaction->commit();
        }
        
        Zen::Database::I_DatabaseTransaction::pFutureKey_type 
            pKey(new Zen::Database::I_DatabaseTransaction::FutureKey_type);

        pKey->setValue(_pSpreadSheetRowDomainObject->getSpreadSheetRowId().getInt64Value());

        return pKey;
    }

}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetRowDataMap::pFutureSpreadSheetRowDataCollection_type
SpreadSheetRowDataMap::getByDocumentId(const boost::uint64_t _spreadSheetDocumentId)
{
    pFutureSpreadSheetRowDataCollection_type pFutureCollection(new FutureSpreadSheetRowDataCollection_type);
    pSpreadSheetRowDataCollection_type pCollection(new SpreadSheetRowDataCollection, &destroyCollection);

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    // Get SpreadSheet rows by spreadSheetDocumentId.
    std::stringstream query;
    query << "SELECT * FROM SpreadSheetRow WHERE " << "spreadSheetDocumentId == " << _spreadSheetDocumentId << " ORDER BY rowNumber";

    pQuery->setQuery(query.str());
    
    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new CollectionResultHandler(pTransaction, pFutureCollection, pCollection));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);    
    
    return pFutureCollection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetRowDataMap::pFutureSpreadSheetRowDataCollection_type
SpreadSheetRowDataMap::getAll()
{
    pFutureSpreadSheetRowDataCollection_type pFutureCollection(new FutureSpreadSheetRowDataCollection_type);
    pSpreadSheetRowDataCollection_type pCollection(new SpreadSheetRowDataCollection, &destroyCollection);

    // Start a transaction
    Zen::Database::I_DatabaseConnection::pDatabaseTransaction_type 
        pTransaction = getDatabaseConnection()->beginTransaction();

    // Create a query
    Zen::Database::I_DatabaseTransaction::pStaticQuery_type 
        pQuery = pTransaction->createStaticQuery();

    // Get all of the records from the SpreadSheetRow.
    pQuery->setQuery("SELECT * FROM SpreadSheetRow");

    // Create a result handler to handle the execution results
    Zen::Database::I_DatabaseTransaction::pQueryResultHandler_type pResultHandler(new CollectionResultHandler(pTransaction, pFutureCollection, pCollection));

    // Execute the query.  
    pTransaction->executeQuery(pQuery, pResultHandler);    
    
    return pFutureCollection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
        
std::string
SpreadSheetRowDataMap::escapeString(const std::string& _value) const
{
	return getDatabaseConnection()->escapeString(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_fieldNames = "spreadSheetRowId, spreadSheetDocumentId, rowNumber, rowText";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_nonPKFieldNames = "spreadSheetDocumentId, rowNumber, rowText";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
SpreadSheetRowDataMap::getFieldNames()
{
    return sm_fieldNames;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
SpreadSheetRowDataMap::getNonPKFieldNames()
{
    return sm_nonPKFieldNames;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static std::string sm_tableName = "SpreadSheetRow";
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
const std::string&
SpreadSheetRowDataMap::getTableName()
{
    return sm_tableName;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetRowDataMap::pDatabaseConnection_type
SpreadSheetRowDataMap::getDatabaseConnection() const
{
	return m_pDatabaseConnection;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

