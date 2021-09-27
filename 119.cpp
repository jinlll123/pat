#include<iostream>
#include<vector>
using namespace std;
struct node {
    int val;
    node* left, * right;
    node(int _v = -1, node* l = nullptr, node* r = nullptr) : val(_v), left(l), right(r) {}
};
int n;
bool fg = true;
vector<int> pre;
vector<int> post;

node* ppi(int prel, int prer, int postl, int postr) {
    if(prel > prer || postl > postr) {
        fg = false;
        return nullptr;
    }
//     printf("%d %d %d %d\n", prel, prer, postl, postr);
    node* tmp = new node(pre[prel]);
    if (prel == prer) return tmp;
    ++prel;
    --postr;
    //if (prer - prel == 1 || postr - postl == 1) fg = false;
    int cur = 0;
    for (; cur <= postr - postl; ++cur) {
        if (post[postl + cur] == pre[prel]) break;
    }
//     cout << cur << endl;
    tmp->left = ppi(prel, prel + cur, postl, postl + cur);
    tmp->right = ppi(prel + cur + 1, prer, postl + cur + 1, postr);
//     if (prel > prel + cur || postl > postl + cur) {
//         fg = false;
//         tmp->left = nullptr;
//     }else { 
//         tmp->left = ppi(prel, prel + cur, postl, postl + cur); 
//     }

//     if (prel + cur + 1 > prer || postl + cur + 1 > postr) {
//         fg = false;
//         tmp->right = nullptr;
//     }else {
//         tmp->right = ppi(prel + cur + 1, prer, postl + cur + 1, postr);
//     }

    //tmp->left = (prel > prer ? nullptr : ppi(prel, prel + cur, postl, postl + cur));
    //tmp->right = (postl > postr ? nullptr : ppi(prel + cur + 1, prer, postl + cur + 1, postr));
    return tmp;
}

vector<int> in;
void inorder(node* cur) {
    if (cur == nullptr) return;
    inorder(cur->left);
    in.push_back(cur->val);
    inorder(cur->right);
}

int main() {
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    node* root = ppi(0, n - 1, 0, n - 1);
    inorder(root);
    if (fg) printf("Yes\n");
    else printf("No\n");
    for (int i = 0; i < in.size(); ++i) {
        cout << in[i] << " \n"[i == in.size() - 1];
    }
}