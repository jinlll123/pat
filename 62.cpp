#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct person{
    int id, virg, talg, totg, k;
    person(int _id, int _virg, int _talg, int _totg, int _k) : id(_id), virg(_virg), talg(_talg), totg(_totg), k(_k) {}
};
bool cmp(person* a, person* b) {
    if(a->k != b->k) return a->k < b->k;
    if(a->totg != b->totg) return a->totg > b->totg;
    if(a->virg != b->virg) return a->virg > b->virg;
    return a->id < b->id;
}
int main() {
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    vector<person*> vec;
    int id, vg, tg;
    for(int i=0; i<n; ++i) {
        scanf("%d %d %d", &id, &vg, &tg);
        if(vg<l || tg<l) continue;
        int k;
        if(vg>=h && tg>=h) k=1;
        else if(vg>=h) k=2;
        else if(vg>=tg) k=3;
        else k=4;
        vec.push_back(new person(id, vg, tg, vg+tg, k));
    }
    sort(vec.begin(), vec.end(), cmp);\
    cout << vec.size() << endl;
    for(int i=0; i<vec.size(); ++i) {
        printf("%08d %d %d\n", vec[i]->id, vec[i]->virg, vec[i]->talg);
    }
}