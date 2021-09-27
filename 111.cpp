#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;
int n, m, sta, des;
struct edge {
    int from, to;
    int length, time;
    bool judt;
    edge(int f = -1, int t = -1, int l = 0, int ti = 0, bool j = false) : from(f), to(t), length(l), time(ti), judt(j) {}
    bool operator < (const edge& e) const {
        if (judt) {
            if (time != e.time)
                return time > e.time;
            return length > e.length;
        }
        else {
            if (length != e.length)
                return length > e.length;
            return time > e.time;
        }
    }
};

vector<vector<edge>> g;
vector<int> tpath, lpath;
void init() {
    cin >> n >> m;
    //cout << n << " " << m << endl;
    g.resize(n);
    //tpath.resize(n);
    //lpath.resize(n);
    int a, b, d, l, t;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d %d", &a, &b, &d, &l, &t);
        //         printf("%d %d %d %d %d\n", a, b, d, l, t);
        g[a].push_back(edge(a, b, l, t));
        if (d == 0) g[b].push_back(edge(b, a, l, t));
    }
    cin >> sta >> des;
}

ll dijkstraL(int s, int t) {
    vector<ll> dis(n, INF);
    dis[s] = 0;
    vector<bool> vis(n, false);
    priority_queue<edge> pq;
    pq.push(edge(-1, s));
    vector<ll> tim(n, INF);
    vector<int> path(n, -1);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (!vis[top.to]) {
            vis[top.to] = true;
            path[top.to] = top.from;
            for (auto nxt : g[top.to]) {
                if (!vis[nxt.to]) {
                    if (dis[nxt.to] > dis[top.to] + nxt.length) {
                        dis[nxt.to] = dis[top.to] + nxt.length;
                        tim[nxt.to] = tim[top.to] + nxt.time;
                        pq.push(edge(top.to, nxt.to, dis[nxt.to], tim[nxt.to]));
                    }
                    else if (dis[nxt.to] == dis[top.to] + nxt.length) {
                        if (tim[nxt.to] > tim[top.to] + nxt.time) {
                            tim[nxt.to] = tim[top.to] + nxt.time;
                            pq.push(edge(top.to, nxt.to, dis[nxt.to], tim[nxt.to]));
                        }
                    }
                }
            }
        }
    }
    int cur = t;
    while (cur != -1) {
        lpath.push_back(cur);
        cur = path[cur];
    }
    reverse(lpath.begin(), lpath.end());
    /*printf("Distance = %d: ", dis[t]);
    for (int i = 0; i < lpath.size(); ++i) {
        cout << lpath[i];
        if (i != lpath.size() - 1) {
            cout << " -> ";
        }
        else cout << endl;
    }*/
    return dis[t];
}

ll dijkstraT(int s, int t) {
    vector<ll> tim(n, INF);
    tim[s] = 0;
    vector<int> num(n, 10000);
    num[s] = 1;
    vector<bool> vis(n, false);
    priority_queue<edge> pq;
    pq.push(edge(-1, s, 0, 0, true));
    vector<int> path(n, -1);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (!vis[top.to]) {
            vis[top.to] = true;
            path[top.to] = top.from;
            for (auto nxt : g[top.to]) {
                if (!vis[nxt.to]) {
                    if (tim[nxt.to] > tim[top.to] + nxt.time) {
                        tim[nxt.to] = tim[top.to] + nxt.time;
                        num[nxt.to] = num[top.to] + 1;
                        pq.push(edge(top.to, nxt.to, num[nxt.to], tim[nxt.to], true));
                    }
                    else if (tim[nxt.to] == tim[top.to] + nxt.time) {
                        if (num[nxt.to] > num[top.to] + 1) {
                            num[nxt.to] = num[top.to] + 1;
                            pq.push(edge(top.to, nxt.to, num[nxt.to], tim[nxt.to], true));
                        }
                    }
                }
            }
        }
    }
    int cur = t;
    while (cur != -1) {
        tpath.push_back(cur);
        cur = path[cur];
    }
    reverse(tpath.begin(), tpath.end());
    /*printf("Time = %d: ", tim[t]);
    for (int i = 0; i < tpath.size(); ++i) {
        cout << tpath[i];
        if (i != tpath.size() - 1) {
            cout << " -> ";
        }
        else cout << endl;
    }*/
    return tim[t];
}

int main() {
    init();
    //cout << sta << " " << des << endl;
    ll resl = dijkstraL(sta, des);
    ll rest = dijkstraT(sta, des);
    bool fg = true;
    if (lpath.size() != tpath.size()) fg = false;
    else {
        for (int i = 0; i < lpath.size(); ++i) {
            if (lpath[i] != tpath[i]) {
                fg = false;
                break;
            }
        }
    }
    if (fg) {
        printf("Distance = %d; Time = %d: ", (int)resl, (int)rest);
        for (int i = 0; i < tpath.size(); ++i) {
            cout << tpath[i];
            if (i != tpath.size() - 1) {
                cout << " -> ";
            }
            else cout << endl;
        }
    }
    else {
        printf("Distance = %d: ", (int)resl);
        for (int i = 0; i < lpath.size(); ++i) {
            cout << lpath[i];
            if (i != lpath.size() - 1) {
                cout << " -> ";
            }
            else cout << endl;
        }

        printf("Time = %d: ", (int)rest);
        for (int i = 0; i < tpath.size(); ++i) {
            cout << tpath[i];
            if (i != tpath.size() - 1) {
                cout << " -> ";
            }
            else cout << endl;
        }
    }
}