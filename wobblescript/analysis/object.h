// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_OBJECT_H
#define PROJECT_OBJECT_H

#include "type.h"

namespace wobblescript
{
    namespace analysis
    {
        class Object
        {
            Object(const Type *type);

            const Type *getType() const;

        private:
            const Type *type;
        };
    }
}


#endif //PROJECT_OBJECT_H
