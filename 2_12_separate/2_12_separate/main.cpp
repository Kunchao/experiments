//
//  main.cpp
//  2_12_separate
//
//  Created by 坤超 on 2018/3/8.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100

typedef int datatype;

typedef struct node {
    datatype data;
    struct node *next;
}lnode, *linklist;

linklist linit(){
    linklist l;
    l = (linklist)malloc(sizeof(lnode));
    if(l == NULL){
        cout<<"memory not enough !";
        exit(0);
    }
    l->next = NULL;
    return l;
}

linklist linkbuild(int n){
    int x;
    linklist l,p;
    l = (linklist)malloc(sizeof(lnode));
    l->next = NULL;
    for(int i =0; i<n; i++){
        cin>>x;
        p = (linklist)malloc(sizeof(lnode));
        p->data = x;
        p->next = l->next;
        l->next = p;
    }
    return l;
}

void seprate(linklist hl, linklist l1, linklist l2){
    linklist p,r;
    //p = (linklist)malloc(sizeof(lnode));
    p = hl->next;
    while(p){
        r = (linklist)malloc(sizeof(lnode));
        r->next = NULL;
        r->data = p->data;
        if(p->data%2 == 0){
            l1->next = r;
            l1=r;
        }else{
            l2->next = r;
            l2 = r;
        }
        p = p->next;
    }
}

void lprint(linklist l){
    linklist p;
    p= l->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    linklist l, p, q;
    int n=0;
    cin>>n;
    l = linit();
    p = linit();
    q = linit();
    l = linkbuild(n);
    seprate(l,p,q);
    lprint(p);
    lprint(q);
    return 0;
}
