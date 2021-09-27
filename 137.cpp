#include<bits/stdc++.h>
using namespace std;

struct person{
    string id;
    int gp, gm, gf, gt;
    person(string _id="", int _p=0, int _m=-1, int _f=-1, int _t=0) : id(_id), gp(_p), gm(_m), gf(_f), gt(_t) {}
};

bool cmp(person* a, person* b) {
    if(a->gt != b->gt) return a->gt > b->gt;
    return a->id < b->id;
}

int main() {
    int p, m, n, g;
    string id;
    cin >> p >> m >> n;
    map<string, person*> mp;
    for(int i=0; i<p; ++i) {
        cin >> id >> g;
        if(g >= 200) {
            mp[id] = new person(id, g);
        }
    }
    for(int i=0; i<m; ++i) {
        cin >> id >> g;
        if(mp.find(id) != mp.end()) {
            mp[id]->gm = g;
        }
    }
    for(int i=0; i<n; ++i) {
        cin >> id >> g;
        if(mp.find(id) != mp.end()) {
            mp[id]->gf = g;
        }
    }
    vector<person*> vec;
    for(auto item : mp) {
        person *cur = item.second;
        if(cur->gf >= cur->gm) {
            cur->gt = cur->gf;
        }else {
            cur->gt = int(cur->gf*0.6 + cur->gm*0.4 + 0.5);
        }
        if(cur->gt >= 60) {
//             if(cur->gm==0) cur->gm=-1;
//             if(cur->gf==0) cur->gf=-1;
            vec.push_back(cur);
        }
            
    }
    sort(vec.begin(), vec.end(), cmp);
    for(auto cur : vec) {
        printf("%s %d %d %d %d\n", cur->id.c_str(), cur->gp, cur->gm, cur->gf, cur->gt);
    }
}