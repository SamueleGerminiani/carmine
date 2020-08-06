#############################################
# Configuration.
#############################################


SET(NAME antlr4Parsers)


include_directories(
    ./
    utils/include
    varDeclarationParser
    varDeclarationParser/grammar/include
    varDeclarationParser/handler/include
    propositionParser
    propositionParser/grammar/include
    propositionParser/handler/include
    PSLParser
    PSLParser/grammar/include
    PSLParser/handler/include
       )

SET(ANTRL4_PARSERS utils/src/parserUtils.cc)

add_library(${NAME} ${ANTRL4_PARSERS})
add_subdirectory(propositionParser)
add_subdirectory(PSLParser)
add_subdirectory(varDeclarationParser)
target_link_libraries(${NAME} antlr4PropositionParser antlr4VarDeclarationParser antlr4PSLParser)

