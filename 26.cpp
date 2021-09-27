#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;

struct table {
    int id;
    int endtime;
    table(int _id) : id(_id), endtime(8*3600){}
    bool operator < (const table& t) const {
        if(endtime != t.endtime)
            return endtime > t.endtime;
        return id > t.id;
    }
};

struct person {
    int arrtime;
    int playtime;
    int servetime;
    person(int a = 0, int p = 0, int s = 0) : arrtime(a), playtime(p), servetime(s) {}
    bool operator < (const person &p) const {return arrtime > p.arrtime;}
};

void outtime(int t) {
    printf("%02d:%02d:%02d ", t / 3600, (t % 3600) / 60, t % 60);
}

int main() {
    int pnum;
    cin >> pnum;
    vector<person> res;
    priority_queue<person> ppq;
    priority_queue<person> vip_ppq;
    int h, m, s, pt, vip;
    for (int i = 0; i < pnum; ++i) {
        scanf("%d:%d:%d %d %d", &h, &m, &s, &pt, &vip);
        if(vip == 1) vip_ppq.push(person(h * 3600 + m * 60 + s, pt*60));
        else ppq.push(person(h * 3600 + m * 60 + s, pt*60));
    }
    int n, k;
    cin >> n >> k;
    vector<bool> tvip(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        tvip[v] = true;
    }
    priority_queue<table> tpq;
    for(int i=1; i<=n; ++i) {
        tpq.push(table(i));
    }
    int maxt = 21 * 3600;
    vector<int> t_serve(n+1, 0);
    while(true) {
        auto t_top = tpq.top();
//         tpq.pop();
//         cout << t_top.id << " endtime = ";
//         outtime(t_top.endtime);
//         cout << endl;
        if(t_top.endtime > maxt || (ppq.empty() && vip_ppq.empty())) break;
        
        int nxt;
        if(!ppq.empty() && !vip_ppq.empty()) {
            if(ppq.top().arrtime < vip_ppq.top().arrtime) {
                nxt = ppq.top().arrtime;
            } else {
                nxt = vip_ppq.top().arrtime;
            }
        } else if(!ppq.empty()) {
            nxt = ppq.top().arrtime;
        } else {
            nxt = vip_ppq.top().arrtime;
        }
        
        while(true) {
            if(tpq.top().endtime < nxt) {
                auto tmp = tpq.top();
                tpq.pop();
                tmp.endtime = nxt;
                tpq.push(tmp);
            } else {
                break;
            }
        }
        
        t_top = tpq.top();
        tpq.pop();
        
        person p_top;
        if(tvip[t_top.id]) {
            if(!vip_ppq.empty()) {
                if(vip_ppq.top().arrtime < t_top.endtime) {
                    p_top = vip_ppq.top();
                    vip_ppq.pop();
                }else if(!ppq.empty()) {
                    if(vip_ppq.top().arrtime < ppq.top().arrtime) {
                        p_top = vip_ppq.top();
                        vip_ppq.pop();
                    } else {
                        p_top = ppq.top();
                        ppq.pop();
                    }
                }
            }
            else{
                p_top = ppq.top();
                ppq.pop();
            }
        } else {
            if(!ppq.empty() && !vip_ppq.empty()) {
                if(ppq.top().arrtime < vip_ppq.top().arrtime) {
                    p_top = ppq.top();
                    ppq.pop();
                } else {
                    p_top = vip_ppq.top();
                    vip_ppq.pop();
                }
            } else if(!ppq.empty()) {
                p_top = ppq.top();
                ppq.pop();
            } else {
                p_top = vip_ppq.top();
                vip_ppq.pop();
            }
        }
        p_top.servetime = max(t_top.endtime, p_top.arrtime);
//         cout << "    p_arrive time = ";
//         outtime(p_top.arrtime);
//         outtime(p_top.servetime);
//         cout << p_top.playtime/60 << endl;
        res.push_back(p_top);
        t_serve[t_top.id]++;
        t_top.endtime = p_top.servetime + p_top.playtime;
        
//         outtime(t_top.endtime);
//         cout << endl;
        tpq.push(t_top);
    }
    for(int i=0; i<res.size(); ++i) {
        outtime(res[i].arrtime);
        outtime(res[i].servetime);
        printf("%.0f\n", 1.0*(res[i].servetime - res[i].arrtime)/60+0.00001);
    }
    for(int i=1; i<=n; ++i) {
        cout << t_serve[i] << " \n"[i==n];
    }
//     printf("%.0f\n", 5.5);
//     printf("%.0f\n", 1.5);
}