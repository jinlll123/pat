#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

struct person {
    int num;
    int t;
    int start;
    person(int _n, int _t) : num(_n), t(_t) {}
    person(int _n, int _t, int _st) : num(_n), t(_t), start(_st) {}
};

struct win {
    int num;
    int ft;
    int cap;
    queue<person> st;
    win(int _n, int _t, int _c) : num(_n), ft(_t), cap(_c) {}
    bool operator < (const win& w) const {
        if (ft != w.ft)
            return ft > w.ft;
        return num > w.num;
    }
};

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> cn(k);
    for (int i = 0; i < k; ++i) cin >> cn[i];
    vector<win> wv;
    for (int i = 0; i < n; ++i) {
        wv.push_back(win(i, 480, m));
    }

    vector<int> vt(n, 480);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int cur = i * n + j;
            if (cur < k) {
                wv[j].st.push(person(cur, cn[cur], vt[j]));
                vt[j] += cn[cur];
                if(i == 0) wv[j].ft += cn[cur];
            }
        }
    }
    priority_queue<win> pq;
    for (win w : wv) {
        // cout << "w----\n" << w.ft << endl;
        pq.push(w);
    }
    vector<int> res(k, -1);
    for (int i = n * m; i < k; ++i) {
        win nxtw = pq.top();
        if (nxtw.ft >= 1020) break;
        pq.pop();
        
        person nxtp = nxtw.st.front();
        nxtw.st.pop();
//         nxtw.ft += nxtp.t;
        if(nxtp.start < 1020)
            res[nxtp.num] = nxtw.ft;  // 当前被服务人员的结束时间
//         cout << nxtw.num << " <= " << i << endl;
        nxtw.st.push(person(i, cn[i], nxtw.ft));
        nxtp = nxtw.st.front();
        nxtw.ft += nxtp.t;
        pq.push(nxtw);
    }
    while (!pq.empty()) {
        win nxtw = pq.top();
        pq.pop();
        if (nxtw.ft >= 1020 && !nxtw.st.empty()) {
            person nxtp = nxtw.st.front();
            if(nxtp.start < 1020) {
//                 cout << "AAA " << nxtp.num << endl;
                res[nxtp.num] = nxtw.ft;
            }
        }
        else {
            while (!nxtw.st.empty()) {  // nxtw.ft <= 1020 && 
                person nxtp = nxtw.st.front();
                nxtw.st.pop();
//                 nxtw.ft += nxtp.t;
                if(nxtw.ft >= 1020) {
                    if(nxtp.start < 1020) res[nxtp.num] = nxtw.ft;
                    break;
                }
                else {
                    res[nxtp.num] = nxtw.ft;
                }
                if(!nxtw.st.empty()) {
                    nxtp = nxtw.st.front();
                    nxtw.ft += nxtp.t;
                }
            }
        }
    }
    int pnum;
    for (int i = 0; i < q; ++i) {
        cin >> pnum;
        --pnum;
        if (res[pnum] == -1) printf("Sorry\n");
        else {
            int h = res[pnum] / 60, m = res[pnum] % 60;
            printf("%02d:%02d\n", h, m);
        }
    }
}