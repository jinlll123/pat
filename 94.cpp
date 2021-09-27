#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> vec(n+1);
    for(int i=0; i<k; ++i) {
        int f, num, t;
        cin >> f >> num;
        for(int j=0; j<num; ++j) {
            cin >> t;
            vec[f].push_back(t);
        }
    }
    queue<int> q;
    q.push(1);
    int res=1, pre=1, lv=1, rl=1;
    while(!q.empty()) {
        lv++;
        int cur = 0;
        for(int i=0; i<pre; ++i) {
            int top = q.front();
            q.pop();
            cur += vec[top].size();
            for(int j=0; j<vec[top].size(); ++j) {
                q.push(vec[top][j]);
            }
        }
        if(cur > res) {
            rl = lv;
            res = cur;
        }
        pre = cur;
    }
    cout << res << " " << rl << endl;
}