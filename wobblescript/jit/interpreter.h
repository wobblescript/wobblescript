// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_INTERPRETER_H
#define PROJECT_INTERPRETER_H

#include <jit/jit.h>
#include "../ir/ir.h"

namespace wobblescript
{
    namespace jit
    {
        class Interpreter
                : public ir::FunctionVisitor<jit_function_t>,
                  public ir::InstructionVisitor<void>,
                  public ir::LinkedProgramVisitor<void>,
                  public ir::ValueVisitor<jit_value_t>
        {
        public:
            jit_function_t visitFunction(const ir::Function *ctx) override;

            void visitLinkedProgram(const ir::LinkedProgram *ctx) override;

            void visitReturnInstruction(const ir::ReturnInstruction *ctx) override;

            jit_value_t visitConstantValue(const ir::ConstantValue *ctx) override;

        private:
            jit_function_t currentFunction;
        };
    }
}

#endif //PROJECT_INTERPRETER_H
