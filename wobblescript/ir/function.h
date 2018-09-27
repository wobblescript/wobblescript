// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_FUNCTION_H
#define PROJECT_FUNCTION_H

#include "block.h"

namespace wobblescript
{
    namespace ir
    {
        class Function
        {
        public:
            const Block *GetEntryBlock() const;

            const std::vector<const Block *> &GetBlocks() const;

            void AddBlock(const Block *block);

            void SetEntryBlock(const Block *block);

        private:
            std::vector<const Block *> blocks;
        };
    }
}


#endif //PROJECT_FUNCTION_H
