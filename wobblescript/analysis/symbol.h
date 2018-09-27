// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_SYMBOL_H
#define PROJECT_SYMBOL_H

#include <string>
#include "object_or_type.h"

namespace wobblescript
{
    namespace analysis
    {
        class SymbolTable;

        class Symbol
        {
        public:
            Symbol(std::string name, const ObjectOrType *value);

            ~Symbol();

            const SymbolTable *getSymbolTable() const;

            const ObjectOrType *getValue() const;

        private:
            const std::string name;
            const SymbolTable *symbolTable;
            const ObjectOrType *value;
        };
    }
}


#endif //PROJECT_SYMBOL_H
