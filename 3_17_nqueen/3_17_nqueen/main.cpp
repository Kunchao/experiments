//
//  main.cpp
//  3_17_nqueen
//
//  Created by 坤超 on 2018/3/9.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100
int w[maxn];
void queen(int a[], int i){
    int j,k,conflict;
    if(i == 9){//i为列
        for(j = 0; j<8 ; j++){
            cout<< j << "row, "<< a[j] << "column" <<endl;
        }
        return ;
    }
    for(j = 0;j<8 ;j++){ //第j行
        conflict = 0;
        for( k = 0; k<i ; k++){//遍历之前的皇后
            if( j== a[k] || abs(i-k) == abs(j-a[k]))conflict = 1;
        }
        if(!conflict){
            a[i] = j;
            queen(a,i+1);
        }
    }
}

int knap(int s, int n){
    if(s==0) return 0;
    if(s<0||(s>0&&n<0)) return 0;
    if(knap(s-w[n-1], n-1)){
        cout<<"result:"<<n<<"w["<<n-1<<"]="<<w[n-1]<<endl;
        return 1;
    }else return knap(s,n-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
