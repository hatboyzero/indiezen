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
#ifndef ZEN_COMMUNITY_CHAT_ALLOWUSER_DOMAIN_OBJECT_HPP_INCLUDED
#define ZEN_COMMUNITY_CHAT_ALLOWUSER_DOMAIN_OBJECT_HPP_INCLUDED

#include "../I_AllowUserDomainObject.hpp"

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Chat {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class AllowUserDomainObject
:	public I_AllowUserDomainObject
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, pElement_type>    FieldElementMap_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the AllowUserId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setAllowUserId().
    virtual ElementReference_type getAllowUserId() const;
    
    /// Set the AllowUserId element value.
    /// This method does not directly update the database.  
    /// You must use the I_AllowUserDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setAllowUserId(const boost::any& _value);

    /// Get the ChatChannelId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setChatChannelId().
    virtual ElementReference_type getChatChannelId() const;
    
    /// Set the ChatChannelId element value.
    /// This method does not directly update the database.  
    /// You must use the I_AllowUserDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setChatChannelId(const boost::any& _value);

    /// Get the AccountId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setAccountId().
    virtual ElementReference_type getAccountId() const;
    
    /// Set the AccountId element value.
    /// This method does not directly update the database.  
    /// You must use the I_AllowUserDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setAccountId(const boost::any& _value);
    
    virtual Zen::Enterprise::DataModel::I_DataElement& getElement(const std::string& _fieldName);
    /// @}

    /// @name Member Variables
    /// @{
private:
    pElement_type               m_pAllowUserId;
    pElement_type               m_pChatChannelId;
    pElement_type               m_pAccountId;

    FieldElementMap_type            m_elements;
    /// @}

    /// @name 'Structors
    /// @{
public:
             AllowUserDomainObject();
    virtual ~AllowUserDomainObject();
    /// @}

};  // class AllowUserDomainObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Community
}   // namespace Chat
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // ZEN_COMMUNITY_CHAT_ALLOWUSER_DOMAIN_OBJECT_HPP_INCLUDED