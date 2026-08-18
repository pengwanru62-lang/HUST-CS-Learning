# BFS（广度优先搜索）

## 1. 什么是 BFS

> 从起点开始，一层一层向外扩展，直到搜索完所有能够到达的状态。

特点：

- 按层搜索
- 先近后远
- 使用队列（FIFO）

---

## 2. BFS 适用题型

关键词：

```text
最少步数
最短距离
最少操作
无权图最短路
```

常见题型：

- 迷宫最短路
- 棋盘搜索
- 最少操作次数
- 图最短路（边权均为1）

---

## 3. 为什么使用队列

队列特点：

```text
先进先出（FIFO）
```

保证搜索顺序：

```text
距离0
  ↓
距离1
  ↓
距离2
  ↓
距离3
```

因此：

> BFS 第一次到达某个状态，就是最短距离。

---

## 4. 状态设计

### 队列

保存当前状态。

例如棋盘：

```cpp
queue<pair<int,int>> q;
```

保存：

```text
(x,y)
```

---

### 距离数组

```cpp
int dist[N][N];
```

含义：

```text
dist[i][j]
```

表示：

> 起点到 `(i,j)` 的最短距离。

初始化：

```cpp
memset(dist,-1,sizeof(dist));
```

其中：

```text
-1
```

表示：

> 尚未访问。

---

## 5. BFS 基本流程

```text
起点入队
        ↓
队列非空
        ↓
取出队首
        ↓
枚举下一状态
        ↓
判断是否合法
        ↓
更新状态
        ↓
新状态入队
```

---

## 6. BFS 模板

```cpp
queue<State> q;

初始化 dist 为 -1

dist[start] = 0;
q.push(start);

while(!q.empty()){

    State cur = q.front();
    q.pop();

    for(所有下一状态){

        if(不能走)
            continue;

        if(已经访问)
            continue;

        dist[next] = dist[cur] + 1;

        q.push(next);
    }
}
```

---

## 7. 网格 BFS 模板

方向数组：

```cpp
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
```

主体：

```cpp
while(!q.empty()){

    auto [x,y]=q.front();
    q.pop();

    for(int i=0;i<4;i++){

        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<1||nx>n||ny<1||ny>m)
            continue;

        if(dist[nx][ny]!=-1)
            continue;

        dist[nx][ny]=dist[x][y]+1;

        q.push({nx,ny});
    }
}
```

---

## 8. DFS 与 BFS

| DFS | BFS |
|------|------|
| 深度优先 | 广度优先 |
| 递归 / 栈 | 队列 |
| 搜索所有方案 | 最短路径 |
| 先走到底 | 一层一层扩展 |

---

## 9. 常见易错点

- 忘记 `q.pop()`
- 起点没有入队
- 起点距离没有初始化
- 没有判断越界
- 已访问状态再次入队
- `dist` 更新错误（应为 `dist[cur] + 1`）

---

## 10. BFS 做题流程

```text
识别题型（最短路、最少操作）
        ↓
设计状态
        ↓
建立队列
        ↓
初始化起点
        ↓
循环取队首
        ↓
枚举下一状态
        ↓
合法性判断
        ↓
更新距离
        ↓
入队
```

---

## 11. 时间复杂度

设：

- 顶点数：`V`
- 边数：`E`

时间复杂度：

```text
O(V+E)
```

网格搜索中：

```text
O(n×m)
```

因为每个格子最多入队一次。

---

## 12. 一句话总结

> BFS 使用队列按层扩展，第一次到达某个状态时得到的就是最短距离，因此常用于求无权图最短路和最少操作次数。

#### P1443 [马的遍历](https://www.luogu.com.cn/problem/P1443 "马的遍历")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 400 + 5;
int dist[N][N]; //dist[i][j]表示从起点到这个位置需要走多少路径。这个不是-1时就表示已经到达过一次了，所以最短。
int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};//状态转移，马有8种走法
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,sx,sy;
    cin >> n >> m >> sx >> sy;

    queue<pair<int, int>> q; //队列存放的是位置

    //距离初始化
    memset(dist, -1, sizeof(dist));

    //起点初始化
    dist[sx][sy] = 0;
    q.push({sx, sy});

    //队列非空的时候就一直走
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //对当前元素列举所有可能的情况
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //如果不可以选择那么continue
            if(nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if(dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;    //更新长度
            q.push({nx, ny});    //新到的位置入队
        }
    }

    //输出答案
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

#### P1135 [奇怪的电梯](https://www.luogu.com.cn/problem/P1135 "奇怪的电梯")(一维BFS)
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 205;
int k[N];
int dist[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    for(int i=1; i<=n; i++)
        cin >> k[i];

    //状态队列
    queue<int> q;

    //dist数组初始化
    memset(dist, -1, sizeof(dist));

    //初始起点入队
    q.push(a);
    dist[a] = 0;    //起点到起点应该是0

    //对每种情况分析，看哪个先到
    while(!q.empty()){
        int current = q.front();
        q.pop();

        //结束条件到达目标楼层
        if(current == b){
            cout << dist[current];
            return 0;
        }

        //列举每种可能的情况
        for(int i=1; i<=2; i++){
            int next;
            if(i == 1) next = current + k[current];
            if(i == 2) next = current - k[current];

            //判断是否可选
            if(next < 1 || next > n)
                continue;
            if(dist[next]!=-1)
                continue;

            dist[next] = dist[current] + 1;
            q.push(next);
        }
    }
    cout << -1;
    return 0;
}
```
#### P1141 [01迷宫](https://www.luogu.com.cn/problem/P1141 "01迷宫")
```cpp
#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N = 1005;
const int MAX_SIZE = 1e6 + 5;
int a[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int id[N][N];    //表示对应位置的编号
int block_size[MAX_SIZE];  //表示相应编号的最大连通面积

void bfs(int sx, int sy, int block_id){
    queue<pair<int, int>> q;

    q.push({sx, sy});

    id[sx][sy] = block_id;

    int cnt = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cnt++;
        
        //列举所有可能的情况
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if(id[nx][ny])    //用id标记是否被处理
                continue;
            if(a[nx][ny] == a[x][y])
                continue;

            q.push({nx, ny});
            id[nx][ny] = block_id;
        }
    }
    block_size[block_id] = cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c;
            cin >> c;
            if(c == '0')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }

    int block_id = 0;

    //对每一个元素进行涂色＋区域划分处理，每一个连通的区域相互可达
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!id[i][j]){
                block_id++;  //更新block_id每一个新的区域
                bfs(i, j, block_id);
            }
        }
    }

    //处理m次查询
    while(m--){
        int x, y;
        cin >> x >> y;
        cout << block_size[id[x][y]] << endl;
    }
    
    return 0;
}
```