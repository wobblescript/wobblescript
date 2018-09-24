// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef PROJECT_C_API_H
#define PROJECT_C_API_H

#include <stdint.h>

#define WS_STATUS_OK 0
#define WS_STATUS_FAILURE 1

typedef void *WS_Analyzer;

typedef void *WS_DataFlowGraph;

typedef void *WS_Environment;

typedef enum
{
    WS_Object_kString,
    WS_Object_kNumber,
    WS_Object_kPointer
} WS_ObjectType;

typedef struct _WS_Object WS_Object;

struct _WS_Object
{
    WS_ObjectType type;
    union
    {
        const char *asString;
        double asDouble;
        void *asPointer;
        struct
        {
            uint64_t length;
            WS_Object *items;
        } asArray;
    };
};

WS_Analyzer WS_NewAnalyzer();

void WS_DeleteAnalyzer(WS_Analyzer analyzer);

WS_DataFlowGraph WS_AnalyzeSourceFromFile(WS_Analyzer analyzer, const char *filename);

WS_DataFlowGraph WS_AnalyzeSourceFromText(WS_Analyzer analyzer, const char *text);

WS_Environment WS_NewEnvironment();

void WS_DeleteEnvironment(WS_Environment environment);

WS_Object *WS_GetEnvironmentValue(WS_Environment environment, const char *name);

void WS_SetEnvironmentValue(WS_Environment environment, const char *name, WS_Object *value);

#endif //PROJECT_C_API_H
