#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b, k;
    scanf("%d %d", &n, &m);
    vector<vector<bool>> g(n+1, vector<bool>(n+1, false));
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &a, &b);
        g[a][b] = true;
        g[b][a] = true;
    }
    scanf("%d", &k);
    for(int i=0; i<k; ++i) {
        bool res = true;
        scanf("%d", &a);
        if(a != n+1) res = false;
        vector<bool> vis(n+1, false);
        int pre, sta, cur;
        scanf("%d", &pre);
        sta = pre;
        vis[sta] = true;
        for(int j=1; j<a-1; ++j) {
            scanf("%d", &cur);
            if(!g[pre][cur] || vis[cur]) res = false;
            vis[cur] = true;
            pre = cur;
        }
        scanf("%d", &cur);
        if(!g[pre][cur] || cur != sta) res = false;
        if(res) printf("YES\n");
        else printf("NO\n");
    }
}