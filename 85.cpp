#include<iostream>
#include<vector>
#include<algorithm>
// #include<cstdio>
using namespace std;
int main() {
    int n;
    long long p;
    scanf("%d %lld", &n, &p);
//     cout << n << " " << p << endl;
    vector<int> vec(n);
    for(int i=0; i<n; ++i) scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    int tmp;
    int res = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i+res; j<n; ++j) {
            if(vec[j] <= vec[i]*p) {
                tmp = j-i+1;
                if(tmp > res)
                    res = tmp;
            }
            else break;
        }
    }
    cout << res << endl;
//     int l=0, r=vec.size()-1;
//     while(l<r) {
//         tmp = vec[l]*p;
//         if(vec[r] <= tmp) break;
//         if(vec[r-1] <= tmp) {
//             r--;
//         }
//         else {
//             long long tmp2 = vec[l+1]*p;
//             if(vec[r] <= tmp2) {
//                 l++;
//             }
//             else  {
//                 if(vec[l+1]==vec[l] || vec[r-1]==vec[r]) {
//                     int suml = 1, sumr = 1;
//                     for(; l+suml<r&&vec[l+suml]==vec[l]; ++suml);
//                     for(; r-sumr>l&&vec[r-sumr]==vec[r]; --sumr);
//                     if(suml > sumr) r-=sumr;
//                     else l+=suml;
// //                     cout << suml << " " << sumr << endl;
//                 }
//                 else {
//                     r--;
//                     l++;
//                 }
//             }
//         }
//     }
//     cout << r-l+1 << endl;
}