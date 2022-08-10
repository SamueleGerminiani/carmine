
include_directories(./include
        )

SET(VISITORS_SRC
        src/visitors/ExpVisitor.cc
        src/visitors/PrinterVisitor.cc
        src/visitors/VarsExtractVisitor.cc
        )

SET(UTILS_SRCS
        src/utils/propositionUtils.cc
        )

SET(CLASSES_SRCS
        src/classes/atom/Constant.cc
        src/classes/atom/Variable.cc
        src/classes/expression/Expression.cc
        src/classes/expression/TypeCast.cc
        )

SET(ALL_EXP_SRCS
        ${CLASSES_SRCS}
        ${UTILS_SRCS}
        ${MODULES_SRCS}
        ${VISITORS_SRC}
        )

add_library(exp ${ALL_EXP_SRCS})
target_link_libraries(exp ${ANTLR4_RUNTIME})

