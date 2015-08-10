//
//  main.cpp
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 6/27/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "Sequence.h"
#include "Stack.h"
#include "Set.h"
#include <time.h>

using namespace std;


// bit pattern swaping
//void swap(int *f, int *second)
//{
//    int temp = *f;
//    *f = *second;
//    *second = temp;
//    
//    cout <<"aac:"<< f << endl;
//}

//generic swap func
void swapp(void *pi1,
          void *pi2,
          int size)
{
    char buffer[size];
    memcpy(buffer, pi1, size);
    memcpy(pi1, pi2, size);
    memcpy(pi2, buffer, size);
}

int main(){
//    stack s;
//    StackNew(&s, sizeof(int));
//    clock_t begin, end1;
//    double time_spent;
//    
//    begin = clock();
//    /* here, do your time-consuming job */
    
//    cout << s.elemSize << " " << s.allocLength;
    
//    int start = 1;
//    int end = 1000000;
//    for (int i = start; i < end; i++) {
//        StackPush(&s, &i);
//    }
//    
//    int tmp = 0;
//
//    for (int i = start; i < end; i++) {
//        StackPop(&s, &tmp);
//        printf(" %d",tmp);
//    }
    
//    int start = 1000000;
//    int end = 0;
//    for (int i = start; i >= end; i--) {
//        StackPush(&s, &i);
//    }
//    
//    int tmp = 0;
//    
//    for (int i = start; i >= end; i--) {
//        StackPop(&s, &tmp);
//        printf(" %d",tmp);
//    }
//    
//    StackDispose(&s);
//    
//    end1 = clock();
//    time_spent = (double)(end1 - begin) / CLOCKS_PER_SEC;
//    
//    cout << "\n\n" << time_spent ;
    
    
    stack ch;
    StackNew(&ch, sizeof(char *));
    
        const char *names[] = {"AL","Bob","Peggi","jony"};
        
        for (int i = 0; i < 4; i++) {
            char *copy = strdup(names[i]);
            StackPush(&ch, &copy);
        }
        
        char *name;
        for (int i = 0; i < 4; i++) {
            StackPop(&ch, &name);
            cout << name << endl;
            free(name);
        }
    
    StackDispose(&ch);

    
//    int x = 7;
//    int y = 9;
//    
//    swapp(&x, &y, sizeof(int));
//    
//    cout << "x:" << x << ", y:" << y << endl;
    
    
//    char *wife = strdup("Wilma");
//    char *husband = strdup("Fred");
//    
//    swapp(&wife, &husband, sizeof(char *));
//    
//    cout << "wife:" << wife << ", husband:" << husband << endl;
    
//                    //    1  2  3  4  5  6  7  8  9  10 11 12 13 14
//    int mSet []        = {1 ,2 ,3 ,4 ,3 ,3 ,7 ,3 ,3 ,3 ,5 ,5 ,10,11};
//    int anotherMSet [] = {99,12,33,4 ,5 ,1 ,23,3 ,3 ,11,23};
//    int anotherMSet1[] = {12,13,14,15,16,17,18,19,20};
//    
//    Set n(mSet,14),a(anotherMSet,11),b(anotherMSet1,9);
//
//    b.print();
//    cout << endl;
//    
//    n.removeObject(0);
//    
//    cout << n << endl;
//    cout << endl;
//    n = n-b;
//    cout << n << endl;
 
    
//    struct fraction
//    {
//        int num;
//        int denum;
//    };
//    
//    fraction pi;
//    pi.num = 22;
//    pi.denum = 7;
//    
//    cout << (((fraction *)&(pi.denum))->num = 12) << endl;
//    cout << (((fraction *)&(pi.denum))->denum = 44) << endl;
//
//    cout << pi.num;

// array no bounds checking exaple!!!
     
    return 0;
}























