#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
struct acc{
    string name, pass;
    acc(string n, string p) {
        name = n;
        pass = p;
    }
};
int main() {
    map<char, char> mp = {
        {'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}
    };
    int n;
    cin >> n;
    string name, pass;
    vector<acc*> vec;
    for(int i=0; i<n; ++i) {
        cin >> name >> pass;
//         cout << i << " " << pass << "========================\n";
        bool flag = false;
        for(int i=0; i<pass.length(); ++i) {
//             cout << pass[i] << endl;
            if(mp.find(pass[i]) != mp.end()) {
//                 cout << "    " << mp[pass[i]] << endl;
                flag = true;
                pass[i] = mp[pass[i]];
            }
        }
        if(flag) vec.push_back(new acc(name, pass));
    }
    if(vec.size() == 0) {
        if(n==1) printf("There is 1 account and no account is modified\n");
        else printf("There are %d accounts and no account is modified\n", n);
    }
    else {
        cout << vec.size() << endl;
        for(auto a : vec) {
            cout << a->name << " " << a->pass << endl;
        }
    }
}