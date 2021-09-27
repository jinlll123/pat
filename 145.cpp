#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    for(int i=2; i*i<=x; ++i) {
        if(x%i==0) return false;
    }
    return true;
}
int getPrime(int x) {
    while(true) {
        if(isPrime(x)) {
            return x;
        }
        ++x;
    }
}
int main() {
    int msize, n, m, t, nxt;
    scanf("%d %d %d", &msize, &n, &m);
    msize = getPrime(msize);
//     printf("msize = %d\n", msize);
    vector<int> vec(msize, -1);
    for(int i=0; i<n; ++i) {
        scanf("%d", &t);
        int j=0;
        for(; j<=msize/2; ++j) {
            nxt = (t+j*j)%msize;
            if(vec[nxt] == -1) {
                vec[nxt] = t;
                break;
            }
        }
        if(j>msize/2)
            printf("%d cannot be inserted.\n", t);
    }
    int cnt = 0;
    for(int i=0; i<m; ++i) {
        scanf("%d", &t);
//         cout << t << endl;
//         vector<bool> vis(msize, false);
        for(int j=0; j<=msize; ++j) {
            nxt = (t+j*j)%msize;
            cnt++;
            if(vec[nxt]==t || vec[nxt]==-1) {
                break;
            }
        }
    }
    printf("%.1f\n", 1.0*cnt/m);
}