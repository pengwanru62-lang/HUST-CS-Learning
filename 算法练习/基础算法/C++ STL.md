## 1.Vector

`vector`是可变长数组，可以随时添加和删除元素。

>注意：在局部区域中（比如局部函数里面）开**vector数组**，是在**堆空间**里面开的。
>在局部区域开**数组**是在**栈空间**开的，而栈空间比较小，如果开了非常长的数组就会发生爆栈。
   故局部区域不可以开大长度数组，但是**可以开大长度`vector`**。

- 头文件
```cpp
#include <vector>
```

- 初始化
```cpp
vector<int> a;  //定义一个名为a的一维数组，数组储存int数据类型
vector<double> b;  //定义一个名为b的一维数组，数组储存double数据类型
vector<node> c; //定义一个名为c的一维数组，数组储存结构体数据类型，node是结构体类型
```
指定长度和初始值的初始化
```cpp
vector<int> v(n);  //定义一个长度为n的int类型数组，数组长度为n，下标范围[0,n-1]
vector<int> v(n,1); //所有元素初始化为1
```
初始化中有多个元素
```cpp
vector<int> a{1, 2, 3, 4, 5};
```
拷贝初始化
```cpp
vector<int> a(n+1, 0);
vector<int> b(a); //拷贝初始化，b与a相同
vector<int> c=a;  //c与a相同
```

- 二维初始化
```cpp
vector<int> v[5] //行不可变只有5行，列可变可以在指定行增添元素
```
可以进行如下操作
```cpp
v[1].push_back(2); //将2加入到v[1]末尾
v[3].push_back(3);
```
行列均可变化
```cpp
vector<vector<int>> v;
```
相关应用
```cpp
vector<int> t1{1,2,3,4};
vector<int> t2{2,3,4,5};
v.push_back(t1);
v.push_back(t2);
v.push_back({3,4,5,6});
//可以在v数组中组装多个数组
```
行列长度均固定 `n + 1`行 `m + 1`列初始值为0
```cpp
vector<vector<int>> a(n+1, vector<int>(m+1,0)); 
```
定义模板类的对象时，可以不指定模板参数，但是必须要在构造函数中可以推导出模板参数
```cpp
vector a{1,2,3};  //可以推测出是int类型
vector b(n+1, vector(m+1,0));
```

- 函数总结

|               代码                | 算法复杂度  | 返回值类型 |                                     含义                                     |
| :-----------------------------: | :----: | :---: | :------------------------------------------------------------------------: |
|           `c.front()`           | $O(1)$ |  引用   |                                返回容器中的第一个数据                                 |
|           `c.back()`            | $O(1)$ |  引用   |                                返回容器中的最后一个数据                                |
|           `c.at(idx)`           |        |  引用   |            返回 `c[idx]` ，会进行边界检查，如果越界会报错，比直接使用 `[]` 更好一些，常在项目中使用            |
|           `c.size()`            | $O(1)$ |       |                            返回实际数据个数（unsigned类型）                            |
|           `c.begin()`           | $O(1)$ |  迭代器  |                            返回首元素的迭代器（通俗来说就是地址）                             |
|            `c.end()`            | $O(1)$ |  迭代器  |                            返回尾元素的迭代器（通俗来说就是地址）                             |
|           `c.empty()`           | $O(1)$ | bool  |                             判断是否为空，为空返回真，反之返回假                             |
|         `c.reserve(sz)`         |        |       |    为数组提前分配`sz`的内存大小，即改变了 `capacity` 的大小，主要是为了防止在 `push_back` 过程中多次的内存拷贝    |
|    **`c.assign(beg, end)`**     |        |       |                 将另外一个容器`[x.begin(), x.end())` 里的内容拷贝到`c`中                  |
|       `c.assign(n, val)`        |        |       | 将`n` 个`val`值拷贝到`c`数组中，这会**清除掉容器中以前的内容**，`c`数组的`size`将变为`n`，`capacity` 不会改变 |
|         `c.pop_back()`          | $O(1)$ |       |                                  删除最后一个数据                                  |
|       `c.push_back(elem)`       | $O(1)$ |       |                                  在尾部加一个数据                                  |
|      `c.emplace_back(ele)`      | $O(1)$ |       |          在数组中加入一个数据，和 `push_back` 功能基本一样，在某些情况下比它效率更高，支持传入多个构造参数           |
|           `c.clear()`           | $O(N)$ |       |                                 清除容器中的所有元素                                 |
|        `c.resize(n, v)`         |        |       |                   改变数组大小为`n`,`n`个空间数值赋为`v`，如果没有默认赋值为`0`                    |
|       `c.insert(pos, x)`        | $O(N)$ |       |                            向任意迭代器`pos`插入一个元素`x`                            |
| 例：`c.insert(c.begin() + 2, -1)` |        |       |                              将`-1`插入`c[2]`的位置                              |
|     `c.erase(first, last)`      | $O(N)$ |       |                           删除`[first, last)`的所有元素                           |
>注意：`end()`返回的**是最后一个元素的后一个位置的地址**，不是最后一个元素的地址，所有STL容器均是如此。

>使用 **vi.resize(n, v)** 函数时，若 vi 之前指定过大小为 pre
	pre > n ：即数组大小变小了，数组会保存前 n 个元素，前 n 个元素值为原来的值，不是都为 v
	pre < n ：即数组大小变大了，数组会在后面插入 n - pre 个值为 v 的元素
	**也就是说，这个初始值 v 只对新插入的元素生效**。

```cpp
#include<bits/stdc++.h>
using namespace std;
void out(vector<int> &a) {for (auto &x:a) cout << x << " "; cout << "\n";}
int main(){
	vector<int> a(5, 1);
	out(a);// 1 1 1 1 1
	
	a.resize(10, 2);
	out(a);// 1 1 1 1 1 2 2 2 2 2
	
	a.resize(3, 2);
	out(a);// 1 1 1
	
	return 0;
}
```

- 使用sort排序需要：`sort(c.begin(), c.end());`
对所有元素进行排序，如果要对指定区间进行排序，可以对sort()里面的参数进行加减改动
```cpp
vector<int> a(n+1);
sort(a.begin()+1, a.end()); //对[1,n]区间进行从小到大排序
```

- 元素访问

1. 下标法,和普通数组一样
```cpp
//添加元素 
for(int i=0; i<5; i++)
{
	v.push_back(i);
}
//下标访问
for(int i=0; i<5; i++)
{
	cout << v[i] << " ";
}
cout << "\n";
```
2. 迭代器法
```cpp
vector<int> a{1, 2, 3, 4};
vector<int> ::iterator it;
//相当于声明了一个指针变量it
//通俗来说就是声明了一个指针变量
```

```cpp
//方式1
vector<int>::iterator it = begin();
for(int i=0; i<5; i++)
	cout << *(it+i) << " ";
cout << "\n";
```
```cpp
//方式2
vector<int>::iterator it;
for(it = a.begin(); it!=a.end(); it++)
	cout << *it << " ";
cout << "\n";
```
```cpp
//方式3
auto it = a.begin();
while(it != a.end()){
	cout << *it << "\n";
	it++;
}
```
3. 智能指针
**只能遍历完数组**，如果要指定的内容进行遍历，需要另选方法。
auto可以自动识别并且获取类型
```cpp
//输入
vector<int> a(n);
for(auto &x: a){
	cin >> x;
}

//输出
vector<int> v;
v.push_back(12);
v.push_back(241);
for(auto val: v)
	cout << val << " ";
```

- vector内存拷贝机制
`vector` 里面有两个变量 `size` （指数组实际长度大小）和 `capacity`（指数组分配的内存空间容量大小）。
存在机制：当长度大于容量时，vector会自动进行扩容。
扩容规则为：vector会重新开辟新的内存空间（大小为原来的capacity的2倍），原来的vector中存储内容先**copy**到新的地址空间中，然后销毁原来的地址空间。
>所以每次push_back进去一个元素，内存空间copy到新的空间中，vector会进行自动扩容，原来地址空间销毁。这种操作可以进行，但是**地址空间的copy占用一定的时间，效率变低**，尽量不要用。

一个减少内存拷贝的思路是：使用reserve提前分配固定的空间大小
```cpp
const int N = 1e6 + 5;
//方式1
vector<int> a;
a.reserve(N);
//方式2
vector<int> b(N);
```

## 2.Set

set容器中元素**不会重复**，当插入集合中已有的元素时，并不会插入进去，而且set容器里的元素自动**从小到大排序**。

- 头文件
```cpp
#include<set>
```
- 初始化定义
```cpp
set<int> s;
```
- 拷贝初始化
```cpp
set<int> a = {1, 2, 5};
set<int> b(a);
set<int> c=a;
```

- 函数方法

|         代码          |    复杂度    |                      含义                       |
| :-----------------: | :-------: | :-------------------------------------------: |
|     `s.begin()`     |  $O(1)$   |             返回set容器的第一个元素的地址（迭代器）             |
|      `s.end()`      |  $O(1)$   |           返回set容器的最后一个元素的下一个地址（迭代器）           |
|    `s.rbegin()`     |  $O(1)$   |             返回逆序迭代器，指向容器元素最后一个位置              |
|     `s.rend()`      |  $O(1)$   |            返回逆序迭代器，指向容器第一个元素前面的位置             |
|     `s.clear()`     |  $O(N)$   |              删除set容器中的所有的元素,无返回值              |
|     `s.empty()`     |  $O(1)$   |                  判断set容器是否为空                  |
| `s.insert(element)` | $O(logN)$ |                    插入一个元素                     |
|     `s.size()`      |  $O(1)$   |                返回当前set容器中的元素个数                |
|  `erase(iterator)`  | $O(logN)$ |               删除定位器iterator指向的值               |
| `erase(first, end)` |           |             删除定位器first和second之间的值             |
| `erase(key_value)`  | $O(logN)$ |                删除键值key_value的值                |
|  `s.find(element)`  |           |      查找set中的某一元素，有则返回该元素对应的迭代器，无则返回结束迭代器      |
| `s.count(element)`  |           | 查找set中的元素出现的个数，由于set中元素唯一，此函数相当于查询element是否出现 |
| `s.lower_bound(k)`  | $O(logN)$ |               返回大于等于k的第一个元素的迭代器               |
| `s.upper_bound(k)`  | $O(logN)$ |                返回大于k的第一个元素的迭代器                |

- 元素访问

1. 迭代器访问
```cpp
for(set<int>::iterator it = s.begin(); it!=end(); it++)
	cout << *it << " ";
```
2. 智能指针
```cpp
for(auto i: s)
	cout << i << " ";
```
3. 访问最后一个元素
```cpp
//第一种 
cout << *s.rbegin() << endl;
//第二种
set<int>::iterator it = s.end;
it--;
cout << (*it) << endl;
//第三种
cout << *(--s.end()) << endl;
```

- 重载运算符<
- 基础数据类型
1. 方式1：改变set排序规则，set中默认使用less比较器，即从小到大排序
```cpp
set<int> s1;  //默认从小到大
set<int, greater<int> > s2;  //从大到小
```
2. 方式2：重载运算符（很麻烦，不太常用，没必要）
3. 初始化时使用匿名函数定义比较规则
```cpp
set<int, function<bool(int,int)> > s([&](int i, int j)){
			return i > j;//从大到小
}  
//function<bool(int,int)>，其中function是比较函数，（int， int）是传参类型，bool是返回值。[&](int i, int j){ return i > j; }是一个lambda表达式
//[&]：以引用方式捕获外部变量（这里虽然没有捕获任何变量，但可以这么写）
//(int i, int j)：两个参数
//return i > j;：当i > j时返回true，表示i排在j前面
```

- 高级数据类型（结构体）
```cpp
struct Point {
	int x, y;
	bool operator < (const Point &p) const {
		// 按照点的横坐标从小到大排序,如果横坐标相同,纵坐标从小到大
		if(x == p.x)
			return y < p.y;
		return x < p.x;
	}
};
set<Point> s;
for(int i = 1; i <= 5; i++) {
    int x, y;
    cin >> x >> y;
    s.insert({x, y});
}	
/* 输入
5 4
5 2
3 7
3 5
4 8
*/

for(auto i : s)
    cout << i.x << " " << i.y << "\n";
/* 输出
3 5
3 7
4 8
5 2
5 4
*/
```

- multiset
`multiset` ：元素**可以重复**，且元素**有序**
1. 方法函数基本和 `set` 一样，参考set即可。
2. 进行删除操作时，要明确删除目标。（ `s` 为声明的multiset变量名）
	1. 删除多个元素：由于元素可以重复，注意使用 `s.erase(val)` 方法时，会删除掉所有与 `val` 相等的元素
	2. - 删除一个元素：需要删除一个元素时，需要使用 `s.erase(s.find(val))` 操作，先找到一个与 `val` 相等的元素迭代器，专门删除这个元素
3. 头文件操作为`#include<set>`
4. `unordered_set` ：元素无序且只能出现一次
5. `unordered_multiset` ：元素无序可以出现多次

## 3.map

映射类 似于函数的对应关系，每个`x`对应一个`y`，而`map`是每个键对应一个值。

容器中的每个储存对为一个键值对，包含两个元素（键和值）

- 头文件
```cpp
#include<map>
```
- 初始化
```cpp
//初始化定义
map<string, string>mp;
map<string, int>mp;
map<int, node>mp;  //node是结构体类型
```
>map会按照键的顺序**从小到大自动排序**，**键的类型必须可以比较大小。**

- 函数方法

|           代码           |                                         含义                                          |       复杂度       |
| :--------------------: | :---------------------------------------------------------------------------------: | :-------------: |
|     `mp.find(key)`     | 返回键为key的映射的迭代器 注意：用find函数来定位数据出现位置，它返回一个迭代器。当数据存在时，返回数据所在位置的迭代器，数据不存在时，返回`mp.end()` |    $O(logN)$    |
|     `mp.erase(it)`     |                                     删除迭代器对应的键和值                                     |    $O(logN)$    |
|    `mp.erase(key)`     |                                     根据映射的键删除键和值                                     |    $O(logN)$    |
| `mp.erase(first,last)` |                                  删除左闭右开区间迭代器对应的键和值                                  | $O(last−first)$ |
|      `mp.size()`       |                                       返回映射的对数                                       |     $O(1)$      |
|      `mp.clear()`      |                                     清空map中的所有元素                                     |     $O(N)$      |
|     `mp.insert()`      |                                   插入元素，插入时要构造键值对                                    |    $O(logN)$    |
|      `mp.empty()`      |                              如果map为空，返回true，否则返回false                               |     $O(1)$      |
|      `mp.begin()`      |                                返回指向map第一个元素的迭代器（地址）                                 |     $O(1)$      |
|       `mp.end()`       |                           返回指向map尾部的迭代器（最后一个元素的**下一个**地址）                           |     $O(1)$      |
|     `mp.rbegin()`      |                                返回指向map最后一个元素的迭代器（地址）                                |     $O(1)$      |
|      `mp.rend()`       |                            返回指向map第一个元素前面(上一个）的逆向迭代器（地址）                            |     $O(1)$      |
|    `mp.count(key)`     |                         查看元素是否存在，因为map中键是唯一的，所以存在返回1，不存在返回0                         |    $O(logN)$    |
|   `mp.lower_bound()`   |                              返回一个迭代器，指向键值>= key的第一个元素                               |                 |
|   `mp.upper_bound()`   |                               返回一个迭代器，指向键值> key的第一个元素                               |                 |
- 查找元素是否存在时，可以使用 ① `mp.find()` ② `mp.count()` ③ `mp[key]`  
但是第三种情况，如果不存在对应的`key`时，会自动创建一个键值对（产生一个额外的键值对空间）  
所以为了不增加额外的空间负担，最好使用前两种方法。

- 迭代器进行正反向遍历
```cpp
//用于正向遍历map
map<int, int> mp;
mp[1] = 2;
mp[2] = 3;
mp[3] = 4;
auto it = mp.begin();
while(it!=mp.end()){
		cout << it->first << it->second << "\n";//first是指key，second是指value。
	it++;
}
//输出
/*
1 2
2 3
3 4
*/
```
迭代器用于逆向遍历map
```cpp
map<int, int> mp;
mp[1] = 2;
mp[2] = 3;
mp[3] = 4;
auto it = mp.rbegin();
while(it != mp.rend()){
	cout << it->first << it->second << "\n";
	it++;  //注意是反向迭代器，所以这里使用it++而不是--
}
```
- 二分查找
二分查找`lower_bound() upper_bound()`
>map的二分查找以第一个(first)元素(即key为准),对**key**进行二分查找**返回值为map迭代器**类型。

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int, int> m{{1, 2}, {2, 2}, {1,2}, {8, 2}, {6, 2}};
	map<int, int>::iterator it1 = m.lower_bound(2);
	cout << it1->first << "\n";//it1->first=2
	
	map<int, int>::iterator it2 = m.upper_bound(2);
	cout << it2->first << "\n";//it2->first=6
	return 0;
}
```
- 添加元素
```cpp
//先声明
map<string, string> mp;

//方式一
mp["学习"] = "看书";
mp["玩耍"] = "打游戏";

//方式二
mp.insert(make_pair("vegetable", "蔬菜"));

//方式三
mp.insert(pair<string, string>("fruit","水果"));
mp.insert(pair<string,string>("zoo","动物园"));

//方式四
mp.insert({"hahaha","wawawa"});
```
- 访问元素
```cpp
mp[1] = 2;
cout << mp[1] << "\n";

//1.迭代器访问
map<string, string>::iterator it;
for(it = mp.begin(); it != mp.end(); it++){
	cout << it->first << " " << it->second << "\n";// it是结构体指针访问所以要用 -> 访问
	cout << (*it).first << " " << (*it).second << "\n";//*it是结构体变量 访问要用 . 访问 cout<<(*it).first<<" "<<(*it).second;
}

//2.智能指针访问
for(auto i : mp){
	cout << i.first << i.second << endl;
}

/*
auto it = mp.begin();其中it是指针
auto i:mp这时i是元素本身
*/

//3.对指定元素进行访问
map<int, int>::iterator it = mp.find('a');
cout << it->first << " " << it->second << "\n";

//4.
for(auto[x, y] : mp)
	cout << x << " " << y << "\n";
//x,y对应键和值
```

- 与unordered_map的比较

**map**：内部用**红黑树**实现，具有**自动排序**（按键从小到大）功能。
**unordered_map**：内部用**哈希表**实现，内部元素无序杂乱。

map：
优点：内部用红黑树实现，内部元素具有有序性，查询删除等操作复杂度为O(logN)
缺点：占用空间，红黑树里每个节点需要保存父子节点和红黑性质等信息，空间占用较大。

unordered_map：
优点：内部用哈希表实现，查找速度非常快（适用于大量的查询操作）。
缺点：建立哈希表比较耗时。


两者方法函数基本一样，差别不大。


> [!Tip] 注意
> 
注意：
随着内部元素越来越多，两种容器的插入删除查询操作的时间都会逐渐变大，效率逐渐变低。
使用[]查找元素时，如果元素不存在，两种容器都是创建一个空的元素；如果存在，会正常索引对应的值。所以如果查询过多的不存在的元素值，容器内部会创建大量的空的键值对，后续查询创建删除效率会大大降低。
查询容器内部元素的最优方法是：先判断存在与否，再索引对应值（适用于这两种容器）

```cpp
// 以 map 为例
map<int, int> mp;
int x = 999999999;
if(mp.count(x)) // 此处判断是否存在x这个键
    cout << mp[x] << "\n";   // 只有存在才会索引对应的值，避免不存在x时多余空元素的创建
```

- 自定义hash函数
```cpp
// 使用 lambda 表达式来定义哈希函数
auto hash_pair = [](const std::pair<int, int>& p) -> std::size_t {
    static hash<long long> hash_ll;
    return hash_ll(p.first + (static_cast<long long>(p.second) << 32));
};

// 使用 lambda 表达式作为哈希函数定义 unordered_map, 10为桶的数量
std::unordered_map<std::pair<int, int>, int, decltype(hash_pair)> my_map(10, hash_pair);
```

## 4.栈

- 头文件
```cpp
#include<stack>
```
- 声明
```cpp
stack<int> s;
stack<string> s;
stack<node> s;  //node是结构体类型
```

- 方法函数

|        代码         |       含义       |  复杂度   |
| :---------------: | :------------: | :----: |
| `s.push(element)` | 元素`ele`入栈，增加元素 | $O(1)$ |
|     `s.pop()`     |     移除栈顶元素     | $O(1)$ |
|     `s.top()`     |  取得栈顶元素（但不删除）  | $O(1)$ |
|    `s.empty()`    |  检测栈内是否为空，空为真  | $O(1)$ |
|    `s.size()`     |   返回栈内元素的个数    | $O(1)$ |

- 栈遍历
栈智能对栈顶元素进行操作，如果想要进行遍历，只能将栈中元素一个个取出来存在数组中
```cpp
stack<int> st;
for(int i = 0; i<10; i++) st.push(i);

while(!st.empty()){  //栈的终止条件是判断是不是空
	int  tp = st.top();
	st.pop();
}
```
- 数组模拟栈进行遍历
通过一个数组对栈进行遍历，一个存放下标的变量top模拟指向栈顶指针。（ 比`STL`的`stack`速度更快，遍历元素方便）

```cpp
int s[100]; //栈 从左到右为栈底到栈顶
int tt = -1;//初始值为-1

for(int i=0; i<=5; i++){
	s[++tt] = i; //入栈
}

int top_element = s[tt--];//出栈
```

## 5. 队列

队列是一种先进先出的数据结构。

- 头文件
```cpp
#include <queue>
```
- 定义初始化
```cpp
queue<int> q;
```
- 方法函数

|       代码        |              含义               | 时间复杂度  |
| :-------------: | :---------------------------: | :----: |
|    q.front()    |            返回队首元素             | $O(1)$ |
|    q.back()     |            返回队尾元素             | $O(1)$ |
| q.push(element) |     尾部添加一个元素`element` 进队      | $O(1)$ |
|     q.pop()     |          删除第一个元素 出队           | $O(1)$ |
|    q.size()     | 返回队列中元素个数，返回值类型`unsigned int` | $O(1)$ |
|    q.empty()    |     判断是否为空，队列为空，返回`true`      | $O(1)$ |
- 队列模拟

使用q[]数组模拟队列
hh:表示队首元素的下标，初始值为0
tt:表示队尾元素的下标，初始值为-1，表示队列刚开始为空

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	int hh = 0, tt = -1;
	q[++tt] = 1;
	q[++tt] = 2;
	
	while(hh<=tt){
		int t = q[hh++];
		cout << t << endl;
	}
	return 0;
}
```

## 6.优先队列 priority_queue

优先队列是在正常队列的基础上加了优先级，保证每一次的队首元素都是优先级最大的。
可以实现每次从优先队列中取出的元素都是队列中**优先级最大**的一个。
它的底层是通过**堆**来实现的。

- 头文件 
```cpp
#include<queue>
```
- 初始化定义
```cpp
priority_queue<int> q;
```
- 函数方法(和栈而不是队列的函数方法相似)

| 代码             | 含义         | 时间复杂度   |
| -------------- | ---------- | ------- |
| q.top()        | 访问队首元素     | O(1)    |
| q.push()       | 入队         | O(logN) |
| q.pop(element) | 堆顶（队首）元素出队 | O(logN) |
| q.size()       | 队列元素个数     | O(1)    |
| q.empty()      | 是否为空       | O(1)    |
| 注意没有clear      | 不提供该方法     |         |
- 设置优先级
- 基本数据类型的优先级
```cpp
priority_queue<int> pq;  //默认大根堆，即每次取出的元素都是队列里面的最大值
priority_queue<int, vector<int>, greater<int>> q;  //小根堆，每次取出的元素都是队列里面的最小值
```
参数解释：

1. 第一个参数：就是优先队列里面储存的数据结构类型
2. 第二个参数：存的是什么类型就写什么对应的类型
3. 第三个参数：`less<int>` 表示数字大的优先级大，堆顶为最大的数字  
			 `greater<int>`表示数字小的优先级大，堆顶为最小的数字  
			 **int代表的是数据类型，也要填优先队列中存储的数据类型**

- 自定义排序，不常见主要是因为写起来比较麻烦
```cpp
struct cmp1{
	bool operator ()(int x, int y){
		return x > y;
	}
};
struct cmp2{
	bool operator()(const int x, const int y){
		return x < y;
	}
};
priority_queue<int, vector<int>, cmp1> q1; //小根堆
priority_queue<int, vector<int>, cmp2> q2; // 大根堆
```

- 高级数据类型（结构体）的优先级

>即优先队列中存储结构体类型，必须要设置优先级，即结构体的比较运算（因为优先队列的堆中要比较大小，才能将对应最大或者最小元素移到堆顶）。

优先级设置可以定义在结构体内进行小于号重载，也可以定义在结构体外
```cpp
struct Point {
	int x, y;
};

//版本一：自定义全局比较规则
struct cmp{
	bool operator ()(const Point& a, const Point& b){
		return a.x < b.x;
	}
}
priority_queue<Point, vector<Point>, cmp> q;

//版本二：直接在结构体里面写
//方式1
struct Point{
	int x, y;
	friend bool operator  < (Point a, Point b){//两个结构体参数，结构体调用上一定要写friend
		return a.x < b.x;
	}
};
//方式二
struct Point{
	int x,y;
	bool operator < (const Point& a) const{//前一个const保证参数a不被修改，后一个const保证当前对象（this）在函数内部不会被修改。
		return x < a.x;
	}
};

//优先队列定义
priority_queue<Point> q;
```
>先队列自定义排序规则和`sort()`函数定义`cmp`函数很相似，但是最后返回的情况是**相反**的。即相同的符号，最后定义的排列顺序是完全相反的。


