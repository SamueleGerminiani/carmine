#############################################
# Configuration.
#############################################

project(codeGenerator)


include_directories( 
    ../oden/include
    ../antlr4/utils/include
    ../antlr4/propositionParser/grammar/include
    ../antlr4/propositionParser/handler/include
    ../antlr4/propositionParser/
    ../oden/include/oden/visitors/
    ${SPOTLTLCPP_INCLUDE_DIRS}
)


SET(CODE_GENERATOR_SRCS
   ./src/globals.cc
   ./src/checkerGenerator.cc
   ./src/handlerGenerator.cc
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
target_link_libraries(codeGenerator oden)
target_link_libraries(codeGenerator antlr4Parsers)
target_link_libraries(codeGenerator ${SPOTLTL_LIB})
