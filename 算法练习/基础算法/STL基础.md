#### P1093 [[NOIP 2007 普及组] 奖学金](https://www.luogu.com.cn/problem/P1093 "[NOIP 2007 普及组] 奖学金")
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Student{
    int total;
    int chinese;
    int math;
    int eng;
    int id;
};
vector<Student> student;

bool cmp(Student& x, Student& y){
    if(x.total != y.total){
        return x.total < y.total;
    }
    if(x.chinese != y.chinese){
        return x.chinese < y.chinese;
    }
    if(x.id != y.id){
        return x.id > y.id;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    
    for(int i=1; i<=n; i++){
        int c,m,e;
        cin >> c >> m >> e;

        int to = c + m + e;

        student.push_back({to,c,m,e,i});
    }

    sort(student.begin(), student.end(), cmp);

    int cnt = 1;
    while(!student.empty() && cnt <= 5){
        Student current = student.back();
        student.pop_back();

        cout << current.id << " " << current.total << "\n";

        cnt++;
    }
    return 0;
}
```
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<tuple<int, int, int>> student;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int c,m,e;
        cin >> c >> m >> e;
        int total = c + m + e;
        student.push_back({-total, -c, i});    //因为tuple默认升序排列
    }

    sort(student.begin(), student.end());

    for(int i=0; i<5; i++){
        int total = -get<0>(student[i]);
        int id = get<2>(student[i]);
        cout << id << " " << total << "\n";
    }
    return 0;
}
```

### set用于排序+去重
#### P1059 [[NOIP 2006 普及组] 明明的随机数](https://www.luogu.com.cn/problem/P1059 "[NOIP 2006 普及组] 明明的随机数")
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> st;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        st.insert(a);
    }

    cout << st.size() << endl;
    for(auto i:st)
        cout << i << " ";
    return  0;
}
```
###### unique + sort 实现数组的排序和去重
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio;
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());    //先进行排序

    a.erase(unique(a.begin(), a.end()), a.end());    //进行去重

    cout << a.size() << endl;

    for(size_t i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}
```

### mp相关操作
#### P5266 [【深基17.例6】学籍管理](https://www.luogu.com.cn/problem/P5266 "【深基17.例6】学籍管理")
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> mp;

    int n;
    cin >> n;

    while(n--){
        int op;
        cin >> op;

        if(op == 1){
            string name;
            int score;
            cin >> name >> score;

            auto f = mp.find(name);

            if(f == mp.end()){
                mp.insert(make_pair(name, score));  //插入操作
            }else{
                mp[name] = score;  //查询操作
            }
            cout << "OK" << endl;
        }
        else if(op == 2){
            string name;
            cin >> name;

            auto f = mp.find(name);

            if(f == mp.end()){
                cout << "Not found" << endl;
            }
            else{
                cout << mp[name] << endl;
            }
        }else if(op == 3){
            string name;
            cin >> name;

            auto f = mp.find(name);

            if(f == mp.end()){
                cout << "Not found" << endl;
            }
            else{
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            }
        }
        else if(op == 4){
            cout << mp.size() << endl;
        }
    }
    return 0;
}
```
### 操作2：查询

不能直接写：

```
cout << mp[name];
```

因为如果 `name` 不存在，`mp[name]` 会自动创建它，并把成绩初始化为 `0`。
可以使用unordered_map
#### P1918 [保龄球](https://www.luogu.com.cn/problem/P1918 "保龄球")（关键是识别map）
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> mp;

    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        mp.insert(make_pair(x, i));
    }

    int q;
    cin >> q;
    while(q--){
        int m;
        cin >> m;
        auto f = mp.find(m);
        if(f == mp.end())
            cout << 0 << endl;
        else
            cout << f->second << endl;
    }
    return 0;
}
```
#### P1102[A-B 数对](https://www.luogu.com.cn/problem/P1102 "A-B 数对")（巧妙使用lower和upper bound）
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N=2e5 + 5;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,c;
    cin >> n >> c;

    for(int i=1; i<=n; i++) cin >> a[i];

    sort(a+1, a+n+1);

    long long ans = 0;
    
    for(int i=1; i<=n; i++){
        int target = a[i] + c;
        int left = lower_bound(a+1, a+n+1, target) - a;
        int right = upper_bound(a+1, a+n+1, target) - a;
        ans += right - left;
    }

    cout << ans;

    return 0;
}
```

#### P3405 [[USACO16DEC] Cities and States S](https://www.luogu.com.cn/problem/P3405 "[USACO16DEC] Cities and States S")(双pair)
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<pair<string, string>, int> cnt;

    long long ans = 0;
    
    while(n--){
        string cityname, citycode;
        cin >> cityname >> citycode;

        cityname = cityname.substr(0,2);

        //排除相同的州
        if(cityname == citycode)
            continue;

        ans += cnt[{citycode, cityname}];

        cnt[{cityname, citycode}]++;    //自动创建并且计数
        
    }
    cout << ans;
    return 0;
}
```
##### P3613 [【深基15.例2】寄包柜](https://www.luogu.com.cn/problem/P3613 "【深基15.例2】寄包柜")
map的复合键值的使用make_pair
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    map<pair<int, int>, int> mp;
    
    while(q--){
        int op;
        cin >> op;

        if(op == 1){
            int i,j,k;
            cin >> i >> j >> k;

            if(k != 0){
                mp.insert({make_pair(i,j),k});
            }else{
                mp.erase(make_pair(i,j));
            }
        }else if(op == 2){
            int i,j;
            cin >> i >> j;
            cout << mp[make_pair(i,j)] << "\n";
        }
        
    }
    return 0;
}
```
- 方法二
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vector<map<int, int>> box(n+1);
    
    while(q--){
        int op;
        cin >> op;

        if(op == 1){
            int i,j,k;
            cin >> i >> j >> k;

            box[i][j] = k;
            
        }else if(op == 2){
            int i,j;
            cin >> i >> j;
            cout << box[i][j] << "\n";
        }
        
    }
    return 0;
}
```
### Stack
#### P4387 [【深基15.习9】验证栈序列](https://www.luogu.com.cn/problem/P4387 "【深基15.习9】验证栈序列")
采用双指针思想，当遇见toped元素就出栈
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        vector<int> pushed(n);
        vector<int> poped(n);

        for(int i=0; i<n; i++){
            cin >> pushed[i];
        }
        for(int i=0; i<n; i++){
            cin >> poped[i];
        }

        stack<int> st;

        int j=0;
        for(int i=0; i<n; i++){
            st.push(pushed[i]);

            while(!st.empty() && j<n && poped[j] == st.top()){
                st.pop();
                j++;
            }
        }

        if(j == n){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
```
#### P1981 [[NOIP 2013 普及组] 表达式求值](https://www.luogu.com.cn/problem/P1981 "[NOIP 2013 普及组] 表达式求值")
防止溢出处处MOD
```cpp
#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e4;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> op;    //符号栈
    stack<long long> num;    //数字栈

    for(size_t i=0; i<s.size();){
        if(s[i] >= '0' && s[i] <='9'){
            int j=i;
            while(j < s.size() && s[j] >= '0' && s[j] <='9') j++;
            int len = j-i;
            string temp = s.substr(i,len);
            long long x = stoll(temp)%MOD;
            num.push(x);
            i=j;

            if(!op.empty() && op.top() == '*'){
                long long a = num.top();
                num.pop();
                long long b = num.top();
                num.pop();

                long long ans = (b*a)%MOD;
                num.push(ans);

                op.pop();

            }
        }else if(s[i] == '+'){
            op.push(s[i]);
            i++;
        }else if(s[i] == '*'){
            op.push(s[i]);
            i++;           
        }
    }

    while(!op.empty()){
        long long a = num.top();
        num.pop();
        long long b = num.top();
        num.pop();

        long long ans = (a+b)%MOD;

        num.push(ans);
        op.pop();
    }
    
    cout << num.top()%MOD;
    return 0;
}
```
#### P1175 [表达式的转换](https://www.luogu.com.cn/problem/P1175 "表达式的转换")
```cpp
#include<bits/stdc++.h>
using namespace std;

int getPriority(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^' )
        return 3;
    return 0;
}

//使用快速幂运算 base^exponent。使用pow(base, esponent)为浮点数可能产生精度误差
//奇数就乘以答案，底数每轮平方，指数每轮减半
long long fastPower(long long base, long long exponent){
    long long result = 1;

    while(exponent > 0){
        if(exponent % 2 == 1){
            result *= base;
        }

        base *= base;
        exponent /= 2;
    }

    return result;
}

//实现数学意义上的向下取整除法
long long floorDivide(long long a, long long b){
    long long result = a/b;
    long long remainder = a % b;

    if(remainder != 0 && ((a<0) != (b<0)))
        result--;

    return result;
}

long long calculate(long long a, long long b, char op){
    if(op == '+')
        return a+b;
    if(op == '-')
        return a-b;
    if(op == '*')
        return a*b;
    if(op == '/')
        return floorDivide(a,b);
    return fastPower(a,b);
}

bool isOperator(const string& token){
    return token=="+"||token=="-"||token=="*"||token=="/"||token=="^";
}

void PrintExpression(const vector<string>& expression){
    for(size_t i=0; i<expression.size(); i++){
        if(i>0)
            cout << ' ';
        cout << expression[i];
    }    
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> op;
    vector<string> expression;    //保存后缀表达式，之所以使用string而不是char是因为后续计算结果可能是多位数或者是负数

    //第一阶段：把中缀表达式转化成后缀表达式
    for(size_t i=0; i<s.size(); i++){
        char current = s[i];

        //情况1：当前字符是数字
        if('0' <= current && current <= '9'){
            expression.push_back(string(1, current));
        }

        //情况2：当前字符是左括号,直接压入运算符栈，用于阻止括号外的运算符影响括号内部。
        else if(current == '('){
            op.push(current);
        }

        //情况3：当前字符是右括号
        else if(current == ')'){
            while(!op.empty() && op.top()!='('){
                expression.push_back(string(1, op.top()));
                op.pop();
            }
            op.pop();    //删除左括号
        } 
        //情况4：当前字符是普通运算符
        else{
            while(!op.empty() && op.top() != '('){
                int topPriority = getPriority(op.top());
                int currentPriority = getPriority(current);

                if(topPriority > currentPriority){
                    expression.push_back(string(1, op.top()));
                    op.pop();
                }

                else if(topPriority == currentPriority && current != '^'){
                    expression.push_back(string(1, op.top()));
                    op.pop();
                }
                else{
                    break;
                }
            }
            op.push(current);
        }
    }

    //整个中缀表达式扫描结束后，运算符栈可能还要没有输出的运算符，按照栈顶到栈底顺序，全部加入后缀表达式
    while(!op.empty()){
        expression.push_back(string(1, op.top()));
        op.pop();
    }

    //第一阶段：输出完整的后缀表达式
    PrintExpression(expression);

    //第二阶段逐步计算后缀表达式
    while(expression.size() > 1){
        //每完成一次运算后，vector的长度和下标都会发生变化,因此每次都重新从头寻找第一个运算符
        for(int i=0; i<(int)expression.size(); i++){
            if(!isOperator(expression[i]))
                continue;

            long long a = stoll(expression[i-2]);
            long long b = stoll(expression[i-1]);

            char currentOp = expression[i][0];

            long long result = calculate(a, b, currentOp);

            expression[i-2] = to_string(result);

            expression.erase(expression.begin()+i-1, expression.begin()+i+1);    //删除从[expression.begin()+i-1, expression.begin()+i+1)所有元素

            PrintExpression(expression);

            //vector已经发生变化，原来的下标不可靠，立即退出本次for循环，回到while，重新从头寻找运算符

            break;
        }     
    }
    return 0;
}
```
## 1. `string` 的这种构造方式

```
string(数量, 字符)
```

表示创建一个包含若干个相同字符的字符串。

### Queue
##### P2058 [[NOIP 2016 普及组] 海港](https://www.luogu.com.cn/problem/P2058 "[NOIP 2016 普及组] 海港")
随时维护ans，不用每一次都扫描统计一遍，以person而不是ship为单位
```cpp
//不是扫描船，而是扫描人的思路
#include<bits/stdc++.h>
using namespace std;

struct Person{
    int time;
    int nation;
};

const int N = 1e5 + 5;
const int T = 86400;

int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<Person> person;

    int ans=0;
    while(n--){
        int t,k;
        cin >> t >> k;

        while(k--){
            int x;
            cin >> x;

            person.push({t,x});

            if(cnt[x] == 0)
                ans++;
            
            cnt[x]++;
        }

        while(!person.empty() && person.front().time <= t-T){
            int x = person.front().nation;
            person.pop();

            cnt[x]--;

            if(cnt[x]==0)
                ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
```
### Priority_queue(优先队列)
##### P2085 [最小函数值](https://www.luogu.com.cn/problem/P2085 "最小函数值")
```cpp
#include<bits/stdc++.h>
using namespace std;
//小根堆＋3路归并的解法
struct Node{
    int value;    //记录值方便比较
    int id;    //记录当前来自于第几个函数
    int x;    //判断当前的x方便出队之后入x+1

    bool operator < (const Node& other) const{
        return value > other.value;
    }
};

const int N = 10005;

int getValue(int A, int B, int C, int x){
    return(A * x * x + B * x + C);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A[N];
    int B[N];
    int C[N];

    int n,m;
    cin >> n >> m;

    priority_queue<Node> q;
    
    for(int i=1; i<=n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        q.push({getValue(a,b,c,1), i, 1});
    }

    for(int i=1; i<=m; i++){
        Node current = q.top();
        q.pop();

        cout << current.value << ' ';

        int c_id = current.id;

        q.push({getValue(A[c_id], B[c_id], C[c_id], current.x+1),c_id, current.x+1});
        
    }
    return 0;
}
```
#### P1168 [中位数](https://www.luogu.com.cn/problem/P1168 "中位数")
两个优先队列，一个存放大的一半，另外一个存放小的一半，这样的话可以不用排序直接输出。
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> daq; //大根堆
    priority_queue<int, vector<int>, greater<int>> xiaoq;    //小根堆

    for(int i=1; i<=n; i++){
        int x;
        cin >> x;

        //判断x应该加入哪里,先保证 左边小于右边
        if(daq.empty() || x <= daq.top()){
            daq.push(x);
        }else{
            xiaoq.push(x);
        }

        //调整数量
        //只有两种情况可以跳出循环，注意这里判断条件的书写方法
        while(!(daq.size() == xiaoq.size() || daq.size() == xiaoq.size()+1)){
            if(daq.size() > xiaoq.size()+1){
                xiaoq.push(daq.top());
                daq.pop();
            }else if(daq.size() < xiaoq.size()){
                daq.push(xiaoq.top());
                xiaoq.pop();
            }
        }

        //输出相关答案
        if(i%2 == 1)
            cout << daq.top() << '\n';
    }
    return 0;
}
```