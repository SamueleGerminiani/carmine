# set the project name
project("CARMINE" CXX)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

### COMPILER FLAGS ###

include(CheckCXXCompilerFlag)


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wpedantic")
elseif (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wpedantic")
endif()


### BUILD TYPE ###

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "${Green}Release mode${Reset}")
    add_compile_options("-O3")
    add_compile_options("-DNDEBUG")

elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
	message(STATUS "${Green}Debug mode${Reset}")
    if (CMAKE_COMPILER_IS_GNUCXX)
        add_compile_options("-ggdb3")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        add_compile_options("-ggdb")
    else()
        add_compile_options("-g")
    endif()

elseif (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message(STATUS "${Green}Coverage Mode${Reset}")
    if (CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "--coverage")
        add_compile_options("--coverage")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

        add_compile_options("-fprofile-instr-generate")
        add_compile_options("-fcoverage-mapping")
        set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS}
                                  "-fprofile-instr-generate -fcoverage-mapping")
    endif()

endif()


#Custom targets

find_program(DOXYGEN_FOUND doxygen)
if (DOXYGEN_FOUND)
    set(current_targets ${current_targets} "doc\n")
    message(STATUS "${Blue}doxygen found!${Reset}")
    add_custom_target(doc COMMAND doxygen ${PROJECT_SOURCE_DIR}/doxygen.cfg)
endif()



#############################################################################
# Basic configuration.
#############################################################################
include(FindPackageHandleStandardArgs)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


################################################################################
# External libraries
################################################################################
find_package(ANTLR4 REQUIRED)
find_package(SPOTLTL REQUIRED)


################################################################################
# Targets.
################################################################################
SET(NAME carmine)
SET(MAIN_SRC ./src/main.cpp)

include_directories(
	${ANTLR4CPP_INCLUDE_DIRS} 
    ${SPOTLTLCPP_INCLUDE_DIRS}
	src/antlr4/propositionParser/grammar/include
	src/antlr4/propositionParser/handler/include
	src/antlr4/PSLParser/grammar/include
	src/antlr4/PSLParser/handler/include
    src/antlr4/utils/include
	src/oden/include
	src/testCaseGenerator/include
    src/codeGenerator/include
    src/commandLineParser/include
	src/codeGenerator/include/rapidxml/include
    src/include
)

#Main executable
add_executable(${NAME} ${MAIN_SRC})

#Antrl4 
add_subdirectory(src/antlr4)
target_link_libraries(${NAME} antlr4Parsers)   

#Propositions
add_subdirectory(src/oden)
target_link_libraries(${NAME} oden) 

#Code generator
add_subdirectory(src/codeGenerator)
target_link_libraries(${NAME} codeGenerator) 


#Command line parser
add_subdirectory(src/commandLineParser)
target_link_libraries(${NAME} commandLineParser)


include_directories(libs
    src/antlr4
    src/antlr4/utils/include
    src/antlr4/propositionParser/grammar/include
    src/antlr4/propositionParser/handler/include
    src/antlr4/propositionParser/
    src/antlr4/varDeclarationParser/grammar/include
    src/antlr4/varDeclarationParser/handler/include
    src/antlr4/varDeclarationParser/
    )

INSTALL(TARGETS carmine
    RUNTIME DESTINATION carmine/bin
    LIBRARY DESTINATION carmine/lib
    ARCHIVE DESTINATION carmine/lib
    )

INSTALL(PROGRAMS ${SPOTLTL_LIB} ${ANTLR4_RUNTIME} DESTINATION carmine/lib)

#Copy the libraries with their symbolic links
INSTALL(
    CODE
    "execute_process(
        COMMAND
        ${CMAKE_COMMAND}
        -DS=${SPOTLTL_LIB}
        -DB=${BDDX_LIB}
        -DA=${ANTLR4_RUNTIME}
        -DIP=${CMAKE_INSTALL_PREFIX}
        -P
        ${CMAKE_SOURCE_DIR}/cmake/PostInstall.cmake
    )"
)

