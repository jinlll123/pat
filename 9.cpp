#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

struct item{
    double c;
    int e;
    item(double _c, int _e) : c(_c), e(_e) {}
};

bool cmp(item* a, item* b) {
    return a->e > b->e;
}

int main() {
    int n;
    cin >> n;
    vector<item*> equ;
    double c;
    int e;
    for (int i = 0; i < n; ++i) {
        cin >> e >> c;
        equ.push_back(new item(c, e));
    }
    cin >> n;
    map<int, item*> mp;
    int et;
    double ct;
    for (int i = 0; i < n; ++i) {
        cin >> e >> c;
        for (auto tmp : equ) {
            et = e + tmp->e;
            ct = c * tmp->c;
            if (mp.find(et) != mp.end()) {
                mp[et]->c += ct;
            }
            else mp[et] = new item(ct, et);
        }
    }
    equ.clear();
    for (auto tmp : mp) {
        if(abs(tmp.second->c - 0) > 1e-8)
            equ.push_back(tmp.second);
    }
    sort(equ.begin(), equ.end(), cmp);
    cout << equ.size();
    for (auto tmp : equ) {
        cout << " " << tmp->e << " " << fixed << setprecision(1) << tmp->c;
    }
    cout << endl;
}