#include<bits/stdc++.h>
using namespace std;
int main() {
    int N, M, k, n, a, b, dist;
    scanf("%d %d", &N, &M);
    vector<vector<int>> g(N+1, vector<int>(N+1, -1));
    for(int i=0; i<M; ++i) {
        scanf("%d %d %d", &a, &b, &dist);
        g[a][b] = dist;
        g[b][a] = dist;
    }
    scanf("%d", &k);
    int idx = -1, mind = 9999999;
    for(int i=1; i<=k; ++i) {
        scanf("%d", &n);
        vector<int> vec(n);
        dist = 0;
        int cnt = 0;
        vector<bool> vis(N+1, false);
        for(int j=0; j<n; ++j) {
            scanf("%d", &vec[j]);
            if(j!=0) {
                if(dist>=0) {
                    if(g[vec[j]][vec[j-1]] == -1) dist = -1;
                    else dist += g[vec[j]][vec[j-1]];
                } 
            }
            if(!vis[vec[j]]) {
                vis[vec[j]] = true;
                cnt++;
            }
        }
        if(n <= N || vec[0]!=vec[n-1] || dist==-1 || cnt<N) {
            if(dist==-1) printf("Path %d: NA (Not a TS cycle)\n", i);
            else printf("Path %d: %d (Not a TS cycle)\n", i, dist);
        }else {
            if(dist < mind) {
                mind = dist;
                idx = i;
            }
            if(n == N+1) {
                printf("Path %d: %d (TS simple cycle)\n", i, dist);
            } else {
                printf("Path %d: %d (TS cycle)\n", i, dist);
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", idx, mind);
}