// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_CONSTANT_VALUE_H
#define PROJECT_CONSTANT_VALUE_H

#include <cstdint>
#include "value.h"

namespace wobblescript
{
    namespace ir
    {
        class ConstantValue : public Value
        {
        public:
            enum ConstantValueType
            {
                kNone,
                kBool,
                kUint8,
                kInt64,
                kUint64,
                kFloat64,
            };

            ConstantValueType type = kNone;

            union
            {
                bool asBool;
                uint8_t asUint8;
                int64_t asInt64;
                uint64_t asUint64;
                double asFloat64 = 0;
            };

            template<typename T>
            T accept(ValueVisitor<T> *visitor) const override {
                return visitor->visitConstantValue(this);
            }
        };


    }
}


#endif //PROJECT_CONSTANT_VALUE_H
