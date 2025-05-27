/*

    并查集模板 已实现对应函数

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int dsu[N];
int dsusize[N];

void build(int n){
    for(int i  = 1;i <= n;i++){
        dsu[i] = i;
        dsusize[i] = 1;
    }
}

int find(int x){
    queue<int> q;
    while(dsu[x] != x){
        q.push(x);
        x = dsu[x];
    }
    while(!q.empty()){
        dsu[q.front()] = x;
        q.pop();
    }
    return x;
}

void uni(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb){
        dsu[fa] = fb;
        dsusize[fb] += dsusize[fa];
    }
}

bool isSame(int a,int b){
    return find(a) == find(b);
}