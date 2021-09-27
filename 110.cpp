#include<bits/stdc++.h>
using namespace std;
struct node{
    int idx;
    node *left, *right;
    node(int i=-1, node *l=nullptr, node *r=nullptr) : idx(i), left(l), right(r) {}
};
vector<node*> vec;
int maxm = -1;
node* ans;
void dfs(node* cur, int idx) {
    if(idx > maxm) {
        maxm = idx;
        ans = cur;
    }
    if(cur->left != nullptr) dfs(cur->left, idx*2);
    if(cur->right != nullptr) dfs(cur->right, idx*2+1);
}
int main() {
    int n;
    cin >> n;
    vec.resize(n);
    for(int i=0; i<n; ++i) {
        vec[i] = new node(i);
    }
    vector<int> fa(n, -1);
    int l, r, rt=0;
    string a, b;
    for(int i=0; i<n; ++i) {
        cin >> a >> b;
//         if(rt==-1 && (a[0]!='-' || a[0]!='-')) {
//             rt = i;
//         }
        if(a[0]!='-') {
            l = stoi(a.c_str());
//             if(l==rt) rt = i;
            vec[i]->left = vec[l];
            fa[l] = 1;
        }
        if(b[0]!='-') {
            r = stoi(b.c_str());
//             if(r==rt) rt = i;
            vec[i]->right = vec[r];
            fa[r] = 1;
        }
    }
    while(fa[rt] != -1) ++rt;
//     cout << rt << endl;
    dfs(vec[rt], 1);
    if(maxm == n) printf("YES %d\n", ans->idx);
    else printf("NO %d\n", rt);
}