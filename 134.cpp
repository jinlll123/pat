#include<bits/stdc++.h>
using namespace std;
int getid(int a, int b) {
    if(a > b) {
        return a*10000+b;
    }
    else return b*10000+a;
}
int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<vector<int>> g(n);
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k, nv, t;
    scanf("%d", &k);
//     cout << "k=" << k << endl;
    for(int i=0; i<k; ++i) {
        set<int> s;
        scanf("%d", &nv);
        for(int j=0; j<nv; ++j) {
            scanf("%d", &t);
            for(int p=0; p<g[t].size(); ++p) {
                s.insert(getid(t, g[t][p]));
            }
        }
        if(s.size()==m) printf("Yes\n");
        else printf("No\n");
    }
}