//
//  main.cpp
//  3_28_locate
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

typedef struct node{
    datatype data;
    datatype freq;
    struct node *llink, *rlink;
}lnode, *linklist;

void init(linklist l){
    l =(linklist)malloc(sizeof(lnode));
    l->rlink = NULL;
    l->llink = NULL;
}

//linklist getElemt(linklist l, int x)

linklist linkbuild( int n){
    linklist l,p,s;
    int x;
    //init(l);
    l = (linklist)malloc(sizeof(lnode));
    l->rlink = NULL;
    l->llink = NULL;
    p=l;
    
    
    for(int i=0; i<n; i++){
        cin>>x;
        s = (linklist)malloc(sizeof(lnode));
        s->data = x;
        p->rlink = s;
        s->llink = p;
        p = s;
    }
    p->rlink = l->rlink;
    l->rlink->llink = p;
    return p;
}

linklist locate(linklist l, datatype x){
    linklist p,s,end;
    end = l;
    p = l->rlink;
    while(p->data!=x && p){
        p=p->rlink;
    }
    if(!p){
        cout<<" not exsist !"<<endl;
        exit(0);
    }else{
        p->freq++;
        
        p->rlink->llink = p->llink;
        p->llink->rlink = p->rlink;
        s = p->llink;
        while(s!=end&&p->freq > s->freq){
            s = s->llink;
        }
        p->rlink = s->rlink;
        s->rlink->llink = p;
        p->llink = s;
        s->rlink = p;
    }
    return l;
}

void lprint(linklist l){
    linklist p = l->rlink;
    while(p!=l){
        cout<<p->data<<" ";
        p=p->rlink;
    }
    cout<<p->data;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    linklist l = nullptr;
    int n = 0;
    cin>>n;
    //init(l);
    l = linkbuild(n);
    int x = 0;
    cin>>x;
    locate(l,x);
    lprint(l);
    return 0;
}
