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
#include "ChatCommandDomainObject.hpp"

#include <Zen/Core/Utility/runtime_exception.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Community {
namespace Chat {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

ChatCommandDomainObject::ChatCommandDomainObject()
{
    m_elements["chatCommandId"] = m_pChatCommandId = Zen::Enterprise::DataModel::I_DataElement::create();
    m_elements["token"] = m_pToken = Zen::Enterprise::DataModel::I_DataElement::create();
    m_elements["action"] = m_pAction = Zen::Enterprise::DataModel::I_DataElement::create();
    m_elements["response"] = m_pResponse = Zen::Enterprise::DataModel::I_DataElement::create();
    m_elements["flags"] = m_pFlags = Zen::Enterprise::DataModel::I_DataElement::create();
    m_elements["ownerId"] = m_pOwnerId = Zen::Enterprise::DataModel::I_DataElement::create();
    m_elements["groupId"] = m_pGroupId = Zen::Enterprise::DataModel::I_DataElement::create();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::~ChatCommandDomainObject()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::ElementReference_type
ChatCommandDomainObject::getChatCommandId() const
{
    return *m_pChatCommandId.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChatCommandDomainObject::setChatCommandId(const boost::any& _value)
{
    m_pChatCommandId->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::ElementReference_type
ChatCommandDomainObject::getToken() const
{
    return *m_pToken.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChatCommandDomainObject::setToken(const boost::any& _value)
{
    m_pToken->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::ElementReference_type
ChatCommandDomainObject::getAction() const
{
    return *m_pAction.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChatCommandDomainObject::setAction(const boost::any& _value)
{
    m_pAction->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::ElementReference_type
ChatCommandDomainObject::getResponse() const
{
    return *m_pResponse.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChatCommandDomainObject::setResponse(const boost::any& _value)
{
    m_pResponse->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::ElementReference_type
ChatCommandDomainObject::getFlags() const
{
    return *m_pFlags.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChatCommandDomainObject::setFlags(const boost::any& _value)
{
    m_pFlags->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::ElementReference_type
ChatCommandDomainObject::getOwnerId() const
{
    return *m_pOwnerId.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChatCommandDomainObject::setOwnerId(const boost::any& _value)
{
    m_pOwnerId->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
ChatCommandDomainObject::ElementReference_type
ChatCommandDomainObject::getGroupId() const
{
    return *m_pGroupId.get();
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
ChatCommandDomainObject::setGroupId(const boost::any& _value)
{
    m_pGroupId->setAnyValue(_value);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Enterprise::DataModel::I_DataElement&
ChatCommandDomainObject::getElement(const std::string& _fieldName)
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
}   // namespace Community
}   // namespace Chat
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

