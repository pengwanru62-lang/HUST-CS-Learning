#### P4779 [【模板】单源最短路径（标准版）](https://www.luogu.com.cn/problem/P4779 "【模板】单源最短路径（标准版）")
##### 题目描述

给定一个 $n$ 个点，$m$ 条有向边的带非负权图，请你计算从 $s$ 出发，到每个点的距离。

数据保证你能从 $s$ 出发到任意点。

##### 输入格式

第一行为三个正整数 $n, m, s$。
第二行起 $m$ 行，每行三个非负整数 $u_i, v_i, w_i$，表示从 $u_i$ 到 $v_i$ 有一条权值为 $w_i$ 的有向边。

##### 输出格式

输出一行 $n$ 个空格分隔的非负整数，表示 $s$ 到每个点的距离。

##### 输入输出样例 #1

##### 输入 #1

```
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
```

##### 输出 #1

```
0 2 4 3
```

##### 说明/提示

样例解释请参考 [数据随机的模板题](https://www.luogu.com.cn/problem/P3371)。

$1 \leq n \leq 10^5$；

$1 \leq m \leq 2\times 10^5$；

$s = 1$；

$1 \leq u_i, v_i\leq n$；

$0 \leq w_i \leq 10 ^ 9$,

$0 \leq \sum w_i \leq 10 ^ 9$。
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int to;
    int weight;
};

const int N = 1e5 + 5;
const int INF = 1e9 + 5;

vector<Edge> graph[N];
long long dist[N]; //表示从起点s到i的最短距离

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    //进行建图
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});    //注意此处是push_back
    }

    //距离初始化最开始视为最大
    for(int i=1; i<=n; i++)
        dist[i] = INF;

    //优先队列初始化，要使用优先队列因为每次要选出最小的作为中转站
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    dist[s] = 0;
    q.push({0,s});

    while(!q.empty()){
        long long distance = q.top().first;
        int id = q.top().second;
        q.pop();

        //过期数据处理，因为过期数据并没有被弹出
        if(distance != dist[id])
            continue;

        //松弛操作所有数据，但是操作的需要是所有从id到的边
        for(const Edge& edge : graph[id]){    //注意这种书写方式
            int To = edge.to;
            int W = edge.weight;

            if(dist[To] > dist[id] + W){
                dist[To] = dist[id] + W;
                q.push({dist[To], To});    
            }
        }
    } 

    for(int i=1; i<=n; i++)
        cout << dist[i] << " ";
    return 0;
}
```
#### P1339 [[USACO09OCT] Heat Wave G](https://www.luogu.com.cn/problem/P1339 "[USACO09OCT] Heat Wave G")（注意区分这个地方是无向图）
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 2505;
const int INF = 1e10; 
struct Edge{
    int to;
    int weight;
};
vector<Edge> graph[N];
long long dist[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s,t;
    cin >> n >> m >> s >> t;

    //进行图的建立
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    //距离初始化
    for(int i=1; i<=n; i++)
        dist[i] = INF;

    //队列初始化
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    dist[s] = 0;
    q.push({0,s});

    while(!q.empty()){
        long long distance = q.top().first;
        int u = q.top().second;
        q.pop();

        //过期数据处理
        if(dist[u] != distance)
            continue;

        for(Edge& edge: graph[u]){
            int To = edge.to;
            int W = edge.weight;

            if(dist[To] > dist[u] + W){
                dist[To] = dist[u] + W;
                q.push({dist[To], To});
            }
        }
    }

    cout << dist[t];
    return 0;
}
```


#### P1828 [[USACO3.2] 香甜的黄油 Sweet Butter](https://www.luogu.com.cn/problem/P1828 "[USACO3.2] 香甜的黄油 Sweet Butter")(多起点Dikjstra)
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 805;
const int INF = 1e6;
int cow[N];
int dist[N];    //起点到i的最短距离
struct Edge{
    int to;
    int weight;
};

vector<Edge> graph[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,p,c;
    cin >> n >> p >> c;

    //记录奶牛
    for(int i=1; i<=n; i++){
        cin >> cow[i];
    }

    //建图
    while(c--){
        int u,v,d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        //无向图
        graph[v].push_back({u, d});
    }


    //列举所有的地方看哪个路径和最短
    int ans = INF+1;
    for(int i=1; i<=p; i++){
        int s = i;    //以i作为起点

        //距离初始化
        for(int i=1; i<=p; i++)
            dist[i] = INF;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        dist[s] = 0;
        q.push({0, s});
        while(!q.empty()){
            int distance = q.top().first;
            int u = q.top().second;
            q.pop();

            //处理过期部分
            if(distance != dist[u])
                continue;

            //处理u可达的每一个地方
            for(Edge& edge : graph[u]){
                int v = edge.to;
                int d = edge.weight;

                if(dist[v] > dist[u] + d){
                    dist[v] = dist[u] + d;
                    q.push({dist[v], v});
                }
            }
        }
        int current = 0;
        for(int j=1; j<=p; j++){
            current += dist[cow[j]];
        }
        ans = min(ans, current);
    }
    cout << ans;
    return 0;
}
```