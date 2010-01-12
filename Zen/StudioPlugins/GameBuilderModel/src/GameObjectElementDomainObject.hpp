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
#ifndef GAMEBUILDER_GAMEOBJECTELEMENT_DOMAIN_OBJECT_HPP_INCLUDED
#define GAMEBUILDER_GAMEOBJECTELEMENT_DOMAIN_OBJECT_HPP_INCLUDED

#include "../I_GameObjectElementDomainObject.hpp"

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace GameBuilder {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class GameObjectElementDomainObject
:	public I_GameObjectElementDomainObject
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, pElement_type>    FieldElementMap_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the GameObjectElementId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setGameObjectElementId().
    virtual ElementReference_type getGameObjectElementId() const;
    
    /// Set the GameObjectElementId element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setGameObjectElementId(const boost::any& _value);

    /// Get the GameObjectTypeId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setGameObjectTypeId().
    virtual ElementReference_type getGameObjectTypeId() const;
    
    /// Set the GameObjectTypeId element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setGameObjectTypeId(const boost::any& _value);

    /// Get the OverrideParent element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setOverrideParent().
    virtual ElementReference_type getOverrideParent() const;
    
    /// Set the OverrideParent element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setOverrideParent(const boost::any& _value);

    /// Get the SequenceNumber element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setSequenceNumber().
    virtual ElementReference_type getSequenceNumber() const;
    
    /// Set the SequenceNumber element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setSequenceNumber(const boost::any& _value);

    /// Get the Name element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setName().
    virtual ElementReference_type getName() const;
    
    /// Set the Name element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setName(const boost::any& _value);

    /// Get the DataType element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setDataType().
    virtual ElementReference_type getDataType() const;
    
    /// Set the DataType element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setDataType(const boost::any& _value);

    /// Get the DefaultValue element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setDefaultValue().
    virtual ElementReference_type getDefaultValue() const;
    
    /// Set the DefaultValue element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setDefaultValue(const boost::any& _value);

    /// Get the PropertiesId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setPropertiesId().
    virtual ElementReference_type getPropertiesId() const;
    
    /// Set the PropertiesId element value.
    /// This method does not directly update the database.  
    /// You must use the I_GameObjectElementDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setPropertiesId(const boost::any& _value);
    
    virtual Zen::Enterprise::DataModel::I_DataElement& getElement(const std::string& _fieldName);
    /// @}

    /// @name Member Variables
    /// @{
private:
    pElement_type               m_pGameObjectElementId;
    pElement_type               m_pGameObjectTypeId;
    pElement_type               m_pOverrideParent;
    pElement_type               m_pSequenceNumber;
    pElement_type               m_pName;
    pElement_type               m_pDataType;
    pElement_type               m_pDefaultValue;
    pElement_type               m_pPropertiesId;

    FieldElementMap_type            m_elements;
    /// @}

    /// @name 'Structors
    /// @{
public:
             GameObjectElementDomainObject();
    virtual ~GameObjectElementDomainObject();
    /// @}

};  // class GameObjectElementDomainObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace GameBuilder
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // GAMEBUILDER_GAMEOBJECTELEMENT_DOMAIN_OBJECT_HPP_INCLUDED