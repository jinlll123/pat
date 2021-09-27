#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {return a > b;}
vector<int> fa;
int find(int x) {
    return (x==fa[x] ? x : fa[x] = find(fa[x]));
}
void unite(int x, int y) {
    int fx = fa[x];
    int fy = fa[y];
    if(fx != fy) {
        fa[y] = fx;
    }
}
int main() {
    int n, k, t, m;
    cin >> n;
    fa.resize(n+1);
    for(int i=1; i<=n; ++i) {
        fa[i] = i;
    }
    int h[1005] = {0};
    for(int i=1; i<=n; ++i) {
        scanf("%d: ", &k);
        for(int j=0; j<k; ++j) {
            cin >> t;
            if(h[t]==0)
                h[t] = i;
            else unite(i, find(h[t]));
        }
    }
    vector<int> num(n+1, 0);
    for(int i=1; i<=n; ++i) {
        fa[i] = find(i);
        num[fa[i]]++;
    }
    int cnt = 0;
    for(int i=1; i<=n; ++i) {
        if(num[i] != 0) cnt++;
    }
    cout << cnt << endl;
    sort(num.begin(), num.end(), cmp);
    for(int i=0; i<cnt; ++i) {
        cout << num[i] << " \n"[i==cnt-1];
    }
//         cout << fa[i] << " \n"[i==n];
//     for(int i=1; i<=n; ++i)
//         cout << find(i) << " \n"[i==n];
    
    
//     sort(sum.begin(), sum.end(), cmp);
//     for(int i=0; i<sum.size(); ++i) {
//         cout << sum[i] << " \n"[i==sum.size()-1];
//     }
}