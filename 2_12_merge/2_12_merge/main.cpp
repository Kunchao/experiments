//
//  main.cpp
//  2_12_merge
//
//  Created by 坤超 on 2018/3/8.
//  Copyright © 2018年 坤超. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100
typedef int DataType;

typedef struct{
    DataType data[maxn];
    int length;
}seqlist;

void init(seqlist *l){
    (*l).length = 0;
}
seqlist insert(seqlist l, int i , int x){
    if(l.length == maxn){
        printf("error happened");
        exit(0);
    }
    if(i<0||i>l.length+1){
        printf("position error");
        exit(0);
    }
    for(int j = l.length-1; j>= i-1 ; j--){
        l.data[j+1] = l.data[j];
    }
    l.data[i-1] = x;
    l.length++;
    return l;
}

seqlist merge(seqlist l, seqlist a, seqlist b){
    if(a.length + b.length >maxn){
        cout<< " error happend too big";
    }
    int k = 0, j = 0,i = 0;
    while(i<a.length && j<b.length){
        if(a.data[i]<b.data[j]){
            l.data[k++] = a.data[i++];
        }
        else{
            l.data[k++] = b.data[j++];
        }
    }
    while(i<a.length){
        l.data[k++] = a.data[i++];
    }
    while(j<b.length){
        l.data[k++] = b.data[j++];
    }
    l.length = k;
    return l;
}
void print(seqlist l){
    int n = l.length;
    for(int i =0; i<n ; i++){
        cout<<l.data[i]<<" ";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    seqlist a,b;
    init(&a);
    init(&b);
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0;i<m; i++){
        int x;
        cin>>x;
        a = insert(a, i+1, x);
    }
    for(int i = 0;i<n; i++){
        int x;
        cin>>x;
        b = insert(b, i+1, x);
    }
    //print(a);
    //print(b);
    seqlist l ;
    init(&l);
    l = merge(l, a, b);
    print(l);
    //a.data = {1,3,5,7,9};
    //b.data = {2,4,6,8};
    
    return 0;
}
