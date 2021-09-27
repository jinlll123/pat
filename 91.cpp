#include<bits/stdc++.h>
using namespace std;
struct node{
    int x, y, z;
    node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int m, n, l, t;
vector<vector<vector<int>>> g;
vector<vector<vector<bool>>> vis;
bool judge(int x, int y, int z) {
    if(x<0 || x>=m || y<0 || y>=n || z<0 || z>=l) return false;
    if(g[x][y][z]==0 || vis[x][y][z]) return false;
    return true;
}
int bfs(int x, int y, int z) {
//     if(vis[x][y][z]) return 0;
    int cnt = 0;
    queue<node> q;
    q.push(node(x, y, z));
    vis[x][y][z] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        cnt++;
        for(int i=0; i<6; ++i) {
            int xi=cur.x+X[i], yi=cur.y+Y[i], zi=cur.z+Z[i];
            if(judge(xi, yi, zi)) {
                vis[xi][yi][zi] = true;
                q.push(node(xi, yi, zi));
            }
        }
    }
    if(cnt >= t) return cnt;
    return 0;
}
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    g.resize(m, vector<vector<int>>(n, vector<int>(l)));
    vis.resize(m, vector<vector<bool>>(n, vector<bool>(l, false)));
    for(int i=0; i<l; ++i) {
        for(int j=0; j<m; ++j) {
            for(int k=0; k<n; ++k) {
                scanf("%d", &g[j][k][i]);
            }
        }
    }
    int res = 0;
    for(int i=0; i<l; ++i) {
        for(int j=0; j<m; ++j) {
            for(int k=0; k<n; ++k) {
                if(g[j][k][i]==1 && !vis[j][k][i])
                    res += bfs(j, k, i);
            }
        }
    }
    cout << res << endl;
}