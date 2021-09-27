#include<bits/stdc++.h>
using namespace std;
map<char, int> seq;
bool cmp(char a, char b) {
    return seq[a] < seq[b];
}
int main() {
    int k, cnt=0;
    cin >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    vector<bool> rep(s.length(), false);
    for(int i=0; i<s.length(); ) {
        int j=1;
        for(; j<k; ++j) {
            if(s[i+j] != s[i]) break;
        }
        if(j<k) mp[s[i]]=-1;
        
//         cout << i << " " << s[i] << " " << j << endl;
        if(j>=k && mp[s[i]]==-1) {
//             cout << "case1\n";
            i += k;
        }
        else if(j >= k){
//             cout << "case2\n";
            mp[s[i]]++;
            rep[i] = true;
            if(seq.find(s[i])==seq.end()) {
                seq[s[i]] = cnt++;
            }
            i += k;
        }
        else {
//             cout << "case3\n";
            i++;
        }
    }
    string res = "";
    for(auto it : mp) {
        if(it.second > 0) {
            char c = it.first;
            res += c;
//             cout << c << endl;
        }
    }
    sort(res.begin(), res.end(), cmp);
    cout << res << endl;
    res = "";
    for(int i=0; i<s.length(); ) {
        res += s[i];
        if(rep[i] && mp[s[i]]>0) i+=k;
        else i++;
    }
    cout << res << endl;
}