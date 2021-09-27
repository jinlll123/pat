#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left, *right;
    node(int _v=0, node *_l=nullptr, node *_r=nullptr) : val(_v), left(_l), right(_r) {}
};
void inorder(vector<int>&res, node *cur){
    if(cur==0) return;
    inorder(res, cur->left);
    res.push_back(cur->val);
    inorder(res, cur->right);
}

int main() {
    int n;
    cin >> n;
    if(n==0) {
        cout << "\n\n";
        return 0;
    }
    vector<node*> vec(n);
    for(int i=0; i<n; ++i)
        vec[i] = new node(i);
//     node* root = nullptr;
//     int ri = -1;
    string a, b;
    vector<int> fa(n, -1);
    for(int i=0; i<n; ++i) {
        cin >> a >> b;
//         if((a[0]!='-' || b[0]!='-') && root==nullptr) {
//             root = vec[i];
//             ri = i;
//         }
        if(a[0] != '-') {
            int ai = stoi(a.c_str());
            vec[i]->right = vec[ai];
            fa[ai] = i;
//             if(ai == ri) {
//                 root = vec[i];
//                 ri = i;
//             }
        }
        if(b[0] != '-') {
            int bi = stoi(b.c_str());
            vec[i]->left = vec[bi];
            fa[bi] = i;
//             if(bi == ri) {
//                 root = vec[i];
//                 ri = i;
//             }
        }
    }
    int ri=-1;
    for(int i=0; i<n; ++i) {
        if(fa[i] != -1) ri = i;
    }
    while(true) {
        if(fa[ri]==-1) break;
        ri = fa[ri];
    }
    vector<int> res1;
    queue<node*> q;
    q.push(vec[ri]);
    int k = 1;
    while(!q.empty()) {
        int tmp = 0;
        for(int i=0; i<k; ++i) {
            auto top = q.front();
            q.pop();
            res1.push_back(top->val);
            if(top->left != nullptr) {
                q.push(top->left);
                tmp++;
            }
            if(top->right != nullptr) {
                q.push(top->right);
                tmp++;
            }
        }
        k = tmp;
    }
    for(int i=0; i<res1.size(); ++i)
        cout << res1[i] << " \n"[i==res1.size()-1];
    
    vector<int> res2;
    inorder(res2, vec[ri]);
//     cout << res2.size() << endl;
    for(int i=0; i<res2.size(); ++i)
        cout << res2[i] << " \n"[i==res2.size()-1];
}