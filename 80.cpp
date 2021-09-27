#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct stu {
    int id, ge, gi, gf, rk;
    int* ch;
    stu(int _id, int _e, int _i, int _k) : id(_id), ge(_e), gi(_i), gf(_e + _i) {
        ch = new int[_k];
    }
};
bool cmp(stu* a, stu* b) {
    if (a->gf != b->gf) return a->gf > b->gf;
    return a->ge > b->ge;
}
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> schm(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &schm[i]);
        //         cout << schm[i] << endl;
    }
    vector<stu*> vec;
    int ge, gi, c;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &ge, &gi);
        stu* stmp = new stu(i, ge, gi, k);
        //         printf("%d %d %d %d ", vec[i]->id, vec[i]->ge, vec[i]->gi, vec[i]->gf);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &c);
            stmp->ch[j] = c;
            //             printf("%d ", vec[i]->ch[j]);
        }
        vec.push_back(stmp);
        //         cout << endl;
    }
    sort(vec.begin(), vec.end(), cmp);
    vec[0]->rk = 1;
    for (int i = 1; i < n; ++i) {
        if (vec[i]->gf == vec[i - 1]->gf && vec[i]->ge == vec[i - 1]->ge) vec[i]->rk = vec[i - 1]->rk;
        else vec[i]->rk = i + 1;
    }
//     cout << "size = " << vec.size() << endl;
//     for (int i = 0; i < vec.size(); ++i) {
//         printf("%d %d %d %d %d ", vec[i]->rk, vec[i]->id, vec[i]->ge, vec[i]->gi, vec[i]->gf);
//         for (int j = 0; j < k; ++j)
//             printf("%d ", vec[i]->ch[j]);
// //         cout << endl;
//     }
    vector<vector<int>> sch(m);
    for (int i = 0; i < n; ) {
//         cout << ">>>>>>  " << i << endl;
        int j = i;
        vector<int> vtmp;
        for (; j < n; ++j) {
            if (vec[i]->rk != vec[j]->rk) break;
            int c = 0;
            for (; c < k; ++c) {
                if (schm[vec[j]->ch[c]] > 0) {
                    vtmp.push_back(vec[j]->ch[c]);
                    break;
                }
            }
            if (c >= k) vtmp.push_back(-1);
        }
//         cout << "---" << j << endl;
        for (int p = 0; p < vtmp.size(); ++p) {
//             cout << vec[i + p]->id << " -> " << vtmp[p] << endl;
            if (vtmp[p] == -1) continue;
            sch[vtmp[p]].push_back(vec[i + p]->id);
            schm[vtmp[p]]--;
        }
        i = j;
    }
    for (int i = 0; i < m; ++i) {
        if (sch[i].size() == 0) cout << endl;
        else {
            sort(sch[i].begin(), sch[i].end());
            for (int j = 0; j < sch[i].size(); ++j) {
                cout << sch[i][j] << " \n"[j == sch[i].size() - 1];
            }
        }
    }
}