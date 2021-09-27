#include<bits/stdc++.h>
using namespace std;
struct person{
    int mest, area;
    bool dt;
    person(int _mest=0, int _area=0, bool _dt=false): mest(_mest), area(_area), dt(_dt) {}
}a[10005];

struct node{
    int fid, fnum, fmest, farea;
    node(int _fid, int _fnum, int _fmest, int _farea) : fid(_fid), fnum(_fnum), fmest(_fmest), farea(_farea) {}
};

bool cmp(node *a, node *b) {
    if(abs(a->farea*1.0/a->fnum - b->farea*1.0/b->fnum) < 0.001) return a->fid < b->fid;
    return a->farea*1.0/a->fnum > b->farea*1.0/b->fnum;
}

vector<int> pa;
int findF(int x) {
    return (x==pa[x] ? x:pa[x] = findF(pa[x]));
}

// void unite(int x, int y) {
//     int fx = findF(x);
//     int fy = findF(y);
//     if(fx != fy) {
//         if(fx < fy) pa[pa[y]] = fx;
//         else pa[pa[x]] = fy;
//     }
// }

void unite(int x, int y) {
    int fx = findF(x);
    int fy = findF(y);
    if(fx != fy) {
        if(fx < fy) pa[fy] = fx;
        else pa[fx] = fy;
    }
}

int main() {
    int n, id, fa, mo, k, chd, mest, area;
    scanf("%d", &n);
    pa.resize(10005);
    for(int i=0; i<10005; ++i) pa[i] = i;
    for(int i=0; i<n; ++i) {
        scanf("%d %d %d %d ", &id, &fa, &mo, &k);
        a[id].dt = true;
        a[fa].dt = true;
        a[mo].dt = true;
        if(fa!=-1) unite(id, fa);
        if(mo!=-1) unite(id, mo);
        int tmp;
        for(int j=0; j<k; ++j) {
            scanf("%d", &tmp);
            a[tmp].dt = true;
            unite(id, tmp);
        }
        scanf("%d %d", &mest, &area);
        a[id].mest = mest;
        a[id].area = area;
    }
    map<int, node*> mp;
    for(int i=0; i<10005; ++i) {
        if(a[i].dt) {
            pa[i] = findF(i);
//             cout << i << " -> " << pa[i] << endl;
            if(mp.find(pa[i])==mp.end()) {
                mp[pa[i]] = new node(pa[i], 1, a[i].mest, a[i].area);
            }
            else {
                mp[pa[i]]->fnum++;
                mp[pa[i]]->fmest += a[i].mest;
                mp[pa[i]]->farea += a[i].area;
            }
        }
    }
    vector<node*> res;
    for(auto it : mp) {
        res.push_back(it.second);
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end(), cmp);
    for(int i=0; i<res.size(); ++i) {
        printf("%04d %d %.3f %.3f\n", res[i]->fid, res[i]->fnum, res[i]->fmest*1.0/res[i]->fnum, res[i]->farea*1.0/res[i]->fnum);
    }
    
}