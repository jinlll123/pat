#include<bits/stdc++.h>
using namespace std;
// struct node{
//     int id, cnt;
//     node(int _id=-1, int _cnt=0) : id(_id), cnt(_cnt) {}
// };
int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<vector<int>> g(n+1);
    vector<int> vec(n+1, 0);
//     for(int i=0; i<=n; ++i) {
//         vec.push_back(node(i));
//     }
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        vec[b]++;
    }
    int k;
//     vector<int> tmp = vec;
//     for(int i=1; i<=n; ++i) {
//         cout << tmp[i] << " ";
//     }
    vector<int> res;
    scanf("%d", &k);
    for(int i=0; i<k; ++i) {
        vector<int> tmp = vec;
        bool fg = true;
        for(int j=0; j<n; ++j) {
            scanf("%d", &a);
            if(fg) {
                if(tmp[a]>0) {
                    res.push_back(i);
                    fg = false;
                }else {
                    for(auto nxt : g[a]) {
                        tmp[nxt]--;
                    }
                }
            }
        }
    }
    for(int i=0; i<res.size(); ++i) {
        cout << res[i] << " \n"[i==res.size()-1];
    }
}