#include<iostream>
#include<vector>
#include <map>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

struct node {
    int exp;
    double coe;
    node(int e=0, double c=0) : exp(e), coe(c) {}
};

bool cmp(node* a, node* b) {
    return a->exp > b->exp;
}

int main() {
    vector<node*> vec;
    map<int, node*> mp;
    for(int k=0; k<2; ++k) {
        int n, e;
        double c;
        cin >> n;
        for(int i=0; i<n; ++i) {
            cin >> e >> c;
            if(mp.find(e) != mp.end()) mp[e]->coe += c;
            else {
                node *tmp = new node(e, c);
                mp[e] = tmp;
            }
        }
    }
    for(auto item : mp) {
        if(abs(item.second->coe-0) < 1e-9) continue;
        vec.push_back(item.second);
    }
    sort(vec.begin(), vec.end(), cmp);
    int sz = vec.size();
    cout << sz;
    for(int i = 0; i<sz; ++i) {
        cout << " " << vec[i]->exp << " " << fixed << setprecision(1) << vec[i]->coe;
    }
    cout << endl;
}