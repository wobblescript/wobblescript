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
#include "instruction.h"

namespace wobblescript
{
    namespace ir
    {
        class Block
        {
        public:
            Block(std::string name);

            const std::string &GetName() const;

            const std::vector<const Instruction *> &GetStatements() const;

            void AddStatement(const Instruction *statement);

        private:
            const std::string name;
            std::vector<const Instruction *> statements;
        };
    }
}


#endif //PROJECT_BLOCK_H
