#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int v=-1, node *l=nullptr, node *r=nullptr) : val(v), left(l), right(r) {}
};

vector<int> pre, in;

node *bst(int prel, int prer, int inl, int inr) {
    if(prel>prer || inl>inr) return nullptr;
    node *cur = new node(pre[prel]);
    if(prel==prer) return cur;
    int i=0;
    while(in[i+inl]!=pre[prel]) ++i;
    cur->left = bst(prel+1, prel+i, inl, inl+i+1);
    cur->right = bst(prel+i+1, prer, inl+i+1, inr);
    return cur;
}

vector<int> post;
void tra(node *cur) {
    if(cur==nullptr) return;
    tra(cur->left);
    tra(cur->right);
    post.push_back(cur->val);
//     cout << cur->val << " ";
}

int main() {
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> pre[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> in[i];
    }
    node *root = bst(0, n-1, 0, n-1);
    tra(root);
    cout << post[0] << endl;
}