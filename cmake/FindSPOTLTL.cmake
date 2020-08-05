include(FindPackageHandleStandardArgs)

if(DEFINED SPOTLTL_INCLUDE_PATH AND DEFINED SPOTLTL_LIB_PATH AND DEFINED BDDX_LIB_PATH)
set(SPOTLTLCPP_INCLUDE_DIRS ${SPOTLTL_INCLUDE_PATH})
set(SPOTLTL_LIB ${SPOTLTL_LIB_PATH})
set(BDDX_LIB ${BDDX_LIB_PATH})
else()

    find_library(SPOTLTL_LIB NAMES libspot.so HINTS /usr/local/lib/spot
        /usr/lib/spot /usr/local/lib /usr/lib)
    find_library(BDDX_LIB NAMES libbddx.so HINTS /usr/local/lib /usr/lib)


find_path(SPOTLTLCPP_INCLUDE_DIRS
    NAMES spot/tl spot/twaalgos
    HINTS /usr/local/include /usr/include /usr/local/include /usr/include
    )

endif()
list(APPEND SPOTLTL_LIB ${BDDX_LIB})

find_package_handle_standard_args(SPOTLTL REQUIRED_VARS SPOTLTL_LIB BDDX_LIB SPOTLTLCPP_INCLUDE_DIRS)
