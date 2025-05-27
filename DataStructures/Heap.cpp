/*

    手写堆 已实现对应函数

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;

int priorityqueue[N] = {0};
int mysize = 0;

void up(int ind){
    int fa = (ind - 1) / 2;
    while(priorityqueue[fa] < priorityqueue[ind]){
        priorityqueue[fa] ^= priorityqueue[ind];
        priorityqueue[ind] ^= priorityqueue[fa];
        priorityqueue[fa] ^= priorityqueue[ind];
        ind = fa;
        fa = (ind - 1) / 2;
    }
}

void down(int ind){
    int l = ind * 2 + 1;
    int r = ind * 2 + 2;
    while(l < mysize){
        int maxind = r < mysize && priorityqueue[r] > priorityqueue[l] ? r : l;
        if(priorityqueue[maxind] < priorityqueue[ind]) break;
        priorityqueue[maxind] ^= priorityqueue[ind];
        priorityqueue[ind] ^= priorityqueue[maxind];
        priorityqueue[maxind] ^= priorityqueue[ind];
        ind = maxind;
        l = ind * 2 + 1;
        r = ind * 2 + 2;
    }
}

void push(int x){
    priorityqueue[mysize] = x;
    up(mysize++);
}

bool isempty(){
    return mysize == 0;
}

int pop(){
    int ans = priorityqueue[0];
    mysize--;
    priorityqueue[0] ^= priorityqueue[mysize];
    priorityqueue[mysize] ^= priorityqueue[0];
    priorityqueue[0] ^= priorityqueue[mysize];
    down(0);
    return ans;
}

int top(){
    return priorityqueue[0];
}

int size(){
    return mysize;
}