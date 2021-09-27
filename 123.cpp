#include<bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node* left, * right;
    node(int _v = -1, node* _l = nullptr, node* _r = nullptr) : val(_v), left(_l), right(_r) {}
};
int getH(node* cur) {
    if (cur == nullptr) return 1;
    return max(getH(cur->left), getH(cur->right)) + 1;
}
int getBal(node* cur) {
    return getH(cur->left) - getH(cur->right);
}
node* R(node* cur) {
    node* tmp = cur->left;
    cur->left = tmp->right;
    tmp->right = cur;
    return tmp;
}
node* L(node* cur) {
    node* tmp = cur->right;
    cur->right = tmp->left;
    tmp->left = cur;
    return tmp;
}
node* LR(node* cur) {
    cur->left = L(cur->left);
    return R(cur);
}
node* RL(node* cur) {
    cur->right = R(cur->right);
    return L(cur);
}
node* insert(node* cur, int val) {
    if (cur == nullptr) {
        return new node(val);
    }
    if (val < cur->val) cur->left = insert(cur->left, val);
    else cur->right = insert(cur->right, val);
    int bal = getBal(cur);
    if (abs(bal) < 2) {
        return cur;
    }
    else {
        if (bal > 0) {  // left > right
            if (getBal(cur->left) > 0) {
                return R(cur);
            }
            else {
                return LR(cur);
            }
        }
        else {
            if (getBal(cur->right) < 0) {
                return L(cur);
            }
            else {
                return RL(cur);
            }
        }
    }
}
int n;
bool fg = true;
void isC(node* cur, int idx) {
    if (cur == nullptr || !fg) return;
    if (idx > n) fg = false;
    isC(cur->left, idx * 2);
    isC(cur->right, idx * 2 + 1);
}
int main() {
    cin >> n;
    int val;
    node* root=nullptr;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
//         cout << "i = " << i << " ==" << root->val << endl;
    }
    queue<node*> q;
    vector<int> lv;
    q.push(root);
    int k=1;
    while(!q.empty()) {
//         cout << k << endl;
        int tmp = 0;
        for(int i=0; i<k; ++i) {
            auto top = q.front();
            q.pop();
            lv.push_back(top->val);
            if(top->left!=nullptr) {
                q.push(top->left);
                tmp++;
            }
            if(top->right!=nullptr) {
                q.push(top->right);
                tmp++;
            }
        }
        k = tmp;
    }
    for (int i = 0; i < lv.size(); ++i) {
        cout << lv[i] << " \n"[i == lv.size() - 1];
    }
    isC(root, 1);
    if (fg) cout << "YES\n";
    else cout << "NO\n";
}