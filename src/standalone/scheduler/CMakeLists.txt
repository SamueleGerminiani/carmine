
include_directories(include ../checkers/include)
#collect all checkers source files
file(GLOB checker_files CONFIGURE_DEPENDS "../checkers/src/*.cpp")
SET(SCHEDULER_SRC src/dispatcher.cpp
	src/worker.cpp src/request.cpp
	${checker_files}
	)
add_library(scheduler ${SCHEDULER_SRC})
target_link_libraries(scheduler pthread)
##Add a dependency to the scheduler executable so messages and services
##will be built before it
add_dependencies(scheduler verification_env_generate_messages_cpp)
