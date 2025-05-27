/*

    迭代版本非降序归并排序
    用法: 输入一个数代表数组长度 接下来输入数组中的数据

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll MAX = 1e5 + 50;

ll help[MAX] = {0};

void merge(ll arr[],int start,int mid,int end){
    int i = start;
    int a = start;
    int b = mid + 1;
    while (a <= mid && b <= end)
    {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= mid)
    {
        help[i++] = arr[a++];
    }
    while (b <= end)
    {
        help[i++] = arr[b++];
    }
    while(start <= end){
        arr[start++] = help[start];
    }
}

void mergeSort(ll arr[],int n){
    for(int a = 1;a <= n;a <<= 1){
        int l = 0;
        while(l < n){
            int m = l + a;
            if(m >= n) break;
            int r = min(m + a - 1,n - 1);
            merge(arr,l,m - 1,r);
            l = r + 1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i = 0;i < n;i++) cin >> arr[i];
    mergeSort(arr,n);
    for(int i = 0;i < n;i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    return 0;
}