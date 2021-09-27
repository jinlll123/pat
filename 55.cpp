#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
struct person{
    string name;
    int age, worth;
    person(){
        name="";
        age=0;
        worth=0;
    }
    person(string _name, int _age, int _worth) {
        name = _name;
        age = _age;
        worth = _worth;
    }
}a[100005];
// bool cmpAge(person* a, person* b) {
//     if(a->age != b->age) return a->age < b->age;
//     if(a->worth != b->worth) return a->worth > b->worth;
//     return a->name < b->name;
// }
// bool cmpP(person* a, person* b) {
//     if(a->worth != b->worth) return a->worth > b->worth;
//     if(a->age != b->age) return a->age < b->age;
//     return a->name < b->name;
// }
bool cmpP(person a, person b) {
    if(a.worth != b.worth) return a.worth > b.worth;
    if(a.age != b.age) return a.age < b.age;
    return a.name < b.name;
}
int main() {
    int n, k;
    cin >> n >> k;
    string name;
    int age, worth;
    vector<person*> vec;
    for(int i=0; i<n; ++i) {
        a[i].name.resize(10);
        scanf("%s %d %d", &a[i].name[0], &a[i].age, &a[i].worth);
//         name.resize(10);
//         scanf("%s %d %d", &name[0], &age, &worth);
//         vec.push_back(new person(name, age, worth));
    }
    sort(a, a+n, cmpP);
//     sort(vec.begin(), vec.end(), cmpP);
    int m, amin, amax;
    for(int i=1; i<=k; ++i) {
        printf("Case #%d:\n", i);
        cin >> m >> amin >> amax;
        int cnt=0;
        for(int i=0; i<n; ++i) {
            if(a[i].age>=amin && a[i].age<=amax) {
                printf("%s %d %d\n", a[i].name.c_str(), a[i].age, a[i].worth);
                cnt++;
            }
            if(cnt==m) break;
        }
//         for(int i=0; i<vec.size(); ++i) {
//             if(vec[i]->age>=amin && vec[i]->age<=amax) {
//                 printf("%s %d %d\n", vec[i]->name.c_str(), vec[i]->age, vec[i]->worth);
//                 cnt++;
//             }
//             if(cnt==m) break;
//         }
        if(cnt==0) printf("None\n");
//         int l=0, r=vec.size()-1;
//         while(vec[l]->age<amin || vec[r]->age>amax) {
//             if(vec[l]->age < amin) ++l;
//             if(vec[r]->age > amax) --r;
//         }
//         vector<person*> vect(vec.begin()+l, vec.begin()+r+1);
// //         for(int j=l; j<=r; ++j) vect.push_back(vec[j]);
//         if(vect.size()==0) {
//             cout << "None\n";
//             continue;
//         }
//         sort(vect.begin(), vect.end(), cmpP);
//         int len = min(m, int(vect.size()));
//         for(int j=0; j<len; ++j) printf("%s %d %d\n", vect[j]->name.c_str(), vect[j]->age, vect[j]->worth);
    }
}