#############################################
# Configuration.
#############################################

SET(NAME antlr4PropositionParserHandler)

include_directories(
    include
    ../grammar/include
    ../../../oden/include
)

#############################################
# Sources.
#############################################
SET (ANTLR4_PROPOSITION_PARSER_HANDLER
     src/parserHandler.cc
     )


#############################################
# Targets.
#############################################
add_library(${NAME} ${ANTLR4_PROPOSITION_PARSER_HANDLER})
target_link_libraries(${NAME} oden)

