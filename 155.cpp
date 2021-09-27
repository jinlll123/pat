#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> vec, path;
bool fg = true, type=true;
void tra(int cur, int prev, bool cp) {
    if(cur>n) return;
    if(cp) {
        if((prev<=vec[cur]) != type)
            fg = false;
    }
    path.push_back(vec[cur]);
    if(cur*2 > n && cur*2+1 > n) {
        for(int i=0; i<path.size(); ++i) {
            cout << path[i] << " \n"[i==path.size()-1];
        }
    }else {
        tra(cur*2+1, vec[cur], true);
        tra(cur*2, vec[cur], true);
    }
    path.pop_back();
}

int main() {
    cin >> n;
    vec.resize(n+1);
    for(int i=1; i<=n; ++i) {
        cin >> vec[i];
    }
    for(int i=2; i<=n; ++i) {
        if(vec[i] != vec[1])
            type = vec[1] < vec[i];
    }
    tra(1, -1, false);
    if(!fg) printf("Not Heap\n");
    else {
        if(type) printf("Min Heap\n");
        else printf("Max Heap\n");
    }
}