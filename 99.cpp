#include<bits/stdc++.h>
using namespace std;
struct node {
    node* left, * right;
    int val;
    node(int _v = -1, node* _l = nullptr, node* _r = nullptr) : val(_v), left(_l), right(_r) {}
};
int cnt;
vector<int> nums;
void fillTree(node* cur) {
    if (cur == nullptr) return;
    /*if (cur->left == nullptr && cur->right == nullptr) {
        cur->val = nums[cnt++];
        return;
    }
    else {*/
    fillTree(cur->left);
//     cout << cur << " " << nums[cnt] << endl;
    cur->val = nums[cnt++];
//     cout << cnt << endl;
    fillTree(cur->right);
    //}
}
int main() {
    int n, l, r;
    cin >> n;
    vector<node*> nds(n);
    for (int i = 0; i < n; ++i) 
        nds[i] = new node(-1, nullptr, nullptr);
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        if (l != -1) nds[i]->left = nds[l];
        if (r != -1) nds[i]->right = nds[r];
    }
    /*for (int i = 0; i < n; ++i) {
        if (nds[i]->left == nullptr) cout << "null";
        else cout << nds[i]->left;
        cout << " ";
        if (nds[i]->right == nullptr) cout << "null";
        else cout << nds[i]->right;
        cout << endl;
    }*/
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
//     for (int i = 0; i < n; ++i) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
    cnt = 0;
    fillTree(nds[0]);
//     cout << "cnt = " << cnt << endl;
    vector<int> res;
    queue<node*> q;
    int k = 1;
    q.push(nds[0]);
    while (!q.empty()) {
        int tmp = 0;
        for (int i = 0; i < k; ++i) {
            auto top = q.front();
            q.pop();
            res.push_back(top->val);
            if (top->left != nullptr) {
                q.push(top->left);
                tmp++;
            }
            if (top->right != nullptr) {
                q.push(top->right);
                tmp++;
            }
        }
        k = tmp;
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " \n"[i == res.size() - 1];
    }
}