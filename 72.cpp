// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<cstdio>
// #include<queue>
// #define ll long long
// using namespace std;
// const ll INF = 1e18;
// int n, m, k, dmax;
// int getid(string s) {
//     if(s[0] != 'G') return stoi(s.c_str());
//     return n+stoi(s.substr(1).c_str());
// }
// struct edge{
//     int to;
//     ll val;
//     edge(int _t, ll _v) : to(_t), val(_v) {}
//     bool operator < (const edge &e) const {return val > e.val;}
// };
// vector<vector<edge>> g;
// ll dijkstra(int s, int t) {
//     vector<bool> vis(n+m, false);
// //     vis[s] = true;
//     vector<ll> dis(n+m, INF);
//     dis[s] = 0;
//     priority_queue<edge> pq;
//     pq.push(edge(s, 0));
//     while(!pq.empty()) {
//         edge top = pq.top();
//         pq.pop();
//         if(!vis[top.to]) {
//             vis[top.to] = true;
//             for(auto nxt : g[top.to]) {
//                 if(!vis[nxt.to] && dis[nxt.to] > dis[top.to] + nxt.val) {
//                     dis[nxt.to] = dis[top.to] + nxt.val;
//                     pq.push(edge(nxt.to, dis[nxt.to]));
//                 }
//             }
//         }
//     }
//     return dis[t];
// }
// vector<ll> ds;
// ll getdis(int s, int t) {
//     ll tmp = INF;
//     for(auto nei : g[t]) {
//         if(ds[nei.to] == -1) {
//             ds[nei.to] = dijkstra(s, nei.to);
// //             cout << "nei : " << s+1 << " -> " << nei.to+1 << " = " << ds[nei.to] << endl;
//         }
//         tmp = tmp < ds[nei.to]+nei.val ? tmp : ds[nei.to]+nei.val;
// //         cout << "tmp = " << tmp << endl;
//     }
//     return tmp;
// }
// int main() {
//     scanf("%d %d %d %d", &n, &m, &k, &dmax);
//     g.resize(n+m);
//     string a, b;
//     int ai, bi, d;
//     for(int i=0; i<k; ++i) {
//         cin >> a >> b >> d;
//         ai = getid(a);
//         bi = getid(b);
//         --ai, --bi;
//         g[ai].push_back(edge(bi, d));
//         g[bi].push_back(edge(ai, d));
//     }
// //     for(int i=0; i<n+m; ++i) {
// //         for(int j=i+1; j<n+m; ++j) {
// //             cout << i+1 << " - " << j+1 << " = " << dijkstra(i, j) << endl;
// //         }
// //     }
//     int gnum=-1;
//     int dmin=1e8;
//     double avg=0;
//     for(int i=n; i<n+m; ++i) {
// //         cout << ">>> i= " << i << endl;
//         ds.clear();
//         ds.resize(n+m, -1);
//         ll tsum=0;
//         int  tmin=1e8;
//         int j=0;
//         for(; j<n; ++j) {
// //             cout << " j= " << j+1 << endl;
//             if(ds[j]==-1) {
//                 ds[j] = getdis(i, j);
// //                 cout << "-";
//             }
// //             cout << "  ds[j]= " << ds[j] << endl;
//             if(ds[j] > dmax) break;
//             tmin = tmin<ds[j] ? tmin:ds[j];
//             tsum += ds[j];
//         }
// //         for(int cur=0; cur<n; ++cur) cout << ds[cur] << " ";
// //         cout << endl;
//         if(j>=n) {
//             if(gnum == -1) {
//                 gnum = i;
//                 dmin = tmin;
//                 avg = tsum*1.0/n;
//             }
//             else if(tmin > dmin) {
//                 gnum = i;
//                 dmin = tmin;
//                 avg = tsum*1.0/n;
//             }
//             else if(tmin == dmin){
//                 if(avg - tsum*1.0/n > 0.05) {
//                     gnum = i;
//                     dmin = tmin;
//                     avg = tsum*1.0/n;
//                 }
//             }
//         }
//     }
// //     double kkk = double(dmin);
//     if(gnum == -1) cout << "No Solution\n";
//     else {
//         printf("G%d\n%d.0 %.1f\n", gnum-n+1, dmin, avg);
//     }
// }
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const ll INF = 1e18;
int n, m, k, dmax;
int getid(string s) {
    if(s[0] != 'G') return stoi(s.c_str());
    return n+stoi(s.substr(1).c_str());
}
struct edge{
    int to;
    ll val;
    edge(int _t, ll _v) : to(_t), val(_v) {}
    bool operator < (const edge &e) const {return val > e.val;}
};
vector<vector<edge>> g;
ll dijkstra(int s, int t) {
    vector<bool> vis(n+m, false);
//     vis[s] = true;
    vector<ll> dis(n+m, INF);
    dis[s] = 0;
    priority_queue<edge> pq;
    pq.push(edge(s, 0));
    while(!pq.empty()) {
        edge top = pq.top();
        pq.pop();
        if(!vis[top.to]) {
            vis[top.to] = true;
            for(auto nxt : g[top.to]) {
                if(!vis[nxt.to] && dis[nxt.to] > dis[top.to] + nxt.val) {
                    dis[nxt.to] = dis[top.to] + nxt.val;
                    pq.push(edge(nxt.to, dis[nxt.to]));
                }
            }
        }
    }
    return dis[t];
}
vector<ll> ds;
ll getdis(int s, int t) {
    ll tmp = INF;
    for(auto nei : g[t]) {
        if(ds[nei.to] == -1) {
            ds[nei.to] = dijkstra(s, nei.to);
//             cout << "nei : " << s+1 << " -> " << nei.to+1 << " = " << ds[nei.to] << endl;
        }
        tmp = tmp < ds[nei.to]+nei.val ? tmp : ds[nei.to]+nei.val;
//         cout << "tmp = " << tmp << endl;
    }
    return tmp;
}
int main() {
    scanf("%d %d %d %d", &n, &m, &k, &dmax);
    g.resize(n+m);
    string a, b;
    int ai, bi, d;
    for(int i=0; i<k; ++i) {
        cin >> a >> b >> d;
        ai = getid(a);
        bi = getid(b);
        --ai, --bi;
        g[ai].push_back(edge(bi, d));
        g[bi].push_back(edge(ai, d));
    }
//     for(int i=0; i<n+m; ++i) {
//         for(int j=i+1; j<n+m; ++j) {
//             cout << i+1 << " - " << j+1 << " = " << dijkstra(i, j) << endl;
//         }
//     }
    int gnum=-1;
    int dmin=1e8;
    double avg=0;
    for(int i=n; i<n+m; ++i) {
//         cout << ">>> i= " << i << endl;
        ds.clear();
        ds.resize(n+m, -1);
        ll tsum=0;
        int  tmin=1e8;
        int j=0;
        for(; j<n; ++j) {
//             cout << " j= " << j+1 << endl;
            if(ds[j]==-1) {
                ds[j] = getdis(i, j);
//                 cout << "-";
            }
//             cout << "  ds[j]= " << ds[j] << endl;
            if(ds[j] > dmax) break;
            tmin = tmin<ds[j] ? tmin:ds[j];
            tsum += ds[j];
        }
//         for(int cur=0; cur<n; ++cur) cout << ds[cur] << " ";
//         cout << endl;
        if(j>=n) {
            if(gnum == -1) {
                gnum = i;
                dmin = tmin;
                avg = tsum*1.0/n;
            }
            else if(tmin > dmin) {
                gnum = i;
                dmin = tmin;
                avg = tsum*1.0/n;
            }
            else if(tmin == dmin){
                if(avg - tsum*1.0/n > 0.05) {
                    gnum = i;
                    dmin = tmin;
                    avg = tsum*1.0/n;
                }
            }
        }
    }
//     double kkk = double(dmin);
    if(gnum == -1) cout << "No Solution\n";
    else {
        printf("G%d\n%d.0 %.1f\n", gnum-n+1, dmin, avg);
    }
}