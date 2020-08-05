#############################################
# Configuration.
#############################################

SET(NAME antlr4VarDeclarationParserHandler)

include_directories(
    include
    ../grammar/include
)

#############################################
# Sources.
#############################################
SET (ANTLR4_VAR_DECLARATION_HANDLER
     src/varDeclarationHandler.cc
     )


#############################################
# Targets.
#############################################
add_library(${NAME} ${ANTLR4_VAR_DECLARATION_HANDLER})
#target_link_libraries(${NAME} oden)

