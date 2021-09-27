#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
struct node{
    int id, lv;
    node(int _id=0, int _lv=0) : id(_id), lv(_lv) {}
    bool operator < (const node& n) const {return lv > n.lv;}
};
int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    vector<vector<int>> g(n+1);
    int num, t;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &num);
        for(int j=0; j<num; ++j) {
            scanf("%d", &t);
            g[t].push_back(i);
        }
    }
//     for(int i=1; i<=n; ++i) {
//         for(int j=0; j<g[i].size(); ++j) cout << g[i][j] << " ";
//         cout << endl;
//     }
    int k;
    scanf("%d", &k);
    for(int i=0; i<k; ++i) {
//         cout << ">>>>>>>>>>i = " << i << endl;
        scanf("%d", &t);
        priority_queue<node> pq;
        pq.push(node(t, 0));
        vector<bool> vis(n+1, false);
//         for(int j=0; j<n+1; ++j) cout << vis[j];
//         cout << endl;
        int cnt = 0;
        while(!pq.empty()) {
            node top = pq.top();
            pq.pop();
            if(top.lv > l) continue;
            if(!vis[top.id]) {
//                 cout << "start >>> " << top.id << endl;
//                 cout << "LV = " << top.lv << endl;
                vis[top.id] = true;
                if(top.id != t) cnt++;
//                 cout << "  size = " << g[top.id].size() << endl;
                for(int nxt : g[top.id]) {
//                     cout << "  to " << nxt;
                    if(!vis[nxt]) {
//                         cout << " is not visited, ++";
                        if(top.lv < l) pq.push(node(nxt, top.lv+1));
//                         else cout << "  NO PUSH FOR L";
                    }
//                     cout << endl;
                }
            }
            
        }
        cout << cnt << endl;
    }
}