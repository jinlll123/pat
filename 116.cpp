#include<bits/stdc++.h>
using namespace std;
bool isP(int n) {
    for(int i=2; i*i<=n; ++i) {
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    int n, t, k;
    cin >> n;
    vector<int> rank(10005, -1);
    vector<int> checked(10005, false);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &t);
        rank[t] = i;
    }
    cin >> k;
    for(int i=0; i<k; ++i) {
        scanf("%d", &t);
        if(rank[t]==-1) {
            printf("%04d: Are you kidding?\n", t);
        }
        else if(checked[t]) {
            printf("%04d: Checked\n", t);
        }
        else {
            checked[t] = true;
            if(rank[t] == 1) {
                printf("%04d: Mystery Award\n", t);
            }
            else if(isP(rank[t])) {
                printf("%04d: Minion\n", t);
            }
            else {
                printf("%04d: Chocolate\n", t);
            }
        }
    }
}