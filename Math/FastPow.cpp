/*

    快速幂带取模
    用法: 输入三个数 分别代表数 次方 取模数(填0不取模)

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fastpow(ll a,ll b,ll mod){
    ll ans = 1;
    if(mod != 0) a %= mod;
    while(b > 0){
        if(b & 1){
            ans *= a;
            if(mod != 0) ans %= mod;
        }
        b >>= 1;
        a *= a;
        if(mod != 0) a %= mod;
    }
    return ans;
}

int main(){
    ll a,b,mod;
    cin >> a >> b >> mod;
    cout << fastpow(a,b,mod);
    return 0;
}