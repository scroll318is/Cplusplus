//
//  Set.h
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 8/10/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#ifndef __Sequence__Set__
#define __Sequence__Set__

#include <iostream>
using namespace std;

class Set {
    int *set;
    int n;
public:
    
    Set ();
    Set (int SET[], unsigned N);
    Set(const Set &obj);
   
    const Set &operator=(const Set &obj);
    Set operator-(const Set& obj);
    
    void addObject(int o);
    void removeObject(int o);
    void addObjects(int arr[], int N);
    void sortSet();
    bool contains(int x);
   
    void print(int arr[],int N);
    void print();
   
    int binary_search1(int array[],int first,int last, int search_key);
    
    ostream& ios(ostream& os)const;
    
    ~Set();
};

ostream& operator<<(ostream& os, const Set& set);


#endif /* defined(__Sequence__Set__) */
