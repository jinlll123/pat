#include<bits/stdc++.h>
using namespace std;
struct edge{
    int a, b;
    edge(int _a, int _b) : a(_a), b(_b) {}
};

int main() {
    int n, m, a, b, k;
    scanf("%d %d", &n, &m);
    vector<edge> vec;
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &a, &b);
        vec.push_back(edge(a, b));
    }
    scanf("%d", &k);
    for(int i=0; i<k; ++i) {
        vector<int> colors(n);
        set<int> s;
        int j;
        for(j=0; j<n; ++j) {
            scanf("%d", &colors[j]);
            s.insert(colors[j]);
        }
        j=0;
        for(; j<m; ++j) {
            if(colors[vec[j].a] == colors[vec[j].b])
                break;
        }
        if(j<m) printf("No\n");
        else printf("%d-coloring\n", s.size());
    }
}