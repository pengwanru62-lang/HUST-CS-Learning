#### P3366 [【模板】最小生成树](https://www.luogu.com.cn/problem/P3366 "【模板】最小生成树")(结合并查集判读连通性)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
};//无向图可以这样保存，之后遍历边就可以求解相关内容
bool cmp(const Edge& x, const Edge& y){
    return x.w < y.w;
}

const int M = 2e5 + 5;

Edge edge[M];

const int N = 5005;
int parent[N];

int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y){
    int root_x = find(x);
    int root_y = find(y);

    if(root_x != root_y){
        parent[root_x] = root_y;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        edge[i].u = x;
        edge[i].v = y;
        edge[i].w = z;
    }

    //将边按照权值排序便于后面依次选择边
    sort(edge+1, edge+m+1, cmp);    //升序

    //利用并查集判断是否连通
    //初始化
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    int ans = 0;
    int cnt = 0;
    //遍历每一条边
    for(int i=1; i<=m; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        if(find(u) != find(v)){
            ans+=w;
            cnt++;
            merge(u,v);
        }

        if(cnt == n-1)
            break;
    }
    cout << ans;
    return 0;
}
```
#### P1546 [[USACO3.1] 最短网络 Agri-Net](https://www.luogu.com.cn/problem/P1546 "[USACO3.1] 最短网络 Agri-Net")
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
};
const int N = 1e4 + 5;
Edge edge[N];

bool cmp(const Edge& x, const Edge& y){
    return x.w < y.w;
}

const int M = 105;
int parent[M];

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    int root_x = find(x);
    int root_y = find(y);

    if(root_x != root_y)
        parent[root_x] =  root_y;    //注意此处是 root_x而不是x防止并查集树的混乱
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    //建立图
    int cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int z;
            cin >> z;

            if(j > i){
                edge[++cnt].u = i;
                edge[cnt].v = j;
                edge[cnt].w = z;
            }
        }
    }

    sort(edge+1, edge+cnt+1, cmp);    //升序排列

    for(int i=1; i<=n; i++)
        parent[i] = i;

    int cnt2 = 0;
    int ans = 0;
    for(int i=1; i<=cnt; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;

        if(find(u) != find(v)){
            cnt2++;
            ans+=w;
            merge(u,v);
        }

        if(cnt2 == n-1)
            break;
    }
    cout << ans;
}
```

#### P2872 [[USACO07DEC] Building Roads S](https://www.luogu.com.cn/problem/P2872 "[USACO07DEC] Building Roads S")
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Coordinate{
    int x;
    int y;
};

struct Edge{
    int u;
    int v;
    double w;
};

const int N = 1005;
Coordinate crd[N];
int parent[N];
vector<Edge> edges;

bool cmp(const Edge& x, const Edge& y){
    return x.w < y.w;
}//有名函数必须使用花括号

int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y){
    int root_x = find(x);
    int root_y = find(y);

    if(root_x == root_y)
        return false;
    
    parent[root_x] = root_y;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        crd[i].x = x;
        crd[i].y = y;
        parent[i] = i;
    }

    int components = n;
    //先merge，相当于边的权为0
    for(int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        if(merge(u,v))    //必须是贡献的有效边
            components--;
    }

    //计算距离并存放在数组中
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){    //防止计算重复边
            long long dx = 1LL * crd[i].x - crd[j].x;
            long long dy = 1LL*crd[i].y - crd[j].y;
            double distance = sqrt(1.0*dx*dx + 1.0*dy*dy);
            edges.push_back({i, j, distance});    //需要这样因为不仅需要判断distance还要记录防止成环
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    //统计长度
    double ans = 0;
    for(Edge edge: edges){
        if(components == 1)
            break;

        if(merge(edge.u, edge.v)){
            ans+=edge.w;
            components--;
        }
    }
    
    cout << fixed << setprecision(2) << ans;
    return 0;
}
```
## 1. 优先队列不能只存距离

你现在存的是：

```
priority_queue<double, vector<double>, greater<double>> q;
```

只有边长，没有保存这条边连接哪两个点。

取出最短距离后，你无法知道：

```
这条边的两个端点是谁
是否会形成环
应该合并哪两个集合
```

Kruskal 中必须存完整边：

```cpp
struct Edge{
    int u;
    int v;
    double w;
};
```

然后优先队列或数组中保存 `Edge`。
## 2. 不能取出最短边后直接累加

你现在：

```
ans += q.top();
q.pop();
cnt++;
```

没有判断这条边的两个端点是否已经连通。

Kruskal 必须判断：

```
if(find(u) == find(v))
    continue;
```

否则可能选择形成环的边，答案不一定最小。

## 3. `cnt = m` 是错误的

你读入每条已有道路时都：

```
cnt++;
```

但已有的 `m` 条边不一定都对连通块合并有贡献。

例如已有：

```
1-2
2-3
1-3
```

共有三条边，但第三条已经形成环，只进行了两次有效合并。

更推荐维护：

```
int components = n;
```

每次成功合并两个不同集合：

```
merge(u, v);
components--;
```

当：

```
components == 1
```

说明全部连通。

## 4. 枚举边时避免重复

你现在：

```
for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
```

会同时加入：

```
1-2
2-1
```

同一条无向边被存两次。

应写：

```
for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
```
## 5. 输出需要保留两位小数

应写：

```
cout << fixed << setprecision(2) << ans;
```
