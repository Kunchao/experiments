//
//  main.cpp
//  4_14_replace
//
//  Created by 坤超 on 2018/3/10.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define maxn 100

void replace(string a, string t, string v){
    int ad, k=0, len ,post=0;
    len = t.length();
    ad = int(a.find(t,0));
    if( ad == -1){
        cout<< "the operation failed!"<<endl;
        exit(0);
    }
    string temp1;
    post=ad;
    while(ad != -1){
        for(int i=post+len; i<ad; i++){
            temp1+= a[i];
        }
        post = ad;
        temp1 += v;
        k++;
        ad = int(a.find(t,ad+len));
    }
    for(int i = post+len; i<a.length();i++){
        temp1+= a[i];
    }

    cout<<temp1<<endl;
    cout<<"the times:"<<k<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string str,v,t;
    cin>> str >> v>> t;
    replace(str, v, t);
    return 0;
}
