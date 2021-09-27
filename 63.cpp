#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int n, k, num, t, a, b;
    scanf("%d", &n);
    vector<set<int>> vec;
    for(int i=0; i<n; ++i) {
        scanf("%d", &num);
        set<int> st;
        while(num--) {
            scanf("%d", &t);
            st.insert(t);
        }
        vec.push_back(st);
    }
    scanf("%d", &k);
    while(k--) {
        scanf("%d %d", &a, &b);
        --a, --b;
        int nt = vec[b].size(), nc=0;
        for(auto i : vec[a]) {
            if(vec[b].find(i) == vec[b].end()) {
                nt++;
            }
            else nc++;
        }
        printf("%.1f%\n", nc*1.0/nt*100);
//         set<int> us, is;
//         set_union(vec[a].begin(), vec[a].end(), vec[b].begin(), vec[b].end(), insert_iterator<set<int>>(us, us.begin()));
//         set_intersection(vec[a].begin(), vec[a].end(), vec[b].begin(), vec[b].end(), insert_iterator<set<int>>(is, is.begin()));
//         printf("%.1f%\n", is.size()*1.0/us.size()*100);
    }
}