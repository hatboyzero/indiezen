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
#include "SpreadSheetDocumentDomainObject.hpp"

#include <Zen/Core/Utility/runtime_exception.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Studio {
namespace Workbench {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

SpreadSheetDocumentDomainObject::SpreadSheetDocumentDomainObject()
{
    m_elements["spreadSheetDocumentId"] = m_pSpreadSheetDocumentId = Zen::Enterprise::DataModel::I_DataElement::create();
    m_elements["explorerNodeId"] = m_pExplorerNodeId = Zen::Enterprise::DataModel::I_DataElement::create();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetDocumentDomainObject::~SpreadSheetDocumentDomainObject()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetDocumentDomainObject::ElementReference_type
SpreadSheetDocumentDomainObject::getSpreadSheetDocumentId() const
{
    return *m_pSpreadSheetDocumentId.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
SpreadSheetDocumentDomainObject::setSpreadSheetDocumentId(const boost::any& _value)
{
    m_pSpreadSheetDocumentId->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpreadSheetDocumentDomainObject::ElementReference_type
SpreadSheetDocumentDomainObject::getExplorerNodeId() const
{
    return *m_pExplorerNodeId.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
SpreadSheetDocumentDomainObject::setExplorerNodeId(const boost::any& _value)
{
    m_pExplorerNodeId->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Enterprise::DataModel::I_DataElement&
SpreadSheetDocumentDomainObject::getElement(const std::string& _fieldName)
{
    // TODO Guard?

    FieldElementMap_type::iterator iter = m_elements.find(_fieldName);
    if (iter != m_elements.end())
    {
        return *iter->second;
    }
    else
    {
        pElement_type pElement = Zen::Enterprise::DataModel::I_DataElement::create();
        m_elements[_fieldName] = pElement;

        return *pElement;
    }
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen
}   // namespace Studio
}   // namespace Workbench
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
