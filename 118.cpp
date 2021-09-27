#include<bits/stdc++.h>
using namespace std;
vector<int> pa;
int find(int x) {
    return (x==pa[x] ? x : pa[x]=find(pa[x]));
}
void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px != py) {
        pa[py] = px;
    }
}
int main() {
    pa.resize(10005);
    for(int i=0; i<10005; ++i)
        pa[i] = i;
    int n, k, x, y, q, num=0;
    cin >> n;
    for(int i=0; i<n; ++i) {
        scanf("%d", &k);
        if(k>0) scanf("%d", &x);
        num = max(num, x);
        for(int j=1; j<k; ++j) {
            scanf("%d", &y);
            num = max(num, y);
            unite(x, y);
        }
    }
//     int cnt = 0;
    set<int> st;
    for(int i=1; i<=num; ++i) {
//         if(pa[i] != find(i)) cnt++;
        pa[i] = find(i);
        st.insert(pa[i]);
    }
//     cout << cnt << endl;
    cout << st.size() << " " << num << endl;
    cin >> q;
    for(int i=0; i<q; ++i) {
        cin >> x >> y;
        if(pa[x] == pa[y]) printf("Yes\n");
        else printf("No\n");
    }
}