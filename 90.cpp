#include<bits/stdc++.h>
using namespace std;
vector<int> path;
vector<int> lv;
int fun(int x) {
    if(lv[x] != -1) return lv[x];
    else if(path[x]==-1) {
        lv[x] = 0;
        return 0;
    }
    lv[x] = fun(path[x])+1;
    return lv[x];
}
int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    r = 1+r/100;
    path.resize(n, -1);
    for(int i=0; i<n; ++i) cin >> path[i];
    lv.resize(n, -1);
    int mlv = -1, cnt=0;
    for(int i=0; i<n; ++i) {
        int tmp = fun(i);
        if(tmp > mlv) {
            cnt = 1;
            mlv = tmp;
        }
        else if(tmp == mlv) cnt++;
    }
//     cout << r << endl;
//     cout << mlv << endl;
    double res = p;
    for(int i=0; i<mlv; ++i) {
        res *= r;
    }
    printf("%.2f %d\n", res, cnt);
}