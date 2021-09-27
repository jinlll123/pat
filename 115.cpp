#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left, *right;
    node(int _v, node *l=nullptr, node *r=nullptr) : val(_v), left(l), right(r) {}
};
node *root = nullptr;
void buildBST(node *cur, int val) {
    if(val <= cur->val) {
//         cout << "l ";
        if(cur->left == nullptr) cur->left = new node(val);
        else buildBST(cur->left, val);
    }
    else {
//         cout << "r ";
        if(cur->right == nullptr) cur->right = new node(val);
        else buildBST(cur->right, val);
    }
}
int main() {
    int n, t;
    cin >> n;
    cin >> t;
    root = new node(t);
    for(int i=1; i<n; ++i) {
        cin >> t;
        buildBST(root, t);
//         cout << endl;
    }
    int n1=1, n2=0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        int tmp=0;
        for(int i=0; i<n1; ++i) {
            auto top = q.front();
            q.pop();
            if(top->left != nullptr) {
//                 cout << "l ";
                tmp++;
                q.push(top->left);
            }
            if(top->right != nullptr) {
//                 cout << "r ";
                tmp++;
                q.push(top->right);
            }
        }
//         cout << tmp << endl;
        if(tmp != 0) {
            n2 = n1;
            n1 = tmp;
        }
    }
    printf("%d + %d = %d\n", n1, n2, n1+n2);
}