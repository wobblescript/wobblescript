// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_ANALYZER_H
#define PROJECT_ANALYZER_H

#include <WobbleScriptParserBaseVisitor.h>
#include "../ir/ir.h"

namespace wobblescript
{
    namespace analysis
    {
        class Analyzer : public WobbleScriptParserBaseVisitor
        {
        public:
            antlrcpp::Any visitFuncDecl(WobbleScriptParserParser::FuncDeclContext *ctx) override;

            antlrcpp::Any visitReturnStmt(WobbleScriptParserParser::ReturnStmtContext *ctx) override;
        };
    }
}

#endif //PROJECT_ANALYZER_H
