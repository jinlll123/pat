#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
int main() {
    int np, ng;
    scanf("%d %d", &np, &ng);
    vector<int> vec(np);
    vector<int> res(np);
    for (int i = 0; i < np; ++i) scanf("%d", &vec[i]);
    queue<int> q;
    int t;
    for (int i = 0; i < np; ++i) {
        scanf("%d", &t);
        q.push(t);
    }
    int tmp = np, group;
    while (q.size() > 1) {
//         cout << q.size() << endl;
        group = tmp / ng + (tmp % ng == 0 ? 0 : 1);
//         cout << "Group=" << group << endl;
//         cout << "tmp=" << tmp << endl;
        for (int i = 0; i < group; ++i) {
            int k = q.front();
            for (int j = 0; j < ng; ++j) {
                if (i * ng + j >= tmp) {
                    break;
                }
                int t = q.front();
                if (vec[k] < vec[t]) k = t;
                res[t] = group + 1;
                q.pop();
            }
            q.push(k);
        }
        tmp = group;
    }
    res[q.front()] = 1;
    for (int i = 0; i < np; ++i) {
        cout << res[i] << " \n"[i == np - 1];
    }
}