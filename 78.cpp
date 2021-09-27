#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool isP(int n) {
    for(int i=2; i <= (int)sqrt(n); ++i) {
        if(n%i == 0) return false;
    }
    return true;
}
int main() {
    int m, n;
    cin >> m >> n;
    if(m < 2) m = 2;
    else if(!isP(m)) {
        while(!isP(++m));
    }
//     cout << m << endl;
    vector<bool> vec(m, false);
    vector<int> res(n, -1);
    int t, num;
    for(int i=0; i<n; ++i) {
        cin >> t;
        for(int j=0; j<=n; ++j) {
            num = (t%m + j*j)%m;
            if(!vec[num]) break;
        }
        if(!vec[num]) {
            vec[num] = true;
            res[i] = num;
        }
    }
    for(int i=0; i<n; ++i) {
        if(res[i]==-1) cout << '-';
        else cout << res[i];
        cout << " \n"[i==n-1];
    }
}