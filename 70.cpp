#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct mc{
    double amount;
    double price, sp;
    mc(double _a=0, double _p=0) : amount(_a), price(_p) {}
};

bool cmp(mc* a, mc* b) {
    return a->sp > b->sp;
}

int main() {
    int n;
    double d;
    cin >> n >> d;
    double a;
    double t;
    vector<mc*> vec(n);
    for(int i=0; i<n; ++i) {
        cin >> a;
        vec[i] = new mc(a);
    }
    for(int i=0; i<n; ++i) {
        cin >> t;
        vec[i]->price = t;
        vec[i]->sp = vec[i]->price / vec[i]->amount;
    }
    sort(vec.begin(), vec.end(), cmp);
    double res = 0;
    for(int i=0; i<n; ++i) {
        if(d - vec[i]->amount > 1e-4) {
            res += vec[i]->price;
            d -= vec[i]->amount;
        }
        else {
            res += (d*1.0/vec[i]->amount)*vec[i]->price;
            break;
        }
    }
    printf("%.2f\n", res);
}