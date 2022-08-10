#############################################
# Configuration.
#############################################

SET(NAME antlr4PSLParserHandler)

include_directories(
    include
    ../grammar/include
)

#############################################
# Sources.
#############################################
SET (ANTLR4_PSL_PARSER_HANDLER
     src/parserHandler.cc
     )


#############################################
# Targets.
#############################################
add_library(${NAME} ${ANTLR4_PSL_PARSER_HANDLER})
target_link_libraries(${NAME} exp)

