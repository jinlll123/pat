#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

map<string, int> si;
map<int ,string> is;
vector<int> pa;
int cur = 0;
vector<int> weight;
void upd(string s, int len) {
    if(si.find(s) == si.end()) {
        si[s] = cur++;
        is[si[s]] = s;
        weight.push_back(len);
    }
    else {
        weight[si[s]] += len;
    }
}

int find(int x) {
    return (x==pa[x] ? x : pa[x]=find(pa[x]));
}

bool unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(x!=y) {
        if(weight[px] >= weight[py]) pa[y] = px;
        else pa[x] = py;
        return true;
    }
    return false;
}

struct head{
    string id;
    int gnum;
    head(string _id, int _gnum) {
        id = _id;
        gnum = _gnum;
    }
};

bool cmp(head* a, head* b) {
    return a->id <= b->id;
}

int main() {
    int n, k;
    cin >> n >> k;
//     weight.resize(2005);
    string a, b;
    int len;
    vector<int> edges;
    for(int i=0; i<n; ++i) {
        cin >> a >> b >> len;
//         int ai, bi;
        upd(a, len);
        upd(b, len);
        edges.push_back(si[a]);
        edges.push_back(si[b]);
    }
    pa.resize(cur);
    for(int i=0; i<cur; ++i) pa[i] = i;
    for(int i=0; i<edges.size(); i+=2) {
//         cout << is[edges[i]] << " " << is[edges[i+1]] << endl;
        unite(edges[i], edges[i+1]);
    }
//     cout << pa.size() << " <-> " << weight.size() << endl;
    map<int, int> gw;  // gangs weight
    vector<int> gnum(cur, 0);
    for(int i=0; i<pa.size(); ++i) {
        pa[i] = find(pa[i]);
        gnum[pa[i]]++;
        gw[pa[i]] += weight[i];
    }
    vector<head*> res;
    for(auto item : gw) {
        if(item.second/2 > k && gnum[item.first] > 2) {
            res.push_back(new head(is[item.first], gnum[item.first]));
        }
    }
    sort(res.begin(), res.end(), cmp);
    cout << res.size() << endl;
    for(auto h : res) {
        cout << h->id << " " << h->gnum << endl;
    }
}