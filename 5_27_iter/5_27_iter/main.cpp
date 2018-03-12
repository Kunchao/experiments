//
//  main.cpp
//  5_27_iter
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
int max;
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

int degree_1(bintree t){
    if(t == NULL) return 0;
    if((t->lchild != NULL && t->rchild == NULL) || (t->lchild ==NULL && t->rchild != NULL))
        return 1+degree_1(t->lchild)+degree_1(t->rchild);
    else return degree_1(t->lchild)+degree_1(t->rchild);
}

int degree_2(bintree t){
    if(t ==NULL) return 0;
    if(t->lchild != NULL && t->rchild != NULL)
        return 1+degree_2(t->lchild)+degree_2(t->rchild);
    else return degree_2(t->lchild)+degree_2(t->rchild);
}

void levelcount(bintree t, int a[], int h){
    if(t!= NULL){
        a[h] = a[h]+1;
        levelcount(t->lchild, a, h+1);
        levelcount(t->rchild, a, h+1);
    }
}

int width(bintree t){
    int a[16], i, width;
    memset(a, 0, sizeof(a));
    levelcount(t, a, 1);
    width = a[0];
    for(i = 1; i<16; i++){
        if(a[i]>width) width = a[i];
    }
    return width;
}

void delete_b(bintree t){
    if(t == NULL) return ;
    if(t->lchild == NULL && t->rchild == NULL){
        delete t; t = NULL;
    }else{
        delete_b(t->lchild);
        delete_b(t->rchild);
    }
}

int level(bintree t, bintree p){
    if(t == NULL) return 0;
    if(t == p) return 1;
    int sub = level(t->lchild, p);
    if(sub > 0){
        return sub+1;
    }else{
        return level(t->rchild, p);
    }
}

void max_value(bintree t, int *max){
    if(t!=NULL){
        if(t->data-'0' >*max) *max = t->data-'0';
        max_value(t->lchild, max);
        max_value(t->rchild, max);
    }
}

void nodeprint(bintree t, int i){
    if(t != NULL){
        cout<<t->data<<","<<i<<endl;
        nodeprint(t->lchild, i+1);
        nodeprint(t->rchild, i+1);
    }
}

int height(bintree t){
    if(t==NULL) return 0;
    int lh = height(t->lchild);
    int rh = height(t->rchild);
    return lh>rh?lh+1:rh+1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    bintree t;
    t = creattree();
    int max = 0,*m;
    m=&max;
    cout<<"-----height-----"<<endl;
    cout<<height(t)<<endl;
    cout<<"------degree_1-------"<<endl;
    cout<<degree_1(t)<<endl;
    cout<<"------degree_2-------"<<endl;
    cout<<degree_2(t)<<endl;
    cout<<"------width---------"<<endl;
    cout<<width(t)<<endl;
    cout<<"-------max_value------"<<endl;
    cout<<max<<endl;
    max_value(t, m);
    cout<<max<<endl;
    return 0;
}

