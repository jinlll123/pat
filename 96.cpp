// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int len=0, left=0, right=0;
//     for(int i=2; i<=n; ++i) {
//         if(n%i != 0) continue;
//         int j=i+1;
// //         cout << i << "-";
//         while(j<sqrt(n)) {
//             int k=j, tmp = n/i, cnt=(i+1==j ? 1:0);
//             for(; tmp%k==0; ++k) {
// //                 if(i==3) cout << k << " ";
//                 tmp/=k;
//             }
// //             if(i==3) cout << " >" << tmp << endl;
//             if(k-j+cnt > len) { //tmp==1 && 
//                 len = k-j+cnt;
//                 left = j-cnt;
//                 right=k;
// //                 if(i==3) cout << ">>>>> " << len << " " << left << " " << right << endl;
//             }
//             ++j;
//         }
//     }
//     if(len > 1) {
//         cout << len << endl;
//         for(int i=left; i<right; ++i) {
//             cout << i << "*\n"[i==right-1];
//         }
//     }
//     else {
//         cout << "1\n" << n << endl;
//     }
    
// }
#include<bits/stdc++.h>
using namespace std;
int main() {
    long int num, tmp;
    cin >> num;
    int first=0, len=0, maxn=sqrt(num)+1;
    for(int i=2; i<=maxn; ++i) {
        int j=i;
        tmp = 1;
        for(; j<=maxn; ++j) {
            tmp *= j;
            if(num % tmp != 0) break;
        }
        if(j - i > len) {
            first = i;
            len = j - i;
        }
    }
    if(first == 0) {
        cout << 1 << endl << num << endl;
    }else {
        cout << len << endl;
        for(int i=0; i<len; ++i) {
            cout << first+i << "*\n"[i==len-1];
        }
    }
}