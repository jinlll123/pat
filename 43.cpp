#include<iostream>
#include<vector>
using namespace std;

struct node{
    node* left;
    node* right;
    int val;
    node(node* a=nullptr, node* b=nullptr, int v=0) :left(a), right(b), val(v) {}
};
int n;
vector<int> pre;
bool flag = true;
node* bst(int l, int r, bool isM) {
    if(!flag || l==-1 || r==-1 || l>r) return nullptr;
//     cout << "lr = " << l << " " << r << endl;
//     cout << "~~~~\n";
    if(l==r) return new node(nullptr, nullptr, pre[l]);
    int b=-1, c=-1;
    int val = pre[l++];
    if(!isM) {
        if(pre[l] < val) b = l++;
        for(int i=l; i<=r; ++i) {
            if(pre[i]>=val) {
                c = i;
                break;
            }
        }
        if(c==-1) c=r+1;
        for(int i=c+1; i<=r; ++i) 
            if(pre[i] < val) {
//                 cout << "ERR=" << i << endl;
                flag = false;
                return nullptr;
            }
//         cout << "bc = " << b << " " << c-1 << endl;
        return new node(bst(b, c-1, isM), bst(c, r, isM), val);
    }
    else {
        if(pre[l] >= val) b = l++;
        for(int i=l; i<=r; ++i) {
            if(pre[i]<val) {
                c = i;
                break;
            }
        }
        if(c==-1) c=r+1;
        for(int i=c+1; i<=r; ++i) 
            if(pre[i] >= val) {
//                 cout << "ERR=" << i << endl;
                flag = false;
                return nullptr;
            }
//         cout << "bcn = " << b << " " << c-1 << endl;
        return new node(bst(b, c-1, isM), bst(c, r, isM), val);
    }
}

vector<int> post;
void posttra(node* root) {
    if(root == nullptr) return;
    posttra(root->left);
    posttra(root->right);
    post.push_back(root->val);
}

int main() {
    int n;
    cin >> n;
    pre.resize(n);
    for(int i=0; i<n; ++i) cin >> pre[i];
    bool isM = pre[1] >= pre[0];
    node* root = bst(0, n-1, isM);
    if(flag) {
        cout << "YES\n";
        posttra(root);
        for(int i=0; i<post.size(); ++i) {
            cout << post[i] << " \n"[i==post.size()-1];
        }
    }
    else cout << "NO\n";
}