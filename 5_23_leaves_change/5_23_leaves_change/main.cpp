//
//  main.cpp
//  5_23_leaves_change
//
//  Created by 坤超 on 2018/3/11.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
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

int leaves(bintree t){
    if(t == NULL) return 0;
    if(t->lchild == NULL && t->rchild == NULL) return 1;
    else return leaves(t->lchild)+leaves(t->rchild);
}

void exchange(bintree t){
    bintree temp;
    if(t->lchild != NULL || t->rchild != NULL){
        temp = t-> lchild;
        t->lchild = t->rchild;
        t->rchild = temp;
        exchange(t->lchild);
        exchange(t->rchild);
    }
}

void print(bintree t){
    if(t != NULL) {
        cout<< t->data;
        print(t->lchild);
        print(t->rchild);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    bintree t;
    t = creattree();
    print(t);
    cout<< "leaves:"<<leaves(t)<<endl;
    exchange(t);
    print(t);
    cout<< "leaves:"<<leaves(t)<<endl;
    return 0;
}
