#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int _val=0, node* _l=nullptr, node* _r=nullptr) : val(_val), left(_l), right(_r) {}
};
vector<int> res;
void post(node *root) {
    if(root == nullptr) return;
    post(root->left);
    post(root->right);
    res.push_back(root->val);
}
int main() {
    int n;
    cin >> n;
    node *root=nullptr, *pre=nullptr, *cur;
    stack<node*> stk;
    string oper;
    int val;
    bool fg = true;  // true = last operator is push
    for(int i=0; i<n*2; ++i) {
        cin >> oper;
        if(oper[1]=='u') {
            cin >> val;
            node *tmp = new node(val);
            if(root == nullptr) {
                root = tmp;
//                 cout << "root = " << val << endl;
            }
            else {
                if(pre==nullptr) {
                    cur = stk.top();
                    cur->left = tmp;
//                     cout << "left = " << val << endl;
                }
                else {
                    pre->right = tmp;
                    pre = nullptr;
//                     cout << "right = " << val << endl;
                }
            }
            stk.push(tmp);
        }
        else {
            pre = stk.top();
            stk.pop();
        }
    }
    post(root);
    for(int i=0; i<res.size(); ++i) {
        cout << res[i] << " \n"[i==res.size()-1];
    }
}