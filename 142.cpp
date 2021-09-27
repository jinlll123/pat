#include<bits/stdc++.h>
using namespace std;
int main() {
    int nv, ne, a, b;
    scanf("%d %d", &nv, &ne);
    vector<vector<int>> g(nv+1);
    for(int i=0; i<ne; ++i) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m, k, t;
    scanf("%d", &m);
    for(int i=0; i<m; ++i) {
        scanf("%d", &k);
        vector<int> vs;
        vector<int> vec(nv+1, 0);
        int maxm = 0;
        for(int j=0; j<k; ++j) {
            scanf("%d", &t);
            vs.push_back(t);
            for(auto v : g[t]) {
                vec[v]++;
                maxm = max(maxm, vec[v]);
            }
        }
        bool fg = true;
        for(int j=0; j<vs.size(); ++j) {
            if(vec[vs[j]]!=vec[vs[0]] || vec[vs[j]]<k-1) {
                printf("Not a Clique\n");
                fg = false;
                break;
            }
        }
        if(fg) {
            if(maxm==k) printf("Not Maximal\n");
            else printf("Yes\n");
        }
    }
}