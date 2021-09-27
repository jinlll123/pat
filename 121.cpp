#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, m;
    scanf("%d", &n);
    vector<int> couple(100005);
    for(int i=0; i<n; ++i) {
        scanf("%d %d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    vector<int> vec;
    vector<bool> pre(100005, false);
    for(int i=0; i<m; ++i) {
        scanf("%d", &a);
        pre[a] = true;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    vector<int> res;
    for(auto i : vec) {
        if(!pre[couple[i]]) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for(int i=0; i<res.size(); ++i) {
        printf("%05d%c", res[i], " \n"[i==res.size()-1]);
    }
}