/*

    非降序插入排序
    用法: 输入一个数代表数组长度 接下来输入数组中的数据

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void insertionSort(ll arr[],int n){
    for(int i = 1;i < n;i++){
        ll tmp = arr[i];
        int now = i - 1;
        while(arr[now] > tmp && now >= 0){
            arr[now + 1] = arr[now];
            now--;
        }
        arr[now + 1] = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    insertionSort(arr,n);
    for(int i = 0;i < n;i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    return 0;
}