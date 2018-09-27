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
        class Value;

        template<typename T>
        class ValueVisitor
        {
        public:
            //virtual T accept(const Value *ctx) = 0;
        };

        class Value
        {
        public:
            template<typename T>
            virtual T accept(ValueVisitor<T> *visitor) = 0;
        };
    }
}

#endif //PROJECT_VALUE_H
