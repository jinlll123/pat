// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<queue>
// using namespace std;
// const int INF = 1e9;
// struct edge{
//     int from;
//     int to;
//     int val;
//     edge(int _f=0, int _t=0, int _v=0) : from(_f), to(_t), val(_v) {}
//     bool operator < (const edge &e) const {
//         return val > e.val;
//     }
// };
// int c, n, m, hc;
// vector<vector<edge>> g;
// vector<int> sta;

// int dijkstra(int s, int t) {
//     vector<int> pre(n+1);
//     vector<bool> vis(n+1, false);
//     vis[0] = true;
//     vector<int> dis(n+1, INF);
//     dis[0] = 0;
//     vector<int> pnum(n+1, 0);
//     priority_queue<edge> pq;
//     pq.push(edge(-1, 0, 0));
//     while(!pq.empty()) {
//         edge top = pq.top();
//         pq.pop();
//         if(!vis[top.to]) {
//             vis[top.to] = true;
//             pre[top.to] = top.from;
//             for(auto nxt : g[top.to]) {
//                 if(!vis[nxt.to]) {
//                     if(dis[nxt.to] > dis[top.to] + top.val) {
//                         dis[nxt.to] = dis[top.to] + top.val;
//                         pnum[nxt.to] = pnum[top.to] + sta[top.to] - hc;
//                         pq.push(edge(top.to, nxt.to, dis[nxt.to]));
//                     }
//                     else if(dis[nxt.to] == dis[top.to] + top.val) {
//                         pnum[nxt.to] = min(pnum[nxt.to], pnum[top.to] + sta[top.to] - hc);
//                         pq.push(edge(top.to, nxt.to, dis[nxt.to]));
//                     }
//                 }
//             }
//         }
//     }
//     vector<int> path;
//     int k = t;
//     while(k != -1) {
//         path.push_back(pre[k]);
//         k = pre[k];
//     }
//     reverse(path.begin(), path.end());
//     if(pnum[t] < 0) cout << -pnum[t] << " ";
//     else cout << "0 ";
//     for(auto i : path) cout << i << " ";
//     if(pnum[t] < 0) cout << "0\n";
//     else cout << pnum[t] << "\n";
//     return dis[t];
// }

// int main() {
//     int sp;
//     cin >> c >> n >> sp >> m;
//     hc = c/2;
//     g.resize(n+1);
//     sta.resize(n+1);
//     for(int i=1; i<=n; ++i) cin >> sta[i];
//     int f, t, v;
//     for(int i=0; i<m; ++i) {
//         cin >> f >> t >> v;
//         g[f].push_back(edge(f, t, v));
//         g[t].push_back(edge(t, f, v));
//     }
//     dijkstra(0, sp);
// }

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
struct edge{
    int from, to, val;
    edge(int _f, int _t, int _v) : from(_f), to(_t), val(_v) {}
    bool operator < (const edge &e) const {return val > e.val;}
};
int cmax, n, sp, m, hf;
vector<vector<edge>> g;
vector<int> bnum;
vector<vector<vector<int>>> paths;
int dijkstra(int s, int t) {
    paths.resize(n+1);
    vector<int> dis(n+1, INF);
    dis[s] = 0;
    vector<bool> vis(n+1, false);
    priority_queue<edge> pq;
    pq.push(edge(-1, 0, 0));
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if(!vis[top.to]) {
//             cout << "->>  " << top.to << endl;
            vis[top.to] = true;
            for(auto nxt : g[top.to]) {
                if(!vis[nxt.to]) {
//                     cout << " ->>  " << nxt.to << endl;
                    if(dis[nxt.to] > dis[top.to] + nxt.val) {
//                         printf("  dis> %d\n", nxt.to);
                        dis[nxt.to] = dis[top.to] + nxt.val;
                        paths[nxt.to].clear();
                        if(paths[top.to].empty()) {
                            vector<int> tmp;
                            tmp.push_back(nxt.to);
                            paths[nxt.to].push_back(tmp);
                        }else {
                            for(auto v : paths[top.to]) {
                                v.push_back(nxt.to);
                                paths[nxt.to].push_back(v);
                            }
                        }
                        pq.push(edge(top.to, nxt.to, dis[nxt.to]));
                    }else if(dis[nxt.to] == dis[top.to] + nxt.val) {
//                         printf("  dis== %d\n", nxt.to);
                        if(paths[top.to].empty()) {
                            vector<int> tmp;
                            tmp.push_back(nxt.to);
                            paths[nxt.to].push_back(tmp);
                        }else {
                            for(auto v : paths[top.to]) {
                                v.push_back(nxt.to);
                                paths[nxt.to].push_back(v);
                            }
                        }
                        pq.push(edge(top.to, nxt.to, dis[nxt.to]));
                    }
                }
                
            }
        }
    }
//     cout << "min dis = " << dis[t] << endl;
    return dis[t];
}
int main() {
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    hf = cmax/2;
    g.resize(n+1);
    bnum.resize(n+1);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &bnum[i]);
    }
    int from, to, val;
    for(int i=0; i<m; ++i) {
        scanf("%d %d %d", &from, &to, &val);
        g[from].push_back(edge(from, to, val));
        g[to].push_back(edge(to, from, val));
    }
    dijkstra(0, sp);
//     cout << paths[sp].size() << endl;
    vector<int> res;
    int min_sd=99999999, min_bk=99999999, sd, bk;
    for(auto v : paths[sp]) {
        sd = 0, bk = 0;
        for(auto i : v) {
            int tmp = bnum[i]-hf;
            if(tmp<0) {
                if(bk==0) {
                    sd -= tmp;
                }else {
                    bk += tmp;
                    if(bk < 0) {
                        sd -= bk;
                        bk = 0;
                    }
                }
            }else {
                bk += tmp;
            }
        }
        if(sd < min_sd) {
            min_sd = sd;
            min_bk = bk;
            res = v;
        }else if(sd == min_sd) {
            if(bk < min_bk) {
                min_bk = bk;
                res = v;
            }
        }
    }
    if(bk == 99999999) bk = 0;
    printf("%d 0", min_sd);
    for(auto i : res) {
        printf("->%d", i);
    }
    printf(" %d\n", min_bk);
}