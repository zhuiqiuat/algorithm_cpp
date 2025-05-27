/*

    非降序冒泡排序
    用法: 输入一个数代表数组长度 接下来输入数组中的数据

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void bubbleSort(ll arr[],int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = 1;j < n - i;j++){
            if(arr[j - 1] > arr[j]){
                ll tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    bubbleSort(arr,n);
    for(int i = 0;i < n;i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    return 0;
}