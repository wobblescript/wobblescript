// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_STATEMENT_H
#define PROJECT_STATEMENT_H

#include <cstdint>

namespace wobblescript
{
    namespace ir
    {
        template<typename T>
        class InstructionVisitor
        {

        };

        class Instruction
        {
            //virtual uint8_t GetSizeInBytes() = 0;

            template<typename T>
            virtual T Accept(InstructionVisitor<T> *visitor) const = 0;
        };
    }
}

#endif //PROJECT_STATEMENT_H
