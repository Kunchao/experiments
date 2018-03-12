//
//  main.cpp
//  5_25_preorder
//
//  Created by 坤超 on 2018/3/11.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

typedef char datatype;

typedef struct node {
    datatype data;
    struct node *lchild, *rchild;
}binnode, *bintree;

bintree creattree(){
    bintree t;
    char c;
    c = getchar();
    if(c == '#') return NULL;
    else{
        t = (bintree)malloc(sizeof(binnode));
        t ->data = c;
        t-> lchild = creattree();
        t-> rchild = creattree();
    }
    return t;
}

void preorder(bintree t){
    if(t != NULL){
        cout<<t->data;
        preorder(t->lchild);
        t = t->rchild;
    }
}

void pre(bintree t){
    stack<bintree> s;
    bintree p;
    s.push(t);
    while(!s.empty()){
        p=s.top();
        cout<<p->data;
        s.pop();
        if(p->rchild != NULL) s.push(t->rchild);
        if(p->lchild != NULL) s.push(p->lchild);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    bintree t;
    t = creattree();
    //preorder(t);
    cout<<"--------"<<endl;
    pre(t);
    return 0;
}
