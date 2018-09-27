// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_OBJECT_OR_TYPE_H
#define PROJECT_OBJECT_OR_TYPE_H

#include "object.h"
#include "type.h"

namespace wobblescript
{
    namespace analysis
    {
        class ObjectOrType
        {
        public:
            ObjectOrType(const Object *object);

            ObjectOrType(const Type *type);

            ~ObjectOrType();

            bool isType() const;

            const Object *asObject() const;

            const Type *asType() const;

        private:
            const Object *object;
            const Type *type;
        };
    }
}

#endif //PROJECT_OBJECT_OR_TYPE_H
