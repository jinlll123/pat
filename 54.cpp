#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int m, n, t;
    cin >> m >> n;
    map<int, int> mp;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> t;
            mp[t]++;
        }
    }
    int res, mx=0;
    for(auto it:mp) {
        if(it.second > mx) {
            res = it.first;
            mx = it.second;
        }
    }
    cout << res << endl;
}