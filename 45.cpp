#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
    int n, m, l, res = 0, k;
    cin >> n >> m;
    vector<int> seq(m+1, 0);
    map<int, int> mp;
    for(int i=1; i<=m; ++i) {
        cin >> k;
        mp[k] = i;
    }
    cin >> l;
    for(int i=0; i<l; ++i) {
        cin >> k;
        int t = 0;
        for(int i=1; i<=mp[k]; ++i) {
            t = max(t, seq[i]);
        }
        seq[mp[k]] = t+1;
        res = max(res, t+1);
    }
    cout << res << endl;
}