set(CMAKE_CXX_STANDARD 11)
set(ANTLR4CPP_JAR_LOCATION $ENV{ANTLR4CPP_JAR_LOCATION})
include(ExternalAntlr4Cpp)

include_directories(${ANTLR4CPP_INCLUDE_DIRS})
link_directories(${ANTLR4CPP_LIBS})
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS}")

antlr4cpp_process_grammar(wobblescript wobblescript
        WobbleScriptLexer.g4
        WobbleScriptParser.g4)

include_directories(${antlr4cpp_include_dirs_wobblescript})

add_executable(wobblescript ${antlr4cpp_src_files_wobblescript} temp_main.cpp)
add_dependencies(wobblescript antlr4cpp ${antlr4cpp_generation_wobblescript})
target_link_libraries(wobblescript antlr4-runtime)

# # add generated grammar to demo binary target
# add_executable(demo main.cpp ${antlr4cpp_src_files_antlrcpptest})
# add_dependencies(demo antlr4cpp antlr4cpp_generation_antlrcpptest)
# target_link_libraries(demo antlr4-runtime)