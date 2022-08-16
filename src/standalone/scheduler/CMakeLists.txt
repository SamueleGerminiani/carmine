
include_directories(include ../monitors/include)
#collect all monitors source files
file(GLOB monitor_files CONFIGURE_DEPENDS "../monitors/src/*.cpp")
SET(SCHEDULER_SRC src/dispatcher.cpp
	src/worker.cpp src/request.cpp
	${monitor_files}
	)
add_library(scheduler ${SCHEDULER_SRC})
target_link_libraries(scheduler pthread)
