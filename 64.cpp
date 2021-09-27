#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int _v, node* l, node* r) : val(_v), left(l), right(r) {}
};
int n;
vector<int> tree;
node* levt(int l, int r, int k, int p) {
    if(k==1) {
        if(l==r) return new node(tree[l], nullptr, nullptr);
        else return nullptr;
    }
    int len=r-l+1;
//     printf("len=%d, ", len);
    int rst = len-k+1, sl=(k-1)/2, sr=(k-1)/2;
//     printf("rst=%d, ", rst);
    if(rst <= k/2) {
        sl+=rst;
    }
    else {
        sl+=(k/2), sr+=(rst-(k/2));
    }
//     printf("l=%d, l+sl-1=%d, r-sr+1=%d, r=%d, k=%d, sl=%d, sr=%d\n", l, l+sl-1, r-sr+1, r, k, sl, sr);
//     cout << tree[sl] << endl;
    return new node(tree[p+sl], levt(l, l+sl-1, k/2, l), levt(r-sr+1, r, k/2, p+sl+1));
}

int main() {
    cin >> n;
    tree.resize(n);
    for(int i=0; i<n; ++i) cin >> tree[i];
    sort(tree.begin(), tree.end());
    int k=1;
    while(n/k > 1) {
        k*=2;
    }
    node* root = levt(0, n-1, k, 0);
    vector<int> res;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* cur = q.front();
        q.pop();
        res.push_back(cur->val);
        if(cur->left != nullptr) q.push(cur->left);
        if(cur->right != nullptr) q.push(cur->right);
    }
    for(int i=0; i<n; ++i) {
        cout << res[i] << " \n"[i==n-1];
    }
}