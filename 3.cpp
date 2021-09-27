// #include <iostream>
// #include <string> 
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <cmath>
// using namespace std;
// #define ll long long
// const ll INF = 1e18;

// struct edge

// {
// 	int t;
// 	ll val;
// 	edge(int t_, ll val_) : t(t_), val(val_) {}
// 	bool operator < (const edge& e) const { return val > e.val; }
// };

// vector<int> cp;  // 每个城市队员数
// vector<vector<edge>> g;
// int n, m, s, t;
// void init() {
// 	cin >> n >> m >> s >> t;
// 	cp.resize(n);
// 	for (int i = 0; i < n; ++i) {
// 		cin >> cp[i];
// 	}
// 	g.resize(n);
// 	for (int i = 0; i < m; ++i) {
// 		int f, t, val;
// 		cin >> f >> t >> val;
// 		g[f].push_back(edge(t, val));
//         g[t].push_back(edge(f, val));
// 	}
// }

// ll dijkstra(int s, int t) {
// 	vector<bool> vis(n, false);
// // 	vector<int> ps(n, 0);  // 每个城市的总人数，每个城市本身就会有人
// //     ps[s] = cp[s];
//     vector<int> ps(cp);
// 	vector<int> pnum(n, 0);  // 节点的路径数
// 	pnum[s] = 1;
// 	vector<ll> dis(n, INF);
// 	dis[s] = 0;
// 	priority_queue<edge> pq;
// 	pq.push(edge(s, 0));
// 	while (!pq.empty()) {
// 		edge top = pq.top();
// 		pq.pop();
// 		if (!vis[top.t]) {
// 			vis[top.t] = true;
// 			for (auto nxt : g[top.t]) {
// 				if (!vis[nxt.t]) {
// 					if (dis[nxt.t] > dis[top.t] + nxt.val) {
// 						dis[nxt.t] = dis[top.t] + nxt.val;
// 						pnum[nxt.t] = pnum[top.t];
// 						ps[nxt.t] = ps[top.t] + cp[nxt.t];
// 						pq.push(edge(nxt.t, dis[nxt.t]));
// 					}
// 					else if (dis[nxt.t] == dis[top.t] + nxt.val) {
// 						ps[nxt.t] = max(ps[nxt.t], ps[top.t] + cp[nxt.t]);
// 						pnum[nxt.t] += pnum[top.t];
// 						pq.push(edge(nxt.t, dis[nxt.t]));
// 					}
// 				}
// 			}
// 		}
// 	}
// 	cout << pnum[t] << " " << ps[t] << endl;
// 	return dis[t];
// }

// int main() {
// 	init();
// 	ll res = dijkstra(s, t);
// 	// cout << res << endl;
// }

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const ll INF = 1e18;
struct edge {
    int from, to, val;
    edge(int f = -1, int t = -1, int v = -1) : from(f), to(t), val(v) {}
    bool operator < (const edge& e) const {
        return val > e.val;
    }
};
int n, m, c1, c2;
vector<int> nums;
vector<vector<edge>> g;
void init() {
    cin >> n >> m >> c1 >> c2;
    nums.resize(n);
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int a, b, v;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> v;
        g[a].push_back(edge(a, b, v));
        g[b].push_back(edge(b, a, v));
    }
}

void dijkstra(int s, int t) {
    vector<ll> dis(n, INF);
    dis[s] = 0;
    vector<bool> vis(n, false);
    vector<int> path_num(n, 0);
    path_num[s] = 1;
    vector<int> person_num(nums);
    priority_queue<edge> pq;
    pq.push(edge(-1, s, 0));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (!vis[top.to]) {
//             printf("top = %d\n", top.to);
            vis[top.to] = true;
            for (auto nxt : g[top.to]) {
                if (!vis[nxt.to]) {
//                     printf("  nxt = %d\n", nxt.to);
                    if (dis[nxt.to] > dis[top.to] + nxt.val) {
//                         cout << "    >\n";
                        dis[nxt.to] = dis[top.to] + nxt.val;
                        person_num[nxt.to] = person_num[top.to] + nums[nxt.to];
                        path_num[nxt.to] = path_num[top.to];
//                         cout << "       psn = " << person_num[nxt.to] << "       pathn = " << path_num[nxt.to] << endl;
                        pq.push(edge(top.to, nxt.to, dis[nxt.to]));
                    }
                    else if (dis[nxt.to] == dis[top.to] + nxt.val) {
//                         cout << "    ==\n";
                        if (person_num[nxt.to] < person_num[top.to] + nums[nxt.to]) {
                            person_num[nxt.to] = person_num[top.to] + nums[nxt.to];
                        }
                        path_num[nxt.to]+=path_num[top.to];
//                         cout << "       psn = " << person_num[nxt.to] << "       pathn = " << path_num[nxt.to] << endl;
                        pq.push(edge(top.to, nxt.to, dis[nxt.to]));
                    }
                }
            }
        }
    }
    cout << path_num[t] << " " << person_num[t] << endl;
}

int main() {
    init();
    dijkstra(c1, c2);
}