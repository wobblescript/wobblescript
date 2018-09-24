// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_MODULE_H
#define PROJECT_MODULE_H

#include "type.h"

namespace wobblescript
{
    class Module
    {
    public:
        enum ModuleSymbolType
        {
            kFunction,
            kType
        };

        struct ModuleSymbol
        {
            ModuleSymbolType type;
            union
            {
                Type *asType;
            };
        };
    };
}


#endif //PROJECT_MODULE_H
