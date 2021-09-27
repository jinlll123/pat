#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
    node(int v=-1, node *l=nullptr, node *r=nullptr) : val(v), left(l), right(r) {}
};
int n;
vector<int> in, post;
node* pi(int postr, int inl, int inr) {
    if(postr<0 || postr>=n || inl > inr) return nullptr;
//     printf("%d %d %d %d\n", post[postr], postr, inl, inr);
    node *tmp = new node(post[postr]);
    if(inl==inr) return tmp;
    int cur = 0;
    for(; cur<=inr-inl; ++cur) {
        if(post[postr] == in[inr-cur]) break;
    }
    tmp->left = pi(postr-cur-1, inl, inr-cur-1);
    if(cur != 0) tmp->right = pi(postr-1, inr-cur+1, inr);
    return tmp;
}
int main() {
    cin >> n;
    in.resize(n);
    post.resize(n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &in[i]);
    }
    for(int i=0; i<n; ++i) {
        scanf("%d", &post[i]);
    }
    node *root = pi(n-1, 0, n-1);
    vector<node*> vec;
    vector<int> res;
    bool rev = true;
    vec.push_back(root);
//     cout << vec[0]->val << endl;
    while(vec.size()>0) {
        vector<node*> tmp;
        vector<int> rt;
        for(int i=0; i<vec.size(); ++i) {
            rt.push_back(vec[i]->val);
            if(vec[i]->left != nullptr) tmp.push_back(vec[i]->left);
            if(vec[i]->right != nullptr) tmp.push_back(vec[i]->right);
        }
        vec = tmp;
        if(rev) reverse(rt.begin(), rt.end());
        rev = !rev;
        for(auto i : rt) res.push_back(i);
    }
    for(int i=0; i<res.size(); ++i) {
        cout << res[i] << " \n"[i==res.size()-1];
    }
}