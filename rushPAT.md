#### 2021年7月16日

##### 1、[ A+B Format](https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400)   __60+min + **答案**

**数据大小**要注意，这一题直接用int相加即可，不需要string

##### 2、[A+B for Polynomials](https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000)   __20min

简单题

debug：注意系数为0 ==>  abs(x - 0) < 1e-9  的时候，要把这一项舍弃

##### 3、[Emergency](https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376)    __60+min + **答案**

**改进的dijkstra**，同dis同级设置数组path_num、person_num分别代表当前节点的最短路径、所能召集到的最多的人数

然后在top.to->nxt.to的时候，在判断nxt的情况下，按照下述情况讨论

- dis[nxt.to] > dis[top.to] + nxt.val
- dis[nxt.to] == dis[top.to] + nxt.val

#### 2021年7月17日

##### 4、[Counting Leaves](https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184)   __40min

利用map构造树+基于queue的层次遍历

debug：

- 层次遍历的时候没有把root节点push到q中

##### 5、[Spell It Right](https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336)   __10min

简单题，累加、输出

debug：

- 输入的累加为0的时候，直接输出0，不然会报错

- 下面这种写法需要vec中所有数值都不相等

  ```cpp
  for(auto i : vec) 
      cout << i << " \n"\[i==vec.back()];
  ```

##### 6、[Sign In and Sign Out](https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928)   __10min

简单题，输入用scanf("%d %d %d", &h, &m, &s)会方便很多

debug：保存了最大最小id之后，需要把对应的时间也保存好

##### 7、[ Maximum Subsequence Sum](https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168)   __40min

~~debug：这里保存left、right的时候，保存index最后访问vec输出就对，直接保存值输出就错 **>>>未理解**~~

[2021-8-17]肯定是什么地方写错了，直接保存值输出也没问题

#### 2021年7月18日

##### 8、[Elevator](https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016)  __5min

简单题

##### 9、[Product of Polynomials](https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344)   __13min

简单题，同[1002]，需要判断double系数是否可以表示为零，可以则舍弃

debug：pat的oj中，abs需要加入cmath的头文件 -> #include\<cmath>

##### 10、[Radix](https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536)   ~~__ 50min+**题目理解错误 => 答案**~~

这里并不是说基数是[0, 35]，而是

- 基数的最小值 = string串中最大字符对应数+1
- 基数的最小值 = 对比字符串对应的数值

所以这里是一个范围很大的搜索，需要使用**二分查找**

#### 2021年7月19日

##### 11、[World Cup Betting](https://pintia.cn/problem-sets/994805342720868352/problems/994805504927186944)    __13min ~~+ **题目读不懂**~~

简单题，按照例子直接猜公式

##### 12、[The Best Rank](https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480)    __60min + **答案**     ~~TODO~~

代码能力不行，应该是简单题，但是数据结构搞得太复杂了，可以用两个数组，一个保存分数，一个保存排名

2021-7-21重做笔记：

- 数组属性按照数组索引排序方式

  ```cpp
  int flag = -1;
  bool cmp(stu* a, stu* b) {
      return a->score[flag] > b->score[flag];
  }
  // ...
  for (flag = 0; flag < 4; ++flag) {
  	sort(vec.begin(), vec.end(), cmp);
  }
  ```

- 排名算法

  ```cpp
  for (flag = 0; flag < 4; ++flag) {
      sort(vec.begin(), vec.end(), cmp);
      vec[0]->rank[flag] = 1;
      for (int i = 1; i < n; ++i) {
          vec[i]->rank[flag] = i + 1;
          // 重点是下面这个，这样写就非常简便
          if (vec[i]->score[flag] == vec[i - 1]->score[flag])
              vec[i]->rank[flag] = vec[i - 1]->rank[flag];
      }
  }
  ```

- 最后输出的时候别忘了，bri保存的是best rank index，所以需要输出rank数组的内容

##### 13、[ Battle Over Cities](https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840)    __40min

并查集，简单题

debug：1. 按照并查集那个做出来之后，结果的father数组中，并不是说所有节点都已经指向根节点的，所以需要使用find来进行验证；2. 查看结果的时候，不止需要去重，还需要把“已经被占领”的城市去除

#### 2021年7月20日

##### 14、[ Waiting in Line](https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936)    ~~__80min + **WA**         TODO~~

逻辑有点乱，需要二刷，可以设置sorry数组

**7.22**重做记录：

- 如果超时服务，输出的并不是17：00，而是不管超时到什么时候的时间
- ~~还是WA了后两个样例TODO2~~

**8.18：**

- 测试点4：最开始排队的时候，第一排的人的开始时间是480，但是第二排开始就不是480了，而是上一排人的结束时间
- 测试点5：line.89，因为当前这个人服务完就已经超过1020了，所以需要直接break

##### 15、[ Reversible Primes](https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000)    __20min + **答案**

算法错误，需要注意**isPrime算法格式**如下

8.24补充：尽量用下面这种写法，`i*i<=n`可能会导致i溢出（用long long）

```cpp
bool isP(long long n) {
    if(n <= 1) return false;  // ***
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++) {  // 等于号别忘了
        if(n % i == 0)
            return false;
    }
    return true;
}
```

##### 16、[ Phone Bills](https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488)    ~~__40min**放弃**             TODO~~    8.21重做

**答案：**

- 对于这种参数多的数据，应该把**每一个参数**都作为struct中的**一个属性**
- 对于这种需要计算两个时间点t1、t2之间的时间差数据的时候，应该先分别计算t1、t2点的数据，然后**相减**
- 对于24小时不同时间不同价格的情况，数组设置为25个，最后一个设置为累计值



##### 17、[ Queueing at Bank](https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968)       ~~TODO~~   8-28

​	**35min  8-28  REDO**

​	priority_queue + vector  模拟

- 首先需要去除掉时间超过17:00:00的人
- 然后要注意priority_queue和vector之间，使用**重载operator < 的区别**



##### 18、[ Public Bike Management](https://pintia.cn/problem-sets/994805342720868352/problems/994805489282433024)    ~~[7-23]__90min放弃    TODO~~   8-28

- ~~dijkstra_3，在dijkstra的基础上，还需要加上dfs~~

- ~~本题需要实现一个正向、反向的最小、最大值，不是像[3]emergency那样只需要求一个累计人员的最大值，一个dijkstra能够实现的~~
- ~~需要通过dijkstra求出所有的最短路径并保存在一个邻接链表里面，然后通过dfs来得到各所有最短路径的组合，通过计算得到所有情况下，最优的情况~~



​	**35min  8-28  REDO**

​	dijkstra  +  vector<vector<vector\<int>>> paths

debug：

- 题目理解不够透彻，在返回的时候，是不会去继续对缺少自行车的站点进行填充的
- 图的构造的时候，需要注意g[from]是from、to，g[to]是to、from
- dijkstra不够熟练
  - 在判断得到 top.to 可以访问之后，需要将   vis[top.to] 置为 true
  - 在nxt的迭代中，也需要判断  !vis[nxt.to]   是够满足



#### 2021年7月21日

##### 19、[General Palindromic Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984)     __20min

简单题，对于基的对称数

debug：

- 对于  121  121  的测试用例，在最后判断是否为对称的时候，需要判断等于的时候

  ```cpp
  for(int i=0; i<=(sz-1)/2; ++i)
  ```

  

##### 20、[ Tree Traversals](https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072)     __40min+**答案**

已知后序、中序，转前序再转层序

debug：

​	代码逻辑错误，初始化**i=il**，然后最后cur->left的时候，sub post root需要是**pr - 1 - ir + i**

```cpp
node* pi2t(int pr, int il, int ir) {
    if (il == ir) return new node(in[il]);
    if (il > ir || pr < 0 || pr >= post.size()) return nullptr;
    node* cur = new node(post[pr]);
    int i = il;  // 不要直接i=0
    while (in[i] != post[pr]) ++i;  // 这里就可以直接使用i，而不需要il+i
    cur->left = pi2t(pr - 1 - ir + i, il, i - 1);  // 这里post root很关键
    cur->right = pi2t(pr - 1, i + 1, ir);
    return cur;
}
```

**答案：**当然还有**更巧妙的方法**，就是用一个map<int, int>存储index-val，函数迭代的时候最后多加一个int类型的index参数，每一次left.index = 2\*index+1，right.index = 2\*index+2。最后直接遍历map就行了

##### 21、[ Deepest Root](https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856)    ~~TODO~~

**答案：**

找图中，作为根的时候，可以使得图的深度最大的节点 + 有多少个连通图

- 连通图可以用并查集来实现，也可以用bool的vis数组+多次dfs来实现
- 找到所有符合条件的节点，需要两次dfs
  - 第一次dfs是随机找一个节点为根，然后找到可以使得图深度最大的节点的集合S1
  - 第二次dfs是从S1中随机找一个节点为根，找到所有满足条件的节点集S2
  - S1和S2的并集就是答案，这里通过两次dfs用同一个roots的向量实现，最后需要用一个set去重

#### 2021年7月22日

​	~~重做14，还是WA         TODO~~

​	再刷21，40min+**答案**（测试点4需要两次dfs的res都直接放到set中去重，set中直接是从小到大顺序排列）

##### 22、[ Digital Library](https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336)      __40min + **答案**

本题主要考察的是对输入输出的熟悉程度

- scanf、printf 要加 `#include<sctdio>`，别忘了！！！

- cin会忽略最后那一个换行符，影响getline，可以使用  `scanf("%d\n", &n);`  代替

- 一行用空格分隔出未知个数的string，用如下方法得到

  ```cpp
  while (cin >> tkey) {
      key[tkey].insert(tid);
      char c = getchar();
      if (c == '\n') break;
  }
  ```

##### 23、[ Have Fun with Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992)    __15min

简单题

##### 24、[Palindromic Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805476473028608)    __40min

大整数相加

debug：**（来自答案的思路）**

- 用long long会有两个测试点溢出，所以用string、

#### 2021年7月23日

重做18，无法得到正确解，这里需要用dijkstra+dfs，而不是单一的dijkstra

##### 25、[PAT Ranking](https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872)     __18min

简单题

#### 2021年7月24日

##### 26、[ Table Tennis](https://pintia.cn/problem-sets/994805342720868352/problems/994805472333250560)    __120min  答案和我思路不一样，**WA = 21分**      TODO

思路：

- 首先是如果将要服务person的arrivetime大于table的endtime，则将table.endtime置为person的arrivetime
- 然后找到最优的可以提供服务的table
  - 如果这个table是vip，则去找是否有vip，有的话下一个就是vip，没有的话就是最首位的person
  - 如果table不是vip，则让最首位的person直接去
- 更新person的servetime、wait和table的endtime
- 对person数组进行排序，然后进行输出

debug：

- 这里单位是**秒**，而playtime单位是**分**
- 能够找到的空闲桌子的endtime晚于21:00:00，剩余的人就不能玩了

 **TODO：**

- 找到逻辑的漏洞，进行完善及代码优化

##### 27、[Colors in Mars](https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768)    __10min

简单题，需要注意补零

##### 28、[ List Sorting](https://pintia.cn/problem-sets/994805342720868352/problems/994805468327690240)    __10min

简单题，排序

##### 29、[ Median](https://pintia.cn/problem-sets/994805342720868352/problems/994805466364755968)    __10min

简单题，暴力排序取中间数

#### 2021年7月25日

##### 30、[Travel Plan](https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392)    __30min

简单题，dijkstra

- dijkstra函数中需要vector有path、dis、cost、visited
- edge的operator < 重载需要考虑到dis相等时的cost的影响

##### 31、[Hello World for U](https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416)    __20min

简单题，数学计算（找到等价条件）+string特定格式输出

##### 32、[ Sharing](https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920)    __20min

简单题，链表

- 两个指针分别从两个首地址开始，如果下一个到达地址为-1，则换到另一个首地址进行遍历，直到两个指针相等（相遇），或者遍历次数超过2n，即不可能相遇

- 如果相遇，则需要格式化输出地址值 `printf("%05d", a);` 

  如果不相遇，或者相遇到-1（这种情况包含在不相遇里面），则输出-1

##### 33、[ To Fill or Not to Fill](https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080)    __100min  ~~+  **WA=20分 **     TODO~~

思路：

- 首先确定当前位置能达到的最远距离
- 如果现在已经是最后一个加油站，且最远距离无法达到终点，break
- 或者下一个加油站的位置在当前加油站的最远距离maxd之外，break
- 查看maxd范围内的所有加油站，找是否存在比当前加油站价格更低的加油站
  - 没有价格更低加油站
    - 如果当前站点能达到终点，加到终点的量
    - 不能直接到达终点，则加满
  - 有价格更低的
    - 当前汽油支持到达那个站点，更新rgas
    - 汽油不够，加汽油保证刚好能到达那个站点
- 输出结果

debug：

- 这里的加油站应该是0~n-1，n是终点

- 很容易越界，比如下面这段代码，就需要第一句，不然会越界

  ```cpp
  if (st == n - 1 && maxd < dis) break;
  if(st < n-1)
      if (vec[st + 1]->dis > maxd) break;
  ```

- printf里面输出数值型数据的时候需要严格按照样式，int作为%f输出会裂开

 ~~**TODO：**~~

- ~~找到逻辑的漏洞，进行完善及代码优化~~
- **测试点1：**计算maxd的时候，需要用cap*run来计算，我直接用了600
- **测试点4：**千万记得**break**！！！这个测试点就是在没到末尾的站点可以直接到达终点的情况，在可以输出”to destination“的那个判断里面，需要加一个全局的判断，并进行break，不然就会一直加下去

#### 2021年7月26日

##### 34、[ Head of a Gang](https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624)    _45min

简单题

- 并查集
- string和int利用map相互转换
- 排序之后再进行输出

##### 35、[ Password](https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520)    __12min

简单题，更改string中的char，计算有效的更新次数并将其保存并输出

debug：

- 记得输入n！！！！！

##### 36、[ Boys vs Girls](https://pintia.cn/problem-sets/994805342720868352/problems/994805453203030016)    __6min

简单题，分female和male比大小

##### 37、[ Magic Coupon](https://pintia.cn/problem-sets/994805342720868352/problems/994805451374313472)    __10min

简单题，数组，排序，计算，输出，long long

##### 38、[ Recover the Smallest Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704)      __30min

**更正：**cmp直接返回a+b < b+a就行了，根本不需要什么递归

- ~~string的排序，按照下面的方法进行排序：~~
  - ~~bool cmp(string &a, string &b)~~
  - ~~a==b 返回 true~~
  - ~~以a、b较小长度遍历a、b，有不同的值则降序返回~~
  - ~~如果a长度大于b，返回递归比较结果，cmp(a.substr(b.length()), b)~~
  - ~~如果b长度大于a，类似上面~~
- 加判断条件输出
  - flag=true
  - 遍历输出，如果flag==true，删掉string的开头的0，如果输出的不为空，则flag置false
  - 如果遍历结束，flag仍然为true，输出0

~~**TODO：**~~

​		~~cmp函数，在输入为3 123 123 12313，或者3 0 00 0，的时候，会出现错误？？？~~

#### 2021年7月27日

##### 39、[ Course List for Student](https://pintia.cn/problem-sets/994805342720868352/problems/994805447855292416)    __10min

简单题，统计并输出，map+string+sort

##### 40、[ Longest Symmetric String](https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344)    __25min + WA  ==>  **答案**

string中最长对称子字符串的长度

采用暴力解法，直接从0到len-1遍历，按照奇数长度和偶数长度，求解

**TODO**：

- 学习动态规划版本方法

- 找到下面注释代码的错误之处

  - while需要break，不然就会越过不相等的，继续和相等的比较了
  
  ```cpp
  //         int l = i-1, r = i+1, tmp = 1;
  //         while(l>=0 && r<len) {
  //             if(s[l--]==s[r++]) tmp += 2;
  //             else break;
  //         }
  //         res = max(res, tmp);
  //         if(s[i]==s[i-1]) {
  //             l=i-2, r=i+1, tmp = 2;
  //             while(l>=0 && r<len) {
  //                 if(s[l--]==s[r++]) tmp += 2;
  //                 else break;
  //             }
  //             res = max(res, tmp);
  //         }
          int j;
          for(j=1; i>=j && i+j<len && s[i-j]==s[i+j]; ++j);
        	res = max(res, 2*j-1);
          for(j=0; i>=j && i+j+1<len && s[i-j]==s[i+j+1]; ++j);
          res = max(res, 2*j);
  ```
  

##### 41、[Be Unique](https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184)    __10min

简单题，找到第一个unique的数

map+vec，两边遍历

#### 2021年7月28日

##### 42、[ Shuffling Machine](https://pintia.cn/problem-sets/994805342720868352/problems/994805442671132672)    __16min

简单题，模拟，vector+map+循环

##### 43、[Is It a Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856)    __43min

**TODO：代码很乱，没有优化，看一下别人的代码怎么写的学习一下**

判断是不是bst或者对称的bst，递归实现判断并构建bst

- 首先在主程序判断pre[0]、pre[1]的大小，确定是不是mirror，传入到函数参数
- 然后找到第一个最小和最大的值（b、c）
- 如果在右子树里面又不符合条件的，比如不是对称bst，但是右子树，及c之后出现了小于root值的点，就将全局的flag置为false

**debug：**

​	针对 `1 2 3 4 5 6 7` 这种情况，需要在c确定完毕之后仍然等于-1的情况下，将c设置为r+1，即没有右子树

##### 44、[ Shopping in Mars](https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264)    __70min

**反思：**耗费这么长时间是因为刚开始想要实现n*n的图存储数据，导致时间的浪费

数组连续子串之和同给定数m之差最小的所有组合（子串和要大于m）

- 动态确定l、r，直到 r >= n-1
- 首先移动r
  - 如果子串和cur小于m，++r，并更新cur
  - cur >= m，判断是否满足，满足条件的话，更新res向量，跳出
- 移动l
  - cur >= m，判断是否满足及进行更新操作
  - cur<m，跳出

##### 45、[ Favorite Color Stripe](https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456)    __22min

动态规划，求解符合输入顺序（用map存储   <数据  :  输入顺序>）的最长子列表（不需要连续）

- 创建一个长度为m+1的向量vec，按照输入第二行的数据顺序，分别为1-m，其保存的是对应颜色到目前为止的可以达到的最大长度
- 按照输入进行迭代
  - 从map得到当前输入k在顺序中的位次mp[k]
  - 遍历得到vec的  [ 1, mp[k]  ]  各个位置中的数据的最大值t
  - 更新vec[mp[k]] = t+1
  - 如果t+1 > res，保存到res中
- 输出res

#### 2021年7月29日

##### 46、[Shortest Distance](https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424)      __40min

**反思：**花这么长时间是因为刚开始思路错了，一直想着dp，这种带环求连续串的值的情况可以用一个累加的长度为n+2的vec相互之间的差来实现

##### 47、[Student List for Course](https://pintia.cn/problem-sets/994805342720868352/problems/994805433955368960)    __ 38min  ->  **WA=21分**（运行超时）

~~**TODO：**用什么数据结构和算法？？？~~

**WA原因：**在输入的时候，使用set或者map去存放人名，一直在find人名有没有存过，耗费了大量的时间，完全可以直接用vector来实现。

- 数据输入是按照人名顺序的，所以人名只需要放在一个vector里面就好了，将人名的序号（本身就是for循环，i=0开始输入，序号就是i）保存即可，不需要map去转换
- 最后比较的时候，也只要按照保存的序号，去访问vector进行比较



##### 48、[ Find Coins](https://pintia.cn/problem-sets/994805342720868352/problems/994805432256675840)    __6min

简单题，排序数组，找到两个数a、b相加刚好等于给定数的情况，求的a最小的情况即可

##### 49、[ Counting Ones](https://pintia.cn/problem-sets/994805342720868352/problems/994805430595731456)    __40min    ->    ~~**WA=26分**（最后一个样例错误）~~

~~解题思路，分析各种情况得到~~

- ~~输入数字n，转化为字符串s（后面分析的时候就是a + i + b），从0开始遍历~~
- ~~s[i]=='0'，说明他后面的数字没用，只受前面的数字a影响，就是这一位能出现1的次数为a*10^(len-1-i)~~
- ~~s[i]=='1'，说明后面的数字b有用，1b能出现b次，且当前位受前面的数字a影响能出现a次，加上现在本身出现的这一次，即出现a*10^(len-1-i)+b+1~~
- ~~s[i]==其他，说明1b能出现所有情况，即可以出现(a+1)*10^(len-1-i)~~

~~**TODO:**~~

​	~~最后那个样例为什么通不过？？？~~      

​	可以直接按照答案的思路（从个位到最高位）来，自己的这个思路太过复杂了

#### 2021年7月30日

##### 50、[ String Subtraction](https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152)    __8min

简单题

##### 51、[Pop Sequence](https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944)    __35min     ~~**WA=23分**，最后一个样例错误~~

**思路错误**！！！这题是栈模拟，而不是找规律！！！

~~stack题~~

- ~~vec[j]-j <= n~~
- ~~当前数vec[p]，出现在p后面的所有数，只要小于vec[p]，就一定要降序~~

~~debug：~~

- ~~**千万不要在输入的时候加跳出语句**，要让输入全部输进去才行！！！~~
- ~~**TODO，**~~

##### 52、[ Linked List Sorting](https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464)       __47min     ~~**WA=21分**，差1、4两个样例没过（30min）~~

- 直接对key进行排序，然后按照排序结果进行输出，当前节点要输出的next address就是排序之后下一个节点的address
- 输出address的时候都要补0，除了-1
- **样例1：**输入的list中，中间可能出现-1，需要将list输入之后，进行遍历，然后保存能够达到的节点到vector，最后再去排序
- **样例4：**输入的首地址可能是-1，这样的话直接输出`0 -1`

##### 53、[ Path of Equal Weight](https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512)    __28min    **WA=28分**，差样例2没过

树的回溯算法

- **样例2：**cmp代码错误，要写成`if(a[i] != b[i]) return a[i] > b[i];`

#### 2021年7月31日

##### 54、[The Dominant Color](https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768)     __5min

简单题，map统计

##### 55、[ The World's Richest](https://pintia.cn/problem-sets/994805342720868352/problems/994805421066272768)    __45min    **WA=23分（25min，测试点2没过）** ==>   **答案**  

<font color="red">**总结：**</font>

- 对于这种struct多属性的题目，如果要按照年龄取出数据，并对年龄范围内的数据排序，再进行输出的情况下

  - **应该**直接按照要求对所有数据进行排序，然后遍历输出
  - **而不是**仅仅按照年龄排序，取出数据之后，再排序，再输出

- vector的效率会比数组低不少，这种题目还是尽量使用数组

  ```cpp
  struct myStruct{
      ...
      // 要么不设置构造函数，要么就设置一个无参构造函数
  }a[100005];
  ```

- 输入输出要使用`scanf`、`printf`，string的输入方法为

  ```cpp
  string str;
  str.resize(10);
  scanf("%s", &str[0]);
  ```

##### 56、[Mice and Rice](https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944)    __110min    ~~**无法理解**~~

**理解错误！**第三行是编号，执行顺序按照这个编号来

这里考虑的是堆queue的应用

- 使用计数的方法来保证单个queue的正常使用，只要计数值大于之前push进queue的数量，就进行下一轮循环
- 最后不要忘了queue中剩下的那一个节点

##### 57、[ Stack](https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592)    __70min  +   **答案**

栈操作 + 快速求中位数

- vector + stack + 二分查找即可实现

- 维护一个stack，保存所有push、pop的数据情况

- 维护一个vector，对push、pop及时相应更新，并可以直接返回中位数

  这里需要注意的是，insert、erase操作、**二分查找**的理解

  - vec.insert(iterator pointer, num);

  - vec.erase(iterator pointer);

  - 二分查找，其中**sign**保存的才是所求的位置，即**相对大于等于num的位置**

    ```cpp
    void bin_greater_equal_find(int num) {
        int l = 0, r = vec.size() - 1, mid, sign;
        while (l <= r) {
            mid = (l + r) / 2;
            if (vec[mid] >= num) {
                sign = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return sign;
    }
    ```

#### 2021年8月1日

##### 58、[ A+B in Hogwarts](https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232)    __10min

简单题，自定义进制的数的相加

##### 59、[ Prime Factors](https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488)    __24min

long long 数的取质数，将所有质数都保存在map中，键:值 := 数:次数

debug：

​	质数获取的时候，是要在**[**2, sqrt(n)**]**的范围内求取的，**两边都要取到**才行

##### 60、[ Are They Equal](https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872)    60min

判断float形式的string是否相等，需要分类讨论

- 首先需要找到两个数第一个小数点出现的位置p，然后删掉小数点
- 然后找到第一个非0数出现的位置n，如果这个位置等于当前字符串的长度，则n=0
- 如果两个字符串的p-k不相等，则flag=false
- 取以非0开头的字符串，从头开始比较n位，如果某位不相等，flag=false
- 格式化输出



重做14



#### 2021年8月2日

##### 61、[Dating](https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608)     __37min  ~~**WA=18分**，差测试点5答案错误~~

按照给定的条件，分类讨论以及计算

debug：（**答案**）

​	测试点5：对星期的确认有误，这里需要是['A', 'G']范围内的，不能是['a', 'g']间

##### 62、[ Talent and Virtue](https://pintia.cn/problem-sets/994805342720868352/problems/994805410555346944)    18min

简答题，struct+排序+格式化输出

##### 63、[ Set Similarity](https://pintia.cn/problem-sets/994805342720868352/problems/994805409175420928)    30min **WA=21分**，差测试点5运行超时

计算<font color="red">set的union、intersection</font>，并以size相除

debug：（**答案**）

​	测试点5：set_union、set_intersection这两个函数复杂度有点过高了，对于求两个set中不同的数nt和相交的数nc而言，只需要将nt初始化为第二个set的sizeB，然后遍历第一个setA，如果能从setB中找到，则nc++，否则nt++

##### 64、[Complete Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568)    50min

完全二叉搜索树（CBT）的层序遍历

- 首先题目只给出了一个序列，所以要先将其排序
- 按照CBT的概念来进行递归构造树，k是2^n，n为层数，从0开始
  - 如果k==1
    - 如果l==r，就返回以vec[l]为值，两子节点都为nullptr的叶节点
    - 否则直接返回nullptr
  - 首先确定当前树的总节点数len=r-l+1
  - 也可以确定的是，当前数的已经完全的层的节点总数为k-1，包含了根节点的1
  - 用len-k+1就是当前树的最后一层的节点数rst
  - 将其按照k/2为分界线，将rst进行划分到两个子树，再加上完全层的节点数量(k-1)/2，这里已经没算根节点了，因为l是偶数，k-1是奇数，就得到了两个子树的节点数量
  - 递归构造子树
- 利用queue来进行层序遍历，类似于BFS，将val保存在数组中，最后进行输出



**重做**1056，这里是理解错误了。



#### 2021年8月3日

##### 65、[A+B and C (64bit)](https://pintia.cn/problem-sets/994805342720868352/problems/994805406352654336)    45min

这里主要是大整数的相加，题目很刁钻的给出了[−2^63,2^63]的long long正好会溢出的情况，所以需要对特殊情况进行特判

- 这里我使用的是自定义struct的方法，对正数的情况，如果等于2^63，则将值置为2^63-1，并将溢出位置1，对于复数，不设置溢出位
- 判断时，需要判断负最值相加、正最值相加多种的情况

答案思路：

- sum = a+b

- a>0 && b>0 && sum<0   T
- a<0 && b<0 && sum>0   F
- sum > 0   T
- sum < 0   F



##### 66、[ Root of AVL Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805404939173888)     __20min   <font color="red">忘记方法，放弃，**直接背答案吧!!!**</font>

```cpp
#include<iostream>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int _v=0, node* _l=nullptr, node* _r=nullptr) : val(_v), left(_l), right(_r) {}
};
int getH(node* root) {
    if(root == nullptr) return 0;
    else return max(getH(root->left), getH(root->right))+1;
}
node* R(node* root) {  // 右旋
    node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node* L(node* root) {
    node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node* RL(node* root) {
    root->right = R(root->right);
    return L(root);
}
node* LR(node* root) {
    root->left = L(root->left);
    return R(root);
}
node* insert(node* root, int val) {
    if(root==nullptr) {
        root = new node(val);
    }
    else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getH(root->left) - getH(root->right) == 2)
            root = val < root->left->val ? R(root) : LR(root);
    }
    else {
        root->right = insert(root->right, val);
        if(getH(root->right) - getH(root->left) == 2)
            root = val > root->right->val ? L(root) : RL(root);
    }
    return root;
}
int main() {
    int n, t;
    cin >> n;
    node* root = nullptr;
    for(int i=0; i<n; ++i) {
        cin >> t;
        root = insert(root, t);
    }
    cout << root->val << endl;
}
```



##### 67、[ Sort with Swap(0, i)](https://pintia.cn/problem-sets/994805342720868352/problems/994805403651522560)    50min  **WA=0分 + 答案**   ~~TODO~~    2021-8-27  REDO

思维题

2021-8-27   这里向量中，每一个索引代表给定数据的值，该索引对应的值代表那个值的索引位置，即这里正好反了一下

2021-9-10  这里其实是一个思路的转换，与其说是swap(0, \*)，不如说是swap(\*, 0)，这里的 * 其实就是vec[0]

- 所以就是遍历到位置  i  之后，交换vec[vec[i]] 和 vec[0] ，直到vec[0] == 0
- 然后还需要判断一下，如果此时vec[i] != i，那么就是说vec[i]的位置的数是等于后面的位置的，那么再进行一个swap(vec[0], vec[i])

##### 68、[ Find More Coins](https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976)    20min  ~~**WA=29分 测试点6运行超时**~~

~~回溯法+剪枝~~

~~debug：（**答案**）~~

​	~~思路错误，这个应该是很明显的01背包问题，   TODO~~

**01背包解法：**

```cpp
// ----------------------------------01背包--------------------------------
// n是物品数，w[i]是物品i的重量，dp[v]为重量为v的时候的最大价值，c[i]是物品i的价值
for(int i=1; i<=n; ++i) {
    for(int v=V; v>=w[i]; --v) {
        dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
    }
}
// ----------------------------------完全背包-------------------------------
for(int i=1; i<=n; ++i) {
    for(int v=w[i]; v<=V; ++v) {
        dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
    }
}
```

首先需要明确的是，本题是假设**价值为m**的物体需要**占m的空间**

- 本题需要的按照题目给定排序方法可得到的最小的序列，所以需要将输入数据按照**降序排序**

- 纵轴为weight个数[1, n]，横轴为背包容量[1, m]

  - 这里需要注意的是weight为了简便，是从1开始存储的，所以排序的时候需要从vec.begin()+1开始，而不是直接使用vec.begin()

- 这里还需要**二维bool数组choice\[1, n][1, m]**来代表第i个物品在背包容量为j的时候是否存入

  - 这里并不会出现choice重复遍历某一个点的情况，因为二重循环本身不会重复

- 因为使用滚动数组进行dp存储（长度为m），所以**第二层**按照m的迭代需要**从后往前**

- 最后将结果输出的时候，是按照如下思路进行输出的

  - 首先确定是否满足dp[m]==m，因为这题是m的空间能达到最大的价值，即能不能到m，能到的话就有解了
  - 其次，第m列的值为true的个数，就是所有的情况个数，只需要从这几个点开始往前搜索进行dfs就可以得到所有的解了
    - 第x行，就是代表的是排序后的第x个数据，如果是要最优解的话，就是从choice\[n][m]开始回去，具体看代码比较清楚

  ```cpp
  bool cmp(int a, int b) { return a > b; }
  int main() {
      int n, m;
      scanf("%d %d", &n, &m);
      vector<vector<bool>> choice(n + 1, vector<bool>(m + 1, false));
      vector<int> dp(m + 1, 0);
      vector<int> w(n + 1);
      for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
      sort(w.begin()+1, w.end(), cmp);
      for (int i = 1; i <= n; ++i) {
          for (int j = m; j >= w[i]; --j) {
              if (dp[j] <= dp[j - w[i]] + w[i]) {
                  dp[j] = dp[j - w[i]] + w[i];
                  choice[i][j] = true;
              }
          }
      }
      vector<int> res;
      if (dp[m] != m) printf("No Solution\n");
      else {
          int v = m, idx = n;
          while (v > 0) {
              if (choice[idx][v]) {
                  v -= w[idx];
                  res.push_back(w[idx]);
              }
              --idx;
          }
          for (int i = 0; i < res.size(); ++i) {
              printf("%d%c", res[i], " \n"[i == res.size() - 1]);
          }
      }
  }
  ```

  

#### 2021年8月4日

##### 69、[The Black Hole of Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088)    17min

简单题，string计算

- 因为复杂度不是那么高，所以只需要使用`stoi(s.c_str())`将string转int进行计算即可，然后保存上一次的结果res，和当前的结果tmp，比较决定是否输出，如果需要继续，则利用to_string()转到s循环

##### 70、[Mooncake](https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376)    15min

简单题，按照月饼单价降序贪心算法

debug：

- 这里隐藏着所需的数量d以及每一种品种的月饼的数量是有可能为double的

##### 71、[Speech Patterns](https://pintia.cn/problem-sets/994805342720868352/problems/994805398257647616)    20min

简单题，string分割处理，map计算

debug：

- 最后如果保存有字符数字串的tmp不为空的话，需要进行mp[tmp]++的操作

##### 72、[ Gas Station](https://pintia.cn/problem-sets/994805342720868352/problems/994805396953219072)    90min    ~~**WA=26分  测试点4错误**~~

dijkstra + 基于向量存储实现加速

debug：

- **测试点1、3：**题目需要的是最近城市的路程最远的情况，或者是平均距离最近的情况，或者是加油站编号最小的情况
- **测试点1、2：**在判断两个站点间平均距离的时候，需要注意差值比较应该是0.05，而不是随意设置的1e-5,1e-2等数据
- **测试点4（看错误测试点发现）：**最后不用加0.05！！！（给出的测试是需要加0.05的，大坑）

#### 2021年8月5日

##### 73、[ Scientific Notation](https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784)    20min

科学计数法，遍历一遍字符串，将相应的数据进行保存，最后输出即可，**不需要进位**

debug：

- **测试点4**：这里是需要在exp大于0，且不足以让coe化为整数的情况下，需要输出小数点后面的数

##### 74、[ Reversing Linked List](https://pintia.cn/problem-sets/994805342720868352/problems/994805394512134144)    43min  ~~**WA=19分（1、5）**~~

已经考虑提前有-1，末尾不是-1的情况，还是错误。

<font color="red">**错误原因：审题错误！！！这里是每k个元素，而不是前k个元素！！！**</font>

- 首先需要明确的一点是，这种题型完全可以将数据存储在一个数组中，然后将其按顺序存放在vector中，最后利用vector的顺序访问数组进行输出

- 对于中间数据会提前指向-1的情况，遍历list，将数据存放到vector中的时候，就已经判断完毕了，后期只需要直接使用vector的size即可

- 代码非常巧妙：

  ```cpp
  for(; i<=idx.size(); i+=k) {
      for(int j=1; j<=k; ++j) {
          res.push_back(idx[i-j]);
      }
  }
  ```

  

##### 75、[ PAT Judge](https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032)    37min

简单题，模拟

- 提交上去是-1的话，如果可以输出，是输出0的
- 提交上去是-1，且没有大于等于0的提交的话，不能够输出这个人
- 将每个人psco初始化为-2，有可能输入-1的情况下，需要注意tsco的更新

##### 76、 [Forwards on Weibo](https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736)    54min

优先队列实现图的遍历，其中node记录的是id和level

debug：

- operator重载错误！这里只需要重载<
  - 如果需要小顶堆，那么就需要设置为`return lv > n.lv;`
- 图存储错误，理解了，但是写代码的时候又忘了，这里是第i行输入j，就使得`g[j].push_back(i);`
- cnt计算错误，cnt应该和vis的更新是在一起的

#### 2021年8月6日

##### 77、[ Kuchiguse](https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096)    10min

简单题，找所有字符串的共有后缀子串

##### 78、[ Hashing](https://pintia.cn/problem-sets/994805342720868352/problems/994805389634158592)    37min + **Google查询知识点**

题目理解错误：

- 这里需要使用Quadratic probing来消除冲突
- **Quadratic probing**就是使用(hash(x)+j*j)%S，其中j∈[0, **S/2]**来进行分配

debug：

- 测试点1：msize < 2
- 测试点3：需要使用Quadratic probing方法消除冲突

##### 79、[Total Sales of Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560)    33min

利用一个链接矩阵存储图，然后按照dfs的方法，遍历图，达到叶节点（零售商）就计算总价值，递归过程中，传递id和当前层price

debug：

- 图搞错了，在存图的时候，应该是按照最外层循环i来进行存储，即第i层对应的各个子节点是i的，我写错成j

##### 80、[ Graduate Admission](https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136)    53min

简单模拟题

- 平均分完全可以按照总分进行存储，这样的话，就可以避免使用double

- 分数相同的学生按照同等优先级进行操作，学校最大招生人数可以超出

  ```cpp
  for (int i = 0; i < n; ) {
      int j = i;
      for (; j < n; ++j) {
          //...
      }
      // ...
      i = j;
  }
  ```

#### 2021年8月7日

##### 81、[Rational Sum](https://pintia.cn/problem-sets/994805342720868352/problems/994805386161274880)    40min   **（Google）**

求最小公倍数

首先找到所有数的质因数，然后把所有不同的质因数相乘，如果a、b有共同质因数c，那么c取a、b中相对更多的那一个数量

##### 82、[Read Number in Chinese](https://pintia.cn/problem-sets/994805342720868352/problems/994805385053978624)    43min

将数按照中文的读法写出来

- 这里首先按照数字和位数全部放到向量vec中
- 然后按照零的读法，将不应该出现的零去除（将vec相应位置为”null“）
- 将vec中不是”null“的数据位放到向量res中输出

##### 83、[ List Grades](https://pintia.cn/problem-sets/994805342720868352/problems/994805383929905152)    10min

简单题，struct+排序+给定范围内的数据进行输出



重做68，搞懂了01背包



#### 2021年8月8日

##### 84、[ Broken Keyboard](https://pintia.cn/problem-sets/994805342720868352/problems/994805382902300672)    7min

简单题，求两个字符串中，不同的的字符

##### 85、[ Perfect Sequence](https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064)    23min    ~~**WA=23分**~~

debug：

- 测试点3：最少是一个元素的，即max==min

- 测试点5：？？？

**答案：**

​	<font color="red">直接暴力+剪枝求解...</font>

- 首先需要排序
- 这里**剪枝**很巧妙，第二个循环的时候，正常应该是j=i开始进行，但是这里使用的是**j=i+res**，其中res是已经保存的最大程度
- int和long long可以直接乘和比较

##### 86、[Tree Traversals Again](https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024)    27min

按照push、pop操作，抽象为树的构建，按照抽象出来的方法构建树，最后后序遍历树得到答案

##### 87、[All Roads Lead to Rome](https://pintia.cn/problem-sets/994805342720868352/problems/994805379664297984)    105min

dijkstra + vector<vector<vector\<int>>> paths保存每一个点的路径

**反思：**这里花了很多的时间去debug，因为后三个测试点错了，后来才发现是**审题不够清楚！！**这里第一行的第二个答案需要输出的是**总花费dis[t]**，我当成了最短路径的节点个数，很不应该

debug：

- 这里需要求所有最短路径的条数，所以需要将满足`dis[nxt.to] == dis[top.to] + nxt.val`的所有路径存放到paths[nxt.to]里面，而当`dis[nxt.to] > dis[top.to] + nxt.val`的时候，需要将paths[nxt.to]进行clear再放
- 然后再针对paths[t]去找happiness最大的各个路径，这里路径还不唯一
- 因为路径答案必然唯一，所以只需要找到上一步求得的size最小的路径，就是avg happiness最大的路径，即所求的答案路径



#### 2021年8月9日

##### 88、[Rational Arithmetic](https://pintia.cn/problem-sets/994805342720868352/problems/994805378443755520)    52min  **放弃直接看答案**

**思路完全错误！**这里应该是直接将数据求出来，然后最简化输出的，而不是将+-*/分开来考虑

按照答案思路，25分钟即可完成

- 求最大公约数方法

```cpp
ll gcd(ll t1, ll t2) {
    return (t2==0 ? t1 : gcd(t2, t1%t2));
}
```

- 两个long long的数进行相乘的时候，如果需要判断他们结果的正负，则不能直接相乘之后进行判断，而是需要按照`(n<0 && m>0) || (n>0 && m<0)`为负的方法来进行讨论，不然溢出很麻烦

##### 89、[Insert or Merge](https://pintia.cn/problem-sets/994805342720868352/problems/994805377432928256)    ~~37min   WA=24分~~

~~测试点2：AcWing测出来是AC，应该是一个很刁钻的数据~~

改变成一种更加可行的方式：

- insertion sort

  - 两个while，第一个查升序，第二个接着第一个查两个数组是否相等
  - 直接在a的基础上进行sort，这里要注意的是**sort是前闭后开**，所以是sort(a, **a+k+2**)

- merge sort：

  - 直接使用a去按照正常merge sort排序，如果和b不相等就break输出

  - 这里merge sort算法需要巩固一下

    ```cpp
    int k = 1, flag = 1;
    while(flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (a[i] != b[i])
                flag = 1;
        }
        k = k * 2;
        for (i = 0; i < n / k; i++)
            sort(a + i * k, a + (i + 1) * k);
        sort(a + i * k, a + n);  // 这里的i * k 也可以是 n / k * k
    }
    ```

    

##### 90、[Highest Price in Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944)    17min

简单题，递归

##### 91、[ Acute Stroke](https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072)    50min+**答案**

三维bfs计数，题目没看懂

```cpp
int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};
bool judge(int x, int y) {
    if(out of bounds) return false;
    if(val==0 || visited) return false;
    return true;
}
int bfs(int x, int y) {
    // int cnt = 0;
    queue<node> q;
    q.push(node(x, y));
    vis[x][y] = false;  // defferent from dijkstra
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            if(judge(tx, ty)) {
                vis[tx][ty] = true;  // defferent from dijkstra
                q.push(node(tx, ty));
            }
        }
    }
    // if(cnt>=t) return cnt;
    // else return 0;
}
```

#### 2021年8月10日

##### 92、[ To Buy or Not to Buy](https://pintia.cn/problem-sets/994805342720868352/problems/994805374509498368)    8min

简单题，两个字符串的减法

##### 93、[Count PAT's](https://pintia.cn/problem-sets/994805342720868352/problems/994805373582557184)    20min

简单题，动态规划

debug：

- 最后结果要mod 1000000007
- 自己做的例子自己做错了，导致凑了个错误的代码

##### 94、[ The Largest Generation](https://pintia.cn/problem-sets/994805342720868352/problems/994805372601090048)    19min

简单题，利用queue进行树的层序遍历

##### 95、[Cars on Campus](https://pintia.cn/problem-sets/994805342720868352/problems/994805371602845696)    50min

模拟题，给定一个停车场的进出记录计算①给定的时刻停车场内的车子数②停车时间最长的车子的车牌号

debug：

- **测试点0、1：**这两个测试点卡的是当有一个车子在T时刻进入，则T时刻的车子数应该加1

- **测试点2、4：**这里卡的是有可能有个时刻（无论进还是出），会相对上一个纪录时刻，跨越多个请求的时刻，即更新请求时刻的车子数的时候需要用while，直到当前请求时刻大于纪录时刻

#### 2021年8月11日

##### 96、[Consecutive Factors](https://pintia.cn/problem-sets/994805342720868352/problems/994805370650738688)    47min  ~~**WA=17分**（完全暴力解法）~~

- ~~测试点4（错误）：~~

- ~~测试点6（超时）：~~
  
    完全暴力解法是没问题的，但是我想复杂了。
    
    - 我的想法是
      - 将所有的因子全部就出来，就是说比如例子的3、5、6、7，都要出来
      - 然后按照里面的最长连续因子进行存储
    - 正确的想法
      - 根本就不需要将所有的因子都算出来，只需要将连续的因子算出来就好了
      - 所以就是两层循环，第一层 i 就是开始的数，第二层 j = i 就是开始计算i及后面连续的数
      - **一直累乘 j ，只要等到num%j不等于0**，就意味着连续数组结束了，剩下的无所谓是多少
        - 这里也是我<font color="red">**思维出错的地方**</font>，我当时一直在循环的时候会更新num_temp，其实完全没有必要
      - 如果求得的连续数组len更长就进行保存
    
##### 97、[ Deduplication on a Linked List](https://pintia.cn/problem-sets/994805342720868352/problems/994805369774129152)    25min

将原先的list中abs(key)值相等的节点放到另一个list中

- struct中，含有old pointer和new pointer两个指针
- 设置两个node数组a、b
  - a存储原list数据，b存储重复节点数据
- 遍历a，重新设置new pointer，如果abs(key)已经出现过，则存入b，这里全都设置new pointer
- 遍历a、b，进行输出

##### 98、[ Insertion or Heap Sort](https://pintia.cn/problem-sets/994805342720868352/problems/994805368847187968)    83min+答案    <font color="red">**不会堆排序！！！**</font>

判断是否为插入排序，进行判断其排序过程

- 插入排序，前面位置都是排完序的，后面没有排序的位置满足`a[x]==b[x]`

  ```cpp
  int p=1, t;
  while(p<n && b[p-1] <= b[p]) ++p;
  t = p;
  while(p<n && a[p] == b[p]) ++p;
  if(p==n) // >> insertion sort
  ```

- 堆排序算法过程
  - 首先需要明确的是，堆排序之后，数组的后面是排序完成的，所以需要先找到第一个没有排好序的位置t，即从后往前遍历，第一个满足`b[t] < b[0]`的位置

  - 然后进行`swap(b[0], b[t])`

  - 然后将b[0]位置上面的元素进行一次向下调整

    ```cpp
    void downadjust(vector<int> &tarv, int low, int high) {
        int i=low, j=i*2;
        while(j<=high) {
            if(j+1 <= high && tarv[j] < tarv[j+1]) j += 1;
            if(tarv[i] > tarv[j]) break;
            swap(tarv[i], tarv[j]);
            i=j;
            j=i*2;
        }
    }
    
    >> downadjust(b, 1, t);
    ```

- 堆的创建过程

  ```cpp
  void createHeap() {
      for(int i=n/2; i>=1; --i) {
          downAdjust(a, i, n);
      }
  }
  ```

##### 99、[Build A Binary Search Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648)    35min

BST的构造及层序输出

- 树的构造是通过按照给定的左右节点关系进行树结构的构造
- 然后将给定的数值进行排序
- 按照前序遍历，将值赋值给各个节点
- 然后通过queue进行层序遍历

debug：

- vector<node*> nodes(n, new node());  ❌

  这样的结果就是所有的节点都是等于这一个new出来的node的地址值

- vector<node*> nds(n);
  for (int i = 0; i < n; ++i) 
       ds[i] = new node(-1, nullptr, nullptr);  **<font color="green">✔</font>**

#### 2021年8月12日

##### 100、[ Mars Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805367156883456)    20min

13进制的字符和数字的相互转换

debug：

- 如果输入数字，且其能被13整除，则只输出前一位，末尾的0，即"tret"不需要输出
- 如果输入字符，则需要判断在只输入一个字符串的时候，是第二位还是第一位的

##### 101、[ Quick Sort](https://pintia.cn/problem-sets/994805342720868352/problems/994805366343188480)    22min

简单题，找出数组中，左右两边子数组的数值都分别小于、大于自身的数

- 只需要设置两个数组
  - 一个从左到右遍历，存储到当前位置的最大值
  - 一个从右到左遍历，存储到当前位置的最小值
- 从左到右遍历vec，如果符合条件则保存到res中

debug：

- 测试点2：如果res.size() ==0，那么需要额外输出一个endl

##### 102、[Invert a Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805365537882112)    45min

左右翻转树，并按照层序和中序输出

debug：

- 测试点1
  - 这里不一定所有的点都会出现，有可能只会出现2、5、7这几个点的组合
  - 所以需要设置一个fa向量，初始化为全-1
  - 保存所有节点的father的索引
  - 然后在输入完成，并完成树的构建之后，搜索到第一个不为-1的位置
  - 然后一直找father索引，直到找到根节点为止
  - 然后再进行层序、中序的遍历输出

##### 103、[Integer Factorization](https://pintia.cn/problem-sets/994805342720868352/problems/994805364711604224)    **80min失败   思路错误**（~~01背包~~      DFS+剪枝）

​	~~**TODO**~~    



#### 2021年8月13日

##### 104、[ Sum of Number Segments](https://pintia.cn/problem-sets/994805342720868352/problems/994805363914686464)    20min    ~~WA=17分~~

找到规律之后，直接按照规律加起来，而不是遍历去累加

~~测试点2：错误，不是输出问题~~

debug：

​	不要直接使用double进行累加，而是先要乘 10^精度，用long long进行累加存储，最后除 10^精度 进行输出

##### 105、[ Spiral Matrix](https://pintia.cn/problem-sets/994805342720868352/problems/994805363117768704)    60+答案

matrix螺旋形赋值，考察一个编程功底

- 应该直接用一个for循环套四个串行的内部for循环去实现
- 在每一个内部for循环中需要判断cnt<N

##### 106、[Lowest Price in Supply Chain](https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464)    18min

给一个供销链，找到最低零售价和对应的店铺**数量**

debug：

- 输出了minh，应该输出的是cnt

##### 107、[Social Clusters](https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744)    ~~40min  WA=17分~~    答案+20min = AC

这里我考虑的过于复杂，对并查集的掌握还是不够充分，对数据应该处理的方法如下：

- 对于hobbys，可以直接使用一个数组来存储每一个hobby第一次出现的时候对应的personID
- 对于person不必刻意去存储，只需要使用father数组确定每一个人的类别就可以了
- 所以每次输入某人的hobby的时候，如果对应的personID为0，即第一次出现，则进行赋值，否则进行unite操作

**总结：**

- 并查集的题目，需要找到重点，需要并的是什么，这一题就是需要并人
- 然后需要关注的是和和这个重点相关联的数据，这里是爱好，爱好的话并不是直接连接两个人的，所以不能像打电话那个一样直接unite(a, b)，而是需要用一个数组来进行存储  爱好<->人 的关系
- <font color="red">2021-8-29</font>
  - 这里也可以想象成类似于图的并查集，不过图的每个节点代表一个索引号，边连接的是两个索引号，所以fa存储索引指向的父节点
  - 这里是每一个节点下面有很多子节点，父节点间边是两个父节点有相同的子节点时，将父节点索引的连接，所以在向量fa存储当前父节点索引指向的父节点基础上，还需要向量h存储第t个爱好当前指向的人的索引号，如果当前ht==0，那么就将索引指向当前的人，如果ht!=0，那么就说明有相同爱好的另外的人，使用unite连接父节点

#### 2021年8月15日

##### 108、[Finding Average](https://pintia.cn/problem-sets/994805342720868352/problems/994805360777347072)    25min

判断string是否是[-1000, 1000]的精度小于等于2的合法浮点数

debug：

- 题目中要求只有一个浮点数的时候，输出的是number而不是numbers

##### 109、[ Group Photo](https://pintia.cn/problem-sets/994805342720868352/problems/994805360043343872)    30min

按照题目指定的顺序，将数据组织起来，最后进行输出，其实就是对于一个数组，按照奇、偶的递增与位置的相对应，进行填写

debug：

- 粗心大意导致cmp函数写错了

##### 110、[ Complete Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805359372255232)     ~~69min  **WA=14分**~~

**反思：**

- 查找root的方法错误，应该设置一个father数组，然后找那个值为-1的索引，即为root
- 判断完全二叉树的方法错误
  - 如果是完全二叉树，那么dfs得到的最大idx必然等于n（idx从1开始）

##### 111、[ Online Map](https://pintia.cn/problem-sets/994805342720868352/problems/994805358663417856)    60min  参考了答案的解题思路

分别用dijkstra求两种最短路，最后比较这两个最短路，一样或者不一样，按照不同的格式进行输出

- 有多条可能解，但是可以保证只有一条最优的解
  - 可以在dijkstra里面设置额外的vector来进行数据的保存，然后进行比较

- 两种dijkstra的operator<重载，可以用一个bool的flag来决定用哪种情况

#### 2021年8月16日

##### 112、[ Stucked Keyboard](https://pintia.cn/problem-sets/994805342720868352/problems/994805357933608960)    ~~33min + WA=12分~~

debug：

- 题目没有理解到位，这里说的是，某一个键卡住之后，所有的这个字符都会重复k次。只要某个字符 c 有没有重复k次的情况，则其没坏，mp[c] = -1

**反思：**再次被样例误导，且想明白题目之后，就没有改回来，这里应该判断的是mp[c]>0，就算是满足条件了，而不是mp[c]>1

##### 113、[ Integer Set Partition](https://pintia.cn/problem-sets/994805342720868352/problems/994805357258326016)    8min

简单贪心

##### 114、[ Family Property](https://pintia.cn/problem-sets/994805342720868352/problems/994805356599820288)    95min

**反思：**

- **思路错误**，这里应该是**并查集**，但是一开始想的是dfs

- ~~pa数组错误，**原因TODO**~~         

  这里是写错了，应该是pa[fx] = fy    、     pa[fy] = fx

##### 115、[Counting Nodes in a BST](https://pintia.cn/problem-sets/994805342720868352/problems/994805355987451904)    17min

简单题，构造BST+层序遍历

#### 2021年8月17日

##### 116、[ Come on! Let's C](https://pintia.cn/problem-sets/994805342720868352/problems/994805355358306304)    13min

简单题，判断输出

##### 117、[ Eddington Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805354762715136)    34min   ~~**WA=16分**~~

~~测试点5：每个数要大于E，而不能等于~~

思路错误，可以不是递增排序，而是递减排序

##### 118、[ Birds in Forest](https://pintia.cn/problem-sets/994805342720868352/problems/994805354108403712)    20min

简单并查集

##### 119、[ Pre- and Post-order Traversals](https://pintia.cn/problem-sets/994805342720868352/problems/994805353470869504)    67min

二叉树的前序、后序遍历，求二叉树是否唯一，并求二叉树的中序遍历

debug：

- 判断是否唯一，需要判断递归过程中是否会有出现`prel > prer || postl > postr`，如果出现，将全局变量fg设置为false，即二叉树不唯一

- 每次递归的时候，可以发现pre[prel] == post[postr]，且其值就是当前子树的根节点，然后按照prel+1位置X作为左子树根节点，找到X再post中相对postl偏移量cur，可得到递归式

  ```cpp
  tmp->left = ppi(prel, prel + cur, postl, postl + cur);
  tmp->right = ppi(prel + cur + 1, prer, postl + cur + 1, postr);
  ```

#### 2021年8月18日

##### 120、[ Friend Numbers](https://pintia.cn/problem-sets/994805342720868352/problems/994805352925609984)    7min

简单题，字符的每个数之和，set去重，vector排序并格式化输出

##### 121、[Damn Single](https://pintia.cn/problem-sets/994805342720868352/problems/994805352359378944)    17min

简单题，给定多组couple，然后再给一组人，找到这组人里面落单的人

##### 122、[Hamiltonian Cycle](https://pintia.cn/problem-sets/994805342720868352/problems/994805351814119424)    30min

测试点1：最后那条边（倒数两个点）也是要判断是否存在的

测试点2：vis[起点] = true

##### 123、[Is It a Complete AVL Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805351302414336)    50min

AVL树+层序遍历+完全树的判断



#### 2021年8月19日

##### 124、[Raffle for Weibo Followers](https://pintia.cn/problem-sets/994805342720868352/problems/994805350803292160)    20min

简单题，想复杂了，查找输入顺序里面的从第s个开始的数据，每次加n，如果之前有过，就加1

##### 125、[Chain the Ropes](https://pintia.cn/problem-sets/994805342720868352/problems/994805350316752896)    13min

简单题，贪心

- 小顶堆优先队列

  `priority_queue<double, vector<double>, greater<double>> pq;`

- 大顶堆优先队列

  `priority_queue<double, vector<double>, less<double>> pq;`

##### 126、[ Eulerian Path](https://pintia.cn/problem-sets/994805342720868352/problems/994805349851185152)    37min    ~~**WA=20分**~~

统计每个节点的度，按照题目给出判断的情况并输出

debug：（看答案）

- 要考虑非连通的情况，这里并不是简单的计算是否有一个点的度为0就能解决的，而是需要用**dfs**来判断

##### 127、[ ZigZagging on a Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805349394006016)    50min

中序+后序  ==>  构造树  ==>  层序之字形输出

debug：

- 虽然例子上面不会出现  `inl > inr`  和  `postr<0 || postr>=n`  的情况，但是还是需要考虑进去，出现则返回nullptr

#### 2021年8月20日

##### 128、[ N Queens Puzzle](https://pintia.cn/problem-sets/994805342720868352/problems/994805348915855360)    11min

简单题，判断是否满足N皇后条件

##### 129、[Recommendation System](https://pintia.cn/problem-sets/994805342720868352/problems/994805348471259136)    ~~38min  WA=21分~~

~~测试点3：运行超时，vector的swap太过频繁，时间复杂度太高，需要使用更好的数据结构~~

应该直接使用重载小于号的struct的set来存放数据

```cpp
int book[50005] = {0};
// ...
auto it = set.find(node(num, book[num]));
if(it != set.end()) set.erase(it);
book[num]++;
set.insert(node(num, book[num]));
```



##### 130、[ Infix Expression](https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312)    20min

debug：

- 测试点2：只有一个节点的时候需要特别注意

##### 131、[ Subway Map](https://pintia.cn/problem-sets/994805342720868352/problems/994805347523346432)    98min

dfs，地铁站路线最短，或者换乘次数最短

debug：

- 记录line需要直接在edge直接记录，不然后期再算特别麻烦
- 对于vis[node]的控制来说，这里其实是控制edge的visited与否，所以应该在将要访问nxt之前，将vis[cur] = true，在访问完nxt之后，重新将vis[cur]置false

#### 2021年8月21日

##### 132、[ Cut Integer](https://pintia.cn/problem-sets/994805342720868352/problems/994805347145859072)    12min

简单题，int当作string输入之后，通过除和模分成左右两部分，然后进行判断

debug：

​	浮点错误：除0错误，这里的z可能是1000，即b=0，所以应该先判断a、b会不会是0，如果是的话，就直接输出NO

##### 133、[ Splitting A Linked List](https://pintia.cn/problem-sets/994805342720868352/problems/994805346776760320)    20min

简单题，按val小于0，小于等于k，大于k把list分成三个vector，并顺序组合起来，最后进行输出

##### 134、[ Vertex Cover](https://pintia.cn/problem-sets/994805342720868352/problems/994805346428633088)    17min

简单题，判断给定的顶点序列能否让所有的边至少有一个点

- 边id定义为两个顶点较小在前，较大在后的组合成一个新的int
- 对每一个顶点v，遍历g[v]，把所有边都放在一个set中，如果set的size==m，即Yes，否则No

##### 135、[ Is It A Red-Black Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640)    60min

简单题，判断是否是红黑树，只需要将红黑树构建出来就好了

需要注意的是，这里**红黑树本身是BST**

debug：

- 黑色节点数量cnt是需要判断的，不是直接加



重做16，60min

- 时间跨度价格的话，用两个时间戳价格相减
- 这里on和off是最近的保留，所以两个必然是相连的，先on后off，其他情况可以直接continue



#### 2021年8月22日

##### 136、[ A Delayed Palindrome](https://pintia.cn/problem-sets/994805342720868352/problems/994805345732378624)    15min

简单题，迭代求string的和，并判断是不是回环数

##### 137、[ Final Grading](https://pintia.cn/problem-sets/994805342720868352/problems/994805345401028608)    22min

简单题，先map，后vec

debug：

- 测试点3：
  - 如果考试分数不存在，则输出-1
  - 如果考试是0分，那么输出0
  - 所以一开始g_mid和g_final都应该初始化为-1，因为如果g_final==-1，那么直接没了，如果g_mid==-1，那就看g_final

##### 138、[Postorder Traversal](https://pintia.cn/problem-sets/994805342720868352/problems/994805345078067200)    30min

BST：preorder + inorder  =>  postorder

##### 139、[First Contact](https://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312)    55min

两个循环求解，利用person{id, gender}保存人

debug：

- 测试点1、2：存在0000和-0000的情况
- 测试点5：要考虑g中回环，在p2中，需要舍弃p1的情况



#### 2021年8月23日

##### 140、[ Look-and-say Sequence](https://pintia.cn/problem-sets/994805342720868352/problems/994805344490864640)    9min

简单题，string循环

##### 141、[PAT Ranking of Institutions](https://pintia.cn/problem-sets/994805342720868352/problems/994805344222429184)    20min

模拟题，排序

- 这里首先需要统计每个学校b、a、t三个档次的总分数，然后再去计算

##### 142、[ Maximal Clique](https://pintia.cn/problem-sets/994805342720868352/problems/994805343979159552)    26min

debug：

- 测试点1：需要考虑到给定的子图中，有节点间没有边的情况

##### 143、[ Lowest Common Ancestor](https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312)    30min

pre+bst  =>  BST，看节点间的关系，能否找到、公共祖先、互为祖先

- 两个bool判断能不能找到
- 两个vector判断祖先



#### 2021年8月24日

##### 144、[The Missing Number](https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160)      6min

​	暴力方法

- 设置一个vector\<bool>(100005, false)
- 然后输入t，如果t∈(0,100005)设置vector[t] = true

- 最后从1开始遍历，遇到第一个为false的直接输出i

##### 145、[ Hashing - Average Search Time](https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744)    42min

​	hash的冲突策略，Quadratic probing，给出一系列数字，计算每次数字能够确认是否存在的查找次数的平均

- nxt = (t+j*j)%msize     j属于[0, msize/2]
- 查找的时候，遇到vec[nxt]==t || **vec[nxt]==-1**    就break

##### 146、[Topological Order](https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760)    17min

​	简单题，拓扑排序

##### 147、[ Heaps](https://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648)    20min

​	简单题，堆+完全二叉树

#### 2021年8月25日

##### 148、[Werewolf - Simple Version](https://pintia.cn/problem-sets/994805342720868352/problems/1038429808099098624)     ~~50min   放弃看答案发现思路错误~~

​	应该两遍遍历的时候先固定两个狼人的，wp中狼人为-1，人为1，如果vec[k]*wp[abs(k)] < 0就代表是骗子，放到liars向量中

​	最后如果**liars中有两个数据**，且**wp[liars[0]]+wp[liars[1]]==0**（即一个狼人一个人），则输出结果

##### 149、[Dangerous Goods Packaging](https://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176)     30min  WA=18分

​	测试点2：~~不能用两重循环？~~是要用两边循环，但是这里应该将输入的list设置向量

##### 150、[Travelling Salesman Problem](https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384)     30min

​	简单题，按照条件进行判断

##### 151、[ LCA in a Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856)    45min

- inorder + perorder => 二叉树
- 计算LCA关系

debug：

- 143题的写法更加好

#### 2021年8月26日

##### 152、[ Google Recruitment](https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672)    23min

- 0、1不是质数
- **2是质数！！！**

##### 153、[Decode Registration Card of PAT](https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928)    49min    ~~WA = 21分~~

- 下面两个测试点的问题出在了输入的参数里面
- ~~测试点1：~~
- ~~测试点4：~~

##### 154、[ Vertex Coloring](https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552)    11min

简单题，遍历所有边，看有没有颜色一样的情况即可

##### 155、[ Heap Paths](https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552)    21min

简单题，堆，输出所有路径，判断是最小堆、最大堆，还是不是堆



#### 2021年8月31日 

##### PAT（甲级）2019年春季考试

1、[Sexy Primes](https://pintia.cn/problem-sets/1102545909403459584/problems/1102545975602159616)    10min

简单题

2、[Anniversary](https://pintia.cn/problem-sets/1102545909403459584/problems/1102545975602159617)     14min

简单题

3、[ Telefraud Detection](https://pintia.cn/problem-sets/1102545909403459584/problems/1102545975602159618)    60min

1. vector<vector\<int>> g  存储数据
2. 遍历，按照short条件进行筛选得到sus(疑似电话)，同时得到总电话数cnt和初步的callback的电话（这里还包含了诈骗之间的电话）
3. 遍历sus，将诈骗之间的电话排除掉留下单纯是普通人callback的情况
4. 按照callback率进行计算，获得真正的诈骗电话
5. 并查集
6. 输出答案

4、[Structure of a Binary Tree](https://pintia.cn/problem-sets/1102545909403459584/problems/1102545975602159619)    96min

1. post + in  ->  tree

2. string判断各种条件（getline + char操作）
   1. 根节点
   2. 兄弟节点
   3. 父子节点
   4. full tree

debug：代码写错了，复制粘贴之后，没有改全



#### 2021年9月1日 

##### PAT（甲级）2019年秋季考试

1、[Forever](https://pintia.cn/problem-sets/1170733800028712960/problems/1170733863463366656)    6 + 35min

- dfs得到符合条件的数A
- gcd（这里是gcd(a, **a%b**)）、isPrime（这里题目说的是要大于2的质数，所以2的时候返回false）
- stol、to_string结合使用
- 按照数（A+1）的各个位数之和n统计数据，存储到map<int, vector\<string>>中
  - 这里需要注意的是，n不一定只有一个，所以要用vector\<int> res来存储所有满足的情况
- 按照n、string的升序进行输出

2、[Merging Linked Lists](https://pintia.cn/problem-sets/1170733800028712960/problems/1170733863463366657)    24min

- 遍历两遍，分别得到两个串的长度，并确定long、short起始位置
- 遍历short串，存放到stack中
- 设置vector<node*> res，遍历long串，将其中节点放到res中，每隔两位，如果stack没空，就把stack顶的节点放到res中
- 遍历格式化输出

3、[Postfix Expression](https://pintia.cn/problem-sets/1170733800028712960/problems/1170733863463366658)    22min

- 首先创建树
- 后缀表达式输出，每一个节点都需要在两边输出括号
- 如果当前节点是“+” or “-”，且左节点是nullptr，那么直接先输出当前节点的数据，然后再递归到右节点
- 否则，按照后序遍历的方法来进行递归输出

4、[Dijkstra Sequence](https://pintia.cn/problem-sets/1170733800028712960/problems/1170733863463366659)    35min

- 和dijkstra比较类似，但是并不完全是dijkstra
- 这里有点最小生成树的意思，利用一个vector\<int> dis保存目前从source节点到其他节点的距离，每一次都遍历所有前一个节点可以达到的下一个节点，然后更新dis
- 然后确认当前可以达到节点的最小距离min_dis
- 如果前一个节点到当前节点的距离 == min_dis，那么就说明继续遍历
  - 如果不相等，则直接返回false
- 全部遍历完成之后，返回true



#### 2021年9月2日 

##### PAT（甲级）2019年冬季考试

1、[Good in C](https://pintia.cn/problem-sets/1203317538312806400/problems/1203317626619691008)   19min

- 格式化输出
- 形如 vec[i*7+j] 的访问方式

2、[ Block Reversing](https://pintia.cn/problem-sets/1203317538312806400/problems/1203317626619691009)    16min

​	链表按照k个节点的块进行转置

3、[Summit](https://pintia.cn/problem-sets/1203317538312806400/problems/1203317626619691010)    15min

​	有过类似的题，其实就是每个area算它len个人，遍历g，累加

- 所有人都需要有len-1，如果没有，则表示有不是互为朋友的人
- 如果有人是len，那么就说明还可以再加人
- 一个area是正确的

4、[ Cartesian Tree](https://pintia.cn/problem-sets/1203317538312806400/problems/1203317626619691011)    15min

​	中序遍历 + heap形式，其实很简单，其实就是找[l, r]中最小的节点作为根节点，左边是左节点，右边是右节点



#### 2021年9月3日 

##### PAT（甲级）2020年春季考试

1、[ Prime Day](https://pintia.cn/problem-sets/1287399212459409408/problems/1287399280935616512)    6min

​	string + prime	简单题

2、[The Judger](https://pintia.cn/problem-sets/1287399212459409408/problems/1287399280939810816)    80min + **答案**

- 一开始题目理解错误，difference是插值的意思，这里通过abs(pre-cur)得到
- 数据天然没有重复，所以用vector而不是set，set的效率比vector低太多了
- 然后因为刚开始的写法效率不高，导致运行错误，所以直接排除了正确的解法
  - 将pre存放在向量prev中，每次如果正确运行，则遍历prev，将diff[abs(pre-cur)]设置为true

3、[ Safari Park](https://pintia.cn/problem-sets/1287399212459409408/problems/1287399280939810817)    15min

​	图 + 相邻节点判断

4、[Replacement Selection](https://pintia.cn/problem-sets/1287399212459409408/problems/1287399280939810818)    20min

​	两个priority_queue实现，并利用threshold将数据划分到两个pq中，结果存放在vector<vector\<int>> 中，格式化输出



#### 2021年9月4日

##### PAT（甲级）2020年秋季考试

1、[ Panda and PP Milk](https://pintia.cn/problem-sets/1302814386427613184/problems/1302814455281307648)

​	思维，从左往右累加一遍得到值，从右往左累加一遍得到值，最后取两遍的较大值

2、[How Many Ways to Buy a Piece of Land](https://pintia.cn/problem-sets/1302814386427613184/problems/1302814455281307649)

​	暴力二重循环求解

3、[Left-View of Binary Tree](https://pintia.cn/problem-sets/1302814386427613184/problems/1302814455281307650)

​	left-view 就是左视图的意思，所以等于层序遍历，然后每一层都取第一个节点的值保存

4、[ Professional Ability Test](https://pintia.cn/problem-sets/1302814386427613184/problems/1302814455281307651)

- 首先需要拓扑判断有没有环

- 然后针对每一个start，去找到到达当前点的最短路，保存符合条件的path，进行输出



#### 2021年9月5日

##### PAT（甲级）2020年冬季考试 

1、[The Closest Fibonacci Number](https://pintia.cn/problem-sets/1336189424478273536/problems/1336189514299293696)    20min

​	二分查找

2、[Subsequence in Substring](https://pintia.cn/problem-sets/1336189424478273536/problems/1336189514299293697)    10min

​	暴力确定起点计算

3、[File Path](https://pintia.cn/problem-sets/1336189424478273536/problems/1336189514299293698)    16min

​	利用一个fa向量，存储当前文件/目录的父亲，这里需要一个辅助向量，vec[i]中存取的是前面有i个空格的文件名，即当前文件前如果有k个空格，那么其父亲就直接是vec[k-1]

4、[Chemical Equation](https://pintia.cn/problem-sets/1336189424478273536/problems/1336189514299293699)    40min

​	dfs，利用vector<vector<vector\<int>>> 存储equations，然后排序，最后dfs，将答案保存起来，并进行输出



#### 2021年9月7日

##### PAT（甲级）2018年秋季考试

- 都是题库题，做过了

1、[Werewolf - Simple Version](https://pintia.cn/problem-sets/1091179335113666560/problems/1091179376683413504)

2、[Dangerous Goods Packaging](https://pintia.cn/problem-sets/1091179335113666560/problems/1091179376683413505)

3、[ Travelling Salesman Problem](https://pintia.cn/problem-sets/1091179335113666560/problems/1091179376683413506)

4、[ LCA in a Binary Tree](https://pintia.cn/problem-sets/1091179335113666560/problems/1091179376683413507)



#### 2021年9月8日

##### PAT（甲级）2015年春季考试

- 都是题库题，做过了

1、[ To Buy or Not to Buy](https://pintia.cn/problem-sets/1091186174119276544/problems/1091186210894934016)

2、[Count PAT's](https://pintia.cn/problem-sets/1091186174119276544/problems/1091186210894934017)

3、[The Largest Generation](https://pintia.cn/problem-sets/1091186174119276544/problems/1091186210894934018)

4、[ Cars on Campus](https://pintia.cn/problem-sets/1091186174119276544/problems/1091186210894934019)



#### 2021年9月10日

##### PAT（甲级）2021年春季考试

1、[Arithmetic Progression of Primes](https://pintia.cn/problem-sets/1371107142560067584/problems/1371107214743625728)

​	找到一组**素数**等差数列，需要等差数列的个数等于n，如果结果不唯一，则输出公差最大，或者第一个数最大的情况，如果没有答案，则输出范围内最大的素数

**debug：**

- 当n==1的时候，需要输出的是最大素数

2、[Lab Access Scheduling](https://pintia.cn/problem-sets/1371107142560067584/problems/1371107214747820032)

​	贪心算法

3、[Structure of Max-Heap](https://pintia.cn/problem-sets/1371107142560067584/problems/1371107214747820033)

​	heap构建 + getline + 输入情况判断

4、[Recycling of Shared Bicycles](https://pintia.cn/problem-sets/1371107142560067584/problems/1371107214747820034)

​	一辆差按照距离当前位置最近的点的贪心算法，在地图上面运动

- 每次都需要使用dijkstra(int start, vector\<int> &dis)
  - **dijkstra其实是找到了start到所有点的最小距离，所以这里并不需要destination**
- 直接在dis中找到reach[i]==false且dis[i]最小的下一个点
  - 累加cnt，更新path，更新cur=nxt
- 输出path
- 查看是否满足path.size() == n+1
  - 满足则输出cnt
  - 不满足，格式化输出reach[i] == false  的点



#### 2021年9月15日

##### 浙江大学计算机与软件学院2019年考研复试上机模拟练习

1、[ Conway's Conjecture](https://pintia.cn/problem-sets/1106490269907619840/problems/1106490594978766848)    15min

​	string、to_string、stol、long long、isPrime

2、[Play with Linked List](https://pintia.cn/problem-sets/1106490269907619840/problems/1106490594978766849)    15min

​	简单题

3、[Unsuccessful Searches](https://pintia.cn/problem-sets/1106490269907619840/problems/1106490594978766850)     30min + **答案**

​	debug：

​		这种需要取模循环的，以后直接用for(int j=0; j<mSize; ++j) {(i+j)%mSize}这种来循环

4、[Ambulance Dispatch](https://pintia.cn/problem-sets/1106490269907619840/problems/1106490594978766851)     90min + WA = 27分

​	dijkstra

- 对于需要另设向量pnum的情况，直接设置在dijkstra函数中，而不是设置在struct中



#### 2021年9月16日

##### 浙江大学计算机与软件学院2019年保研上机模拟练习

1、[Happy Numbers](https://pintia.cn/problem-sets/1176509880014966784/problems/1176509949720104960)    10min

​	简单题，平方、to_string

2、[ Zigzag Sequence](https://pintia.cn/problem-sets/1176509880014966784/problems/1176509949720104961)    10min

​	简单题，格式化输出

3、[ Is It An AVL Tree](https://pintia.cn/problem-sets/1176509880014966784/problems/1176509949720104962)    16min

​	简单题，构造BST，递归

4、[Index of Popularity](https://pintia.cn/problem-sets/1176509880014966784/problems/1176509949720104963)    24min

​	简单题，struct、vector、map、排序、输出



#### 2021年9月17日

##### 浙江大学软件学院2020年保研上机模拟练习

1、[ Standard Form of Polynomial](https://pintia.cn/problem-sets/1308776503006846976/problems/1308776567443939328)    10min

​	简单题，遍历，相乘

​	这里很巧合得写反了（从0开始，是高位到末位），但是正好是和答案一致得

2、[ Distance of Triples](https://pintia.cn/problem-sets/1308776503006846976/problems/1308776567443939329)    30min + 10min

debug：

- 输出的时候，三元组得顺序是必须和集合得顺序一致的

3、[ Partial School Ranking](https://pintia.cn/problem-sets/1308776503006846976/problems/1308776567443939330)    30min

​	并查集

debug：

- cmp函数又写错了
- 需要注意，并不是所有人都有成绩的，所以需要另设置一个vector\<bool> exist来判断人是否出现过

4、[ Shopping With Coupons](https://pintia.cn/problem-sets/1308776503006846976/problems/1308776567443939331)    60min（WA=24） + **答案**

​	优先队列，但是我用错了

- 需要实现的是一个在一个matrix上面，找到最优的哪些点作为结果
  - 把所有点都存起来，会爆内存
  - 逐行遍历，并利用priority_queue加速，还是超时
- 所以不能使用遍历的方法，而是需要设置一个struct，并用优先队列实现
  - 首先需要对商品价格升序，优惠券降序排序
  - struct node保存商品和优惠券索引，重载小于号，使得pq中价格最低的在最上面
  - 将每一个商品+最大优惠券作为一个点，放到pq中
  - 拿出pq.top，如果超过剩余的钱rst，结束循环
  - 否则作为一个点，更新cnt和rst
  - 把当前商品+优惠力度较低一点的点放到pq中



