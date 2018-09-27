// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_RETURNINSTRUCTION_H
#define PROJECT_RETURNINSTRUCTION_H

#include "instruction.h"
#include "value.h"

namespace wobblescript
{
    namespace ir
    {
        class ReturnInstruction : public Instruction
        {
        public:
            explicit ReturnInstruction(const Value *value);

            const Value *getValue() const;

            template<typename T>
            T accept(InstructionVisitor<T> *visitor) const override {
                return visitor->visitReturnInstruction(this);
            }

        private:
            const Value *value;
        };
    }
}


#endif //PROJECT_RETURNINSTRUCTION_H
