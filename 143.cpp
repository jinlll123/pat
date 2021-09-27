#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left, *right;
    node(int v=-1, node *l=nullptr, node *r=nullptr) : val(v), left(l), right(r) {}
};
vector<int> pre;
node* bst(int l, int r) {
    if(l>r) return nullptr;
    node *cur = new node(pre[l]);
    if(l==r) return cur;
    int i=1;
    for(; l+i<=r; ++i) {
        if(pre[l+i]>pre[l]) break;
    }
    cur->left = bst(l+1, l+i-1);
    cur->right = bst(l+i, r);
    return cur;
}
void tra(node* cur) {
    if(cur==nullptr) return;
    cout << cur->val << " ";
    tra(cur->left);
    tra(cur->right);
}

bool find(node* cur, int tar, vector<int> &vec) {
    if(cur==nullptr) return false;
    vec.push_back(cur->val);
    if(cur->val == tar) {
        return true;
    }else if(cur->val < tar) {
        return find(cur->right, tar, vec);
    }else {
        return find(cur->left, tar, vec);
    }
}

int main() {
    int m, n, a, b;
    scanf("%d %d", &m, &n);
    pre.resize(n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &pre[i]);
    }
    node *root = bst(0, n-1);
//     tra(root);
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &a, &b);
        vector<int> va, vb;
        bool fa = find(root, a, va);
        bool fb = find(root, b, vb);
        if(!fa && !fb) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        }else if(!fa) {
            printf("ERROR: %d is not found.\n", a);
        }else if(!fb) {
            printf("ERROR: %d is not found.\n", b);
        }else {
            int anc = va[0], j=1, len = min(va.size(), vb.size());
//             cout << j << " " << len << endl;
            for(; j<len; ++j) {
                if(va[j] != vb[j]) break;
//                 cout << j << endl;
                anc = va[j];
            }
            if(j<len) printf("LCA of %d and %d is %d.\n", a, b, anc);
            else if(va.size() > vb.size()) {
                printf("%d is an ancestor of %d.\n", b, a);
            }else {
                printf("%d is an ancestor of %d.\n", a, b);
            }
            
//             if(va[va.size()-2]==b) {
//                 cout << "a- " << va[va.size()-2] << endl;
//                 printf("%d is an ancestor of %d.\n", b, a);
//             }else if(vb[vb.size()-2]==a) {
//                 cout << "b- " << vb[vb.size()-2] << endl;
//                 printf("%d is an ancestor of %d.\n", a, b);
//             }else {
//                 int anc = va[0];
//                 for(int j=1; j<min(va.size(), vb.size()); ++j) {
//                     if(va[j] != vb[j]) break;
//                     anc = va[j];
//                 }
//                 printf("LCA of %d and %d is %d.\n", a, b, anc);
//             }
        }
    }
}
