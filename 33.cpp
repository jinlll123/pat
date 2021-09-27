// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<cstdio>
// using namespace std;

// struct sta {
//     int dis;
//     double price;
//     sta(int _d, double _p) : dis(_d), price(_p) {}
// };

// bool cmp(sta* a, sta* b) {
//     return a->dis < b->dis;
// }

// int main() {
//     int cap, dis, run, n;
//     cin >> cap >> dis >> run >> n;
//     vector<sta*> vec;
//     for (int i = 0; i < n; ++i) {
//         int dis;
//         double price;
//         cin >> price >> dis;
//         vec.push_back(new sta(dis, price));
//     }
//     sort(vec.begin(), vec.end(), cmp);
// //     for (int i = 0; i < vec.size(); ++i) cout << i << " " << vec[i]->dis << " " << vec[i]->price << endl;
//     if (vec[0]->dis != 0) cout << "The maximum travel distance = 0.00\n";
//     // else if (vec[n - 1]->dis < dis - 600) printf("The maximum travel distance = %.2f", vec[n - 1]->dis + 600);
//     else {
//         int st = 0;
//         double maxd = 0;
//         double sump = 0, rgas = 0;
//         while (st < n) {
// //             cout << "====st==== " << st << endl;
//             maxd = vec[st]->dis + cap*run;
// //             cout << "maxd = " << maxd << endl;
//             if (st == n - 1 && maxd < dis) break;
//             if(st < n-1)
//                 if (vec[st + 1]->dis > maxd) break;
//             int i = st;
//             bool flag = true;  // 有价格更低的，则为true
//             for (; i < n && vec[i]->dis <= maxd; ++i) {
//                 if (vec[i]->price < vec[st]->price) {
//                     flag = false;
//                     break;
//                 }
//             }
// //             cout << "i = " << i << endl;
//             if (flag) {  // 没有价格更低的
// //                 cout << "no lower price\n";
//                 if (dis <= maxd) {  // 能够直接到达终点，加到终点的量
// //                     cout << "to destination\n";
//                     sump += (dis - vec[st]->dis) * 1.0 / run * vec[st]->price;
//                     rgas = 0;
//                     st++;
//                 }
//                 else {  // 不能直接到达终点，则加满
// //                     cout << "get gas\n";
//                     sump += (cap - rgas) * vec[st]->price;
//                     rgas = cap - (vec[st+1]->dis - vec[st]->dis) * 1.0 / run;
//                     st++;
//                 }

//             }
//             else {  // 有价格更低的
// //                 cout << "have lower price , sta = " << i << endl;
//                 if (vec[st]->dis + run * rgas > vec[i]->dis) {  // 能到那个站点
// //                     cout << "can get to without getting gas\n";
//                     rgas -= (vec[i]->dis - vec[st]->dis) * 1.0 / run;
//                 }
//                 else {  // 不能，加油
// //                     cout << "cant get to there\n";
// //                     cout << "sum+= " << ((vec[i]->dis - vec[st]->dis) * 1.0 / run - rgas) * vec[st]->price << endl;
//                     sump += ((vec[i]->dis - vec[st]->dis) * 1.0 / run - rgas) * vec[st]->price;
//                     rgas = 0;
//                 }
//                 st = i;
//             }
// //             cout << "sump = " << sump << endl;
// //             cout << "rest gas = " << rgas << endl << endl;

//         }
//         // cout << "====>>>  " << maxd << endl;
//         if (st < n) printf("The maximum travel distance = %.2f\n", maxd);
//         else printf("%.2f\n", sump);
//     }
// }
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

struct sta {
    int dis;
    double price;
    sta(int _d, double _p) : dis(_d), price(_p) {}
};

bool cmp(sta* a, sta* b) {
    return a->dis < b->dis;
}

int main() {
    int cap, dis, run, n;
    cin >> cap >> dis >> run >> n;
    vector<sta*> vec;
    for (int i = 0; i < n; ++i) {
        int dis;
        double price;
        cin >> price >> dis;
        vec.push_back(new sta(dis, price));
    }
    sort(vec.begin(), vec.end(), cmp);
    // for (int i = 0; i < vec.size(); ++i) cout << i << " " << vec[i]->dis << " " << vec[i]->price << endl;
    if (vec[0]->dis != 0) cout << "The maximum travel distance = 0.00\n";
    // else if (vec[n - 1]->dis < dis - 600) printf("The maximum travel distance = %.2f", vec[n - 1]->dis + 600);
    else {
        int st = 0;
        double maxd = 0;
        double sump = 0, rgas = 0;
        bool right = false;
        while (st < n) {
//             cout << "====st==== " << st << endl;
            maxd = vec[st]->dis + cap*run;
//             cout << "maxd = " << maxd << endl;
            if (st == n - 1 && maxd < dis) break;
            if(st < n-1)
                if (vec[st + 1]->dis > maxd) break;
            int i = st;
            bool flag = true;  // 有价格更低的，则为false
            for (; i < n && vec[i]->dis <= maxd; ++i) {
                if (vec[i]->price < vec[st]->price) {
                    flag = false;
                    break;
                }
            }
//             cout << "i = " << i << endl;
            if (flag) {  // 没有价格更低的
//                 cout << "no lower price\n";
                if (dis <= maxd) {  // 能够直接到达终点，加到终点的量
//                     cout << "to destination\n";
                    sump += (dis - vec[st]->dis) * 1.0 / run * vec[st]->price;
                    rgas = 0;
                    // st++;
                    right = true;
                    break;
                }
                else {  // 不能直接到达终点，则加满
//                     cout << "get gas\n";
                    sump += (cap - rgas) * vec[st]->price;
                    rgas = cap - (vec[st+1]->dis - vec[st]->dis) * 1.0 / run;
                    st++;
                }

            }
            else {  // 有价格更低的
//                 cout << "have lower price , sta = " << i << endl;
                if (vec[st]->dis + run * rgas > vec[i]->dis) {  // 能到那个站点
//                     cout << "can get to without getting gas\n";
                    rgas -= (vec[i]->dis - vec[st]->dis) * 1.0 / run;
                }
                else {  // 不能，加油
//                     cout << "cant get to there\n";
//                     cout << "sum+= " << ((vec[i]->dis - vec[st]->dis) * 1.0 / run - rgas) * vec[st]->price << endl;
                    sump += ((vec[i]->dis - vec[st]->dis) * 1.0 / run - rgas) * vec[st]->price;
                    rgas = 0;
                }
                st = i;
            }
//             cout << "sump = " << sump << endl;
//             cout << "rest gas = " << rgas << endl << endl;

        }
//         cout << "====>>>  " << maxd << endl;
        if (st < n && !right) printf("The maximum travel distance = %.2f\n", maxd);
        else printf("%.2f\n", sump);
    }
}