include(FindPackageHandleStandardArgs)

if(DEFINED ANTRL4_INCLUDE_PATH AND DEFINED ANTRL4_LIB_PATH)
    set(ANTLR4_RUNTIME ${ANTRL4_LIB_PATH})
    set(ANTLR4CPP_INCLUDE_DIRS ${ANTRL4_INCLUDE_PATH})
else()
    find_library(ANTLR4_RUNTIME NAMES libantlr4-runtime.so 
        HINTS /usr/local/lib/antlr4 /usr/lib/antlr4 /usr/local/lib /usr/lib)

    find_path(ANTLR4CPP_INCLUDE_DIRS
        NAMES antlr4-runtime.h
        HINTS /usr/local/include/antlr4-runtime /usr/include/antlr4-runtime /usr/local/include /usr/include
        DOC "ANTLR4 C++ headers"
        )
endif()

find_package_handle_standard_args(ANTLR4 REQUIRED_VARS ANTLR4_RUNTIME ANTLR4CPP_INCLUDE_DIRS)
