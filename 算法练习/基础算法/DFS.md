# DFS（深度优先搜索）

## 1. 什么是 DFS

> 从一个状态开始，不断向更深层搜索，直到无法继续，再返回上一层继续搜索。

特点：

- 一条路走到底
- 不能继续时回退
- 穷举所有可能方案

---

## 2. DFS 与回溯

DFS：负责搜索。

回溯：递归返回时恢复现场，继续尝试其它方案。

经典流程：

```text
做选择
    ↓
递归
    ↓
撤销选择（回溯）
```

---

## 3. DFS 适用题型

- 全排列
- 组合
- 子集
- 八皇后
- 迷宫搜索
- 连通块统计
- 路径搜索

关键词：

```text
所有方案
所有可能
是否存在
统计方案数
```

---

## 4. DFS 模板

```cpp
void dfs(状态){

    if(终止条件){
        更新答案;  //达到了终止条件再更新答案
        return;
    }

    for(所有可选方案){ //列举所有可以选择的方案

        if(不能选择)
            continue;

        // 做选择

        dfs(下一状态);

        // 撤销选择（回溯）
    }
}
```

---

## 5. 回溯模板

```cpp
// 做选择
used[i] = true;

// 进入下一层
dfs(...);

// 撤销选择
used[i] = false;
```

恢复现场是回溯的核心。

---

## 6. 常见状态设计

### 当前答案

```cpp
int path[N];
```

记录当前方案。

---

### 是否访问过

```cpp
bool used[N];
```

适用于：

- 全排列
- 图搜索
- 网格搜索

---

### 四方向数组

```cpp
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
```

适用于：

- 迷宫
- 连通块
- 岛屿问题
#### P1605 [迷宫](https://www.luogu.com.cn/problem/P1605 "迷宫")
```cpp
#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int sx, sy, fx, fy;
const int N = 5+5;
bool visited[N][N] = {false};
int ans = 0;
int dx[4] = {-1, 1, 0, 0};  //注意此时角标就从0开始的
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y){
    //终止条件是到达了中点
    if(x == fx && y == fy){
        ans++;
        return;
    }

    //列举所有可能的情况
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        //如果选择不到
        if(nx < 1 || nx > n || ny < 1 || ny > m)
            continue;
        if(visited[nx][ny])
            continue;

        visited[nx][ny] = true;
        dfs(nx, ny);
        visited[nx][ny] = false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;

    cin >> sx >> sy >> fx >> fy;

    for(int i=1; i<=t; i++){
        int a, b;
        cin >> a >> b;
        visited[a][b] = true; //直接将障碍物设置成已经访问过的之后就不可以访问了
    }

    visited[sx][sy] = true;
    dfs(sx, sy);

    cout << ans;
    return 0;
}
```

---

## 7. DFS 三要素

### ① 当前状态

例如：

```cpp
dfs(step)
```

表示：

> 当前正在处理第 step 层。

---

### ② 终止条件

例如：

```cpp
if(step > n)
    return;
```

到达叶子结点。

---

### ③ 状态转移

枚举下一步所有可能：

```cpp
for(...)
```

进入下一层：

```cpp
dfs(...)
```

---

## 8. 回溯为什么必须恢复现场

例如：

```text
1 _
```

第二个位置先放：

```text
2
```

递归结束后必须：

```cpp
used[2] = false;
```

否则后面的方案：

```text
1 3
2 1
3 1
```

都无法搜索。

---

## 9. DFS 与 BFS

| DFS | BFS |
|------|------|
| 深度优先 | 广度优先 |
| 递归 / 栈 | 队列 |
| 找所有方案 | 找最短路径 |
| 需要回溯 | 一般不回溯 |

---

## 10. 时间复杂度

一般取决于：

```text
搜索树大小
```

例如：

- 全排列：`O(n!)`
- 子集：`O(2^n)`
- 组合：`O(C(n,k))`

---

## 11. DFS 做题流程

```text
分析状态
    ↓
确定递归参数
    ↓
写终止条件
    ↓
枚举下一状态
    ↓
做选择
    ↓
递归
    ↓
回溯
```

---

## 12. 常见易错点

- 忘记写 `return`
- 忘记恢复现场
- `used` 没有恢复
- 数组越界
- 递归参数写错
- 终止条件错误

---

## 13. 一句话总结

> DFS = 做选择 → 递归 → 回溯，通过搜索树遍历所有可能方案。

### 典型例题

#### P1706 [全排列问题](https://www.luogu.com.cn/problem/P1706 "全排列问题")
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 9+5;
int path[N];  //表示当前层的路径
int used[N];  //标记当前元素是否被使用过
int n;

void dfs(int step){
    //如果路径长了，终止条件
    if(step > n){
        for(int i=1; i<=n; i++)
            cout << setw(5) << path[i];
        cout << "\n";
        return;
    }

    //否则对每一个数字枚举
    for(int i=1; i<=n; i++){
        //不能选择那么就continue
        if(used[i])
            continue;
        
        //做选择
        path[step] = i;  //当前步选i
        
        used[i] = 1;

		//dfs搜索
        dfs(step+1);  //搜索下一步
		
		//状态恢复
        used[i] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dfs(1);
    
    return 0;
}
```

#### P1036 [[NOIP 2002 普及组] 选数](https://www.luogu.com.cn/problem/P1036 "[NOIP 2002 普及组] 选数")
```cpp
#include<bits/stdc++.h>
using namespace std;

int n,k;
const int N = 20 + 5;
int x[N];

long long ans = 0;

bool is_prime(int sum){
    if(sum <= 1) return false;
    if(sum == 2) return true;
    if(sum % 2 == 0) return false;

    for(int i=3; i<=sqrt(sum); i+=2){
        if(sum % i == 0) return false;
    }
    return true;
}

void dfs(int start, int cnt, int sum){
    //终止条件
    if(cnt == k){
        if(is_prime(sum)) ans++;
        return;
    }

    for(int i=start; i<=n; i++){
        dfs(i+1,cnt+1,sum+x[i]);  //值传递所以不用回溯
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    
    for(int i=1; i<=n; i++)
        cin >> x[i];

    int sum=0;
    dfs(1,0,sum);

    cout << ans;
    
    return 0;
}
```
#### P1162 [填涂颜色](https://www.luogu.com.cn/problem/P1162 "填涂颜色")（边界开始遍历 && 并没有显式终止条件）
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
int matrix[N][N];
bool visited[N][N] = {false};
int n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

//从边界0出发，将所有边界0可以到达的地方认为是圈外，其余地方认为是圈内 ，从外部Flood Fill
void dfs(int x, int y)
{
    //遍历类型没有显式终止条件
    visited[x][y] = true;

    //列举所有情况
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        //无法选择
        if(nx < 1 || nx > n || ny < 1 || ny > n)
            continue;
        if(visited[nx][ny])
            continue;
        if(matrix[nx][ny])
            continue;

        dfs(nx, ny);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> matrix[i][j];

    //存在多个起点：为0的边界 都是起点
    for(int i=1; i<=n; i++){
        if(!matrix[i][1])
            dfs(i, 1);
        if(!matrix[1][i])
            dfs(1, i);
        if(!matrix[n][i])
            dfs(n, i);
        if(!matrix[i][n])
            dfs(i, n);
    }

    //输出
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j]){
                cout << matrix[i][j] << " ";
            }else if(!visited[i][j] && matrix[i][j] == 0){
                cout << "2" << " ";
            }else if(!visited[i][j] && matrix[i][j] == 1){
                cout << "1" << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
```
这个题目也可以用BFS完成
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 30 + 5;
int matrix[N][N];
bool visited[N][N] = {false};
int n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

//从边界0出发，将所有边界0可以到达的地方认为是圈外，其余地方认为是圈内 ，从外部Flood Fill
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> matrix[i][j];
        }
    }
    
    queue<pair<int, int>> q;  //状态队列

    //队列初始化
    for(int i=1; i<=n; i++){
        if(!matrix[1][i] && !visited[1][i]){
            q.push({1, i});
            visited[1][i] = true;
        }
        if(!matrix[n][i] && !visited[n][i]){
            q.push({n, i});
            visited[n][i] = true;
        }
        if(!matrix[i][1] && !visited[i][1]){
            q.push({i, 1});
            visited[i][1] = true;
        }
        if(!matrix[i][n] && !visited[i][n]){
            q.push({i, n});
            visited[i][n] = true;
        }
    }

        while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //列举所有情况
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n)  //先进行这个条件的判断从而防止越界
                continue;
            if(visited[nx][ny])
                continue;
            if(matrix[nx][ny] == 1)
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!visited[i][j] && matrix[i][j] == 0){
                cout << "2" << " ";
            }else{
                cout << matrix[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
```

#### P1451 [求细胞数量](https://www.luogu.com.cn/problem/P1451 "求细胞数量")（用dfs来对所有连通区域上色）
```cpp
#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N = 105;
int matrix[N][N];
int ans = 0;
bool visited[N][N] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y){
    //每有一块连通区域时，ans++    
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(nx < 1 || nx > n || ny < 1 || ny > m)
            continue;
        if(visited[nx][ny])
            continue;
        if(matrix[nx][ny] == 0)
            continue;

        dfs(nx,ny);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            cin >> c;
            if(c == '0')
                matrix[i][j] = 0;
            else
                matrix[i][j] = 1;
        }
    }

    //dfs的目的是对于连通的区域全部上色
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!visited[i][j] && matrix[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}
```