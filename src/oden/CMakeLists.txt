#############################################
# Configuration.
#############################################

project(oden)


include_directories(./include
         ../grammar/include/
        ${ANTLR4CPP_INCLUDE_DIRS}
        ../testCaseGenerator/include/z3/
        )

#############################################
# Sources.
#############################################

SET(BASE_SRCS
        src/odenEnums.cc
        )

SET(VISITORS_SRC
        src/OdenVisitor.cc
        src/visitors/PrinterVisitor.cc
        src/visitors/VarsExtractVisitor.cc
        )

SET(UTILS_SRCS
    src/odenUtils/applicationUtils.cc
        src/odenUtils/xmlUtils.cc
        src/odenUtils/propositionUtils.cc
        )

SET(CLASSES_SRCS
        src/classes/atom/Constant.cc
        src/classes/atom/Variable.cc
        src/classes/expression/Expression.cc
        src/classes/expression/TypeCast.cc
        )

#### All the previous ####
SET(ALL_ODEN_SRCS
        ${BASE_SRCS}
        ${CLASSES_SRCS}
        ${UTILS_SRCS}
        ${MODULES_SRCS}
        ${VISITORS_SRC}
        )

#############################################
# Targets.
#############################################
add_library(oden ${ALL_ODEN_SRCS})
target_link_libraries(oden ${ANTLR4_RUNTIME})

