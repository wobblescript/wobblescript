// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_BINARY_ARTIFACT_H
#define PROJECT_BINARY_ARTIFACT_H

#include <cstdint>
#include <vector>
#include "../ir/function.h"

namespace wobblescript
{
    namespace ir
    {
        /**
         * A utility class that can build a bytecode file from a program.
         */
        class BytecodeWriter
        {
        public:
            uint64_t CreateDataConstant(void *data, uint64_t len);

            uint64_t CreateStringConstant(const std::string &s);

            uint64_t CreateStringConstant(const char *s);

            uint64_t CreateLongConstant(int64_t value);

            uint64_t CreateUnsignedLongConstant(uint64_t value);

            uint64_t AddFunction(const Function *function);

        private:
            std::vector<uint8_t> constantData;
            std::vector<const Function *> functions;
        };
    }
}

#endif //PROJECT_BINARY_ARTIFACT_H
