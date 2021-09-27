#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left, *right;
    node(int v=-1, node *l=nullptr, node *r=nullptr) : val(v), left(l), right(r) {}
};
vector<int> pre, in;

node* bst(int prel, int prer, int inl, int inr) {
    if(prel > prer || inl > inr) return nullptr;
    node *cur = new node(pre[prel]);
    if(prel==prer && inl==inr) return cur;
    int i=0;
    for(; inl+i<=inr; ++i) {
        if(in[inl+i] == pre[prel]) break;
    }
    cur->left = bst(prel+1, prel+i, inl, inl+i-1);
    cur->right = bst(prel+i+1, prer, inl+i+1, inr);
    return cur;
}

// void tra(node *cur) {
//     if(cur == nullptr) return;
//     cout << cur->val << " ";
//     tra(cur->left);
//     tra(cur->right);
// }

bool find(node *cur, int tar, vector<int> &path) {
    if(cur == nullptr) return false;
//     cout << cur->val << endl;
    path.push_back(cur->val);
    if(cur->val == tar) {
        return true;
    }else {
        bool fl = find(cur->left, tar, path);
        if(fl) return true;
        bool fr = find(cur->right, tar, path);
        if(fr) return true;
        path.pop_back();
    }
    return false;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    pre.resize(n);
    in.resize(n);
    for(int i=0; i<n; ++i) scanf("%d", &in[i]);
    for(int i=0; i<n; ++i) scanf("%d", &pre[i]);
    node *root = bst(0, n-1, 0, n-1);
//     cout << root->val;
//     tra(root);
    int a, b;
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &a, &b);
        vector<int> pa, pb;
//         cout << "find " << a << endl;
        bool fa = find(root, a, pa);
//         cout << "find " << b << endl;
        bool fb = find(root, b, pb);
//         for(auto p : pa) cout << p << " ";
//         cout << endl;
//         for(auto p : pb) cout << p << " ";
//         cout << endl;
        if(!fa && !fb) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        }else if(!fa){
            printf("ERROR: %d is not found.\n", a);
        }else if(!fb){
            printf("ERROR: %d is not found.\n", b);
        }else {
            int k=0;
            for(; k<pa.size(); ++k) {
                if(pa[k] == b) break;
            }
            if(k < pa.size()) {
                printf("%d is an ancestor of %d.\n", b, a);
                continue;
            }
            
            k=0;
            for(; k<pb.size(); ++k) {
                if(pb[k] == a) break;
            }
            if(k < pb.size()) {
                printf("%d is an ancestor of %d.\n", a, b);
                continue;
            }
            
            int res;
            for(int i=0; i<min(pa.size(), pb.size()); ++i) {
                if(pa[i] != pb[i]) break;
                res = pa[i];
            }
            printf("LCA of %d and %d is %d.\n", a, b, res);
            
        }
    }
}