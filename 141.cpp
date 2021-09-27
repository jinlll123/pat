#include<bits/stdc++.h>
using namespace std;
struct school{
    string name;
    int t, a, b, tws, ns, rk;
    school(string _name="") : name(_name), t(0), a(0), b(0), tws(0), ns(0), rk(0) {}
    bool operator < (const school& s) const {
        if(tws != s.tws) return tws > s.tws;
        else if(ns != s.ns) return ns < s.ns;
        return name < s.name;
    }
};
int main() {
    int n;
    cin >> n;
    string id, sch;
    int score;
    map<string, school> mp;
    for(int i=0; i<n; ++i) {
        cin >> id >> score >> sch;
        for(int j=0; j<sch.length(); ++j) {
            if('A'<=sch[j] && sch[j]<='Z') {
                sch[j] += 32;
            }
        }
        if(mp.find(sch) == mp.end()) {
            school tmp(sch);
            mp[sch] = tmp;
        }
        mp[sch].ns++;
        if(id[0]=='B') {
            mp[sch].b += score;
        }else if(id[0]=='A') {
            mp[sch].a += score;
        }else {
            mp[sch].t += score;
        }
    }
    vector<school> vec;
    for(auto item : mp) {
        item.second.tws = item.second.b/1.5 + item.second.a + item.second.t*1.5;
        vec.push_back(item.second);
    }
    sort(vec.begin(), vec.end());
    vec[0].rk = 1;
    for(int i=1; i<vec.size(); ++i) {
        if(vec[i].tws == vec[i-1].tws) {
            vec[i].rk = vec[i-1].rk;
        }else {
            vec[i].rk = i+1;
        }
    }
    cout << vec.size() << endl;
    for(auto s : vec) {
        printf("%d %s %d %d\n", s.rk, s.name.c_str(), s.tws, s.ns);
    }
}