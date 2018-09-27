// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_LINKED_PROGRAM_H
#define PROJECT_LINKED_PROGRAM_H

namespace wobblescript
{
    namespace ir
    {
        class LinkedProgram;

        template<typename T>
        class LinkedProgramVisitor
        {
        public:
            virtual T visitLinkedProgram(const LinkedProgram *ctx) = 0;
        };

        class LinkedProgram
        {
        public:
            template<typename T>
            T accept(LinkedProgramVisitor *visitor) const {
                return visitor->visitLinkedProgram(this);
            }
        };
    }
}


#endif //PROJECT_LINKED_PROGRAM_H
