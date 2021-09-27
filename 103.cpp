#include<bits/stdc++.h>
using namespace std;
int n, k, p;
vector<int> res;
int max_sum = -1;
vector<int> path;
void dfs(int num, int rst, int cnt, int sum) {
    if (rst < 0 || ((k-cnt)*pow(num, p)<rst)) return;
    else if (rst == 0) {
        if (cnt == k) {
            if (sum > max_sum) {
                max_sum = sum;
                res = path;
            }
        }
        return;
    }
    for (int i = num; i >= 1; --i) {
        path.push_back(i);
        int tmp = rst - pow(i, p);
        if(tmp >= 0)
            dfs(i, tmp, cnt + 1, sum + i);
        path.pop_back();
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    int num = (int)pow(n, 1.0 / p);
    dfs(num, n, 0, 0);
    if (max_sum == -1) printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (int i=0; i<res.size(); ++i) {
            cout << res[i] << "^" << p;
            if(i == res.size()-1) cout << endl;
            else cout << " + ";
        }
    }
}