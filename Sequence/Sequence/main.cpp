//
//  main.cpp
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 6/27/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "Sequence.h"
#include "Stack.h"
#include "Set.h"
#include <pthread.h>
#include <time.h>
#include <vector>


#define MAX(a,b) \
(a) > (b) ? (a) : (b)

int kthGreatestValue(vector<int> arr, int k);
int *merge(int a[],int b[],int a1, int b1);

struct Locale{
    Locale(long parmX){ this->parmX = parmX; }
    
    bool operator () (long &i,long &j)
    {
        long ri = i % parmX;
        long rj = j % parmX;
        
        if(ri > rj)return true;
        if(ri == rj)return i > j;
        else return false;
    }
    
    long parmX;
};

using std::cout;
using std::endl;


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

class Count {
public:
    Count(int a = 0):a(a)
    {   cout << "Construct" << endl;
        instancesAlive++;
        print();
    }
    inline void print()
    {
        cout << instancesAlive << endl;
    }
    ~Count()
    {   cout << "Destruct" << endl;
        instancesAlive--;
        print();
    }
private:
    int a;
    static int instancesAlive;
};

int Count::instancesAlive = 0;

void declareAndInitArray()
{
    int arr[100];
    int i;
    for (i=0;i<100;i++) {
        arr[i] = i;
    }
}

void printArray()
{
    int arr[100];
    int i;
    for (i=0;i<100;i++) {
        printf("%d\n",arr[i]);
    }
}

void initPrintArray()
{
    declareAndInitArray();
    printArray();
}


// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
    // Store the value argument passed to this thread
    long long myid = reinterpret_cast<long long> (vargp);
    int sig = static_cast<int>(myid);
    
    // Let us create a static variable to observe its changes
    static int s = 0;
    
    // Change static and global variables
    ++s; ++g;
    
    int rand = lrand48() % 10 + 1;
    
    //if (myid % 2 == 0) {
        sleep(rand);
   // }
    // Print the argument, static and global variables
    printf("Thread ID: %d, Static: %d, Global: %d\n", sig, ++s, ++g);
    return (void*)0;
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
    
    
//    stack ch;
//    StackNew(&ch, sizeof(char *));
//    
//        const char *names[] = {"AL","Bob","Peggi","jony"};
//        
//        for (int i = 0; i < 4; i++) {
//            char *copy = strdup(names[i]);
//            StackPush(&ch, &copy);
//        }
//        
//        char *name;
//        for (int i = 0; i < 4; i++) {
//            StackPop(&ch, &name);
//            cout << name << endl;
//            free(name);
//        }
//    
//    StackDispose(&ch);

    
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

//    int a = 11;
//    int b = 7;
//    
//    int & c = a;
//    int * d = &a;
//    
//    *d = 60;
//    c = 70;
//    
//    c = b;
//    
//    cout << &a << endl;
//    cout << &b << endl;
//    cout << &c << endl;
//    
   // Count arr[100];
    
    
//    printf("adwad");
    
// memmory footprint example
//    initPrintArray();
    
// printf placeholders example
//    int n1 = printf("Hellomm\n");
//    int n2 = printf("%d\n",n1);
//    int n3 = printf("%d %d\n",n1,n2);
//    printf("%d %d %d\n",n1,n2,n3);
    
    
// thread example
//    int i;
//    pthread_t tid;
//    
//    // Let us create three threads
//    for (i = 0; i < 50; i++)
//        pthread_create(&tid, NULL, myThreadFun, reinterpret_cast<void*>(i));
//    
//    pthread_exit(NULL);
    
    
// k-th great value
//    vector<int>arr = {2 ,3 , 4,10,12,15,17, 18, 18,19};
//    vector<int>arr1= {20,16,15,15,14,13,12,-10,-15};
//
//    
//    for (int k=0; k<arr1.size(); k++) {
//        int result = kthGreatestValue(arr1, k);
//        
//        if (result != -INT32_MAX) {
//            cout << k+1 << ":" << result << endl;
//        }
//    }
    
// merge example
//    
//    int arr[]  = {2 ,3 , 4,10,12,15,17, 18, 18, 19};
//    int arr1[] = {-1,16,15,15,14,13,12,-10,-15,-20,-25,-44,0,15,21};
//    sort(arr1, arr1 + 15);
//    int *ptr = merge(arr,arr1,10,15);
//    
//    for (int i = 0 ; i < 25; i++) {
//        cout << ptr[i] << endl;
//    }
//    free(ptr);
    
// the rest of x sorting problem
//    long arr[] = {1,2,3,4,5,6,7,8,9};
//    long n = 9;
//    long x = 4;
  
//    long arr1[] = {2, 55, 100, 293, 1, 2, 9, 1337, 233, 11};
//
//    long n1 = 10;
//    long x1 = 1;
//    long arr1[] = {4000000000};
//    long x = 3999999999;
//    long n = 1;
//    sort(arr1, arr1+n, Locale(x));
//    
//    for (int i = 0 ; i < n; i++) {
//        cout << arr1[i] << endl;
//    }
    

    
    return 0;
}

int *merge(int a[],int b[],int a1, int b1)
{
    const int size = a1+b1;
    int *c = (int*)malloc(size * sizeof(int));
    
    int i=0,j=0,k=0;
    
    for (; i < size; i++) {
        if (j<a1 && k<b1) {
            if (a[j] <= b[k]) {
                c[i] = a[j++];
            } else {
                c[i] = b[k++];
            }
        } else if (j == a1) {
            c[i] = b[k++];
        } else {
            c[i] = a[j++];
        }
    }
    
    return c;
}

int kthGreatestValue(vector<int> arr, int k)
{   int tmp = -INT32_MAX;
    if (arr.size() == 0 || k > arr.size()-1) {
        return tmp;
    }
    if (arr[0] >= arr[arr.size()-1]) {
        tmp = arr[0];
        for (int i=0;i<arr.size();i++) {
            if (tmp > arr[i]) {
                tmp = arr[i];
                k--;
            }
            if (k == 0) {
                return tmp;
            }
        }
    } else {
        tmp = arr[arr.size()-1];
        for (int i = (int)arr.size()-1;i>=0;i--) {
            if (tmp > arr[i]) {
                tmp = arr[i];
                k--;
            }
            if (k == 0) {
                return tmp;
            }
        }
    }
    if (k > 0) {
        return -INT32_MAX;
    }
    return tmp;
}


















