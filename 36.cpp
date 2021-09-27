#include<iostream>
#include<string>
using namespace std;
int main() {
    string fname="", fid="", mname="", mid="", name, id;
    int fg = -1, mg = 999, g;
    char gender;
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> name >> gender >> id >> g;
        if(gender == 'M') {
            if(g < mg) {
                mname = name;
                mid = id;
                mg = g;
            }
        }
        else {
            if(g > fg) {
                fname = name;
                fid = id;
                fg = g;
            }
        }
    }
    if(fg == -1) cout << "Absent\n";
    else cout << fname << " " << fid << endl;
    if(mg == 999) cout << "Absent\n";
    else cout << mname << " " << mid << endl;
    if(fg==-1 || mg==999) cout << "NA\n";
    else cout << fg - mg << endl;
}