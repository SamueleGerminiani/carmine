#############################################
# Configuration.
#############################################

project(codeGenerator)


include_directories( 
    ../exp/include
    ../antlr4/utils/include
    ../antlr4/propositionParser/grammar/include
    ../antlr4/propositionParser/handler/include
    ../antlr4/propositionParser/
    ../rapidxml/include/
    ${SPOTLTLCPP_INCLUDE_DIRS}
)


SET(CODE_GENERATOR_SRCS
   ./src/monitorGenerator.cc
   ./src/ver_envGenerator.cc
   ./src/codeGenerator.cc
    )
#############################################
# Sources.
#############################################


#############################################
# Targets.
#############################################
add_library(codeGenerator ${CODE_GENERATOR_SRCS})
target_link_libraries(codeGenerator exp)
target_link_libraries(codeGenerator antlr4Parsers)
target_link_libraries(codeGenerator ${SPOTLTL_LIB})
