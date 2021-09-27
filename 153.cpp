#include<bits/stdc++.h>
using namespace std;
struct stu{
    string id;
    int score;
    stu(string _id, int _score) : id(_id), score(_score) {}
};

bool cmp(stu* a, stu* b) {
    if(a->score != b->score) return a->score > b->score;
    return a->id < b->id;
}

struct date_site_num{
    int site, num;
    date_site_num(int _site, int _num=1) : site(_site), num(_num) {}
};
bool cmp2(date_site_num* a, date_site_num* b) {
    if(a->num != b->num) return a->num > b->num;
    return a->site < b->site;
}
// vector<stu*> vec;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
//     vec.resize(n);
    string id;
    int score;
    vector<stu*> level[3];
    vector<int> site_num(1000, 0);
    vector<int> site_score(1000, 0);
    map<int, vector<int>> mp;
    for(int i=0; i<n; ++i) {
        cin >> id >> score;
        stu* tmp = new stu(id, score);
        if(id[0]=='T') level[0].push_back(tmp);
        else if(id[0]=='A') level[1].push_back(tmp);
        else if(id[0]=='B') level[2].push_back(tmp);
        
        int site = stoi(id.substr(1, 3).c_str());
        site_num[site]++;
        site_score[site] += score;
        
        int date = stoi(id.substr(4, 6).c_str());
        if(mp.find(date) == mp.end()) {
            mp[date].resize(1000, 0);
        }
        mp[date][site]++;
//         cout << id.substr(4, 6) << endl;
//         cout << id.substr(10, 3) << endl;
    }
    int type;
    string par;
    for(int i=1; i<=m; ++i) {
        cin >> type;
        if(type == 1) {
            cin >> par;
            printf("Case %d: %d %s\n", i, type, par.c_str());
            int k=-1;
            if(par[0]=='T') k=0;
            else if(par[0]=='A') k=1;
            else if(par[0]=='B') k=2;
            
            if(par.size()!=1 || k==-1) printf("NA\n");
            else if(level[k].size()==0) printf("NA\n");
            else {
                sort(level[k].begin(), level[k].end(), cmp);
                for(auto tmps : level[k]) {
                    printf("%s %d\n", tmps->id.c_str(), tmps->score);
                }
            }
        }else if(type == 2) {
            cin >> par;
            int site = stoi(par.c_str());
            printf("Case %d: %d %s\n", i, type, par.c_str());
            if(site_num[site]==0) printf("NA\n");
            else {
                printf("%d %d\n", site_num[site], site_score[site]);
            }
            
        }else if(type == 3){
            cin >> par;
            int date = stoi(par.c_str());
            printf("Case %d: %d %s\n", i, type, par.c_str());
            if(mp.find(date) == mp.end()) {
                printf("NA\n");
            }else {
                vector<date_site_num*> res;
                for(int i=101; i<1000; ++i) {
                    if(mp[date][i] != 0) {
                        res.push_back(new date_site_num(i, mp[date][i]));
                    }
                }
                if(res.size()==0) {
                    printf("NA\n");
                }else {
                    sort(res.begin(), res.end(), cmp2);
                    for(auto dsn : res) {
                        printf("%d %d\n", dsn->site, dsn->num);
                    }
                }
                
            }
        }
        else {
            string stmp;
            cin >> stmp;
            printf("Case %d: %d %s\n", i, type, stmp.c_str());
            printf("NA\n");
        }
    }
}