#include<iostream>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int _v=0, node* _l=nullptr, node* _r=nullptr) : val(_v), left(_l), right(_r) {}
};
int getH(node* root) {
    if(root == nullptr) return 0;
    else return max(getH(root->left), getH(root->right))+1;
}
node* R(node* root) {  // 右旋
    node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node* L(node* root) {
    node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node* RL(node* root) {
    root->right = R(root->right);
    return L(root);
}
node* LR(node* root) {
    root->left = L(root->left);
    return R(root);
}
node* insert(node* root, int val) {
    if(root==nullptr) {
        root = new node(val);
    }
    else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getH(root->left) - getH(root->right) == 2)
            root = val < root->left->val ? R(root) : LR(root);
    }
    else {
        root->right = insert(root->right, val);
        if(getH(root->right) - getH(root->left) == 2)
            root = val > root->right->val ? L(root) : RL(root);
    }
    return root;
}
int main() {
    int n, t;
    cin >> n;
    node* root = nullptr;
    for(int i=0; i<n; ++i) {
        cin >> t;
        root = insert(root, t);
    }
    cout << root->val << endl;
}