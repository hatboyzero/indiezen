cmake_minimum_required (VERSION 2.6) 

project (ZOpenAL)

if ( NOT INDIEZEN_PARENT)
	find_path ( INDIEZEN_PARENT Zen .. ../.. ../../.. ENV )
endif (NOT INDIEZEN_PARENT)

set(CMAKE_MODULE_PATH "${INDIEZEN_PARENT}/Zen/build/CMake/Modules" ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})
list (REMOVE_DUPLICATES CMAKE_MODULE_PATH)

Find_Package(IndieZen REQUIRED)
Find_Package(Boost REQUIRED system )
Find_Package(OpenAL REQUIRED)
Find_Package(Alut REQUIRED)
Find_Package(Ogg REQUIRED)
Find_Package(Vorbis REQUIRED)

SET (LIB_TYPE SHARED)

#-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
# Include ZOpenAL source file

source_group(
    src\\
	REGULAR_EXPRESSION 
	src/*.*
	)


	
set ( ZOpenAL_SRC
    Configuration.hpp
    src/Resource.cpp
    src/Resource.hpp
    src/ResourceService.cpp
    src/ResourceService.hpp
    src/ResourceServiceFactory.cpp
    src/ResourceServiceFactory.hpp
    src/SoundService.cpp
    src/SoundService.hpp
    src/SoundServiceFactory.cpp
    src/SoundServiceFactory.hpp
    src/Source.cpp
    src/Source.hpp
    src/ZOpenALModule.cpp
    src/ZOpenALPlugin.cpp
    src/ZOpenALPlugin.hpp

    )

add_definitions( -DZOPENAL_EXPORTS ${Zen_DEFINITIONS})

include_directories ( ${Boost_INCLUDE_DIR} ${INDIEZEN_PARENT} ${OPENAL_INCLUDE_DIR} ${OPENAL_INCLUDE_DIR}/AL ${ALUT_INCLUDE_DIR} ${OGG_INCLUDE_DIR} ${VORBIS_INCLUDE_DIR})

link_directories ( ${DEV_LIB} ${Boost_LIBRARY_DIRS} )

add_library ( ZOpenAL ${LIB_TYPE} ${ZOpenAL_SRC} )

add_dependencies( ZOpenAL ZenCore ZenEngine )

target_link_libraries( ZOpenAL ZenCore ZenEngine ${OPENAL_LIBRARY} ${ALUT_LIBRARY} ${OGG_LIBRARIES} ${VORBIS_LIBRARIES})

set_target_properties ( ZOpenAL 
						PROPERTIES
						DEBUG_POSTFIX "_d"
					)

if (MSVC_IDE)
    # hack to get around the "Debug" and "Release" directories cmake tries to add on Windows
    set_target_properties ( ZOpenAL PROPERTIES PREFIX "../../bin/" )
	set_target_properties ( ZOpenAL PROPERTIES IMPORT_PREFIX "../../lib/" )
endif(MSVC_IDE)

