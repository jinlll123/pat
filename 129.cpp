#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    int time;
    node(int v, int t=1) : val(v), time(t) {}
    bool operator < (const node& nd) const {
        if(time != nd.time) return time > nd.time;
        return val < nd.val;
    }
};
int book[50005] = {0};
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
//     vector<bool> vis(n+1, false);
//     vector<int> vec(n);
    int num;
    set<node> s;
    for(int i=0; i<n; ++i) {
//         scanf("%d", &vec[i]);
        scanf("%d", &num);
        if(i!=0) {
            printf("%d:", num);
            int cnt = 0;
            for(auto it = s.begin(); it != s.end() && cnt < k; ++it) {
                printf(" %d", it->val);
                cnt++;
            }
            printf("\n");
        }
        auto it = s.find(node(num, book[num]));
        if(it != s.end()) s.erase(it);
        book[num]++;
        s.insert(node(num, book[num]));
    }
//     vector<node*> seq;
//     map<int, int> mp;
//     for(int i=1; i<n; ++i) {
//         int tmp = vec[i-1], j;
//         if(vis[tmp]) {
//             j = mp[tmp];
//             seq[j]->time++;
// //             for(j=0; j<seq.size(); ++j) {
// //                 if(seq[j]->val == tmp) {
// //                     seq[j]->time++;
// //                     break;
// //                 }
// //             }
//         }else {
//             j = seq.size();
//             seq.push_back(new node(tmp));
//             vis[tmp] = true;
//             mp[tmp] = j;
//         }
// //         cout << tmp << " " << seq[j]->val << endl;
//         for(int p=j-1; p>=0; --p) {
//             if(seq[p]->time < seq[p+1]->time || 
//                (seq[p]->time==seq[p+1]->time && seq[p]->val>seq[p+1]->val)) {
//                 swap(seq[p], seq[p+1]);
//                 mp[seq[p]->val] = p;
//                 mp[seq[p+1]->val] = p+1;
// //                 printf("%d %d   %d %d\n", seq[p]->val, p, seq[p+1]->val, p+1);
//             }
                
//             else break;
//         }
//         printf("%d:", vec[i]);
//         for(int j=0; j<min(k, int(seq.size())); ++j) {
//             printf(" %d", seq[j]->val);
//         }
//         printf("\n");
//     }
}