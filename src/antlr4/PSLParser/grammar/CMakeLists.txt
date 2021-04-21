#############################################
# Configuration.
#############################################

SET(NAME antlr4PSLParserGrammar)

include_directories(
    include/
    ${ANTLR4CPP_INCLUDE_DIRS}  
)

#############################################
# Sources.
#############################################
SET (ANTLR4_PSL_PARSER_GRAMMAR
     src/temporalLexer.cpp
     src/temporalParser.cpp
     src/temporalListener.cpp
     src/temporalBaseListener.cpp
     )

 set_source_files_properties(
     ${ANTLR4_PSL_PARSER_GRAMMAR}
     PROPERTIES
     COMPILE_FLAGS "-w"
     )

#############################################
# Targets.
#############################################
add_library(${NAME} ${ANTLR4_PSL_PARSER_GRAMMAR})
target_link_libraries(${NAME} ${ANTLR4_RUNTIME})


