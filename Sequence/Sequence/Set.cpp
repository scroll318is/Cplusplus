//
//  Set.cpp
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 8/10/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#include "Set.h"
#include <algorithm>
#include <iostream>

using namespace std;
    
Set::Set () {
    this->set = new int[0];
    this->n = 0;
}
    
Set::Set (int SET[], unsigned N):set(NULL),n(0){
    this->set = new int[N];
    sort(SET, SET+N);
    for (int i=0,c=0;c<N;c++) {
        if (!contains(SET[c])) {
            this->set[i] = SET[c];
            this->n++;
            i++;
        }
    }
}
    
Set::Set(const Set &obj) {
    cout << "Set - Copy Const" << endl;
    this->set = new int[obj.n+1];
    this->n = obj.n;
    memcpy(this->set, obj.set, sizeof(int) * this->n);
}
    
const Set& Set::operator=(const Set &obj) {
    cout << "Set - copy asigment" << endl;
    if (this != &obj) {
        this->set = new int[obj.n+1];
        this->n = obj.n;
        memcpy(this->set, obj.set, sizeof(int) * this->n);
    }
    return *this;
}

Set Set::operator-(const Set& obj) {
        Set newSet1 = *this;
        
        for (int i=0; i < this->n; i++) {
            if (newSet1.contains(obj.set[i]) ) {
                newSet1.removeObject(obj.set[i]);
            }
        }
        
        return newSet1;
    }
    
    
void Set::addObject(int o) {
    if (!contains(o)){
        int c = this->n+1;
        int *temp = new int [c];
        memcpy(temp, this->set, sizeof(int) * c-1);
        temp[c-1] = o;
        this->set = temp;
        this->n = c;
        sortSet();
    }
}
    
void Set::removeObject(int o) {
    int index = binary_search1(this->set, 0, this->n, o);
    if (index != -1) {
        int c = this->n-1;
        int *temp = new int [c];
        
        for (int i=0; i<index; i++) {
            temp[i] = this->set[i];
        }
        
        for (int i = index,co=index+1; co<n; i++,co++) {
            temp[i] = this->set[co];
        }
        this->set = temp;
        this->n = c;
    }
}
    
void Set::addObjects(int arr[], int N){
    for (int i=0; i<N; i++) {
        addObject(arr[i]);
    }
}
    
void Set::sortSet() {
    sort(this->set, this->set+n);
}
    
bool Set::contains(int x){
    return binary_search(set, set+n, x);
}

void Set::print(int arr[],int N) {
    cout << N << endl;
    for (int i=0; i<N; i++) {
        cout << arr[i] << endl;
    }
}

void Set::print() {
    cout << n << endl;
    for (int i=0; i<n; i++) {
        cout << set[i] << endl;
    }
}

int Set::binary_search1(int array[],int first,int last, int search_key) {
    int index;
    
    if (first > last)
        index = -1;
    
    else
    {
        int mid = (first + last)/2;
        
        if (search_key == array[mid])
            index = mid;
        else
            
            if (search_key < array[mid])
                index = binary_search1(array,first, mid-1, search_key);
            else
                index = binary_search1(array, mid+1, last, search_key);
        
    }
    return index;
}

ostream& Set::ios(ostream& os)const {
    os << n << endl;
    for (int i=0; i<n; i++) {
        os << set[i] << endl;
    }
    return os;
}

Set::~Set(){
    if (this->set)
        delete [] set;
}

ostream& operator<<(ostream& os, const Set& set)
{
    return set.ios(os);
}
