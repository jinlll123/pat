#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct person{
    string id;
    int score, loc, locr, finr;
    person(string _s, int _sco, int _l) {
        id = _s;
        score = _sco;
        loc = _l;
    }
};

bool cmp(person *a, person *b) {
    if(a->score != b->score) return a->score > b->score;
    return a->id < b->id;
}

int main() {
    int n, k;
    cin >> n;
    vector<person*> total_vec;
    for(int i=1; i<=n; ++i) {
        cin >> k;
        vector<person*> loc_vec;
        string id;
        int score;
        for(int j=0; j<k; ++j) {
            cin >> id >> score;
            loc_vec.push_back(new person(id, score, i));
        }
        sort(loc_vec.begin(), loc_vec.end(), cmp);
        loc_vec[0]->locr = 1;
        for(int i=1; i<loc_vec.size(); ++i) {
            if(loc_vec[i]->score == loc_vec[i-1]->score) loc_vec[i]->locr = loc_vec[i-1]->locr;
            else loc_vec[i]->locr = i+1;
        }
        for(auto p : loc_vec) total_vec.push_back(p);
    }
    sort(total_vec.begin(), total_vec.end(), cmp);
    cout << total_vec.size() << endl;
    total_vec[0]->finr = 1;
    for(int i=1; i<total_vec.size(); ++i) {
        if(total_vec[i]->score == total_vec[i-1]->score) total_vec[i]->finr = total_vec[i-1]->finr;
        else total_vec[i]->finr = i+1;
    }
    for(auto p : total_vec) {
        cout << p->id << " " << p->finr << " " << p->loc << " " << p->locr << endl;
    }
}