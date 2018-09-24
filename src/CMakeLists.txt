set(CMAKE_CXX_STANDARD 11)
set(ANTLR4CPP_JAR_LOCATION $ENV{ANTLR4CPP_JAR_LOCATION})
include(ExternalAntlr4Cpp)
find_library(ANTLR4 antlr4-runtime)
find_path(ANTLR4_INC antlr4-runtime/antlr4-runtime.h)
include_directories(${ANTLR4_INC}/antlr4-runtime)
antlr4cpp_process_grammar(wobblescript wobblescript
        ${CMAKE_CURRENT_SOURCE_DIR}/WobbleScriptLexer.g4
        ${CMAKE_CURRENT_SOURCE_DIR}/WobbleScriptParser.g4)
include_directories(${antlr4cpp_include_dirs_wobblescript})
add_library(wobblescript ${antlr4cpp_src_files_wobblescript})
add_dependencies(wobblescript antlr4cpp_generation_wobblescript)