set(CMAKE_CXX_STANDARD 11)
set(ANTLR4CPP_JAR_LOCATION $ENV{ANTLR4CPP_JAR_LOCATION})
include(ExternalAntlr4Cpp)

find_library(ANTLR4 antlr4-runtime)
find_library(LIBJIT jit)

find_path(ANTLR4_INC antlr4-runtime/antlr4-runtime.h)
find_path(JIT_INC jit/jit.h)
include_directories(${JIT_INC})
include_directories(${ANTLR4_INC}/antlr4-runtime)

antlr4cpp_process_grammar(wobblescript wobblescript
        src/WobbleScriptLexer.g4
        src/WobbleScriptParser.g4)

include_directories(${antlr4cpp_include_dirs_wobblescript})

add_library(wobblescript ${antlr4cpp_src_files_wobblescript}
        c/c_api.h
        analysis/analyzer.cc analysis/analyzer.h
        analysis/statement.cc analysis/statement.h
        analysis/type.cc analysis/type.h
        analysis/object.cpp analysis/object.h
        analysis/module.cc analysis/module.h
        ir/function.cc ir/function.h
        ir/block.cc ir/block.h
        ir/instruction.cc ir/instruction.h
        bytecode/bytecode_writer.cc bytecode/bytecode_writer.h
        ir/linked_program.cc ir/linked_program.h
        ir/ir.h
        jit/interpreter.cc jit/interpreter.h ir/value.cc ir/value.h ir/return_instruction.cc ir/return_instruction.h ir/constant_value.cc ir/constant_value.h)

add_dependencies(wobblescript antlr4cpp_generation_wobblescript)