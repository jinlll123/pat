#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
    int n, m, k;
    cin >> m >> n >> k;
    for(int i=0; i<k; ++i) {
        stack<int> stk;
//         cout << i << ":\n";
        vector<int> vec(n);
        for(int j=0; j<n; ++j) cin >> vec[j];
//         cout << "i= " << i << endl;
//         for(int j=0; j<n; ++j) cout << vec[j] << " ";
//         cout << endl;
        int cur=0, cnt=0;
        bool flag = true;
        for(int j=1; j<=n&&flag; ++j) {
            stk.push(j);
            cnt++;
            if(cnt > m) flag=false;
            while(!stk.empty() && flag) {
                if(stk.top() != vec[cur]) break;
//                 cout << "- " << stk.top() << endl;
                stk.pop();
                cur++;
                cnt--;
            }
        }
        if(!stk.empty()) flag = false;
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}