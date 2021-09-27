#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// struct node{
//     int id, h;
// };
vector<int> rt;
vector<vector<int>> g;
double res;
int n;
double p, r;
void fun(int id, double pri) {
//     cout << ">>> " << id << " " << h << endl;
    if(rt[id]!=-1) {
//         cout << id << " t=" << rt[id] << " p=" << p << " h=" << h << endl;
//         double tmp = rt[id]*p;
//         for(int i=0; i<h; ++i) tmp*=r;
        res += rt[id]*p*pri;
    }
    else {
        for(int i : g[id]) {
            fun(i, pri*r);
        }
    }
}
int main() {
    cin >> n >> p >> r;
    r = 1 + r/100;
//     cout << "r=" << r << endl;
    rt.resize(n, -1);
    g.resize(n);
    int k, t;
    for(int i=0; i<n; ++i) {
        cin >> k;
        if(k==0) {
            cin >> t;
            rt[i] = t;
        }
        else {
            for(int j=0; j<k; ++j) {
                cin >> t;
                g[i].push_back(t);
            }
        }
    }
    res = 0;
    int h=0;
    fun(0, 1);
    printf("%.1f\n", res);
}