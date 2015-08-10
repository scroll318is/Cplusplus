//
//  Sequence.cpp
//  Sequence
//
//  Created by Stoyan Yordanov Kostov on 8/10/15.
//  Copyright (c) 2015 com.kostov. All rights reserved.
//

#include "Sequence.h"

Sequense::Sequense(int x) :x(x){}

double Sequense::operator()(int n){
    double sum = 1 + x, temp =0;
    for (int i = 1; i < n; i++){
        temp = fact(i) + pow(x, i+1);
        sum /= temp;
    }
    return sum;
}

double Sequense::operator[](int n) {
    return pow(x, n)/fact(n);
}

int Sequense::fact(int n) {
    int sum = 1;
    for (int i = 1; i <= n; i++){
        sum = sum * i;
    }
    return sum;
}

ostream& Sequense::ios(ostream& os)const {
    return os << x << endl;
}

ostream& operator<<(ostream& os, const Sequense& obj) {
    return obj.ios(os);
}
