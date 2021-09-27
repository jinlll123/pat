#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {return a > b;}
int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &vec[i]);
    }
    sort(vec.begin(), vec.end(), cmp);
    int e=0;
    while(e<n && vec[e]>e+1) e++;
    cout << e << endl;
//     int res = 0, cur=0;
// //     if(vec[0]>res && n-i>=vec[0]) res = vec[0];
//     for(int i=1; i<=n; ++i) {
// //         cout << "     i = " << i << endl;
//         while(vec[cur]<=i && cur<n) ++cur;
// //         cout << cur << " " << vec[cur] << endl;
//         if(n-cur <= res) break;
//         if((n-cur) > i) res = i;  // vec[cur]>=i && 
// //         cout << "res = " << res << endl;
//     }
//     cout << res << endl;
}