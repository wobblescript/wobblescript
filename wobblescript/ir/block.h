// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_BLOCK_H
#define PROJECT_BLOCK_H

#include <string>
#include <vector>
#include "statement.h"

namespace wobblescript
{
    namespace ir
    {
        class Block
        {
        public:
            Block(std::string name);

            const std::string &GetName() const;

            const std::vector<const Statement *> &GetStatements() const;

            void AddStatement(const Statement *statement);

        private:
            const std::string name;
            std::vector<const Statement *> statements;
        };
    }
}


#endif //PROJECT_BLOCK_H
