// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "interpreter.h"

jit_function_t wobblescript::jit::Interpreter::visitFunction(const wobblescript::ir::Function *ctx) {
    return nullptr;
}

void wobblescript::jit::Interpreter::visitLinkedProgram(const wobblescript::ir::LinkedProgram *ctx) {
    // TODO: Actually keep track of functions, etc.
}
