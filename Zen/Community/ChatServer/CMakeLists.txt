cmake_minimum_required (VERSION 2.6) 

project (ChatServer)
set ( PROJECT_PREFIX "Community/ChatServer" )

if ( NOT INDIEZEN_PARENT)
	find_path ( INDIEZEN_PARENT Zen .. ../.. ../../.. ENV )
endif (NOT INDIEZEN_PARENT)

set(CMAKE_MODULE_PATH "${INDIEZEN_PARENT}/Zen/build/CMake/Modules" ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})
list (REMOVE_DUPLICATES CMAKE_MODULE_PATH)

Find_Package(IndieZen REQUIRED)
Find_Package(Boost REQUIRED )

SET (LIB_TYPE SHARED)

#-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
# Include various modules of Zen Engine

source_group(
    src\\
	REGULAR_EXPRESSION 
	src/*.*
	)


	
set ( ChatServer_SRC
    Configuration.hpp
    src/Channel.cpp
    src/Channel.hpp
    src/ChannelController.cpp
    src/ChannelController.hpp
    src/ChannelMemberController.cpp
    src/ChannelMemberController.hpp
    src/ChannelMemberModel.cpp
    src/ChannelMemberModel.hpp
    src/ChannelMemberViewProxy.cpp
    src/ChannelMemberViewProxy.hpp
    src/ChannelModel.cpp
    src/ChannelModel.hpp
    src/ChannelViewProxy.cpp
    src/ChannelViewProxy.hpp
    src/ChatServerPlugin.cpp
    src/ChatService.cpp
    src/ChatService.hpp
    src/ChatServiceFactory.cpp
    src/ChatServiceFactory.hpp

    )

add_definitions( -DCHATSERVER_EXPORTS ${Zen_DEFINITIONS} )

include_directories ( ${Boost_INCLUDE_DIR} ${INDIEZEN_PARENT} )

link_directories ( ${DEV_LIB} ${Boost_LIBRARY_DIRS} )

add_library ( ChatServer ${LIB_TYPE} ${ChatServer_SRC} )

add_dependencies(ChatServer ZenCore ZenEngine ZenEnterprise ZenObjectModel ChatCommon ChatProtocol ChatModel )

target_link_libraries(ChatServer ZenCore ZenEngine ZenEnterprise ZenObjectModel ChatCommon ChatProtocol ChatModel ${Boost_LIBRARIES} )

set_target_properties ( ChatServer
						PROPERTIES
						DEBUG_POSTFIX "_d"
					)

if (MSVC_IDE)
    # hack to get around the "Debug" and "Release" directories cmake tries to add on Windows
    set_target_properties ( ChatServer PROPERTIES PREFIX "../../bin/" )
	set_target_properties ( ChatServer PROPERTIES IMPORT_PREFIX "../../lib/" )
endif(MSVC_IDE)


install ( FILES 
    Configuration.hpp
    plugin.xml
    DESTINATION
    Zen/${PROJECT_PREFIX}/
)


install ( TARGETS
	ChatServer
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)