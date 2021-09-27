#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    int a, b;
    scanf("%d %d", &n, &m);
    map<int, vector<int>> mp;
    int cnt = 1;
    for(int i=0; i<n; ++i) {
        scanf("%d %d", &a, &b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=0; i<m; ++i) {
        int k;
        scanf("%d", &k);
        vector<int> vec(k);
        vector<bool> list(1000005, false);
        for(int j=0; j<k; ++j) {
            scanf("%d", &vec[j]);
            list[vec[j]] = true;
        }
        bool fg = true;
        for(int j=0; j<k && fg; ++j) {
            for(auto num : mp[vec[j]]) {
                if(list[num]) {
                    fg = false;
                    break;
                }
            }
        }
        if(fg) cout << "Yes\n";
        else cout << "No\n";
    }
}
