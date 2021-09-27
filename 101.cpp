#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> vec(n), left(n), right(n);
    for(int i=0; i<n; ++i) scanf("%d", &vec[i]);
    int maxm = -1;
    for(int i=0; i<n; ++i) {
        if(vec[i] > maxm) {
            left[i] = vec[i];
            maxm = vec[i];
        }
        else left[i] = maxm;
    }
    int minm = 1000000005;
    for(int i=n-1; i>=0; --i) {
        if(vec[i] < minm) {
            right[i] = vec[i];
            minm = vec[i];
        }
        else right[i] = minm;
    }
//     for(int i=0; i<left.size(); ++i) {
//         cout << left[i] << " \n"[i==left.size()-1];
//     }
//     for(int i=0; i<right.size(); ++i) {
//         cout << right[i] << " \n"[i==right.size()-1];
//     }
    vector<int> res;
//     if(vec[0] == right[0]) res.push_back(vec[0]);
    for(int i=0; i<n; ++i) {
        if(left[i] <= vec[i] && vec[i] <= right[i])
            res.push_back(vec[i]);
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); ++i) {
        cout << res[i] << " \n"[i==res.size()-1];
    }
    if(res.size() == 0) cout << endl;
}
