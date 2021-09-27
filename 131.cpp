#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct seg {
    int line, from, to;
    seg(int l, int f, int t) : line(l), from(f), to(t) {}
};
struct edge
{
    int from;
    int to;
    int line;
    edge(int f, int t, int l) : from(f), to(t), line(l) {}
};
vector<vector<edge>> g;
vector<set<int>> lines;
vector<seg> res;
vector<seg> path;
vector<bool> vis;
int maxl, dest;
void run(int cur, int len, int from, int line) {
//     cout << cur << endl;
    if (cur == dest) {
        path.push_back(seg(line, from, cur));
        if (len < maxl) {
            maxl = len;
            res = path;
        }
        else if (len == maxl) {
            if (path.size() < res.size())
                res = path;
        }
        path.pop_back();
        return;
    }
    if (vis[cur]) return;
//     cout << lines[cur].size() << endl;
    for (auto nxt : g[cur]) {
        vis[cur] = true;
        if (!vis[nxt.to]) {
            if(line==-1) 
                run(nxt.to, len + 1, from, nxt.line);
            else if(nxt.line == line)
                run(nxt.to, len + 1, from, nxt.line);
            else {
                path.push_back(seg(line, from, nxt.from));
                run(nxt.to, len + 1, nxt.from, nxt.line);
                path.pop_back();
            }
        }
        vis[cur] = false;
    }
}
int main() {
    int n, m, pre, t;
    g.resize(10005);
    lines.resize(10005);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        if (m == 0) continue;
        cin >> pre;
        lines[pre].insert(i);
        for (int j = 1; j < m; ++j) {
            cin >> t;
            lines[t].insert(i);
            g[pre].push_back(edge(pre, t, i));
            g[t].push_back(edge(t, pre, i));
            pre = t;
        }
    }
    cin >> m;
    int a;
    for (int i = 0; i < m; ++i) {
        cin >> a >> dest;
        maxl = 1e8;
        vis.clear();
        vis.resize(10005, false);
        path.clear();
        run(a, 0, a, -1);
        cout << maxl << endl;
        for (auto s : res) {
            printf("Take Line#%d from %04d to %04d.\n", s.line, s.from, s.to);
        }
    }
}