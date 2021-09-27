#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
ll getPri(ll n) {
    for (ll i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return i;
    }
    return n;
}
int main() {
    ll n;
    cin >> n;
    cout << n << "=";
    if(n<2) {
        cout << n << endl;
    }
    else {
        map<ll, int> mp;
        while (n > 1) {
            ll tmp = getPri(n);
            mp[tmp]++;
            n /= tmp;
    //         cout << n << " " << tmp << endl;
        }
        auto it = mp.begin();
        while(it != mp.end()) {
            cout << it->first;
            if (it->second > 1) cout << "^" << it->second;
            it++;
            cout << "*\n"[it == mp.end()];
        }
    }
    
}