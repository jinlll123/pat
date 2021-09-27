#include<bits/stdc++.h>
using namespace std;
struct stu{
    string name;
    int high;
    stu(string n, int h) {
        name = n;
        high = h;
    }
};
bool cmp(stu* a, stu* b) {
    if(a->high != b->high) return a->high > b->high;
    return a->name < b->name;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<stu*> vec;
    string name;
    int high;
    for(int i=0; i<n; ++i) {
        cin >> name >> high;
        vec.push_back(new stu(name, high));
    }
    sort(vec.begin(), vec.end(), cmp);
    int m = n/k, r=n%k, cnt=0;
    vector<vector<int>> g(k);
    for(int i=0; i<k; ++i) {
        int cur = m + (i==0 ? r:0);
        g[i].resize(cur+1);
        int mid = cur/2+1, tmp = 0;
        for(int j=mid; j<=cur; ++j) {
//             cout << j << " " << cnt+tmp << endl;
            g[i][j] = cnt+tmp;
            tmp += 2;
        }
        for(int j=mid-1; j>=1; --j) {
//             cout << j << " " << cnt+(mid-j)*2-1 << endl;
            g[i][j] = cnt+(mid-j)*2-1;
        }
        cnt += cur;
    }
//     for(int i=0; i<n; ++i ) {
//         cout << i << vec[i]->name << endl;
//     }
    for(int i=0; i<k; ++i) {
//         cout << i << "\n";
        for(int j=1; j<g[i].size(); ++j) {
            cout << vec[g[i][j]]->name << " \n"[j==g[i].size()-1];
        }
//         cout << endl;
    }
}