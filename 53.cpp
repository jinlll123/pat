#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> tree;
vector<vector<int>> paths;
vector<int> wht;
vector<int> path;
int n, m, s;

void tra(int cur, int cnt) {
    if(cnt > s) return;
    path.push_back(wht[cur]);
    
    if(tree[cur].size() == 0) {
        if(cnt+wht[cur]==s) paths.push_back(path);
    }
    else {
        for(auto nxt : tree[cur]) {
            tra(nxt, cnt+wht[cur]);
        }
    }
    
    path.pop_back();
}

bool cmp(vector<int> &a, vector<int> &b) {
    int len = min(a.size(), b.size());
    for(int i=0; i<len; ++i) {
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

int main() {
    cin >> n >> m >> s;
    wht.resize(n);
    tree.resize(n);
    for(int i=0; i<n; ++i) cin >> wht[i];
    int id, k;
    for(int i=0; i<m; ++i) {
        cin >> id >> k;
        tree[id].resize(k);
        for(int j=0; j<k; ++j) cin >> tree[id][j];
    }
    tra(0, 0);
    sort(paths.begin(), paths.end(), cmp);
//     cout << paths.size() << endl;
    for(int i=0; i<paths.size(); ++i) {
        int sz = paths[i].size();
        for(int p=0; p<sz; ++p) cout << paths[i][p] << " \n"[p==sz-1];
    }
}