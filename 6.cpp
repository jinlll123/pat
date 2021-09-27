#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct person{
    string id;
    int in, out;
    person(string _id, int _in, int _out) : in(_in), out(_out) {id = _id;}
};

int main() {
    int m;
    cin >> m;
//     vector<person*> vec;
    string id, ip, op;
    int hi, mi, si, ho, mo, so;
    int it = 3600*24, ot = 0;
    for(int i=0; i<m; ++i) {
        cin >> id;
        scanf("%d:%d:%d %d:%d:%d", &hi, &mi, &si, &ho, &mo, &so);
//         vec.push_back(new person(id, hi*3600+mi*60+si, ho*3600+mo*60+so));
        if(hi*3600+mi*60+si < it) {
            ip = id;
            it = hi*3600+mi*60+si;
        }
        if(ho*3600+mo*60+so > ot) {
            op = id;
            ot = ho*3600+mo*60+so;
        }
    }
    cout << ip << " " << op << endl;
}