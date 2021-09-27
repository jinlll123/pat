#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct stu {
    int id;
    double* score;
    int* rank;
    int bri;  // best rank index
    stu() {
        score = new double[4];
        rank = new int[4];
    }
    //     stu(int _id, int _c, int _m, int _e) : id(_id) {
    //         score = new double[4];
    //         rank = new int[4];
    //         bri = -1;
    //     }
};

int flag = -1;
bool cmp(stu* a, stu* b) {
    return a->score[flag] > b->score[flag];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<stu*> vec;
    for (int i = 0; i < n; ++i) {
        stu* cur = new stu();
        cin >> cur->id >> cur->score[1] >> cur->score[2] >> cur->score[3];
        cur->score[0] = (cur->score[1] + cur->score[2] + cur->score[3]) / 3;
        vec.push_back(cur);
    }
//     for (int i = 0; i < n; ++i) {
//         cout << vec[i]->id << " " << vec[i]->score[0] << " " << vec[i]->score[1] << " " << vec[i]->score[2] << "\n";
//     }

    for (flag = 0; flag < 4; ++flag) {
        sort(vec.begin(), vec.end(), cmp);
        vec[0]->rank[flag] = 1;
        for (int i = 1; i < n; ++i) {
            vec[i]->rank[flag] = i + 1;
            if (vec[i]->score[flag] == vec[i - 1]->score[flag])
                vec[i]->rank[flag] = vec[i - 1]->rank[flag];
        }
    }
    for (int i = 0; i < n; ++i) {
        vec[i]->bri = 0;
        int min = vec[i]->rank[0];
        for (int j = 1; j < 4; ++j) {
            if (vec[i]->rank[j] < min) {
                vec[i]->bri = j;
                min = vec[i]->rank[j];
            }
        }
    }
    map<int, stu*> mp;
    for (auto item : vec) {
        mp[item->id] = item;
    }
    int k;
    string sub = "ACME";
    for (int i = 0; i < m; ++i) {
        cin >> k;
        //cout << k << endl;
        if (mp.find(k) == mp.end()) {
            cout << "N/A\n";
        }
        else {
            cout << mp[k]->rank[mp[k]->bri] << " " << sub[mp[k]->bri] << endl;
        }

    }
}