#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    vector<bool> vec(100005, false);
    for(int i=0; i<n; ++i) {
        scanf("%d", &t);
        if(t < 100005 && t > 0) vec[t] = true;
    }
    for(int i=1; i<100005; ++i) {
        if(!vec[i]) {
            printf("%d\n", i);
            break;
        }
    }
}