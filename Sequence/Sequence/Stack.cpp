//
//  Stack.cpp
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 8/10/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#include "Stack.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void StackNew(stack *s, int elemSize)
{
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->lrglenght = 0;
    s->allocLength = 4;
    s->elems = malloc(s->allocLength * s->elemSize);
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{   // just for the moment
    free(s->elems);
}

// static marks the func private and accessable only in this file
static void StackGrow(stack *s)
{
    s->allocLength *= 2;
    s->elems = realloc(s->elems, s->allocLength * s->elemSize);
}

void StackPush(stack *s, void *elemAddress)
{
    if (s->lrglenght == s->allocLength) {
        StackGrow(s);
    }
    void *target = (char *)s->elems + s->lrglenght * s->elemSize;
    memcpy(target, elemAddress, s->elemSize);
    s->lrglenght++;
}

void StackPop(stack *s, void *elemAddress)
{
    s->lrglenght--;
    void *source = (char *)s->elems + s->lrglenght * s->elemSize;
    memcpy(elemAddress, source, s->elemSize);
}
