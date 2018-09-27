// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "return_instruction.h"

wobblescript::ir::ReturnInstruction::ReturnInstruction(const wobblescript::ir::Value *value) {
    this->value = value;
}

const wobblescript::ir::Value *wobblescript::ir::ReturnInstruction::getValue() const {
    return value;
}
