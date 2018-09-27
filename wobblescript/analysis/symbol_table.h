// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_SYMBOL_TABLE_H
#define PROJECT_SYMBOL_TABLE_H

#include <vector>
#include "symbol.h"

namespace wobblescript
{
    namespace analysis
    {
        class SymbolTable
        {
        public:
            SymbolTable();

            Symbol *assign(std::string name, const Object *value);

            Symbol *assign(std::string name, const Type *value);

            bool canAssign(const std::string &name) const;

            const Symbol *resolve(const std::string &name) const;

        private:
            SymbolTable(const SymbolTable *parent);

            const SymbolTable *parent;
            std::vector<Symbol *> symbols;
        };
    }
}


#endif //PROJECT_SYMBOL_TABLE_H
