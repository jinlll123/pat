#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

const int INF = 1e9;

struct edge
{
	int from, to, dis, cost;
	edge(int _f, int _t, int _d, int _c) : from(_f), to(_t), dis(_d), cost(_c) {}
	bool operator < (const edge& e) const {
		if (dis != e.dis) return dis > e.dis;
		return cost > e.cost;
	}
};

vector<vector<edge>> g;
int n, m, s, d;
void init() {
	cin >> n >> m >> s >> d;
	g.resize(n);
	int from, to, dis, cost;
	for (int i = 0; i < m; ++i) {
		cin >> from >> to >> dis >> cost;
		g[from].push_back(edge(from, to, dis, cost));
		g[to].push_back(edge(to, from, dis, cost));
	}
}

int dijkstra(int s, int d) {
	vector<int> dis(n, INF);
	dis[s] = 0;
	vector<int> cost(n, 0);
	vector<bool> visited(n, false);
	priority_queue<edge> pq;
	pq.push(edge(-1, s, 0, 0));
	vector<int> pre(n);
	while (!pq.empty()) {
		edge top = pq.top();
		pq.pop();
		if (!visited[top.to]) {
			visited[top.to] = true;
			pre[top.to] = top.from;
			for (auto nxt : g[top.to]) {
				if (!visited[nxt.to]) {
					if (dis[nxt.to] > dis[top.to] + nxt.dis) {
						dis[nxt.to] = dis[top.to] + nxt.dis;
						cost[nxt.to] = cost[top.to] + nxt.cost;
						pq.push(edge(top.to, nxt.to, dis[nxt.to], cost[nxt.to]));
					}
					else if (dis[nxt.to] == dis[top.to] + nxt.dis) {
						if (cost[nxt.to] > cost[top.to] + nxt.cost) {
							cost[nxt.to] = cost[top.to] + nxt.cost;
							pq.push(edge(top.to, nxt.to, dis[nxt.to], cost[nxt.to]));
						}
					}
				}
			}
		}
	}
	vector<int> path;
	int k = d;
	while (k != -1) {
		path.push_back(k);
		k = pre[k];
	}
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); ++i) {
		cout << path[i] << " ";
	}
	cout << dis[d] << " " << cost[d] << endl;
	return dis[d];
}

int main() {
	init();
	dijkstra(s, d);
}