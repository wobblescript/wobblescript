// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "interpreter.h"
#include "../ir/constant_value.h"

jit_function_t wobblescript::jit::Interpreter::visitFunction(const wobblescript::ir::Function *ctx) {
    return nullptr;
}

void wobblescript::jit::Interpreter::visitLinkedProgram(const wobblescript::ir::LinkedProgram *ctx) {
    // TODO: Actually keep track of functions, etc.
}

void wobblescript::jit::Interpreter::visitReturnInstruction(const wobblescript::ir::ReturnInstruction *ctx) {
    auto *returnValue = ctx->getValue()->accept(this); // TODO: Handle error
    jit_insn_return(currentFunction, returnValue);
}

jit_value_t wobblescript::jit::Interpreter::visitConstantValue(const wobblescript::ir::ConstantValue *ctx) {
    if (ctx->type == wobblescript::ir::ConstantValue::kBool) {
        return jit_value_create_nint_constant(currentFunction, jit_type_sys_bool, ctx->asBool);
    } else if (ctx->type == wobblescript::ir::ConstantValue::kUint8) {
        return jit_value_create_nint_constant(currentFunction, jit_type_sys_long, ctx->asUint8);
    } else if (ctx->type == wobblescript::ir::ConstantValue::kInt64) {
        return jit_value_create_long_constant(currentFunction, jit_type_sys_long, ctx->asInt64);
    } else if (ctx->type == wobblescript::ir::ConstantValue::kUint64) {
        return jit_value_create_long_constant(currentFunction, jit_type_sys_long, jit_ulong_to_long(ctx->asUint64));
    } else if (ctx->type == wobblescript::ir::ConstantValue::kFloat64) {
        return jit_value_create_float64_constant(currentFunction, jit_type_sys_double, ctx->asFloat64);
    }

    // TODO: Throw error on default
    return nullptr;
}
