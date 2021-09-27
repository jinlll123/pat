#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int cnt, minh;
void fun(int cur, int h) {
//     if(h > minh) return;
    if(g[cur].size()==0) {
        if(h < minh) {
            cnt = 1;
            minh = h;
        }
        else if(h == minh) {
//             cout << minh << " " << cur << endl;
            cnt++;
        }
    }
    else {
        for(auto i : g[cur]) {
            fun(i, h+1);
        }
    }
}
int main() {
    int n, k, t;
    double p, r;
    cin >> n >> p >> r;
    r = 1+r/100;
    g.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> k;
        for(int j=0; j<k; ++j) {
            cin >> t;
            g[i].push_back(t);
        }
    }
    cnt=0, minh=10000005;
    fun(0, 0);
//     cout << minh << endl;
    for(int i=0; i<minh; ++i) p *= r;
    printf("%.4f %d\n", p, cnt);
}
