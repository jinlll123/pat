// #include<iostream>
// #include<vector>
// using namespace std;
// int main() {
//     int k;
//     cin >> k;
//     vector<int> vec(k);
//     bool flag = true;
//     for(int i=0; i<k; ++i) {
//         cin >> vec[i];
//         if(vec[i] >= 0) flag = false;
//     }
//     if(flag) {
//         printf("0 %d %d\n", vec[0], vec[k-1]);
//     }
//     else {
//         long long bs = -1, s = 0;
//         int bl, br, l, r;
//         for(int i=0; i<k; ++i) {
//             if (s + vec[i] < 0) {
//                 s = 0;
//                 if(i+1 < k) l = i+1;
//             }
//             else {
//                 r = i;
//                 s += vec[i];
//                 if(s > bs) {
//                     bl = vec[l], br = vec[r], bs = s;
//                 }
//             } 
//         }
//         printf("%lld %d %d\n", bs, bl, br);
//     }
// }

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int k;
	cin >> k;
	vector<int> vec(k);
    bool fg = true;
	for (int i = 0; i < k; ++i) {
		cin >> vec[i];
        if(vec[i] >= 0) fg = false;
	}
    if(fg) {
        printf("0 %d %d\n", vec[0], vec[k-1]);
    } else {
        long long maxm = -1, l, r;
        for (int i = 0; i < k; ) {
            if (vec[i] < 0) ++i;
            else {
                long long t = 0, j=i;
                for (; j < k; ++j) {
                    t += vec[j];
                    if (t > maxm) {
                        maxm = t;
                        l = i, r = j;
                    }
                    else if(t < 0){
                        break;
                    }
                }
                i = j + 1;
            }
        }
        printf("%d %d %d\n", maxm, vec[l], vec[r]);
    }
}