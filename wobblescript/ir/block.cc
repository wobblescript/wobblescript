// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "block.h"

wobblescript::ir::Block::Block(std::string name)
        : name(std::move(name)) {}

const std::string &wobblescript::ir::Block::GetName() const {
    return name;
}

const std::vector<const wobblescript::ir::Instruction *> &wobblescript::ir::Block::GetStatements() const {
    return statements;
}

void wobblescript::ir::Block::AddStatement(const wobblescript::ir::Instruction *statement) {
    statements.push_back(statement);
}
