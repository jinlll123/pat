#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<int> father;

int find(int x) {
    return (x==father[x] ? x : father[x] = find(father[x]));
}

bool unite(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if(fa != fb) {
        father[fb] = fa;
        return true;
    }
    return false;
}

struct edge{
    int f, t;
    edge(int _f, int _t) : f(_f), t(_t) {}
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> evec;
    for(int i=0; i<m; ++i) {
        int f, t;
        cin >> f >> t;
        --f, --t;
        evec.push_back(edge(f, t));
    }
    int cur;
    for(int i=0; i<k; ++i) {
        father.clear();
        for(int j=0; j<n; ++j) father.push_back(j);
        
        cin >> cur;
        --cur;
        for(auto e : evec) {
            if(e.f!=cur && e.t!=cur) unite(e.f, e.t);
        }
        
//         for(int i=0; i<father.size(); ++i) {
//             cout << father[i] << " ";
//         }
//         cout << endl;
        set<int> st;
        for(int i=0; i<father.size(); ++i) {
            if(father[i]!=cur) st.insert(find(i));
        }
        cout << st.size() - 1 << endl;
    }
}