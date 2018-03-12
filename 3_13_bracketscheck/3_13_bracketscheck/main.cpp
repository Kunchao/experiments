//
//  main.cpp
//  3_13_bracketscheck
//
//  Created by 坤超 on 2018/3/9.
//  Copyright © 2018年 坤超. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100
typedef char datatype;

typedef struct stack{
    datatype data[maxn];
    int top;
}seqstack;

void init(seqstack &s){
    s.top = -1;
}

void push(seqstack &s, datatype x){
    if(s.top == maxn-1){
        cout<<"overflow!"<<endl;
        exit(0);
    }
    s.data[++s.top] = x;
}

char pop(seqstack &s){
    if(s.top == -1){
        cout<<"no elemt!"<<endl;
        exit(0);
    }
    datatype x = s.data[s.top--];
    return x;
}

void print(seqstack s){
    for(int i = 0; i<=s.top ; i++){
        cout<< s.data[i];
    }
}

bool isempty(seqstack s){
    return (s.top==-1)?true:false;
}

bool bracketscheck(char *str){
    seqstack s;
    init(s);
    int i = 0;
    char x;
    while(str[i] != '\0'){
        switch(str[i]){
            case '(': push(s , '('); break;
            case '[': push(s, '[');break;
            case '{': push(s, '{');break;
            case ')': x = pop(s);
                if(x!='(') return false;break;
            case ']': x= pop(s);
                if(x != '[') return false;break;
            case '}': x= pop(s);
                if(x != '{') return false;break;
            default: break;
                
        }
        i++;
    }
    print(s);
    if(!isempty(s)){
        cout<<"sorry failed!"<<endl;
        return false;
    }else{
        cout<<"you are right!"<<endl;
        return true;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[maxn];
    cin>>str;
    bracketscheck(str);
    return 0;
}
