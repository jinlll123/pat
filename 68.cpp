#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<bool>> choice(n + 1, vector<bool>(m + 1, false));
    vector<int> dp(m + 1, 0);
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    sort(w.begin()+1, w.end(), cmp);
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            if (dp[j] <= dp[j - w[i]] + w[i]) {
                dp[j] = dp[j - w[i]] + w[i];
                choice[i][j] = true;
            }
        }
    }
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             cout << choice[i][j] << " ";
//         }
//         cout << endl;
//     }
    vector<int> res;
    if (dp[m] != m) printf("No Solution\n");
    else {
        int v = m, idx = n;
        while (v > 0) {
            if (choice[idx][v]) {
                v -= w[idx];
                res.push_back(w[idx]);
            }
            --idx;
        }
        for (int i = 0; i < res.size(); ++i) {
            printf("%d%c", res[i], " \n"[i == res.size() - 1]);
        }
    }
}