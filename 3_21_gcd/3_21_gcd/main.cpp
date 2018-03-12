//
//  main.cpp
//  3_21_gcd
//
//  Created by 坤超 on 2018/3/9.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100

int gcd(int a, int b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    cin>>a>>b;
    int x = gcd(a,b);
    cout<< x;
    return 0;
}
