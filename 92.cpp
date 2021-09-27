#include<bits/stdc++.h>
using namespace std;
int main () {
    string a;
    map<int, int> mp;
    cin >> a;
    for(int i=0; i<a.length(); ++i) mp[a[i]]++;
    cin >> a;
    bool fg = true;
    int cnt=0;
    for(int i=0; i<a.length(); ++i) {
        if(mp[a[i]] > 0) mp[a[i]]--;
        else {
            fg = false;
            cnt++;
        }
    }
//     cout << fg << " " << cnt << endl;
    if(fg) {
        for(auto it : mp) {
            cnt += it.second;
        }
        cout << "Yes" << " " << cnt << endl;
    }
    else {
        cout << "No" << " " << cnt << endl;
    }
}