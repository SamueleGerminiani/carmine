SET(NAME antlr4PSLParser)

add_subdirectory(grammar)
add_subdirectory(handler)


add_library(${NAME} INTERFACE)
target_link_libraries(${NAME} INTERFACE antlr4PSLParserHandler antlr4PSLParserGrammar)
