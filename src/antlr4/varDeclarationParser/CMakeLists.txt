SET(NAME antlr4VarDeclarationParser)

add_subdirectory(grammar)
add_subdirectory(handler)


add_library(${NAME} INTERFACE)
target_link_libraries(${NAME} INTERFACE antlr4VarDeclarationParserHandler antlr4VarDeclarationParserGrammar)
