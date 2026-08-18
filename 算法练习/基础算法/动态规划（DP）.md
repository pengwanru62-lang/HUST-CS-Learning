## 1. 什么是 DP

动态规划（Dynamic Programming）：

> 将一个大问题拆分成若干个子问题，并利用已经计算出的子问题答案，避免重复计算。

适用条件：

- 最优子结构
- 重叠子问题

---

## 2. DP 四步法

### ① 定义状态

定义 `dp[i]` 的含义。

例如：

```cpp
dp[i]
```

表示：

- 前 i 个物品最大价值
- 到达 i 的方案数
- 到达 i 的最短距离
- 完成第 i 个任务的最早时间

**状态定义是 DP 最重要的一步。**

---

### ② 初始化

确定最开始的状态。

例如：

```cpp
dp[1] = 0;
```

或者

```cpp
dp[0] = 1;
```

初始化一定根据状态定义决定。

---

### ③ 状态转移

根据已经求出的状态推出新的状态。

一般形式：

```cpp
dp[i] = ...
```

例如：

最长路

```cpp
dp[v] = max(dp[v], dp[u] + w);
```

路径计数

```cpp
dp[v] += dp[u];
```

背包

```cpp
dp[j] = max(dp[j], dp[j-w] + v);
```

---

### ④ 输出答案

可能是：

```cpp
dp[n]
```

也可能是：

```cpp
max(dp[i])
```

或者

```cpp
sum(dp[i])
```

根据题目决定。

---

# DP 常见模型

## ① 线性 DP

特点：

```text
当前位置只依赖前面状态
```

例如：

- 爬楼梯
- 最长上升子序列
- 数字三角形
#### P1115 [最大子段和](https://www.luogu.com.cn/problem/P1115 "最大子段和")
核心判断：
```
前面的连续段之和对我有帮助
→ 接上

前面的连续段是负贡献
→ 从当前位置重新开始
```

```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int dp[N];  //表示必须以a[i]结尾的最大连续子段和
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=1; i<=n; i++){
        dp[i] = max(a[i], dp[i-1] + a[i]);
    }
    
    int ans = -1e5;
    for(int i=1; i<=n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;
}
```
#### P1020 [[NOIP 1999 提高组] 导弹拦截](https://www.luogu.com.cn/problem/P1020 "[NOIP 1999 提高组] 导弹拦截")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
int dp1[N];    //以第i个元素结尾的最大非递增子序列
int dp2[N];    //以第i个元素结尾的最大严格递增子序列

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=0;
    while(cin >> a[++n]);
    n--;    //输入并且计数

    //从前面向后面扫描
    int ans1 = 1;
    for(int i=1; i<=n; i++){
        dp1[i] = 1;
        for(int j=1; j<i; j++){
            if(a[i] <= a[j]){    //如果i前面的元素比i大的话，那就可以把这个元素放在i之后
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
        ans1 = max(ans1, dp1[i]);
    }

    cout << ans1 << endl;

    //从前面向后面扫描
    int ans2 = 1;
    for(int i=1; i<=n; i++){
        dp2[i] = 1;
        for(int j=1; j<i; j++){
            if(a[i] > a[j])
                dp2[i] = max(dp2[i], dp2[j]+1);
        }
        ans2  = max(ans2, dp2[i]);
    }
    cout << ans2;
    return 0;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=0;
    while(cin >> a[++n]);
    n--;    //输入并且计数

    //第一问找非递增子序列
    vector<int> tail1;    //tail[len] = x表示长度为len的非递减子序列的结尾的最小值
    //要用upper_bound二分查找只能构造单调不减序列，所以用相反数
    for(int i=1; i<=n; i++){
        int x = -a[i];    //对于每一个x

        auto pos = upper_bound(tail1.begin(),tail1.end(),x);

        if(pos == tail1.end()){    //没找到大于x的，证明x是最大，可以进数组
            tail1.push_back(x);
        }else{
            *pos = x;    //替换成为更小的方便更新
        }
    }

    cout << tail1.size() << endl;

    //第二问找严格递增序列
    vector<int> tail2;
    for(int i=1; i<=n; i++){
        int x = a[i];

        auto pos = lower_bound(tail2.begin(),tail2.end(),x);

        if(pos == tail2.end())
            tail2.push_back(x);
        else
            *pos = x;
    }
    cout << tail2.size() << endl;
    return 0;
}
```
#### P1091 [[NOIP 2004 提高组] 合唱队形](https://www.luogu.com.cn/problem/P1091 "[NOIP 2004 提高组] 合唱队形")(双向的)
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int l[N];    //表示以第i个元素结尾的左侧单调递增序列
int r[N];    //表示以第i个元素结尾的右侧单调递减序列
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=1; i<=n; i++){
        l[i] = 1;
        r[i] = 1;

        for(int j=1; j<i; j++){
            if(a[j] < a[i])
                l[i] = max(l[i], l[j] + 1);
        }

        /*当计算 r[i] 的时候，j>i，也就是 r[j] 还没有被计算，r[j] 此时是随机垃圾值或者刚初始化为 1，得不到正确结果。
        for(int j=i+1; j<=n; j++){
            if(a[j] < a[i])
                r[i] = max(r[i], r[j]+1);    //注意此时需要从i+1开始更新
        }

        ans = max(ans, l[i]+r[i]-1);*/
    }

    // 2.反向求 r[i]：以i开头最长下降子序列
    for(int i=n; i>=1; i--){
        r[i] = 1;

        for(int j=n; j>i; j--){
            if(a[j] < a[i])
                r[i] = max(r[i], r[j]+1);
        }
    }

    int Maxkeep = 0;
    
    for(int i=1; i<=n; i++){
        Maxkeep = max(Maxkeep, l[i]+r[i]-1);
    }

    int k = n-Maxkeep;
    cout << k;
    return 0;
}
```
#### P1280 [[CHCI 2002 National Competition #2 Juniors] 尼克的任务](https://www.luogu.com.cn/problem/P1280 "[CHCI 2002 National Competition #2 Juniors] 尼克的任务")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int dp[N];    //dp[i]表示假设在第i分钟开始时为空闲状态，从i开始到n分钟可以休息的最大时间，由于假设不一定成立，所以并不是每一个dp[i]都表述从i开始到n分钟结束可以休息的最大时间

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<int> task[N];    //task[p]里面的元素表示从p时刻开始的任务所持续的长度
    for(int i=1; i<=k;i++){
        int p,t;
        cin >> p >> t;

        task[p].push_back(t);
    }

    //后面的状态依赖前面的状态，所以需要倒序更新
    for(int i=n; i>=1; i--){
        if(task[i].empty()){    //如果当前没有任务
            dp[i] = dp[i+1] + 1;
        }else{
           for(int t : task[i]){
               dp[i] = max(dp[i], dp[i+t]);
           }
        }
    }
    cout << dp[1];
    return 0;
}
```
---

## ② DAG DP

特点：

```text
状态按照拓扑顺序转移
```

例如：

P1113 杂务

```cpp
dp[v] = max(dp[v], dp[u] + len[v]);
```

P4017 最大食物链

```cpp
dp[v] += dp[u];
```

---

## ③ 背包 DP

特点：

```text
容量作为状态
```

例如：

```cpp
dp[j]
```

表示容量 j 的最优答案。
#### P1048 [[NOIP 2005 普及组] 采药](https://www.luogu.com.cn/problem/P1048 "[NOIP 2005 普及组] 采药")
## 为什么贪心不正确

每株草药只能：

```
采整株
或不采
```

不能只采一部分，所以这是 **01 背包**，不是可以按照性价比选择的分数背包。

例如：

```
总时间：50

时间  价值  性价比
10    60    6
20    100   5
30    120   4
```

按照性价比从高到低，先选前两株：

```
时间 = 30
价值 = 160
```

剩余时间 20，第三株无法选择。

但最优选择是第二、三株：

```
时间 = 20 + 30 = 50
价值 = 100 + 120 = 220
```

所以即使把你的排序改为从大到小，贪心仍然不成立。

另外，你现在的比较函数还是从小到大：

```
return x.price < y.price;
```

不过这不是主要问题，主要问题是整个性价比贪心模型不适用。
正确的方式是二维dp
```cpp
#include<bits/stdc++.h>
using namespace std;
struct Herbs{
    int cost;
    int value;
};
const int M = 105;
Herbs herbs[M];
const int T = 1000 + 5;
int dp[M][T];    //dp[i][j]表示考虑前i株草药，在总时间不超过j的情况下，可以获得的最大价值。

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,m;
    cin >> t >> m;

    for(int i=1; i<=m; i++){
        cin >> herbs[i].cost  >> herbs[i].value;
    }

    //依次考虑每一株草药
    for(int i=1; i<=m; i++){
        //枚举总时间上限
        for(int j=1; j<=t; j++){
            //不采草药
            dp[i][j] = dp[i-1][j];

            //采集草药
            if(j >= herbs[i].cost)
                dp[i][j] = max(dp[i][j], dp[i-1][j-herbs[i].cost]+herbs[i].value);
        }
    }

    cout << dp[m][t];
    
    return 0;
}
```
01背包：倒序不是为了从大到小选时间，而是为了保护左边的旧状态，防止当前草药被重复使用。
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,m;
    cin >> t >> m;

    for(int i=1; i<=m; i++){
        int cost, value;
        cin >> cost >> value;

        for(int j=t; j>=cost; j--){
            dp[j] = max(dp[j], dp[j-cost]+value);
        }
    }

    cout << dp[t];
    return 0;
}
```
#### P1616 [疯狂的采药](https://www.luogu.com.cn/problem/P1616 "疯狂的采药")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int T = 1e7+5;
long long dp[T];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,m;
    cin >> t >> m;

    for(int i=1; i<=m; i++){
        int cost, value;
        cin >> cost >> value;

        for(int j=cost; j<=t; j++){
            dp[j] = max(dp[j], dp[j-cost]+value);
        }
    }

    cout << dp[t];
    return 0;
}
```
#### P1164[小 A 点菜](https://www.luogu.com.cn/problem/P1164 "小 A 点菜")（dp计数）
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
long long dp[N];    //dp[j]表示花j元有多少种点菜方法

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    //dp初始化
    dp[0] = 1;    //花0元有一种方案
    for(int i=1; i<=n; i++){
        int price;
        cin >> price;

        //只有一份菜，所以倒序
        for(int j=m; j>=price; j--){
            dp[j] = dp[j] + dp[j-price];    //不买这个+买这个
        }
    }
    cout << dp[m];
    return 0;
}
```
#### P1853 [[NWERC 2004] 投资的最大效益](https://www.luogu.com.cn/problem/P1853 "[NWERC 2004] 投资的最大效益")
多了一个每年都需要更新capacity的购买能力。
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N =1e6+5;
long long dp[N];    //dp[i]在总投入不超过i千元的时候，可以获得的最大的收益
struct Bond{
    int invest;
    int income;
};

const int D = 15;
Bond bond[15];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s,n,d;
    cin >> s >> n >> d;

    for(int i=1; i<=d; i++){
        int a,b;
        cin >> a >> b;
        bond[i].invest = a/1000;
        bond[i].income = b;
    }

    //对于每一年而言,更新一次资产总数
    for(int year=1; year<=n; year++){
        int capacity = s/1000;

        //每一年都要初始化dp
        for(int i=1; i<=capacity; i++)
            dp[i] = 0;

        //完全背包正序
        for(int j=1; j<=d; j++){
            for(int k=bond[j].invest; k<=capacity; k++){
                dp[k] = max(dp[k], dp[k-bond[j].invest] + bond[j].income);
            }
        }
           
        s += dp[capacity];
    }

    cout << s;
    return 0;
}
```
#### P1064 [[NOIP 2006 提高组] 金明的预算方案](https://www.luogu.com.cn/problem/P1064 "[NOIP 2006 提高组] 金明的预算方案")

目标：01 背包综合题。

这题会加入“主件和附件”的限制，不能直接套最简单模板。  
它很适合训练：

- 如何预处理合法组合
- 如何把约束转成若干组选项
- 如何从普通 01 背包过渡到分组背包思想

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Goods{
    int mainvalue;
    int mainprice;

    int attachprice[2];
    int attachvalue[2];
    int attachcnt;
};
const int N = 65;
Goods goods[N];

const int M = 2e5 + 5;
int dp[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    //读入数据
    for(int i=1; i<=m; i++){
        int v, w, q;
        cin >> v >> w >> q;

        if(q == 0){
            goods[i].mainvalue = v * w;
            goods[i].mainprice = v;
        }else{
            goods[q].attachprice[goods[q].attachcnt] = v;
            goods[q].attachvalue[goods[q].attachcnt] = v * w;
            goods[q].attachcnt++;
        }
    }

    //进行数据处理
    //列举所有的物品
    for(int i=1; i<=m; i++){
        if(goods[i].mainprice == 0)
            continue;    //如果不是主件，那么跳过这个选择

        //每一个物体最多购买一次，倒序
        for(int j=n; j>=goods[i].mainprice; j--){
            //只考虑主件
            dp[j] = max(dp[j], dp[j-goods[i].mainprice]+goods[i].mainvalue);

            //购买主件 + 附件1
            if(goods[i].attachcnt >= 1){
                if(j>=goods[i].mainprice+goods[i].attachprice[0]){
                    dp[j] = max(dp[j], dp[j-(goods[i].mainprice+goods[i].attachprice[0])]+goods[i].mainvalue+goods[i].attachvalue[0]);
                }
            }

            //购买主件 + 附件2
            if(goods[i].attachcnt == 2){
                if(j>=goods[i].mainprice+goods[i].attachprice[1]){
                    dp[j] = max(dp[j], dp[j-(goods[i].mainprice+goods[i].attachprice[1])]+goods[i].mainvalue+goods[i].attachvalue[1]);
                }
            }

            //购买主件 + 附件1 + 附件2
            if(goods[i].attachcnt == 2){
                if(j>=goods[i].mainprice+goods[i].attachprice[0]+goods[i].attachprice[1]){
                    dp[j] = max(dp[j], dp[j-(goods[i].mainprice+goods[i].attachprice[0]+goods[i].attachprice[1])]+goods[i].mainvalue+goods[i].attachvalue[0]+goods[i].attachvalue[1]);
                }
            }
            
        }
    }

    cout << dp[n];
    return 0;
}
```
#### P1833 [樱花](https://www.luogu.com.cn/problem/P1833 "樱花")(分类讨论，无限次采用正序)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Flower{
    int t;
    int c;
    int p;
};
const int N = 10005;
Flower f[N];
const int T = 1005;
int dp[T];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h1,m1,h2,m2;
    char c;
    cin >> h1 >> c >> m1 >> h2 >> c >> m2;

    int ts = h1*60 + m1;
    int te = h2*60 + m2;
    int t = te-ts;
    
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> f[i].t >> f[i].c >> f[i].p;
    }

    //处理每一个树
    for(int i=1; i<=n; i++){
        if(f[i].p == 0){
            //无限次可以正序
            for(int j=f[i].t; j<=t; j++){
                dp[j] = max(dp[j], dp[j-f[i].t]+f[i].c);
            }
        }else{
            //由于有数量限制，所以需要逆序
            for(int j=t; j>=f[i].t; j--){
                int cnt = 1;
                while(j>=cnt*f[i].t && cnt<=f[i].p){    //相当于“附件”依次列举
                    dp[j] = max(dp[j], dp[j-cnt*f[i].t]+(cnt*f[i].c));
                    cnt++;
                }
            }
        }
    }
    
    cout << dp[t];
    return 0;
}
```
#### P1776 [宝物筛选](https://www.luogu.com.cn/problem/P1776 "宝物筛选")（和樱花那个题相似但是使用了二进制划分优化时间复杂度）
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int v[N];
int w[N];
int m[N];
const int W = 4e4+5;
int dp[W];    //dp[i]表示花费i的重量可以手机到的宝物的最大价值

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,weight;
    cin >> n >> weight;

    for(int i=1; i<=n; i++)
        cin >> v[i] >> w[i] >> m[i];

    //处理每一个物体 
    for(int i=1; i<=n; i++){
        int cnt = 1;    //每一个物体的初始化

        //开始按照1、2、4......这样的顺序去列举,然后依次处理每一组
        while(cnt <= m[i]){
            int currentweight = cnt*w[i];
            int currentvalue = cnt*v[i];

            for(int j=weight; j>=currentweight; j--){
                dp[j] = max(dp[j], dp[j-currentweight]+currentvalue);
            }

            //从剩余的物品中拿走这一组
            m[i] -= cnt;
            //下一组的数目乘以2
            cnt *= 2;
        }

        if(m[i] >  0){
            int currentweight = m[i]*w[i];
            int currentvalue = m[i]*v[i];

            for(int j=weight; j>=currentweight; j--){
                dp[j] = max(dp[j], dp[j-currentweight]+currentvalue);
            }
        }
    }
    
    cout << dp[weight];
    return 0;
}
```
#### P2918 [[USACO08NOV] Buying Hay S](https://www.luogu.com.cn/problem/P2918 "[USACO08NOV] Buying Hay S")（至少购买H包草料，所以最后的答案需要向后面更新）
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Grass{
    int p;
    int c;
};
const int N = 105;
Grass grass[N];
const int M = 50000 + 5000 + 5;
int dp[M];    //dp[i]表示买到i的干草需要的最小花费
const int INF = 1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,h;
    cin >> n >> h;

    for(int i=1; i<=n; i++){
        cin >> grass[i].p >>grass[i].c;
    }

    dp[0] = 0;
    for(int i=1; i<M; i++){    //防止下标访问越界
        dp[i] = INF;
    }

    for(int i=1; i<=n; i++){
        for(int j=grass[i].p; j<=M; j++){
            dp[j] = min(dp[j], dp[j-grass[i].p] + grass[i].c);
        }
    }
    int ans = INF;
    for(int i=h; i<M; i++)
        ans = min(ans, dp[i]);
    
    cout << ans;
    return 0;
}
```
---
# 常见 DP 转移

## 最值

```cpp
dp[v] = max(dp[v], dp[u] + w);
```

## 最小值

```cpp
dp[v] = min(dp[v], dp[u] + w);
```

## 方案数

```cpp
dp[v] += dp[u];
```

通常需要：

```cpp
dp[v] %= MOD;
```



---

# 做题步骤

看到 DP：

```text
① 状态是什么？
        ↓
② 初始状态是谁？
        ↓
③ 如何由旧状态推出新状态？
        ↓
④ 最终答案在哪里？
```

---

# 一句话总结

> DP 的核心就是：定义状态 → 初始化 → 状态转移 → 输出答案。
#### P1113[[USACO02FEB] 杂务](https://www.luogu.com.cn/problem/P1113 "[USACO02FEB] 杂务")
```cpp
//由于是按照顺序的线性输入，所以可以用线性dp而不是拓扑排序
//状态转移只发生在线性有序的序列
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int dp[N];//表示最晚结束时间

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int id, len;
        cin >> id >> len;

        int pre;
        dp[i] = len;
        int latest = 0;
        while(cin >> pre && pre != 0){
            latest = max(dp[pre],latest);
        }
        dp[i] = latest + len;
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;
}
```

#### P4017 [最大食物链计数](https://www.luogu.com.cn/problem/P4017 "最大食物链计数")（dp状态转移+拓扑排序）
```cpp
#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 5;
const int MOD = 80112002;
vector<int> graph[N];
int indegree[N];    //统计入度
int outdegree[N];    //统计出度
long long dp[N];    //统计到i的时候有几条线路

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    //进行建图
    while(m--){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);    //统计边
        indegree[b]++;    //更新入度
        outdegree[a]++;    //更新出度
    }

    //拓扑排序采用队列的实现方式，首先让入度为0的入队，并且初始化dp
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            dp[i] = 1;//初始为1
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        //遍历每一个u可以到达的地方
        for(int v : graph[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
            indegree[v]--;    //更新入度
            if(indegree[v] == 0)    //判断是否入队
                q.push(v);
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        if(outdegree[i] == 0)
            ans = (ans + dp[i]) % MOD;
    }

    cout << ans;
    return 0;
}
```

#### P1807 [最长路](https://www.luogu.com.cn/problem/P1807 "最长路")
存在权值为负数的边，所以常见的Dikjstra算法失效
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1505;
struct Edge{
    int to;
    int weight;
};
vector<Edge> graph[N];
long long dp[N];      //从1到i的最大距离

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    //建立图
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    //距离初始化
    for(int i=1; i<=n; i++)
        dp[i] = -1;

    int s = 1;
    dp[s] = 0;

    //优先队列初始化
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    q.push({0, s});

    //存在负数权值的边，所以dikjstra算法失效
    while(!q.empty()){
        long long distance = q.top().first;
        int u = q.top().second;
        q.pop();

        if(distance != dp[u])
            continue;

        for(Edge& edge : graph[u]){
            int v = edge.to;
            int w = edge.weight;

            if(dp[v] < dp[u] + w){
                dp[v] = dp[u] + w;
                q.push({dp[v], v});
            }
        }
    }

    cout << dp[n];
    
    return 0;
}
```
以上算法是错误的.题干上保证了u<v，正确的方法是拓扑排序+动态规划dp
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1505;
struct Edge{
    int to;
    int weight;
};
vector<Edge> graph[N];
long long dp[N];      //从1到i的最大距离

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    //建立图
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    //距离初始化
    for(int i=1; i<=n; i++)
        dp[i] =  -(1LL << 60);

    int s = 1;
    dp[s] = 0;

    //由于u<v,所以编号顺序就是拓扑排序
    for(int u = 1; u<=n; u++){
        //不可以到达那么就跳过
        if(dp[u] == -(1LL << 60))
            continue;

        for(const Edge& edge : graph[u]){
            int v = edge.to;
            int w = edge.weight;

            dp[v] = max(dp[v], dp[u]+w);
        }
    }
    if(dp[n] == -(1LL << 60))
        cout << -1;
    else
        cout << dp[n];

    
    
    return 0;
}
```
纯拓扑排序写法如下：
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1505;
struct Edge{
    int to;
    int weight;
};
vector<Edge> graph[N];
long long dp[N];      //从1到i的最大距离
int indegree[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    //建立图
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        indegree[v]++;
    }

    //距离初始化
    for(int i=1; i<=n; i++)
        dp[i] =  -(1LL << 60);

    int s = 1;
    dp[s] = 0;

    //由于u<v,所以编号顺序就是拓扑排序
    //但是如果不知道这个条件也可以完成

    //队列初始化
    queue<int> q;
    
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(const Edge& edge: graph[u]){
            int v = edge.to;
            int w = edge.weight;
            indegree[v]--;
            
            //如果不可达到就跳过，但是跳过了就没有办法入队
            if(!(dp[u] == -(1LL << 60))){
                dp[v] = max(dp[v], dp[u]+w);
            }
            
            if(!indegree[v])
                q.push(v);
        }
    }
    if(dp[n] == -(1LL << 60))
        cout << -1;
    else
        cout << dp[n];
    
    return 0;
}
```
### DP- P1216 数字三角形

练习：

- DP 状态定义
- 从上一层转移到下一层
- `dp[i][j]` 的含义
- 滚动数组优化先不要求

核心思考：

```
到达当前位置，只可能从左上或右上过来
```

#### P1216 [[IOI 1994 / USACO1.5] 数字三角形 Number Triangles](https://www.luogu.com.cn/problem/P1216 "[IOI 1994 / USACO1.5] 数字三角形 Number Triangles")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N];
int dp[N][N];    //表示到(i, j)处的最大路径和

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r;
    cin >> r;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=i; j++){
            cin >> a[i][j];
        }
    }

    dp[1][1] = a[1][1];    //初始化
    for(int i=1; i<=r; i++){
        for(int j=1; j<=i; j++){
            if(j == 1 && i != 1){    //左边界
                dp[i][1] = dp[i-1][1] + a[i][1];
            }else if(j == i && i != 1){    //右边界
                dp[i][i] = dp[i-1][i-1] + a[i][i];
            }else{
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
            }            
        }
    }

    int ans = 0;
    for(int i=1; i<=r; i++)
        ans = max(ans, dp[r][i]);

    cout << ans;
    
    return 0;
}
```
## 1. 状态定义

设：

```
dp[i][j]
```

表示：

> 从三角形顶点走到第 `i` 行第 `j` 个数字时，能够获得的最大数字和。

例如：

```
第 3 行第 2 个位置
```

对应：

```
dp[3][2]
```

---

## 2. 状态从哪里转移

第 `i` 行第 `j` 个位置，只可能从上一行两个位置走来：

```
左上方：(i-1, j-1)
右上方：(i-1, j)
```

因此：

```
dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
```

其中 `a[i][j]` 是当前位置的数字。

---

## 3. 边界位置

每一行最左边：

```
(i,1)
```

只能从：

```
(i-1,1)
```

走过来。

所以：

```
dp[i][1] = dp[i-1][1] + a[i][1];
```

每一行最右边：

```
(i,i)
```

只能从：

```
(i-1,i-1)
```

走过来。

所以：

```
dp[i][i] = dp[i-1][i-1] + a[i][i];
```

中间位置才有两个来源：

```
dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
```
#### P1508 [Likecloud-吃、吃、吃](https://www.luogu.com.cn/problem/P1508 "Likecloud-吃、吃、吃")（用无穷大标记没有办法到达的位置）
```cpp
//本题目的巧妙之处是在设置不可到达的地方为NEG_INF
#include<bits/stdc++.h>
using namespace std;

const int N = 205;
int a[N][N];
int dp[N][N];
const int NEG_INF = -1e8;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin >> m >> n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    //dp初始化
    for(int i=1; i<=m+1; i++){
        for(int j=0; j<=n+1; j++){
            dp[i][j] = NEG_INF;
        }
    }
    dp[m+1][(n+1)/2] = 0;

    for(int i=m; i>=1; i--){
        for(int j=1; j<=n; j++){
            dp[i][j] = max(dp[i+1][j], max(dp[i+1][j-1], dp[i+1][j+1]))+a[i][j];
        }//（max函数只能传递两个参数）
    }
    int ans = NEG_INF;
    for(int i=1; i<=n;i++){
        ans = max(ans, dp[1][i]);
    }
    cout << ans;
    return 0;
}
```
#### P1002 [[NOIP 2002 普及组] 过河卒](https://www.luogu.com.cn/problem/P1002 "[NOIP 2002 普及组] 过河卒")
### 2. P1002 过河卒

练习：

- 网格路径计数
- 障碍处理
- DP 初始化
- 第一行、第一列的边界问题

核心转移：

```
dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```

但被马控制的位置不能走。
```cpp
#include<bits/stdc++.h>
using namespace std;

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const int N = 25;
bool visited[N][N] = {false};
long long dp[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int fx, fy, mx, my;
    cin >> fx >> fy >> mx >> my;

    //初始化
    dp[0][0] = 1;
    visited[0][0] = true;
    dp[mx][my] = 0;
    visited[mx][my] = true;

    for(int i=0; i<8; i++){
        int nx = mx + dx[i];
        int ny = my + dy[i];

        if(nx < 0 || nx >fx || ny < 0 || ny >fy)
            continue;
        
        visited[nx][ny] = true;

        dp[nx][ny] = 0;
    }

    for(int i=0; i<=fx; i++){
        for(int j=0; j<=fy; j++){
            if(!visited[i][j]){
                if(i>0)
                    dp[i][j] += dp[i-1][j];
                if(j>0)
                    dp[i][j] += dp[i][j-1];
            }
        }
    }
    cout << dp[fx][fy];
    return 0;
}
```
# 区间 DP

## 核心思想

定义：

```cpp
dp[l][r]
```

表示区间 `[l,r]` 的最优答案。

大区间通常依赖小区间，所以按区间长度从小到大枚举。

```cpp
for(int len=1; len<=n; len++){
    for(int l=1; l+len-1<=n; l++){
        int r=l+len-1;
    }
}
```

## 常见转移

### 两端选择

```cpp
dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
```

### 枚举分割点

把 `[l,r]` 分成：

```text
[l,k] 和 [k+1,r]
```

```cpp
for(int k=l; k<r; k++){
    dp[l][r] = min或max(
        dp[l][r],
        dp[l][k] + dp[k+1][r] + cost
    );
}
```

## 石子合并

```cpp
dp[l][r]
```

表示把 `[l,r]` 合并成一堆的最优得分。

区间和：

```cpp
sum = prefix[r] - prefix[l-1];
```

转移：

```cpp
dp[l][r] = min(
    dp[l][r],
    dp[l][k] + dp[k+1][r] + sum
);
```

初始化：

```cpp
dp[i][i] = 0;
```

求最小值时：

```cpp
dp[l][r] = INF;
```

## 环形处理

把数组复制一遍：

```cpp
a[i+n] = a[i];
```

最后枚举所有长度为 `n` 的区间：

```cpp
for(int i=1; i<=n; i++){
    ans = min或max(ans, dp[i][i+n-1]);
}
```

## 记忆

```text
状态：dp[l][r]
顺序：区间长度从小到大
转移：两端选择或枚举分割点
环形：复制数组
```
#### P1880 [[NOI1995] 石子合并](https://www.luogu.com.cn/problem/P1880 "[NOI1995] 石子合并")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int INF = 1e9;

int a[N];
int prefix[N];
int dpmax[N][N];    //dp[l][r]把第 l 堆到第 r 堆合并成一堆的最大得分。
int dpmin[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    //读取数据
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i+n] = a[i];    //复制一遍数组保证环形
    }

    //构造前缀和数组
    prefix[1] = a[1];
    for(int i=2; i<=2*n; i++){
        prefix[i] = prefix[i-1] + a[i];
    }

    //初始化
    for(int i=1; i<=2*n; i++){
        dpmax[i][i] = 0;
        dpmin[i][i] = 0;
    }

    //区间dp
    //首先列举长度
    for(int len=2; len<=n; len++){
        //列举左侧保证长度的前体现在数组内滑动
        for(int l=1; l+len-1<=2*n; l++){
            int r =  l+len-1;

            //区间dp初始化
            dpmin[l][r] = INF;

            //计算和
            int sum = prefix[r] - prefix[l-1];

            for(int k=l; k<r; k++){
                dpmax[l][r] = max(dpmax[l][r], dpmax[l][k]+dpmax[k+1][r]+sum);
                dpmin[l][r] = min(dpmin[l][r], dpmin[l][k]+dpmin[k+1][r]+sum);
            }
        }
    }

    int minans = INF;
    int maxans = 0;

    //列举1~n作为不同起点的最值
    for(int i=1; i<=n; i++){
        minans = min(minans, dpmin[i][i+n-1]);
        maxans = max(maxans, dpmax[i][i+n-1]);
    }

    cout << minans << endl;
    cout << maxans << endl;
    
    return 0;
}
```
#### P1063 [[NOIP 2006 提高组] 能量项链](https://www.luogu.com.cn/problem/P1063 "[NOIP 2006 提高组] 能量项链")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 205;
int dp[N][N];
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i+n] = a[i];    //复制数组从而形成环形
    }

    for(int len=2; len<=n; len++){
        for(int l=1; l+len-1<=2*n; l++){
            int r = l+len-1;

            for(int k=l; k<r; k++){  //注意k的截至位置是r
                dp[l][r] = max(dp[l][r], dp[l][k]+dp[k+1][r]+a[l]*a[k+1]*a[r+1]);
            }            
        }
    }

    int E = 0;
    for(int i=1; i<=n; i++){
        E = max(E, dp[i][i+n-1]);
    }
    cout << E;
    return 0;
}
```
#### P3146 [[USACO16OPEN] 248 G](https://www.luogu.com.cn/problem/P3146 "[USACO16OPEN] 248 G")（区间合并）
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 248 + 5;
int a[N];
int dp[N][N];    //dp[l][r]表示从l到r是否可以完全合并成一个数字，如果可以，那么是结果；不可以就是0

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i][i] = a[i];
        ans = max(ans, a[i]);    //初始化ans
    }

    //开始区间dp
    for(int len=2; len<=n; len++){
        for(int l=1; l+len-1<=n; l++){
            int r = l+len-1;

            for(int k=l; k<r; k++){    //区间划分
                if(dp[l][k]!=0 && dp[l][k] == dp[k+1][r]){
                    dp[l][r] = max(dp[l][r], dp[l][k]+1);
                }
            }
            ans = max(dp[l][r],ans);
        }
    }
    cout << ans;
    return 0;
}
```
#### P2858 [[USACO06FEB] Treats for the Cows G/S](https://www.luogu.com.cn/problem/P2858 "[USACO06FEB] Treats for the Cows G/S")
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> dq;

    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        dq.push_back(a);
    }

    int money = 0;
    for(int day=1; day<=n; day++){
        int front_val = dq.front();  // 获取队首
        int back_val  = dq.back();   // 获取队尾
        if(front_val < back_val){
            money += front_val*day;
            dq.pop_front();
        }else{
            money += back_val*day;
            dq.pop_back();
        }
    }

    cout << money;
    return 0;
}
```
你的代码用了贪心：

> 每天先卖两端价值较小的零食，把价值大的留到后面乘更大的天数。

这个想法很自然，但不一定最优，因为今天从哪一端取，会影响明天能露出哪个零食。

## 贪心反例

序列：

```
3 4 1 4
```

你的方法：

```
第1天：卖左边3，收入3
第2天：两端都是4，卖右边4，收入8
第3天：卖右边1，收入3
第4天：卖4，收入16

总收入 = 30
```

更优方案：

```
第1天：卖右边4，收入4
第2天：卖右边1，收入2
第3天：卖左边3，收入9
第4天：卖4，收入16

总收入 = 31
```

所以不能只根据当前两端大小决定。
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
int a[N];
int dp[N][N];    //dp[l][r]表示从第l个到第r个零食可以买到的最大价格
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i][i] = a[i] * n;    //初始化只剩一个的时候一定是在n天地的时候卖出去
    }

    //区间dp
    for(int len=2; len<=n; len++){
        for(int l=1; l+len-1<=n; l++){
            int r = l+len-1;

            int day = n-(r-l);

            dp[l][r] = max(dp[l+1][r]+day*a[l], dp[l][r-1]+day*a[r]);    //因为长区间的计算必须依赖短的区间，所以区间长度必须从小到大来列举
        }
    }
    cout << dp[1][n];
    return 0;
}
```
# 树形 DP

## 核心思想

定义：

```cpp
dp[u]
```

或：

```cpp
dp[u][0]
dp[u][1]
```

表示以节点 `u` 为根的子树中的最优答案。第二个数字本质上代表选择

父节点依赖子节点，所以用 DFS：

```cpp
void dfs(int u){
    for(int v : graph[u]){
        dfs(v);       //先计算子树
        //再用 dp[v] 更新 dp[u]
    }
}
```

## 没有上司的舞会

状态：

```cpp
dp[u][0] //u不参加时，u子树的最大快乐值
dp[u][1] //u参加时，u子树的最大快乐值
```

初始化：

```cpp
dp[u][0] = 0;
dp[u][1] = r[u];
```

转移：

```cpp
for(int v : graph[u]){
    dfs(v);

    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
}
```

原因：

```text
u参加：直接下属不能参加
u不参加：直接下属可参加，也可不参加
```

答案：

```cpp
max(dp[root][0], dp[root][1])
```

## 找根节点

输入 `l k` 表示 `k` 是 `l` 的上司：

```cpp
graph[k].push_back(l);
hasParent[l] = true;
```

没有父节点的节点就是根：

```cpp
if(!hasParent[i])
    root = i;
```

## 记忆

```text
状态：以 u 为根的子树答案
顺序：先儿子，后父亲
实现：DFS 回溯时转移
答案：通常在根节点
```
#### P1352 [没有上司的舞会](https://www.luogu.com.cn/problem/P1352 "没有上司的舞会")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 6e3 + 5;
int r[N];
vector<int> graph[N];    //采用邻接表的方式储存图
bool hasParent[N] = {false};
int dp[N][2];     //dp[u][0]表示u不参加时，以u为根的子树的最大快乐值；dp[u][1]表示u参加时，以u为根的子树的最大快乐值

void dfs(int u){
    //初始化dp
    dp[u][0] = 0;
    dp[u][1] = r[u];

    //遍历根
    for(int v:graph[u]){
        dfs(v);

        dp[u][0] += max(dp[v][0], dp[v][1]);    //u不参加的时候v可以参加也可以不参加
        dp[u][1] += dp[v][0]; 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    //读取快乐值
    for(int i=1; i<=n; i++)
        cin >> r[i];

    //建图
    for(int i=1; i<n; i++){
        int l,k;
        cin >> l >> k;

        hasParent[l] = true;

        graph[k].push_back(l);
    }

    //找根，必须从根（起点）开始dfs，使用dfs是因为根u依赖他的孩子v
    int root;
    for(int i=1; i<=n; i++){
        if(!hasParent[i]){
            root = i;
            break;
        }
    }

    dfs(root);

    cout << max(dp[root][0], dp[root][1]);
    return 0;
}
```

#### P2016 [[SEERC 2000] 战略游戏](https://www.luogu.com.cn/problem/P2016 "[SEERC 2000] 战略游戏")
```cpp
//这题本质是：在树上选择最少节点，使每条边至少有一个端点被选择，也就是树上的最小点覆盖。
#include<bits/stdc++.h>
using namespace std;

const int N = 1505;
int dp[N][2];    //dp[u][0]表示该点不放士兵，覆盖以u为根的子树中所有边的最少士兵数；dp[u][1]表示该点放士兵，覆盖以u为根的子树中所有边的最少士兵数
vector<int> graph[N];    //建立无向图，这里必须建立无向图才可以保证从任何节点出发都可以到达其他节点

void dfs(int u, int parent){
    //初始化
    dp[u][0] = 0;
    dp[u][1] = 1;

    for(int v : graph[u]){
        if(v == parent)    //防止重复无线递归
            continue;
        dfs(v, u);  //dfs无向图需要记录parent

        //u不放士兵那么v必须放
        dp[u][0] += dp[v][1];
        //u放士兵那么v可以放也可以不放
        dp[u][1] += min(dp[v][1], dp[v][0]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int u,k;
        cin >> u >> k;

        while(k--){
            int r;
            cin >> r;
            graph[u].push_back(r);
            graph[r].push_back(u);    //两次建立无向图
        }
    }

    //因为没有指定根，所以从任何节点开始都可以
    dfs(0,-1);

    cout << min(dp[0][0], dp[0][1]);
    return 0;
}
```
#### P1122 [最大子树和](https://www.luogu.com.cn/problem/P1122 "最大子树和")（DP树+最大子段和只保留正贡献的）
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 16005;
int a[N];
int dp[N];    //dp[u]表示以u为根的树的最大美丽值,u是必须要选择的
vector<int> graph[N];
const int NEG_INF = INT_MIN;

void dfs(int u, int parent){
    //初始化
    dp[u] = a[u];

    //遍历
    for(int v: graph[u]){
        if(v == parent)
            continue;

        dfs(v, u);

        dp[u] += max(0, dp[v]);    //保留所有具有正贡献的子树，有点像最大子段和思想
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    //建立图
    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    int ans = NEG_INF;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
```
#### P1273 [[CHCI 2002 Final Exam #2] 有线电视网](https://www.luogu.com.cn/problem/P1273 "[CHCI 2002 Final Exam #2] 有线电视网")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
vector<pair<int, int>> graph[N];    //图需要同时储存邻接节点和花费
int money[N];
int dp[N][N];    //dp[u][j]表示以u为根的子树链接j个用户的最大净利润
int cnt[N];    //记录当前节点的当前用户数量
const int NEG_INF = INT_MIN;
int n,m;

void dfs(int u){
    //u为用户节点时返回
    if(u>n-m){
        cnt[u] = 1;
        dp[u][0] = 0;
        dp[u][1] = money[u];
        return;
    }

    //转播站
    cnt[u] = 0;    //当前还没有合并子树
    dp[u][0] = 0;

    //开始合并子树
    for(auto edge: graph[u]){
        int v = edge.first;    //当前连接的子树
        int cost = edge.second;    //开通u-v的花费

        dfs(v);    //更新v以及以下的dp因为当层依赖下层

        //dp背包，倒序防止多选
        for(int j=cnt[u]; j>=0; j--){
            for(int k=1; k<=cnt[v]; k++){    //j不变，k从小到大更新
                dp[u][j+k] = max(dp[u][j+k], dp[u][j]+dp[v][k]-cost);    //jk要么不用这种方式达到，要么就用这种方式
            }              
        }  
        // v子树已经纳入考虑范围，更新当前可供选择的用户总数
        cnt[u] += cnt[v];    //因为你无论如何都需要合并一个子树
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    //输入传播站到节点的信息
    for(int i=1; i<=n-m; i++){
        int k;
        cin >> k;
        while(k--){
            int a,c;
            cin >> a >> c;
            graph[i].push_back({a, c});
        }
    }

    //读入用户的money
    for(int i=n-m+1; i<=n; i++){    //注意输入顺序和节点匹配
        cin >> money[i];
    }

    //初始化
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++)
            dp[i][j] = NEG_INF;
    }

    dfs(1);

    for(int i=m; i>=0; i--){
        if(dp[1][i] >= 0){
            cout << i;
            break;
        }       
    }
    return 0;
}
```
#### P2014 [[CTSC1997] 选课](https://www.luogu.com.cn/problem/P2014 "[CTSC1997] 选课")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 305;
const int NEG_INF = -300;
vector<pair<int, int>> graph[N];
int dp[N][N];    //dp[u][j]表示以u为根的子树中选择j个课程的最大学分
int cnt[N];     //cnt[u]表示已经合并到u的部分中最多有多少课程可以选择
int s[N];    //直接记录学分
int n,m;

void dfs(int u){
    //初始化
    if(u!=0){
        dp[u][0] = 0;
        dp[u][1] = s[u];
        cnt[u] = 1;
    }else{
        dp[u][0] = 0;
        cnt[u] = 0;
    }

    //开始合并子树
    for(auto edge:graph[u]){
        int v = edge.first;

        //先处理子树
        dfs(v);

        int start = (u == 0 ? 0 : 1);    //虚拟根需要0但是非虚拟根不可以有0；所以在循环的时候需要判断清楚
        for(int j=min(cnt[u],m); j>=start; j--){
            for(int k=1; k<=cnt[v] && k+j<=m; k++){
                dp[u][k+j] = max(dp[u][k+j], dp[u][j]+dp[v][k]);
            }
        }
        
        cnt[u] += cnt[v];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        int k,score;
        cin >> k >> score;
        graph[k].push_back({i,score});
        s[i] = score;
    }

    //dp初始化,注意设置一个为0的虚拟根，方便dfs
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = NEG_INF;
        }
    }

    dfs(0);

    cout << dp[0][m];
    
    return 0;
}
```
#### P2585 [[ZJOI2006] 三色二叉树](https://www.luogu.com.cn/problem/P2585 "[ZJOI2006] 三色二叉树")
```cpp
#include<bits/stdc++.h>
using namespace std;

struct State{//表示节点的状态对应不同颜色的最大绿色数目（包含以该节点为根的子树）
    int maxdp[3];    
    int mindp[3];
};

struct Node{
    int need;    //需要的子节点
    int cnt;    //现在有的子节点
    State child[2];
};

const int INF = 1e9;

State calculate(Node node){
    State current;

    //列举三种颜色
    for(int color=0; color<3; color++){
        int add = (color == 0);

        current.maxdp[color] = -INF;
        current.mindp[color] = INF;

        //叶子节点
        if(node.need == 0){
            current.maxdp[color] = add;
            current.mindp[color] = add;
        }
        //一个孩子
        else if(node.need == 1){
            for(int leftcolor=0; leftcolor<3; leftcolor++){
                if(leftcolor == color)
                    continue;
                current.maxdp[color] = max(current.maxdp[color],add+node.child[0].maxdp[leftcolor]);
                current.mindp[color] = min(current.mindp[color],add+node.child[0].mindp[leftcolor]);
            }
        }
        //两个孩子
        else if(node.need == 2){
            for(int leftcolor=0; leftcolor<3; leftcolor++){
                for(int rightcolor=0; rightcolor<3; rightcolor++){
                    if(leftcolor == rightcolor)
                        continue;
                    if(rightcolor == color)
                        continue;
                    if(leftcolor == color)
                        continue;

                    current.maxdp[color] = max(current.maxdp[color], add+node.child[0].maxdp[leftcolor]+node.child[1].maxdp[rightcolor]);
                    current.mindp[color] = min(current.mindp[color], add+node.child[0].mindp[leftcolor]+node.child[1].mindp[rightcolor]);
                }
            }
        }
    }
    return current;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    //由于是先序遍历，所以使用栈
    vector<Node> st;
    st.reserve(s.size());

    State root;    //根节点的状态

    for(char ch : s){
        //当前处理节点的初始化
        Node node;
        node.need = ch - '0';
        node.cnt = 0;

        st.push_back(node);
        //当处理完子树的时候，就可以处理当前节点,并且一直处理到没有为止，方便ch接下一个位置
        while(!st.empty() && st.back().need == st.back().cnt){
            State current = calculate(st.back());
            st.pop_back();

            //栈空说明处理完成
            if(st.empty()){
                root = current;    //找到根
            }else{
                st.back().child[st.back().cnt++]  = current;    //当前节点是上一个节点的孩子
            }
        }
    }

    int minAns = INF;
    int maxAns = -INF;

    for(int i=0; i<3; i++){
        minAns = min(minAns, root.mindp[i]);
        maxAns = max(maxAns, root.maxdp[i]);
    }

    cout << maxAns << ' ' << minAns;
    
    return 0;
}
```
#### P1044 [[NOIP 2003 普及组] 栈](https://www.luogu.com.cn/problem/P1044 "[NOIP 2003 普及组] 栈")
可以dp栈模拟，也可以看作图表示再i=j这一条线的限制之下，从(0,0)到(n,n)方法数
```cpp
#include<bits/stdc++.h>
using namespace std;

long long dp[20][20];//dp[i][j]表示入栈i个元素出栈j个元素的合法方案数

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    //dp初始化
    dp[0][0] = 1;

    //状态转移
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(i<n)    //还有元素可以入栈
                dp[i+1][j] += dp[i][j];
            if(j<i)    //还有元素可以出栈
                dp[i][j+1] += dp[i][j];
        }
    }
    cout << dp[n][n];
    return 0;
}
```
```cpp
#include<bits/stdc++.h>
using namespace std;

long long dp[20][20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 什么操作都没做时，有一种空方案
    dp[0][0] = 1;

	//网格的每一个点都要扫描并且注意边界处理
    // i：已经入栈的数量
    for(int i=0; i<=n; i++){

        // j：已经出栈的数量
        // 合法状态必须满足 j <= i
        for(int j=0; j<=i; j++){

            // (0,0)已经初始化，不需要重新计算
            if(i == 0 && j == 0){
                continue;
            }

            // 从左边来：
            // (i-1,j) 再进行一次入栈，到达 (i,j)
            if(i > 0){
                dp[i][j] += dp[i-1][j];
            }

            // 从下边来：
            // (i,j-1) 再进行一次出栈，到达 (i,j)
            if(j > 0){
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    cout << dp[n][n];

    return 0;
}
```