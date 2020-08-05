SET(NAME antlr4PropositionParser)

add_subdirectory(grammar)
add_subdirectory(handler)


add_library(${NAME} INTERFACE)
target_link_libraries(${NAME} INTERFACE antlr4PropositionParserHandler antlr4PropositionParserGrammar)
