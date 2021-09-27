#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct edge{
    int from, to, val;
    edge(int _f, int _t, int _v, int _h=0) : from(_f), to(_t), val(_v) {}
    bool operator < (const edge& e) const {
        return val > e.val;
    }
};
int n, k;
vector<vector<edge>> g;
vector<int> haps;
map<int, string> idx_name;
map<string, int> name_idx;
void init() {
    string name;
    int hp;
    cin >> n >> k >> name;
    haps.resize(n);
    g.resize(n);
    name_idx[name] = 0;
    idx_name[0] = name;
    haps[0] = 0;
    for(int i=1; i<n; ++i) {
        cin >> name >> hp;
        name_idx[name] = i;
        idx_name[i] = name;
        haps[i] = hp;
    }
    string f, t;
    int fi, ti, v;
    for(int i=0; i<k; ++i) {
        cin >> f >> t >> v;
        fi = name_idx[f];
        ti = name_idx[t];
        g[fi].push_back(edge(fi, ti, v));
        g[ti].push_back(edge(ti, fi, v));
    }
}
const int INF = 1e8;
int dijkstra(int s, int t) {
    vector<int> dis(n, INF);
    dis[s] = 0;
    vector<int> hapt(haps);
//     vector<int> line(n, 0);
//     line[s] = 1;
    vector<bool> vis(n, false);
    priority_queue<edge> pq;
    pq.push(edge(-1, s, 0));
//     vector<int> path(n, -1);
    vector<vector<vector<int>>> paths(n);
    vector<int> tmp(1, s);
    paths[s].push_back(tmp);
    while(!pq.empty()) {
        auto top=pq.top();
        pq.pop();
        if(!vis[top.to]) {
            vis[top.to] = true;
//             path[top.to] = top.from;
            for(auto nxt : g[top.to]) {
                if(!vis[nxt.to]) {
                    if(dis[nxt.to] > dis[top.to] + nxt.val) {
                        dis[nxt.to] = dis[top.to] + nxt.val;
                        hapt[nxt.to] = hapt[top.to] + haps[nxt.to];
                        paths[nxt.to].clear();
                        for(auto vt : paths[top.to]) {
                            vector<int> tmp(vt);
                            tmp.push_back(nxt.to);
                            paths[nxt.to].push_back(tmp);
                        }
//                         line[nxt.to] = line[top.to];
                        pq.push(edge(top.to, nxt.to, dis[nxt.to], hapt[nxt.to]));
                    }
                    else if(dis[nxt.to] == dis[top.to] + nxt.val) {
//                         line[nxt.to]++;
//                         if(hapt[nxt.to] <= hapt[top.to] + haps[nxt.to]) {
//                             paths[nxt.to].clear();
                        for(auto vt : paths[top.to]) {
                            auto tmp = vt;
                            tmp.push_back(nxt.to);
                            paths[nxt.to].push_back(tmp);
                        }
                        if(hapt[nxt.to] <= hapt[top.to] + haps[nxt.to])
                            hapt[nxt.to] = hapt[top.to] + haps[nxt.to];
                        pq.push(edge(top.to, nxt.to, dis[nxt.to], hapt[nxt.to]));
//                         }
                    }
                }
            }
        }
    }
    vector<vector<int>> res;
    int hp = hapt[t];//0;
    for(int i=0; i<paths[t].size(); ++i) {
        int thp = 0;
        for(auto p : paths[t][i]) {
            thp += haps[p];
        }
//         if(thp > hp) {
//             res.clear();
//             res.push_back(paths[t][i]);
//             hp = thp;
//         }
//         else 
        if(thp == hapt[t]) { //hp) {
            res.push_back(paths[t][i]);
        }
    }
    int vi, msz=999;
    for(int i=0; i<res.size(); ++i) {
        if(res[i].size() < msz) {
            msz = res[i].size();
            vi = i;
//             cout << "msz - vi = " << msz << " " << vi << endl;
        }
    }
//     for(int i=0; i<paths[t].size(); ++i) 
//         for(int j=0; j<paths[t][i].size(); ++j)
//             cout << idx_name[paths[t][i][j]] << (i==paths[t][i].size()-1 ? "\n" : "->");
    cout << paths[t].size() << " " << dis[t] << " " << hp << " " << (int) hp/(msz-1) << endl;
    for(int i=0; i<res[vi].size(); ++i)
        cout << idx_name[res[vi][i]] << (i==res[vi].size()-1 ? "\n" : "->");
}
int main() {
    init();
    dijkstra(0, name_idx["ROM"]);
}