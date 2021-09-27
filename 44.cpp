#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct rg {
    int l, r;
    rg(int _l = 0, int _r = 0) : l(_l), r(_r) {}
};

bool cmp(rg a, rg b) {
    return a.l < b.l;
}

int main() {
    int n, m, k = 100000010;
    cin >> n >> m;
    vector<int> vec(n);
    vector<rg> res;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        /*int t = vec[i] - m;
        if (t < 0) continue;
        if (t < k) {
            res.clear();
            res.push_back(rg(i, i));
            k = t;
        }
        else if (t == k) {
            res.push_back(rg(i, i));
        }*/
    }
//     cout << k << endl;
    int l = 0, r = 0, cur = vec[0];
    if (cur >= m) {
        k = cur - m;
        res.push_back(rg(l, r));
    }
    while (true) {
        if (r >= n-1) break;
        while (r < n) {
            ++r;
            cur += vec[r];
//             cout << "r=" << r << endl;
            if (cur >= m) {
//                 printf("1 cur=%d l=%d r=%d\n", cur, l, r);
                int t = cur - m;
                if (t < 0) continue;
                if (t < k) {
//                     cout << "< clear push\n";
                    res.clear();
                    res.push_back(rg(l, r));
                    k = t;
                }
                else if (t == k) {
//                     printf("1== push l=%d r=%d\n", l, r);
                    res.push_back(rg(l, r));
                }
                break;
            }
        }
        while (l < r) {
            cur -= vec[l++];
            if (cur >= m) {
//                 printf("2 cur=%d l=%d r=%d\n", cur, l, r);
                int t = cur - m;
                if (t < 0) continue;
                if (t < k) {
                    res.clear();
                    res.push_back(rg(l, r));
                    k = t;
                }
                else if (t == k) {
//                     printf("2== push l=%d r=%d\n", l, r);
                    res.push_back(rg(l, r));
                }
            }
            else break;
        }
    }

    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].l + 1 << "-" << res[i].r + 1;
        if (i != res.size() - 1) cout << endl;
    }
}