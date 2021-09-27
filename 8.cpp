#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = 5*n, cur = 0, nxt;
    for(int i=0; i<n; ++i) {
        cin >> nxt;
        if(nxt > cur) res += (nxt-cur)*6;
        else res += (cur-nxt)*4;
        cur = nxt;
    }
    cout << res << endl;
}