//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Enterprise Framework
//
// Copyright (C) 2001 - 2011 Tony Richards
// Copyright (C) 2008 - 2011 Matthew Alan Gray
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
#ifndef ZEN_ZPOSTGRES_DATABASE_CONNECTION_HPP_INCLUDED
#define ZEN_ZPOSTGRES_DATABASE_CONNECTION_HPP_INCLUDED

#include <Zen/Enterprise/Database/I_DatabaseConnection.hpp>
#include <Zen/Enterprise/Database/I_DatabaseService.hpp>

#include <Zen/Core/Memory/managed_ptr.hpp>
#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <libpq-fe.h>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace ZPostgres {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class DatabaseService;
class DatabaseTransaction;

class DatabaseConnection
: public Database::I_DatabaseConnection
{
    /// @name Types
    /// @{
public:
    typedef Database::I_DatabaseService::config_type                 config_type;
    /// @}

    /// @name I_DatabaseService implementation
    /// @{
public:
    virtual const std::string& getName() const;
    virtual pDatabaseTransaction_type beginTransaction();
    virtual void commitTransaction(pDatabaseTransaction_type _pDatabaseTransaction);
    virtual void rollbackTransaction(pDatabaseTransaction_type _pDatabaseTransaction);
    virtual std::string escapeString(const std::string& _string);
    virtual pDatabaseService_type getDatabaseService() const;
    /// @}

    /// @name DatabaseConnection implementation
    /// @{
public:
    /// Give the connection an opportunity to keep a weak self-reference
    //void setSelfReference(self_reference_type _pReference);

    /// @name Event Handlers
    /// @{
    typedef Zen::Memory::managed_weak_ptr<DatabaseTransaction>  wpConcreteDatabaseTransaction_type;
    static void onDestroyTransaction(wpConcreteDatabaseTransaction_type _pDatabaseTransaction);
    /// @}

    /// @name 'Structors
    /// @{
public:
             DatabaseConnection(pDatabaseService_type _pDatabase, const std::string& _name, PGconn* _pConnection);
    virtual ~DatabaseConnection();
    /// @}

    /// @name Member Variables
    /// @{
private:
    /// Reference to the database for this connection.  This reference
    /// prevents the database object from being deleted while it has
    /// open connections.
    pDatabaseService_type       m_pDatabase;

    std::string                 m_name;

    PGconn*                     m_pConnection;

    /// Keep a weak pointer so the client application can let it
    /// be destroyed when it goes out of scope.
    /// mgray@one.ducommun.com -- 2011/04/14
    /// Changed this to a strong concrete reference and set up to 
    /// reuse the reference on reset.
    typedef Zen::Memory::managed_ptr<DatabaseTransaction>   pConcreteDatabaseTransaction_type;
    pConcreteDatabaseTransaction_type   m_pTransaction;
    //pDatabaseTransaction_type   m_pTransaction;
    /// @}

};  // class DatabaseConnection

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace ZPostgres
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_ZPOSTGRES_DATABASE_CONNECTION_HPP_INCLUDED
