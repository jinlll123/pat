#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct person{
    string name;
    int id, grade;
    person(int i, string n, int g) {
        id = i;
        name = n;
        grade = g;
    }
};
int c;
bool cmp(person* a, person* b) {
    if(c==1) return a->id < b->id;
    else if(c==2) {
        if(a->name != b->name) return a->name < b->name;
        return a->id < b->id;
    }
    else if(c==3) {
        if(a->grade != b->grade) return a->grade < b->grade;
        return a->id < b->id;
    }
}

int main() {
    int n;
    cin >> n >> c;
    vector<person*> vec;
    for(int i=0; i<n; ++i) {
        int id, grade;
        string name;
        cin >> id >> name >> grade;
        vec.push_back(new person(id, name, grade));
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i=0; i<n; ++i) {
        printf("%06d %s %d\n", vec[i]->id, vec[i]->name.c_str(), vec[i]->grade);
    }
}