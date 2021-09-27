#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct stu{
    string name, id;
    int grade;
    stu(string _n, string _i, int _g) {
        name = _n;
        id = _i;
        grade = _g;
    }
};
bool cmp(stu* a, stu* b) {
    return a->grade > b->grade;
}
int main() {
    int n;
    string name, id;
    int grade;
    cin >> n;
    vector<stu*> vec;
    for(int i=0; i<n; ++i) {
        cin >> name >> id >> grade;
        vec.push_back(new stu(name, id, grade));
    }
    int low, high;
    cin >> low >> high;
    vector<stu*> res;
    for(auto p : vec) {
        if(low<=p->grade && p->grade<=high) res.push_back(p);
    }
    sort(res.begin(), res.end(), cmp);
    if(res.size()==0) cout<<"NONE\n";
    else {
        for(auto p : res) {
            cout << p->name << " " << p->id << endl;
        }
    }
}