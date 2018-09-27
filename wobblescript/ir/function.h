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
        class Function;

        template<typename T>
        class FunctionVisitor
        {
        public:
            virtual T visitFunction(const Function *ctx) = 0;
        };

        class Function
        {
        public:
            const Block *getEntryBlock() const;

            const std::vector<const Block *> &getBlocks() const;

            template<typename T>
            T accept(FunctionVisitor<T> *visitor) const {
                return visitor->visitFunction(this);
            }

            void addBlock(const Block *block);

            void setEntryBlock(const Block *block);

        private:
            std::vector<const Block *> blocks;
        };
    }
}


#endif //PROJECT_FUNCTION_H
