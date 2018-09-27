// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "analyzer.h"

using antlrcpp::Any;

antlrcpp::Any wobblescript::Analyzer::visitFuncDecl(wobblescript::WobbleScriptParserParser::FuncDeclContext *ctx) {
    auto name = ctx->name->getText();
    // TODO: Check for name collision
    auto *func = new ir::Function;
    // TODO: Set source info
    // TODO: Check for parameters
    auto *entry = new ir::Block("entry");
    func->setEntryBlock(entry);
    // TODO: Visit block
    // TODO: Throw on empty statement
    ctx->block()->accept(this);
    return Any(func);
}
