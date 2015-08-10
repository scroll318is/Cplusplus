//
//  Sequence.h
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 6/28/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#ifndef Sequence_Sequence_h
#define Sequence_Sequence_h

#include <iostream>
#include <cmath>
using namespace std;
class Sequense {
    int x;
public:
    Sequense(int x);
    double operator()(int n);
    double operator[](int n);
    int fact(int n);
    ostream& ios(ostream& os)const;
    
};

ostream& operator<<(ostream& os, const Sequense& obj);

#endif
