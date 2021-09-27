#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;
vector<string> vname;
bool cmp(int a, int b) {
//     return a < b;
    return vname[a] < vname[b];
}

int main() {
    int n, k, c, t, cnt=0;
    string name;
    scanf("%d %d", &n, &k);
//     cin >> n >> k;
    map<int, vector<int>> mp;
    for(int i=0; i<n; ++i) {
        cin >> name;
        vname.push_back(name);
        scanf("%d", &c);
//         cin >> name >> c;
        for(int j=0; j<c; ++j) {
            scanf("%d", &t);
//             cin >> t;
            mp[t].push_back(i);
        }
    }
    for(int i=1; i<=k; ++i) {
        int sz = mp[i].size();
        printf("%d %d\n", i, sz);
//         cout << i << " " << sz << endl;
        sort(mp[i].begin(), mp[i].end(), cmp);
        for(int j=0; j<sz; ++j) {
            printf("%s\n", vname[mp[i][j]].c_str());
//             cout << mp[i][j] << endl;
        }
    }
}