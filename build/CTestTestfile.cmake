# CMake generated Testfile for 
# Source directory: /home/sam/CARMINE
# Build directory: /home/sam/CARMINE/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(CompileTest "make" "mist_test")
set_tests_properties(CompileTest PROPERTIES  WORKING_DIRECTORY "/home/sam/CARMINE/build" _BACKTRACE_TRIPLES "/home/sam/CARMINE/CMakeLists.txt;148;ADD_TEST;/home/sam/CARMINE/CMakeLists.txt;0;")
subdirs("src/antlr4")
subdirs("src/oden")
subdirs("src/codeGenerator")
subdirs("src/commandLineParser")
