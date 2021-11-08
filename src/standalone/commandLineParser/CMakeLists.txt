#############################################
# Configuration.
#############################################

SET(NAME commandLineParser)

include_directories(
    include/
    ../lib/clp/include/
)

#############################################
# Sources.
#############################################
SET (COMMANDLINE_PARSER_SRCS
    src/commandLineParser.cc
    )

#############################################
# Targets.
#############################################
add_library(${NAME} ${COMMANDLINE_PARSER_SRCS})
target_link_libraries(${NAME} stdc++fs)

