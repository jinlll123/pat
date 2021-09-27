#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    string a, b;
    cin >> a >> b;
    int wk=-1, h=-1, m=-1;
    for(int i=0; i<min(a.length(), b.length()); ++i) {
        if(a[i]==b[i]) {
            if(wk==-1) {
//                 if('a'<=a[i] && a[i]<='g') wk = a[i]-'a';
                if('A'<=a[i] && a[i]<='G') wk = a[i]-'A';
            }
            else if(h==-1){
                if('0'<=a[i] && a[i]<='9') h = a[i]-'0';
                else if('A'<=a[i] && a[i]<='N') h = a[i]-'A'+10;
//                 else if('a'<=a[i] && a[i]<='n') h = a[i]-'A'+10;
                
            }
        }
        
    }
    cin >> a >> b;
    for(int i=0; i<min(a.length(), b.length()); ++i) {
        if(a[i]==b[i] && (('a'<=a[i] && a[i]<='z') || ('A'<=a[i] && a[i]<='Z'))) {
            m = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", week[wk].c_str(), h, m);
}