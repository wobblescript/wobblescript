// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_DATA_FLOW_GRAPH_H
#define PROJECT_DATA_FLOW_GRAPH_H

#include <stack>
#include <vector>
#include "statement.h"

namespace wobblescript
{
    class DataFlowGraph
    {
    public:
        void enter();

        void exit();

        void addStatement(const Statement *statement);

        struct Node
        {
            std::vector<const Statement *> statements;
            Node *next = nullptr;
        };
    };
}

#endif //PROJECT_DATA_FLOW_GRAPH_H
