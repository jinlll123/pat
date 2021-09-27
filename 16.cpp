#include<bits/stdc++.h>
using namespace std;
int price[25] = { 0 };
struct record {
    string name;
    int M, d, h, m, time;
    bool state;
    record(string _name = "", int M_ = 0, int _d = 0, int _h = 0, int _m = 0, int _t = 0, bool _st = true) :
        name(_name), M(M_), d(_d), h(_h), m(_m), time(_t), state(_st) {}
    /*bool operator < (const record* r) const {
        if (name != r->name) return name < r->name;
        return time < r->time;
    }*/
};

bool cmp(record* a, record* b) {
    if (a->name != b->name) return a->name < b->name;
    return a->time < b->time;
}

int getPrice(record* r) {
    int sum = 0;
    for (int i = 1; i < r->d; ++i) {
        sum += 60 * price[24];
    }
    for (int i = 0; i < r->h; ++i) {
        sum += 60 * price[i];
    }
    sum += r->m * price[r->h];
    return sum;
}

int main() {
    for (int i = 0; i < 24; ++i) {
        scanf("%d", &price[i]);
        price[24] += price[i];
    }
    int n;
    scanf("%d", &n);
//     cout << n << endl;
    vector<record*> vec;
    string name, state;  // on->true,  off->false
    int M, d, h, m;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        scanf("%d:%d:%d:%d", &M, &d, &h, &m);
        cin >> state;
        vec.push_back(new record(name, M, d, h, m, d * 24 * 60 + h * 60 + m, state[1] == 'n'));
//         printf("%d:%d:%d:%d  %d\n", M, d, h, m, d * 24 * 60 + h * 60 + m);
    }
    sort(vec.begin(), vec.end(), cmp);
//     cout << vec.size() << endl;
//     for (int i = 0; i < vec.size(); ++i) {
//         printf("%s %d:%d:%d:%d ", vec[i]->name.c_str(), vec[i]->M, vec[i]->d, vec[i]->h, vec[i]->m);
//         if (vec[i]->state) printf("on\n");
//         else printf("off\n");
//     }
    vector<record*> res;
    for (int i = 0; i < vec.size(); ) {
        if (i + 1 >= vec.size()) break;
        // cout << i << endl;
        if (!vec[i]->state || vec[i + 1]->state || vec[i]->name != vec[i + 1]->name) {
            ++i;
            continue;
        }
        res.push_back(vec[i]);
        res.push_back(vec[i+1]);
        i += 2;
    }
//     cout << getPrice(res[3]) - getPrice(res[2]) << endl;
    // cout << res.size() << endl;
    name = res[0]->name;
    printf("%s %02d\n", name.c_str(), M);
    int sumP = 0;
    for (int i = 0; i < res.size(); i += 2) {
        int time = res[i + 1]->time - res[i]->time;
        int pri = getPrice(res[i + 1]) - getPrice(res[i]);
        if (name == res[i]->name) {
            sumP += pri;
        }
        else {
            printf("Total amount: $%.2f\n", sumP * 1.0 / 100);
            name = res[i]->name;
            printf("%s %02d\n", name.c_str(), M);
            sumP = pri;
        }
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
            res[i]->d, res[i]->h, res[i]->m, res[i + 1]->d, res[i + 1]->h, res[i + 1]->m, time, pri * 1.0 / 100);
    }
    printf("Total amount: $%.2f\n", sumP * 1.0 / 100);
}