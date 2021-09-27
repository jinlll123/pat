#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int m;
        scanf("%d", &m);
        bool fg = true;
        vector<int> vis(m+1, false);
        vector<int> vec(m+1);
        for(int j=1; j<=m; ++j) {
            scanf("%d", &vec[j]);
            if(vis[vec[j]]) fg = false;
            vis[vec[j]] = true;
        }
        if(!fg) printf("NO\n");
        else {
            for(int k=1; k<m && fg; ++k) {
                for(int j=k+1; j<=m && fg; ++j) {
                    if(abs(j-k)==abs(vec[j]-vec[k]))
                        fg = false;
                }
            }
            if(fg) printf("YES\n");
            else printf("NO\n");
        }
    }
}