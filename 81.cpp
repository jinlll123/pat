#include<iostream>
#include<vector>
#include<string>
#include<map>
#define ll long long
using namespace std;
ll getminc(vector<ll>& dv) {
    map<int, int> mp;
    for (int t : dv) {
        map<int, int> tmp;
        while (t > 1) {
            int i = 2;
            for (; i * i <= t; ++i) {
                if (t % i == 0) {
                    tmp[i]++;
                    t /= i;
                    break;
                }
            }
            if (i * i > t) {
                tmp[t]++;
                break;
            }
        }
        for (auto it : tmp) {
            if (mp[it.first] < it.second) mp[it.first] = it.second;
        }
    }
    ll res = 1;
    for (auto it : mp) {
        //         cout << it.first << " " << it.second << endl;
        for (int i = 0; i < it.second; ++i) res *= it.first;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    string s;
    vector<ll> nv;
    vector<ll> dv;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int j = 0;
        while (s[j++] != '/');
        --j;
        nv.push_back(stoll(s.substr(0, j).c_str()));
        dv.push_back(stoll(s.substr(j + 1).c_str()));
    }
    ll t = getminc(dv);
    ll num = 0;
    //     cout << t << endl;
    for (int i = 0; i < n; ++i) {
        num += (nv[i] * (t / dv[i]));
    }
    /*for (int i = 0; i < n; ++i) {
        num += nv[i];
    }*/
//     cout << num << endl;
    if (num < 0) {
        cout << '-';
        num = -num;
    }
    ll a = num / t, b = num % t;
    if(a==0 && b==0) cout << "0";
    else {
        if(a!=0) cout << a;
        if (b != 0) {
            if(a!=0) cout << " ";
            while (true) {
    //             cout << "ab= " << b << " " << t << endl;
                ll i = 2;
                for (; i < t; ++i) {
                    if (b % i == 0 && t % i == 0) {
                        b /= i;
                        t /= i;
                        break;
                    }
                }
    //             cout << "i= " << i << endl;
                if (i >= t) break;
            }
            cout << b << "/" << t;
        }
    }
    
    cout << endl;
}