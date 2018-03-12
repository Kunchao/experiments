//
//  main.cpp
//  4_12_saddle
//
//  Created by 坤超 on 2018/3/10.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100
int a[maxn][maxn];

void saddle(int a[][maxn], int m, int n){
    int i, j, k , found ,min;
    for(i = 0; i<m; i++){
        min = 0;
        for(j = 0; j<n; j++){
            if(a[i][j]<a[i][min]) min = j;
        }
        found = 1;
        for( k =0; k<m; k++){
            if(a[i][min]<a[k][min]) found = 0;
        }
        if(found == 1){
            cout << a[i][j]<<endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[maxn][maxn], m,n;
    cout<<"enter m,n";
    cin>>m>>n;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }
    saddle(a,m,n);
    return 0;
}
