//
//  Stack.h
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 8/10/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#ifndef __Sequence__Stack__
#define __Sequence__Stack__

#include <stdio.h>
// generic stack
typedef struct{
    void *elems;
    int elemSize;
    int lrglenght;
    int allocLength;
    // one more
} stack;

void StackNew(stack *s, int elemSize);
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAddress);
void StackPop(stack *s, void *elemAddress);

#endif /* defined(__Sequence__Stack__) */
