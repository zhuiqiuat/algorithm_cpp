/*

    非降序选择排序
    用法: 输入一个数代表数组长度 接下来输入数组中的数据

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void selectionsort(ll arr[],int n){
    for(int i = 0;i < n - 1;i++){
        int min = i;
        for(int j = i + 1;j < n;j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        ll tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

int main(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    selectionsort(arr,n);
    for(int i = 0;i < n;i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    return 0;
}