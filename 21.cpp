#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<bool> vis;
vector<int> res;
set<int> st;
int n, maxh;
void dfs(vector<vector<bool>>& g, int cur, int height) {
    if (vis[cur]) return;
    vis[cur] = true;
//     cout << cur << " " << height << "-----------\n";
    if (height > maxh) {
        res.clear();
        res.push_back(cur);
        maxh = height;
//         cout << "better   " << "maxh = " << maxh << endl;
    }
    else if (height == maxh) {
//         cout << "equal\n";
        res.push_back(cur);
    }
    for (int i = 0; i < n; ++i) {
        if (g[cur][i] && !vis[i]) dfs(g, i, height + 1);
    }
}

int main() {
    maxh = 0;
    cin >> n;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    vis.resize(n);
//     for (auto i : vis) cout << i << " ";
//     cout << endl;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a][b] = g[b][a] = true;
    }
    int num = 0, s1 = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            num++;
            dfs(g, i, 0);
            if(i==0) {
                s1 = res[0];
                for(auto j : res) {
                    st.insert(j);
                }
            }
        }
    }
//     cout << "=================\n";
//     for (auto i : res) {
//         cout << i << endl;
//     }
//     cout << "==================\n";
    if (num > 1) printf("Error: %d components", num);
    else {
//         cout << " ---\n";
        vis.clear();
        vis.resize(n);
        dfs(g, s1, 0);
        for (int i : res) st.insert(i);
        for (int i : st) {
            cout << i+1 << endl;
        }
//         res.clear();
//         for (int i : st) res.push_back(i);
//         sort(res.begin(), res.end());
//         for (int i : res) {
//             cout << i+1 << endl;
//         }
    }
}