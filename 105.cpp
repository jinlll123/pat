#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {return a >= b;}
vector<int> vec;
vector<vector<int>> res;
int N;
int main() {
    cin >> N;
    int k=sqrt(N), m, n, cnt=0;
    while(k) {
        if(N%k==0) {
            m=k;
            n=N/k;
            break;
        }
        --k;
    }
    if(m<n) {
        int tmp = m;
        m=n;
        n=tmp;
    }
    vec.resize(N);
    for(int i=0; i<N; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), cmp);
//     for(auto i : vec) cout << i << " ";
//     cout << endl;
    res.resize(m, vector<int>(n));
    int level = m/2 + m%2;
    for(int i=0; i<level; ++i) {
        for(int j=i; j<n-i && cnt<N; ++j) {
            res[i][j] = vec[cnt++];
        }
        for(int j=i+1; j<m-i && cnt<N; ++j) {
            res[j][n-i-1] = vec[cnt++];
        }
        for(int j=n-i-2; j>=i && cnt<N; --j) {
            res[m-i-1][j] = vec[cnt++];
        }
        for(int j=m-i-2; j>=i+1 && cnt<N; --j) {
            res[j][i] = vec[cnt++];
        }
    }
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cout << res[i][j] << " \n"[j==n-1];
        }
    }
}