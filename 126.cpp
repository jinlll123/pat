#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> vis;
void dfs(int x) {
    vis[x] = true;
    for(int i=0; i<g[x].size(); ++i) {
        if(!vis[g[x][i]]) {
            dfs(g[x][i]);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, false);
    int a, b;
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
//     vector<int> res;
//     bool fg = true;
    int odd = 0, sum = 0;
    for(int i=1; i<=n; ++i) {
        printf("%d%c", g[i].size(), " \n"[i==n]);
        odd += g[i].size()%2;
        if(!vis[i]) {
            dfs(i);
            ++sum;
        }
//         if(g[i].size() == 0) fg = false;
    }
    if(sum==1) {
        if(odd==0) printf("Eulerian\n");
        else if(odd==2) printf("Semi-Eulerian\n");
        else printf("Non-Eulerian\n");
    }else {
        printf("Non-Eulerian\n");
    }
    
}