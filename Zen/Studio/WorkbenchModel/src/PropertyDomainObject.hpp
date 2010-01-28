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
#ifndef ZEN_STUDIO_WORKBENCH_PROPERTY_DOMAIN_OBJECT_HPP_INCLUDED
#define ZEN_STUDIO_WORKBENCH_PROPERTY_DOMAIN_OBJECT_HPP_INCLUDED

#include "../I_PropertyDomainObject.hpp"

#include <map>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


class PropertyDomainObject
:	public I_PropertyDomainObject
{
    /// @name Types
    /// @{
public:
    typedef std::map<std::string, pElement_type>    FieldElementMap_type;
    /// @}

    /// @name Getter / Setter methods
    /// @{
public:
    /// Get the PropertyId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setPropertyId().
    virtual ElementReference_type getPropertyId() const;
    
    /// Set the PropertyId element value.
    /// This method does not directly update the database.  
    /// You must use the I_PropertyDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setPropertyId(const boost::any& _value);

    /// Get the PropertiesId element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setPropertiesId().
    virtual ElementReference_type getPropertiesId() const;
    
    /// Set the PropertiesId element value.
    /// This method does not directly update the database.  
    /// You must use the I_PropertyDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setPropertiesId(const boost::any& _value);

    /// Get the Name element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setName().
    virtual ElementReference_type getName() const;
    
    /// Set the Name element value.
    /// This method does not directly update the database.  
    /// You must use the I_PropertyDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setName(const boost::any& _value);

    /// Get the Value element.
    /// Use this return value to check to see if the column is NULL in the database,
    /// or you can use it to modify the value instead of calling setValue().
    virtual ElementReference_type getValue() const;
    
    /// Set the Value element value.
    /// This method does not directly update the database.  
    /// You must use the I_PropertyDataMap::update() method for the modifications
    /// to be persisted.
    virtual void setValue(const boost::any& _value);
    
    virtual Zen::Enterprise::DataModel::I_DataElement& getElement(const std::string& _fieldName);
    /// @}

    /// @name Member Variables
    /// @{
private:
    pElement_type               m_pPropertyId;
    pElement_type               m_pPropertiesId;
    pElement_type               m_pName;
    pElement_type               m_pValue;

    FieldElementMap_type            m_elements;
    /// @}

    /// @name 'Structors
    /// @{
public:
             PropertyDomainObject();
    virtual ~PropertyDomainObject();
    /// @}

};  // class PropertyDomainObject

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~


#endif // ZEN_STUDIO_WORKBENCH_PROPERTY_DOMAIN_OBJECT_HPP_INCLUDED
