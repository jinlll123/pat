#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct node {
    int add, nxt, val;
    node(int _a = 0, int _n = 0, int _v = 0) : add(_a), nxt(_n), val(_v) {}
}a[100010];
int main() {
    int fst, n, k;
    scanf("%d %d %d", &fst, &n, &k);
//     printf("%d, %d, %d\n", fst, n, k);
//     a[fst].pre = -1;
    int add, val, nxt;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &add, &val, &nxt);
        a[add].val = val;
        a[add].nxt = nxt;
        a[nxt].add = add;
    }
    vector<int> idx;
    int cur = fst, cnt=0;
    while(cnt < n && cur != -1) {
        idx.push_back(cur);
        cur = a[cur].nxt;
        ++cnt;
    }
//     cout << cur << endl;
    vector<int> res;
    int i=k;
    for(; i<=idx.size(); i+=k) {
        for(int j=1; j<=k; ++j) {
            res.push_back(idx[i-j]);
        }
    }
    i-=k;
    for(; i<idx.size(); ++i) res.push_back(idx[i]);
    for(int i=0; i<res.size()-1; ++i) {
        printf("%05d %d %05d\n", res[i], a[res[i]].val, res[i+1]);
    }
    int sz = res.size();
    if(cur == -1) printf("%05d %d -1\n", res[sz-1], a[res[sz-1]].val);
    else printf("%05d %d %05d\n", res[sz-1], a[res[sz-1]].val, cur);
}