#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n;
    vector<int> cp(n);
    for(int i=0; i<n; ++i) cin >> cp[i];
    sort(cp.begin(), cp.end());
    cin >> m;
    vector<int> pro(m);
    for(int i=0; i<m; ++i) cin >> pro[i];
    sort(pro.begin(), pro.end());
    ll res = 0;
    for(int i=0; i<n && i<m && cp[i]<0 && pro[i]<0; ++i) {
        res += cp[i]*pro[i];
    }
    for(int i=n-1, j=m-1; i>=0 && j>=0 && cp[i]>0 && pro[j]>0; --i, --j) {
        res += cp[i]*pro[j];
    }
    cout << res;
}