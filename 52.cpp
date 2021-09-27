#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
struct node{
    int ads, key, nxt;
    node(int _a, int _k, int _n) : ads(_a), key(_k), nxt(_n) {}
};

bool cmp(node* a, node* b) {
    return a->key < b->key;
}

int main() {
    int n, fst;
//     int ed = -2;
    cin >> n >> fst;
    if(fst == -1) {
        cout << 0 << " " << -1 << endl;
    }
    else {
        vector<node*> vec;
    //     map<int, int> mp;
    //     mp[fst]++;
        vector<int> keys(100005, 0);
        vector<int> nxts(100005, 0);
        int ads, key, nxt;
        for(int i=0; i<n; ++i) {
            cin >> ads >> key >> nxt;
            keys[ads] = key;
            nxts[ads] = nxt;
    //         if(ed==-2) {
    //             if(nxt==-1) ed=-1;
    //             else {
    //                 mp[ads]++;
    //                 mp[nxt]++;
    //             }
    //         }
    //         vec.push_back(new node(ads, key, nxt));
        }
        int cur = fst;
        for(int i=0; i<n; ++i) {
            if(cur==-1) break;
    //         cout << cur << "-\n";
            vec.push_back(new node(cur, keys[cur], nxts[cur]));
            cur = nxts[cur];
        }
    //     if(ed==-2) {
    //         for(auto it : mp) {
    //             if(it.second==1) ed = it.first;
    //         }
    //     }
    //     cout << "ed = " << ed << endl;
        sort(vec.begin(), vec.end(), cmp);
        int sz = vec.size();
        printf("%d %05d\n", sz, vec[0]->ads);
        for(int i=0; i<sz-1; ++i) {
            printf("%05d %d %05d\n", vec[i]->ads, vec[i]->key, vec[i+1]->ads);
        }
        if(cur == -1) printf("%05d %d %d\n", vec[sz-1]->ads, vec[sz-1]->key, -1);
        else printf("%05d %d %05d\n", vec[sz-1]->ads, vec[sz-1]->key, cur);
    }
    
}