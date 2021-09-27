#include<bits/stdc++.h>
using namespace std;
struct node{
    int add, val, nxt;
    node(int a=-1, int v=-1, int nx=-1) : add(a), val(v), nxt(nx) {}
}lst[100000];
int main() {
    int fadd, n, k;
    scanf("%d %d %d", &fadd, &n, &k);
    int add, val, nxt;
    for(int i=0; i<n; ++i) {
        scanf("%d", &add);
        lst[add].add = add;
        scanf("%d %d", &lst[add].val, &lst[add].nxt);
    }
    vector<vector<int>> vec(3);
    int cur = fadd;
    while(cur != -1) {
//         cout << cur << endl;
        if(lst[cur].val < 0) {
            vec[0].push_back(cur);
        }else if(lst[cur].val <= k){
            vec[1].push_back(cur);
        }else {
            vec[2].push_back(cur);
        }
        cur = lst[cur].nxt;
    }
//     for(int i=0; i<3; ++i) {
//         cout << vec[i].size() << endl;
//     }
    for(int i=1; i<3; ++i) {
        for(int j=0; j<vec[i].size(); ++j)
            vec[0].push_back(vec[i][j]);
    }
    int i=0;
    for(; i<vec[0].size()-1; ++i) {
        printf("%05d %d %05d\n", vec[0][i], lst[vec[0][i]].val, vec[0][i+1]);
    }
    printf("%05d %d -1\n", vec[0][i], lst[vec[0][i]].val);
}