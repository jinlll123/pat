// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> oriv(n), tarv(n);
//     for (int i = 0; i < n; ++i) scanf("%d", &oriv[i]);
//     for (int i = 0; i < n; ++i) scanf("%d", &tarv[i]);
//     bool fg = false;
//     int len = 1;
//     for (; len < n; len *= 2) {
// //         cout << "len = " << len << endl;
//         int lo = 0, hi = len;
//         while (lo < n) {
//             map<int, int> mp;
//             bool tf = true;
//             int pre = -1;
//             for (int i = lo; i < hi; ++i) {
//                 if (tarv[i] >= pre) pre = tarv[i];
//                 else {
//                     tf = false;
//                     break;
//                 }
// //                 cout << oriv[i] << " " << tarv[i] << endl;
//                 mp[oriv[i]]++;
//                 mp[tarv[i]]--;
//             }
//             if (!tf) break;
//             for (auto it : mp) {
//                 if (it.second != 0) {
//                     tf = false;
//                     break;
//                 }
//             }
//             if (!tf) break;
//             lo = hi;
//             if (lo >= n) break;
//             hi += len;
//             if (hi >= n) hi = n;
//         }
//         if (lo >= n) {
//             fg = true;
//             break;
//         }
//     }
//     if (fg) {
//         printf("Merge Sort\n");
//         len *= 2;
//         auto beg = tarv.begin();
//         fg = true;
//         while (fg) {
//             auto ed = beg;
//             for (int i = 0; i < len; ++i) {
//                 if (ed == tarv.end()) {
//                     fg = false;
//                     break;
//                 }
//                 ed++;
//             }
//             sort(beg, ed);
//             beg = ed;
//         }
//     }
//     else {
//         printf("Insertion Sort\n");
//         int k=1;
//         while(k<n && tarv[k] > tarv[k-1]) ++k;
//         while (k > 0 && tarv[k - 1] > tarv[k]) {
//             int tmp = tarv[k - 1];
//             tarv[k - 1] = tarv[k];
//             tarv[k] = tmp;
//             --k;
//         }
//     }
//     for (int i = 0; i < tarv.size(); ++i) {
//         cout << tarv[i] << (i == tarv.size() - 1 ? "" : " ");
//     }
// }
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, a[100], b[100], i, j;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; a[j] == b[j] && j < n; j++);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2);
    } else {
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while(flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (a[i] != b[i])
                    flag = 1;
            }
            k = k * 2;
            for (i = 0; i < n / k; i++)
                sort(a + i * k, a + (i + 1) * k);
            sort(a + i * k, a + n);
        }
    }
    for (j = 0; j < n; j++) {
        if (j != 0) printf(" ");
        printf("%d", a[j]);
    }
    return 0;
}