include(FindPackageHandleStandardArgs)

if(DEFINED Z3_INCLUDE_PATH AND DEFINED Z3_LIB_PATH)
    set(Z3_INCLUDE_DIRS ${Z3_INCLUDE_PATH})
    set(Z3_LIBRARY ${Z3_LIB_PATH})
else()
    find_library(Z3_LIBRARY NAMES libz3.so
        PATHS ${CMAKE_SOURCE_DIR}/lib/z3/lib/)

    find_path(Z3_INCLUDE_DIRS
        NAMES z3++.h z3.h
        PATHS ${CMAKE_SOURCE_DIR}/lib/z3/include/
        DOC "Z3 C++ header")
endif()

find_package_handle_standard_args(Z3 REQUIRED_VARS Z3_LIBRARY Z3_INCLUDE_DIRS)

