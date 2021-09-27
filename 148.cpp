#include<bits/stdc++.h>
using namespace std;
// bool fg = false;
// int n, wn=0;
// vector<bool> isW;
// vector<int> liars;
// vector<int> vec;
// void getW(int cur, int wn) {
//     if(fg) return;
//     if(cur==n+1) {
//         if(liars.size()==2 && wn==2) {
//             if((isW[liars[0]]&&!isW[liars[1]]) || (!isW[liars[0]]&&isW[liars[1]])) {
//                 cout << liars[0] << " " << liars[1] << endl;
//                 fg = true;
//             }
//         }
//     }
//     else {
//         bool tf = vec[cur]<0;
//         isW[abs(vec[cur])] = tf;
// //         if(tf) wn++;
//         for(int i=cur+1; i<=n+1 && wn<=2; ++i) {
//             getW(i, wn+tf);
//         }
// //         if(tf) wn--;
//         if(liars.size()<2) {
//             liars.push_back(cur);
//             isW[abs(vec[cur])] = !tf;
// //             if(!tf) wn++;
//             for(int i=cur+1; i<=n+1 && wn<=2; ++i) {
//                 getW(i, wn+!tf);
//             }
//             liars.pop_back();
// //             if(!tf) wn--;
//         }
//     }
// }
int main() {
    int n;
    cin >> n;
    vector<int> vec(n+1);
    for(int i=1; i<=n; ++i) {
        cin >> vec[i];
    }
    bool fg = true;
    for(int i=1; i<n && fg; ++i) {  // i+j == liars
        for(int j=i+1; j<=n; ++j) {
            vector<int> wp(n+1, 1);
            wp[i] = wp[j] = -1;
            vector<int> liars;
            for(int k=1; k<=n; ++k) {
                if(vec[k]*wp[abs(vec[k])] < 0) liars.push_back(k);
            }
            if(liars.size()==2 && wp[liars[0]]+wp[liars[1]]==0) {
                printf("%d %d\n", i, j);
                fg = false;
                break;
            }
        }
    }
    if(fg) cout << "No Solution\n";
}