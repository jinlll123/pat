#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *left, *right;
    node(int v = 0, node *l = nullptr, node *r = nullptr) : val(v), left(l), right(r) {}
};
vector<int> pre;
node *brT(int l, int r) {
    if(l > r) return nullptr;
    node *cur = new node(pre[l]);
    if(l == r) return cur;
    int tmp = abs(pre[l]);
    int i;
    for(i=l+1; i<=r; ++i) {
        if(abs(pre[i]) > tmp) break;
    }
    cur->left = brT(l+1, i-1);
    cur->right = brT(i, r);
    return cur;
}

int bnum;
bool fg;
void tra(node *cur, int cnt, bool color) { // black=true
    if(!fg) return;
    if(cur==nullptr) {
        if(bnum == -1) bnum = cnt;
        else if(bnum != cnt) {
//             cout << "bnum != cnt  " << bnum << " " << cnt << endl;
            fg = false;
        }
        return;
    }
    if(!color && cur->val < 0) {
//         cout << "!color && cur->val < 0   " << cur->val << endl;
        fg = false;
        return;
    }
    int tmp = cur->val>0 ? 1:0;
    tra(cur->left, cnt+tmp, cur->val>0);
    tra(cur->right, cnt+tmp, cur->val>0);
}

int main() {
    int k, n, t;
    scanf("%d", &k);
    for(int i=0; i<k; ++i) {
        scanf("%d", &n);
        pre.resize(n);
        for(int j=0; j<n; ++j) {
            scanf("%d", &pre[j]);
        }
        if(pre[0]<0) printf("No\n");
        else {
            bnum = -1;
            fg = true;
            node *root = brT(0, n-1);
            tra(root, 0, true);
            if(fg) printf("Yes\n");
            else printf("No\n");
        }
        
    }
}