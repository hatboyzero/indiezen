//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Art Library
//
// Copyright (C) 2001 - 2009 Tony Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//
// Licensed under the Games by Sarge Publishing License - See your licensing
// agreement for terms and conditions.
//
// Do not redistribute this source code.
//
// Tony Richards trichards@gamesbysarge.com
// Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#include "../I_Folder.hpp"

#include <Zen/Core/Memory/managed_weak_ptr.hpp>

#include <Zen/Core/Utility/runtime_exception.hpp>

#include <Zen/Studio/WorkbenchCommon/I_ExplorerNodeType.hpp>
#include <Zen/Studio/WorkbenchCommon/I_ExplorerNode.hpp>

#include <Zen/Studio/WorkbenchCommon/generic_explorer_node_type.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace ArtLibrary {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
I_Folder::I_Folder(const std::string& _name)
:   Zen::Studio::Workbench::I_ExplorerNode::UserData(_name)
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
I_Folder::~I_Folder()
{
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class FolderType
:   public Zen::Studio::Workbench::generic_explorer_node_type<FolderType>
{
    /// @name I_ExplorerNodeType implemenetation
    /// @{
public:
    virtual bool getNameMutability(Zen::Studio::Workbench::I_ExplorerNode& _explorerNode) const
    {
        // Return true if this is not the main folder.  This is the main folder
        // if the parent's user data is a project (or not another art folder).

        // Get the parent.
        Zen::Studio::Workbench::I_ExplorerNode* pParent = _explorerNode.getParent();

        // Make sure there is a parent.
        if (pParent)
        {
            // If the parent is a I_ArtFolder then this isn't the main folder, 
            // so return true.
            I_Folder* pParentFolder = dynamic_cast<I_Folder*>(pParent->getUserData().get());

            if (pParentFolder != NULL)
            {
                return true;
            }
        }

        return false;
    }

    virtual bool isDraggable(Zen::Studio::Workbench::I_ExplorerNode& _explorerNode) const
    {
        return false;
    }

    virtual bool canDrop(Zen::Studio::Workbench::I_ExplorerNode& _sourceNode, Zen::Studio::Workbench::I_ExplorerNode& _destNode) const
    {
        return false;
    }
    /// @}

    /// @name 'Structors
    /// @{
public:
    FolderType()
    :   Zen::Studio::Workbench::generic_explorer_node_type<FolderType>::generic_explorer_node_type("ArtLibrary::Folder", "./icons/folder.png")
    {
    }

    virtual ~FolderType()
    {
    }
    /// @}

};  // class FolderType

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
static FolderType sm_type;
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
Zen::Studio::Workbench::I_ExplorerNodeType&
I_Folder::getNodeType()
{
    return sm_type;
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace ArtLibrary
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
