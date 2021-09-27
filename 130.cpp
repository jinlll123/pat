#include<bits/stdc++.h>
using namespace std;
struct node{
    string data;
    node *left, *right;
    node(string _d="", node *l=nullptr, node *r=nullptr) : data(_d), left(l), right(r) {}
};

node *root=nullptr;

void output(node* cur) {
    if(cur == nullptr) return;
    bool fg = (cur->left != nullptr || cur->right != nullptr) && cur != root;
    if(fg) cout << "(";
    output(cur->left);
    cout << cur->data;
    output(cur->right);
    if(fg) cout << ")";
}

int main() {
    int n;
    cin >> n;
    string data;
    int l, r;
    vector<node*> vec(n+1);
    vector<int> pa(n+1, -1);
    for(int i=1; i<=n; ++i) {
        vec[i] = new node();
    }
    int rt=-1;
    for(int i=1; i<=n; ++i) {
        cin >> data >> l >> r;
        vec[i]->data = data;
        if(l!=-1) {
            vec[i]->left = vec[l];
            pa[l] = i;
            if(rt==-1) rt = i;
        }
        if(r!=-1) {
            vec[i]->right = vec[r];
            pa[r] = i;
            if(rt==-1) rt = i;
        }
    }
    if(n==1) rt = 1;
//     for(int i=1; i<=n; ++i) {
//         if(pa[i] != -1) {
//             rt = i;
//             break;
//         }
//     }
    while(pa[rt] != -1) rt = pa[rt];
    root = vec[rt];
    output(root);
    cout << endl;
}