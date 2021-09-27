// #include <iostream>
// #include <string> 
// #include <vector>
// #include <algorithm>
// using namespace std;

// string cal_p(string a, string b) {
// 	int lena = a.length(), lenb = b.length();
// 	string res = "";
// 	int tmp = 0;
// 	for (int i = 1; i <= lenb; ++i) {
// 		tmp += a[lena - i] - '0' + b[lenb - i] - '0';
// 		res += (tmp % 10 + '0');
// 		tmp /= 10;
// 	}
// 	for (int i = lenb + 1; i <= lena; ++i) {
// 		tmp += a[lena - i] - '0';
// 		res += (tmp % 10 + '0');
// 		tmp /= 10;
// 	}
// 	if (tmp != 0) res += (tmp + '0');
// 	reverse(res.begin(), res.end());
// 	return res;
// }

// string cal_n(string a, string b) {
// 	int pre = 0, tmp = 0;
// 	int lena = a.length(), lenb = b.length();
// 	string res = "";
// 	for (int i = 1; i <= lenb; ++i) {
// 		tmp = a[lena - i] -  b[lenb - i] + pre;
// 		//cout << i << " - " << tmp << endl;
// 		if (tmp < 0) {
// 			tmp += 10;
// 			pre = -1;
// 		}
// 		else pre = 0;
// 		//cout << i << " -- " << tmp << " "  << pre << endl;
// 		res += (tmp + '0');
// 		//cout << res << endl;
// 	}
// 	//cout << "** " << pre << endl;
// 	for (int i = lenb + 1; i <= lena; ++i) {
// 		tmp = a[lena - i] - '0' + pre;
// 		//cout << i << " -> " << tmp << endl;
// 		if (tmp < 0) {
// 			tmp += 10;
// 			pre = -1;
// 		}
// 		else pre = 0;
// 		//cout << i << " ->> " << tmp << " " << pre << endl;
// 		res += (tmp + '0');
// 		//cout << res << endl;
// 	}
// 	reverse(res.begin(), res.end());
// 	return res;
// }

// bool bigger(string a, string b) {
// 	if (a.length() != b.length()) return a.length() != b.length();
// 	for (int i = 0; i < a.length(); ++i) {
// 		if (a[i] != b[i]) return a[i] > b[i];
// 	}
// 	return true;
// }

// int main() {
// 	//while (true) {
//     string a, b, res;
//     cin >> a >> b;
//     bool fg = false;

//     if (a[0] == '-' && b[0] == '-') {
//         fg = true;
//         if (a.length() >= b.length()) res = cal_p(a.substr(1), b.substr(1));
//         else res = cal_p(b.substr(1), a.substr(1));
//     }
//     else if (a[0] == '-') {
//         string c = a.substr(1);
//         if (c == b) res = "0";
//         else {
//             if (bigger(c, b)) {
//                 fg = true;
//                 res = cal_n(c, b);
//             }
//             else {
//                 res = cal_n(b, c);
//             }
//         }
//     }
//     else if (b[0] == '-') {
//         string c = b.substr(1);
//         if (c == a) res = "0";
//         else {
//             if (bigger(c, a)) {
//                 fg = true;
//                 res = cal_n(c, a);
//             }
//             else {
//                 res = cal_n(a, c);
//             }
//         }
//     }
//     else {
//         if (a.length() >= b.length()) res = cal_p(a, b);
//         else res = cal_p(b, a);
//     }
//     int i=0;
//     for(; i<res.length(); ++i) {
//         if(res[i]!='0') break;
//     }
//     res = res.substr(i);
//     int len = res.length();
//     if (fg) cout << "-";
//     for (int i = 0; i < len; i++) {
//         cout << res[i];
//         if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
//     }
// //     if(res.length() <= 3) cout << res << endl;
// //     else {
// //         int f = res.length()%3, i=0;
// //         bool kkk = (f==0 ? false : true);
// //         for(; i<f; ++i) {
// //             cout << res[i];
// //         }
// //         for(i=0; i+f<res.length(); ++i) {
// //             if(i%3==0 && kkk) cout << ",";
// //             else kkk = true;
// //             cout << res[f+i];
// //         }
// //     }
//     cout << endl;
// 	//}
	

// }

#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >>b;
    string res = to_string(a+b);
    int len = res.length();
    for(int i=0; i<len; ++i) {
        cout << res[i];
        if(res[i]=='-') continue;
        if((i+1)%3 == len%3 && i!=len-1) cout << ",";
    }
    cout << endl;
}