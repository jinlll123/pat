#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> post;
vector<int> in;

struct node {
    int val;
    node* left;
    node* right;
    node(int _v = 0, node* _l = nullptr, node* _r = nullptr) : val(_v), left(_l), right(_r) {}
};

node* pi2t(int pr, int il, int ir) {
//     cout << pr << " " << il << " " << ir << endl;
    if (il == ir) return new node(in[il]);
    if (il > ir || pr < 0 || pr >= post.size()) return nullptr;  // 
    //     cout << " " << post[pr];
    node* cur = new node(post[pr]);
    int i = il;
    while (in[i] != post[pr]) ++i;
    cur->left = pi2t(pr - 1 - ir + i, il, i - 1);
    cur->right = pi2t(pr - 1, i + 1, ir);
    return cur;
}

int main() {
    int n;
    cin >> n;
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i) cin >> post[i];
    for (int i = 0; i < n; ++i) cin >> in[i];
    node* root = pi2t(n - 1, 0, n - 1);
    queue<node*> q;
    cout << root->val;
    q.push(root);
    while (!q.empty()) {
        node* cur = q.front();
        q.pop();
        if (cur->left != nullptr) {
            cout << " " << cur->left->val;
            q.push(cur->left);
        }
        if (cur->right != nullptr) {
            cout << " " << cur->right->val;
            q.push(cur->right);
        }
    }
    cout << endl;
}