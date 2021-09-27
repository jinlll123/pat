#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct person{
    int uid, *psco, tsco, rk, perf;
    person(int _uid, int k) {
        uid = _uid;
        psco = new int[k+1];
        for(int i=0; i<=k; ++i) psco[i] = -2;
        tsco = 0;
        rk = 1;
        perf = 0;
    }
};
bool cmp(person* a, person* b) {
    if(a->tsco != b->tsco) return a->tsco > b->tsco;
    if(a->perf != b->perf) return a->perf > b->perf;
    return a->uid < b->uid;
}
int main() {
    int n, k, s;
    scanf("%d %d %d", &n, &k, &s);
    vector<int> msco(k+1);
    for(int i=1; i<=k; ++i) cin >> msco[i];
    map<int, person*> mp;
    int uid, pnum, ps;
    for(int i=0; i<s; ++i) {
        scanf("%d %d %d", &uid, &pnum, &ps);
        if(mp.find(uid)==mp.end()) {
            mp[uid] = new person(uid, k);
            mp[uid]->psco[pnum] = ps;
            if(ps > 0) mp[uid]->tsco += ps;
            if(ps==msco[pnum]) mp[uid]->perf++;
        }
        else {
            person* curp = mp[uid];
            if(ps<=0 && curp->psco[pnum]==-2) {
                curp->psco[pnum] = ps;
            }
            else if(curp->psco[pnum] < ps) {
                curp->tsco += (ps - (curp->psco[pnum]>0 ? curp->psco[pnum]:0));
                curp->psco[pnum] = ps;
                if(ps==msco[pnum]) curp->perf++;
            }
        }
    }
    vector<person*> vec;
    for(auto it : mp) {
        if(it.second->tsco==0) {
            int i=1;
            for(; i<=k; ++i) if(it.second->psco[i]>=0) break;
            if(i>k) continue;
        }
        vec.push_back(it.second);
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i=1; i<vec.size(); ++i) {
        if(vec[i]->tsco == vec[i-1]->tsco) vec[i]->rk = vec[i-1]->rk;
        else vec[i]->rk = i+1;
    }
    for(auto p : vec) {
        printf("%d %05d %d",p->rk, p->uid, p->tsco);
        for(int i=1; i<=k; ++i) {
            cout << " ";
            if(p->psco[i]==-2) cout << '-';
            else if(p->psco[i]==-1) cout << 0;
            else cout << p->psco[i];
        }
//         cout << " " << p->perf;
        cout << endl;
    }
    
}