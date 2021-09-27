#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length();
    vector<vector<ll>> vec(len, vector<ll>(3, 0));
//     ll res = 0;
    if(s[0]=='P') vec[0][0]=1;
    for(int i=1; i<len; ++i) {
        vec[i][0] = vec[i-1][0];
        vec[i][1] = vec[i-1][1];
        vec[i][2] = vec[i-1][2];
        if(s[i] == 'P') {
            vec[i][0] += 1;
        }
        else if(s[i] == 'A') {
            vec[i][1] += vec[i][0];
        }
        else {
            vec[i][2] += vec[i][1];
        }
    }
    cout << vec[len-1][2]%1000000007 << endl;
}