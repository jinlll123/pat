#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left, *right;
    node(int v=-1, node *l=nullptr, node *r=nullptr) : val(v), left(l), right(r) {}
};
void postTra(node *cur, vector<int> &vec) {
    if(cur==nullptr) return;
    postTra(cur->left, vec);
    postTra(cur->right, vec);
    vec.push_back(cur->val);
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i) {
        vector<int> vec(m+1);
        for(int j=1; j<=m; ++j) {
            scanf("%d", &vec[j]);
        }
        bool fg = vec[1] > vec[2];
        bool res = true;
        for(int j=1; j<=m/2; ++j) {
            if(fg) {
                if(vec[j]<vec[j*2] || (j*2+1<=m && vec[j]<vec[j*2+1])) {
                    res = false;
                    break;
                }
            }else {
                if(vec[j]>vec[j*2] || (j*2+1<=m && vec[j]>vec[j*2+1])) {
                    res = false;
                    break;
                }
            }
        }
        if(res) {
            if(fg) printf("Max Heap\n");
            else printf("Min Heap\n");
        }else {
            printf("Not Heap\n");
        }
        node *root = new node(vec[1]);
        int cur = 2;
        queue<node*> q;
        q.push(root);
        while(cur<=m) {
            auto top = q.front();
            q.pop();
            top->left = new node(vec[cur++]);
            q.push(top->left);
            if(cur <= m) {
                top->right = new node(vec[cur++]);
                q.push(top->right);
            }else {
                break;
            }
        }
        vector<int> post;
        postTra(root, post);
        for(int j=0; j<post.size(); ++j) {
            cout << post[j] << " \n"[j==post.size()-1];
        }
    }
}