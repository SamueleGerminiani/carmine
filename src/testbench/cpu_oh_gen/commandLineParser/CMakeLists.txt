#############################################
# Configuration.
#############################################

SET(NAME commandLineParserOH)

include_directories(
    include/
    ../lib/clp/include/
)

#############################################
# Sources.
#############################################
SET (COMMANDLINE_PARSER_OH_SRCS
    src/commandLineParser.cc
    )

#############################################
# Targets.
#############################################
add_library(${NAME} ${COMMANDLINE_PARSER_OH_SRCS})
target_link_libraries(${NAME} stdc++fs)

