#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, sum=0, t, m, a, b;
    cin >> n;
    vector<int> vec(n+2, 0);
    for(int i=1; i<=n; ++i) {
        cin >> t;
        vec[i+1] = vec[i] + t;
        sum += t;
    }
    cin >> m;
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        if(b==1) b=n+1;
        t = vec[b]-vec[a];
        cout << min(t, sum-t) << endl;
    }
}