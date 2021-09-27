#include<bits/stdc++.h>
using namespace std;
struct info{
    string plate;
    int time;
    bool fg;
    info(string _p, int _t, bool _f) : plate(_p), time(_t), fg(_f) {}
};
bool cmp1(info* a, info* b) {
    if(a->plate != b->plate) return a->plate > b->plate;
    else return a->time < b->time;
}
bool cmp2(info* a, info* b) {
    return a->time < b->time;
}
// bool cmp3(string a, string b) {
//     return a<b;
// }

int main() {
    int n, k;
    cin >> n >> k;
    string p, fg;
    int h, m, s;
    vector<info*> vec;
    for(int i=0; i<n; ++i) {
        cin >> p;
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> fg;
//         cout << (fg=="in" ? "in" : "out") << endl;
        vec.push_back(new info(p, h*3600+m*60+s, fg=="in"));
    }
    sort(vec.begin(), vec.end(), cmp1);
    vector<info*> v;
    map<string, int> mp;
    for(int i=0; i<vec.size(); ) {
        if(vec[i]->fg) {
            if(i+1 >= vec.size()) break;
            else if(vec[i]->plate==vec[i+1]->plate && !vec[i+1]->fg) {
                v.push_back(vec[i]);
                v.push_back(vec[i+1]);
                mp[vec[i]->plate] += vec[i+1]->time - vec[i]->time;
                i+=2;
            }
            else ++i;
        }
        else ++i;
    }
    vector<string> maxp;
    int maxt = 0;
    for(auto it : mp) {
        if(it.second > maxt) {
            maxp.clear();
            maxp.push_back(it.first);
            maxt = it.second;
        }
        else if(it.second == maxt) {
            maxp.push_back(it.first);
        }
    }
//     map<int, int> idx;
    vector<int> times;
    for(int i=0; i<k; ++i) {
        scanf("%d:%d:%d", &h, &m, &s);
        int tmp = h*3600+m*60+s;
//         idx[tmp] = i;
        times.push_back(tmp);
    }
//     sort(times.begin(), times.end());
    vector<int> res(k, 0);
    
    sort(v.begin(), v.end(), cmp2);
    int x=0, cnt=0;
    for(int i=0; i<v.size(); ++i) {
        while(v[i]->time > times[x]) {
            res[x++] = cnt;
            if(x>=k) break;
        }
        if(v[i]->fg) cnt++;
        else cnt--;
    }
//     vector<int> out(k);
//     for(int i=0; i<k; ++i) {
//         out[idx[times[i]]] = res[i];
//     }
    
    for(int i=0; i<res.size(); ++i) {
        cout << res[i] << endl;
    }
    
//     sort(maxp.begin(), maxp.end(), cmp3);
    for(int i=0; i<maxp.size(); ++i) {
        cout << maxp[i] << " ";
    }
    printf("%02d:%02d:%02d\n", maxt/3600, maxt%3600/60, maxt%60);
}