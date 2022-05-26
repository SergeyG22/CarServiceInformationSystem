########## MACROS ###########################################################################
#############################################################################################

function(conan_message MESSAGE_OUTPUT)
    if(NOT CONAN_CMAKE_SILENT_OUTPUT)
        message(${ARGV${0}})
    endif()
endfunction()


macro(conan_find_apple_frameworks FRAMEWORKS_FOUND FRAMEWORKS FRAMEWORKS_DIRS)
    if(APPLE)
        foreach(_FRAMEWORK ${FRAMEWORKS})
            # https://cmake.org/pipermail/cmake-developers/2017-August/030199.html
            find_library(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND NAME ${_FRAMEWORK} PATHS ${FRAMEWORKS_DIRS} CMAKE_FIND_ROOT_PATH_BOTH)
            if(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND)
                list(APPEND ${FRAMEWORKS_FOUND} ${CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND})
            else()
                message(FATAL_ERROR "Framework library ${_FRAMEWORK} not found in paths: ${FRAMEWORKS_DIRS}")
            endif()
        endforeach()
    endif()
endmacro()


function(conan_package_library_targets libraries package_libdir deps out_libraries out_libraries_target build_type package_name)
    unset(_CONAN_ACTUAL_TARGETS CACHE)
    unset(_CONAN_FOUND_SYSTEM_LIBS CACHE)
    foreach(_LIBRARY_NAME ${libraries})
        find_library(CONAN_FOUND_LIBRARY NAME ${_LIBRARY_NAME} PATHS ${package_libdir}
                     NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
        if(CONAN_FOUND_LIBRARY)
            conan_message(STATUS "Library ${_LIBRARY_NAME} found ${CONAN_FOUND_LIBRARY}")
            list(APPEND _out_libraries ${CONAN_FOUND_LIBRARY})
            if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
                # Create a micro-target for each lib/a found
                string(REGEX REPLACE "[^A-Za-z0-9.+_-]" "_" _LIBRARY_NAME ${_LIBRARY_NAME})
                set(_LIB_NAME CONAN_LIB::${package_name}_${_LIBRARY_NAME}${build_type})
                if(NOT TARGET ${_LIB_NAME})
                    # Create a micro-target for each lib/a found
                    add_library(${_LIB_NAME} UNKNOWN IMPORTED)
                    set_target_properties(${_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CONAN_FOUND_LIBRARY})
                    set(_CONAN_ACTUAL_TARGETS ${_CONAN_ACTUAL_TARGETS} ${_LIB_NAME})
                else()
                    conan_message(STATUS "Skipping already existing target: ${_LIB_NAME}")
                endif()
                list(APPEND _out_libraries_target ${_LIB_NAME})
            endif()
            conan_message(STATUS "Found: ${CONAN_FOUND_LIBRARY}")
        else()
            conan_message(STATUS "Library ${_LIBRARY_NAME} not found in package, might be system one")
            list(APPEND _out_libraries_target ${_LIBRARY_NAME})
            list(APPEND _out_libraries ${_LIBRARY_NAME})
            set(_CONAN_FOUND_SYSTEM_LIBS "${_CONAN_FOUND_SYSTEM_LIBS};${_LIBRARY_NAME}")
        endif()
        unset(CONAN_FOUND_LIBRARY CACHE)
    endforeach()

    if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
        # Add all dependencies to all targets
        string(REPLACE " " ";" deps_list "${deps}")
        foreach(_CONAN_ACTUAL_TARGET ${_CONAN_ACTUAL_TARGETS})
            set_property(TARGET ${_CONAN_ACTUAL_TARGET} PROPERTY INTERFACE_LINK_LIBRARIES "${_CONAN_FOUND_SYSTEM_LIBS};${deps_list}")
        endforeach()
    endif()

    set(${out_libraries} ${_out_libraries} PARENT_SCOPE)
    set(${out_libraries_target} ${_out_libraries_target} PARENT_SCOPE)
endfunction()


########### FOUND PACKAGE ###################################################################
#############################################################################################

include(FindPackageHandleStandardArgs)

conan_message(STATUS "Conan: Using autogenerated FindSQLite3.cmake")
set(SQLite3_FOUND 1)
set(SQLite3_VERSION "3.38.5")

find_package_handle_standard_args(SQLite3 REQUIRED_VARS
                                  SQLite3_VERSION VERSION_VAR SQLite3_VERSION)
mark_as_advanced(SQLite3_FOUND SQLite3_VERSION)

set(SQLite_COMPONENTS SQLite::SQLite3)

if(SQLite3_FIND_COMPONENTS)
    foreach(_FIND_COMPONENT ${SQLite3_FIND_COMPONENTS})
        list(FIND SQLite_COMPONENTS "SQLite::${_FIND_COMPONENT}" _index)
        if(${_index} EQUAL -1)
            conan_message(FATAL_ERROR "Conan: Component '${_FIND_COMPONENT}' NOT found in package 'SQLite'")
        else()
            conan_message(STATUS "Conan: Component '${_FIND_COMPONENT}' found in package 'SQLite'")
        endif()
    endforeach()
endif()

########### VARIABLES #######################################################################
#############################################################################################


set(SQLite_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/include")
set(SQLite_INCLUDE_DIR "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/include")
set(SQLite_INCLUDES "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/include")
set(SQLite_RES_DIRS )
set(SQLite_DEFINITIONS )
set(SQLite_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)
set(SQLite_COMPILE_DEFINITIONS )
set(SQLite_COMPILE_OPTIONS_LIST "" "")
set(SQLite_COMPILE_OPTIONS_C "")
set(SQLite_COMPILE_OPTIONS_CXX "")
set(SQLite_LIBRARIES_TARGETS "") # Will be filled later, if CMake 3
set(SQLite_LIBRARIES "") # Will be filled later
set(SQLite_LIBS "") # Same as SQLite_LIBRARIES
set(SQLite_SYSTEM_LIBS )
set(SQLite_FRAMEWORK_DIRS )
set(SQLite_FRAMEWORKS )
set(SQLite_FRAMEWORKS_FOUND "") # Will be filled later
set(SQLite_BUILD_MODULES_PATHS "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/lib/cmake/conan-official-sqlite3-variables.cmake")

conan_find_apple_frameworks(SQLite_FRAMEWORKS_FOUND "${SQLite_FRAMEWORKS}" "${SQLite_FRAMEWORK_DIRS}")

mark_as_advanced(SQLite_INCLUDE_DIRS
                 SQLite_INCLUDE_DIR
                 SQLite_INCLUDES
                 SQLite_DEFINITIONS
                 SQLite_LINKER_FLAGS_LIST
                 SQLite_COMPILE_DEFINITIONS
                 SQLite_COMPILE_OPTIONS_LIST
                 SQLite_LIBRARIES
                 SQLite_LIBS
                 SQLite_LIBRARIES_TARGETS)

# Find the real .lib/.a and add them to SQLite_LIBS and SQLite_LIBRARY_LIST
set(SQLite_LIBRARY_LIST sqlite3)
set(SQLite_LIB_DIRS "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/lib")

# Gather all the libraries that should be linked to the targets (do not touch existing variables):
set(_SQLite_DEPENDENCIES "${SQLite_FRAMEWORKS_FOUND} ${SQLite_SYSTEM_LIBS} ")

conan_package_library_targets("${SQLite_LIBRARY_LIST}"  # libraries
                              "${SQLite_LIB_DIRS}"      # package_libdir
                              "${_SQLite_DEPENDENCIES}"  # deps
                              SQLite_LIBRARIES            # out_libraries
                              SQLite_LIBRARIES_TARGETS    # out_libraries_targets
                              ""                          # build_type
                              "SQLite")                                      # package_name

set(SQLite_LIBS ${SQLite_LIBRARIES})

foreach(_FRAMEWORK ${SQLite_FRAMEWORKS_FOUND})
    list(APPEND SQLite_LIBRARIES_TARGETS ${_FRAMEWORK})
    list(APPEND SQLite_LIBRARIES ${_FRAMEWORK})
endforeach()

foreach(_SYSTEM_LIB ${SQLite_SYSTEM_LIBS})
    list(APPEND SQLite_LIBRARIES_TARGETS ${_SYSTEM_LIB})
    list(APPEND SQLite_LIBRARIES ${_SYSTEM_LIB})
endforeach()

# We need to add our requirements too
set(SQLite_LIBRARIES_TARGETS "${SQLite_LIBRARIES_TARGETS};")
set(SQLite_LIBRARIES "${SQLite_LIBRARIES};")

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/" ${CMAKE_PREFIX_PATH})


########### COMPONENT SQLite3 VARIABLES #############################################

set(SQLite_SQLite3_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/include")
set(SQLite_SQLite3_INCLUDE_DIR "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/include")
set(SQLite_SQLite3_INCLUDES "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/include")
set(SQLite_SQLite3_LIB_DIRS "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/lib")
set(SQLite_SQLite3_RES_DIRS )
set(SQLite_SQLite3_DEFINITIONS )
set(SQLite_SQLite3_COMPILE_DEFINITIONS )
set(SQLite_SQLite3_COMPILE_OPTIONS_C "")
set(SQLite_SQLite3_COMPILE_OPTIONS_CXX "")
set(SQLite_SQLite3_LIBS sqlite3)
set(SQLite_SQLite3_SYSTEM_LIBS )
set(SQLite_SQLite3_FRAMEWORK_DIRS )
set(SQLite_SQLite3_FRAMEWORKS )
set(SQLite_SQLite3_BUILD_MODULES_PATHS "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/lib/cmake/conan-official-sqlite3-variables.cmake")
set(SQLite_SQLite3_DEPENDENCIES )
set(SQLite_SQLite3_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)


########## FIND PACKAGE DEPENDENCY ##########################################################
#############################################################################################

include(CMakeFindDependencyMacro)


########## FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #######################################
#############################################################################################

########## COMPONENT SQLite3 FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(SQLite_SQLite3_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(SQLite_SQLite3_FRAMEWORKS_FOUND "${SQLite_SQLite3_FRAMEWORKS}" "${SQLite_SQLite3_FRAMEWORK_DIRS}")

set(SQLite_SQLite3_LIB_TARGETS "")
set(SQLite_SQLite3_NOT_USED "")
set(SQLite_SQLite3_LIBS_FRAMEWORKS_DEPS ${SQLite_SQLite3_FRAMEWORKS_FOUND} ${SQLite_SQLite3_SYSTEM_LIBS} ${SQLite_SQLite3_DEPENDENCIES})
conan_package_library_targets("${SQLite_SQLite3_LIBS}"
                              "${SQLite_SQLite3_LIB_DIRS}"
                              "${SQLite_SQLite3_LIBS_FRAMEWORKS_DEPS}"
                              SQLite_SQLite3_NOT_USED
                              SQLite_SQLite3_LIB_TARGETS
                              ""
                              "SQLite_SQLite3")

set(SQLite_SQLite3_LINK_LIBS ${SQLite_SQLite3_LIB_TARGETS} ${SQLite_SQLite3_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/sqlite3/3.38.5/_/_/package/5e2ee2bbbf247701a335de1962053720f3cbabf1/" ${CMAKE_PREFIX_PATH})


########## TARGETS ##########################################################################
#############################################################################################

########## COMPONENT SQLite3 TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET SQLite::SQLite3)
        add_library(SQLite::SQLite3 INTERFACE IMPORTED)
        set_target_properties(SQLite::SQLite3 PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${SQLite_SQLite3_INCLUDE_DIRS}")
        set_target_properties(SQLite::SQLite3 PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${SQLite_SQLite3_LIB_DIRS}")
        set_target_properties(SQLite::SQLite3 PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${SQLite_SQLite3_LINK_LIBS};${SQLite_SQLite3_LINKER_FLAGS_LIST}")
        set_target_properties(SQLite::SQLite3 PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${SQLite_SQLite3_COMPILE_DEFINITIONS}")
        set_target_properties(SQLite::SQLite3 PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${SQLite_SQLite3_COMPILE_OPTIONS_C};${SQLite_SQLite3_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## GLOBAL TARGET ####################################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    if(NOT TARGET SQLite::SQLite)
        add_library(SQLite::SQLite INTERFACE IMPORTED)
    endif()
    set_property(TARGET SQLite::SQLite APPEND PROPERTY
                 INTERFACE_LINK_LIBRARIES "${SQLite_COMPONENTS}")
endif()

########## BUILD MODULES ####################################################################
#############################################################################################
########## COMPONENT SQLite3 BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${SQLite_SQLite3_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
