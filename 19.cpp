#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main () {
    int n, b;
    cin >> n >> b;
    vector<int> vec;
    while(n) {
        vec.push_back(n%b);
        n /= b;
    }
    reverse(vec.begin(), vec.end());
    bool fg = true;
    int sz = vec.size();
    for(int i=0; i<=(sz-1)/2; ++i) {
        if(vec[i] != vec[sz-1-i]) {
            fg = false;
            break;
        }
    }
    if(fg) cout << "Yes\n";
    else cout << "No\n";
    cout << vec[0];
    for(int i=1; i<sz; ++i) {
        cout << " " << vec[i];
    }
    cout << endl;
}