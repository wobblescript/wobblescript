// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_VALUE_H
#define PROJECT_VALUE_H

namespace wobblescript
{
    namespace ir
    {
        class ConstantValue;

        template<typename T>
        class ValueVisitor
        {
        public:
            virtual T VisitConstantValue(const ConstantValue *ctx) = 0;
        };

        class Value
        {
        public:
            template<typename T>
            virtual T Accept(ValueVisitor<T> *visitor) const = 0;
        };
    }
}

#endif //PROJECT_VALUE_H
