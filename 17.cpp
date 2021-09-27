#include<bits/stdc++.h>
using namespace std;
struct window{
    int id;
    int endtime;
    window(int _id=-1, int _endtime=8*3600) : id(_id), endtime(_endtime) {}
    bool operator < (const window& w) const {
        if(endtime != w.endtime)
            return endtime > w.endtime;
        return id > w.id;
    }
};
struct person{
    int id, atime, ptime;
    person(int _id, int _a, int _p) : id(_id), atime(_a), ptime(_p) {}
    bool operator < (const person& p) const {
        if(atime != p.atime)
            return atime < p.atime;
        return id < p.id;
    }
};
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<person> ps;
    int h, m, s, p, thre=17*3600;
    for(int i=0; i<n; ++i) {
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        int tmp = h*3600+m*60+s;
        if(tmp > thre) continue;
        if(p > 60) p=60;
        p*=60;
//         printf("%d  %d:%d:%d\n", i, tmp/3600, tmp%3600/60, tmp%60);
        ps.push_back(person(i, tmp, p));
    }
    sort(ps.begin(), ps.end());
    priority_queue<window> pq;
    for(int i=0; i<k; ++i) {
        pq.push(window(i));
    }
    int cnt = 0;
    for(int i=0; i<ps.size(); ++i) {
//         printf("person=%d  %d:%d:%d  %d\n", ps[i].id, ps[i].atime/3600, ps[i].atime%3600/60, ps[i].atime%60, ps[i].ptime/60);
        auto top = pq.top();
        pq.pop();
        if(top.endtime >= ps[i].atime) {
            cnt += top.endtime - ps[i].atime;
            top.endtime += ps[i].ptime;
        }else {
            top.endtime = ps[i].atime + ps[i].ptime;
        }
//         printf("%d  %d:%d:%d\n", top.id, top.endtime/3600, top.endtime%3600/60, top.endtime%60);
        pq.push(top);
    }
    printf("%.1f\n", 1.0*cnt/60/ps.size());
}