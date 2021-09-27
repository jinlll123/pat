#include<bits/stdc++.h>
using namespace std;
void downadjust(vector<int> &tarv, int low, int high) {
    int i=0, j=i*2+1;
    while(j<=high) {
        if(j+1 <= high && tarv[j] < tarv[j+1]) j += 1;
        if(tarv[i] > tarv[j]) break;
        swap(tarv[i], tarv[j]);
        i=j;
        j=i*2+1;
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> oriv(n), tarv(n);
    for (int i = 0; i < n; ++i) scanf("%d", &oriv[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &tarv[i]);
//     int i = n - 1, t;
//     for (; i >= 0; --i)
//         if (oriv[i] != tarv[i]) break;
//     t = i + 1;
//     while (i >= 1) {
//         if (tarv[i] < tarv[i - 1]) break;
//         --i;
//     }
//     bool fg = i < 1;
    int p=1, t;
    while(p<n && tarv[p-1] <= tarv[p]) ++p;
    t = p;
    while(p<n && oriv[p]==tarv[p]) ++p;
    if (p==n) {
        cout << "Insertion Sort\n";
        while (t >= 1) {
            if (tarv[t] < tarv[t - 1]) {
                swap(tarv[t], tarv[t - 1]);
                --t;
            }
            else break;
        }
    }
    else {
        cout << "Heap Sort\n";
        int t = n - 1;
        while (t >= 1 && tarv[t] > tarv[0]) --t;
//         cout << "t = " << t << endl;
        swap(tarv[0], tarv[t]);
        downadjust(tarv, 0, t-1);
    }
    for (int i = 0; i < n; ++i) {
        cout << tarv[i] << " \n"[i == n - 1];
    }
}