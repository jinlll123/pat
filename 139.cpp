#include<bits/stdc++.h>
using namespace std;
struct person{
    int id;
    int gender;
    person(int _id, int _g) : id(_id), gender(_g) {}
};

struct friends{
    int a, b;
    friends(int _a=0, int _b=0) : a(_a), b(_b) {}
    bool operator < (const friends& f) const {
        if(a != f.a) return a < f.a;
        return b < f.b;
    }
};
int main() {
    int n, m, k, a, b;
    string as, bs;
    cin >> n >> m;
    map<int, vector<person>> g;
    for(int i=0; i<m; ++i) {
        cin >> as >> bs;
        int ai = stoi(as.c_str());
        int bi = stoi(bs.c_str());
        g[abs(ai)].push_back(person(abs(bi), (bs[0]=='-' ? -1:1)));
        g[abs(bi)].push_back(person(abs(ai), (as[0]=='-' ? -1:1)));
    }
    cin >> k;
    for(int i=0; i<k; ++i) {
        cin >> a >> b;
        int ap = abs(a), bp = abs(b);
        if(g.find(ap)==g.end() || g.find(bp)==g.end()) {
            printf("0\n");
            continue;
        }
        vector<bool> isF(10005, false);
        for(auto p : g[bp]) {
            isF[p.id] = true;
        }
        vector<friends> r;
        for(auto p1 : g[ap]) {
            if(p1.id==bp || p1.id==ap) continue;
            if(p1.gender*a>0) {
                for(auto p2 : g[p1.id]) {
                    if(p2.id==bp || p2.id==ap || p2.id==p1.id) continue;
                    if(p2.gender*b>0 && isF[p2.id]) {
                        r.push_back(friends(p1.id, p2.id));
                    }
                }
            }
        }
        sort(r.begin(), r.end());
        cout << r.size() << endl;
        for(int i=0; i<r.size(); ++i) {
            printf("%04d %04d\n", r[i].a, r[i].b);
        }
    }
}