#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    int oldp, newp;
    node(int _k=0, int _o=-1, int _n=-1) : key(_k), oldp(_o), newp(_n) {}
}a[100005], b[100005];
int main() {
    int st, n;
    scanf("%d %d", &st, &n);
    int idx;
    for(int i=0; i<n; ++i) {
        scanf("%d", &idx);
        scanf("%d %d", &a[idx].key, &a[idx].oldp);
    }
    int pre = st, cur = a[st].oldp, rp=-1, rst = -1;
    vector<bool> vis(100005, false);
    vis[abs(a[st].key)] = true;
    while(cur != -1) {
        int k = abs(a[cur].key);
        if(!vis[k]) {
            a[pre].newp = cur;
            vis[k] = true;
            pre = cur;
        }
        else {
            b[cur].key = a[cur].key;
            if(rp != -1) b[rp].newp = cur;
            else rst = cur;
            rp = cur;
        }
        cur = a[cur].oldp;
    }
    cur = st;
    while(cur != -1) {
        printf("%05d %d ", cur, a[cur].key);
        if(a[cur].newp == -1) printf("-1\n");
        else printf("%05d\n", a[cur].newp);
        cur = a[cur].newp;
    }
    cur = rst;
    while(cur != -1) {
        printf("%05d %d ", cur, b[cur].key);
        if(b[cur].newp == -1) printf("-1\n");
        else printf("%05d\n", b[cur].newp);
        cur = b[cur].newp;
    }
}
