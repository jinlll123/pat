#include<bits/stdc++.h>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d %d %d", &m, &n, &s);
    vector<string> vec(m+1);
    map<string, int> mp;
    for(int i=1; i<=m; ++i) {
        cin >> vec[i];
//         printf("%s\n", vec[i].c_str());
    }
//     if(s > n) {
        
//     }
//     for(int i=0; i<m/s; ++i) {
        
//     }
    vector<string> res;
    int cur = s;
    while(cur <= m) {
        if(mp.find(vec[cur]) == mp.end()) {
            res.push_back(vec[cur]);
            mp[vec[cur]] = 1;
            cur += n;
        }
        else ++cur;
    }
    if(res.size()==0) {
        printf("Keep going...\n");
    }else {
        for(int i=0; i<res.size(); ++i) {
            printf("%s\n", res[i].c_str());
        }
    }
    
}