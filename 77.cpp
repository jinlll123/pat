#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    string t;
    getline(cin, t);
    vector<string> vec(n);
    int mlen = 266;
    for(int i=0; i<n; ++i) {
        getline(cin, t);
        vec[i] = t;
        mlen = min(mlen, (int)t.length());
    }
    t = "";
    for(int i=1; i<=mlen; ++i) {
        int j=0;
        char c = vec[j][vec[j].length()-i];
        for(j=1; j<n; ++j) {
            if(c != vec[j][vec[j].length()-i]) break;
        }
        if(j >= n) {
            t = c+t;
        }
        else break;
    }
    if(t.length()==0) cout << "nai\n";
    else cout << t << endl;
}