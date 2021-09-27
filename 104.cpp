#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
//     vector<double> vec(n+1);
    long long sum = 0;
    double tmp;
    for(int i=1; i<=n; ++i) {
        cin >> tmp;
        sum += (long long)(tmp*1000) * i * (n-i+1);
    }
//     double sum = 0;
//     for(int i=1; i<=n; ++i) {
//         sum += vec[i] * i * (n+1-i);
//     }
//     for(int i=1; i<=n; ++i) {
//         for(int j=0; j<=n-i; ++j) {
//             for(int k=i; k<=i+j; ++k) 
//                 sum += vec[k];
//         }
//     }
    printf("%.2f\n", sum/1000.0);
}