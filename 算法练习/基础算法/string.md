# P5734 【深基6.例6】文字处理软件

## 题目描述

你需要开发一款文字处理软件。最开始时输入一个字符串作为初始文档。可以认为文档开头是第 $0$ 个字符。需要支持以下操作：

- `1 str`：后接插入，在文档后面插入字符串 $\texttt{str}$，并输出文档的字符串；
- `2 a b`：截取文档部分，只保留文档中从第 $a$ 个字符起 $b$ 个字符，并输出文档的字符串；
- `3 a str`：插入片段，在文档中第 $a$ 个字符前面插入字符串 $\texttt{str}$，并输出文档的字符串；
- `4 str`：查找子串，查找字符串 $\texttt{str}$ 在文档中最先的位置并输出；如果找不到输出 $-1$。
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    string str;
    cin >> str;

    while(q--){
        int op;
        cin >> op;

        if(op == 1){
            string s;
            cin >> s;
            str += s;
            cout << str << "\n";
        }
        else if(op == 2){
            int a,b;
            cin >> a >> b;

            str = str.substr(a,b);
            cout << str << "\n";
        }
        else if(op == 3){
            int a;
            string s;
            cin >> a >> s;
            str.insert(a,s);
            cout << str << "\n";
        }
        else if(op == 4){
            string s;
            cin >> s;
            
            size_t pos = str.find(s);
            
            if(pos == string::npos)
	            cout << -1 << '\n';
	        else
		        cout << pos << '\n';
        }
    }
    return 0;
}
```
#### P1957 [口算练习题](https://www.luogu.com.cn/problem/P1957 "口算练习题")
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i;
    cin >> i;

    char op = ' ';  //op定义在外面方便保存上一轮的状态
    
    while(i--){
        string first;
        cin >> first;

        int x,y;
        
        if(first == "a" ||first == "b" ||first == "c" ){
            op = first[0];
            cin >> x >> y;
        }else{
            x = stoi(first);
            cin >> y;
        }

        int result;
        char symbol;

        if(op == 'a'){
            result = x+y;
            symbol = '+';            
        }else if(op == 'b'){
            result = x-y;
            symbol = '-';
        }else if(op == 'c'){
            result = x*y;
            symbol = '*';
        }

        string expression;
        expression = to_string(x) + symbol + to_string(y) + "=" + to_string(result);

        cout << expression << "\n";
        cout << expression.size() << "\n";
    }
    return 0;
}
```
#### P1308 [[NOIP 2011 普及组] 统计单词数](https://www.luogu.com.cn/problem/P1308 "[NOIP 2011 普及组] 统计单词数")
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word, article;
    getline(cin, word);
    getline(cin, article);

    //全部转化小写
    for(int i=0; i<word.size();i++){
        word[i] = tolower(word[i]);
    }
    for(int i=0; i<article.size(); i++){
        article[i] = tolower(article[i]);
    }

    //加上空格方便匹配
    word = " " + word + " ";
    article = " " + article + " ";

    //接下来开始查找和匹配
    //初始化参数
    int cnt = 0;    //计数器
    size_t first = -1;    //记录第一次出现的位置
    size_t pos = -1;    //记录每一次出现的位置
    size_t start = 0;    //记录每一次开始查找的位置

    pos = article.find(word, start);

    while(pos != string::npos){
        cnt ++;

        if(first == -1){
            first = pos;
        }

        start = pos + 1;

        pos = article.find(word, start);
    }
	//注意输出情况判断
    if(cnt == 0)
        cout << -1;
    else
        cout << cnt << ' ' << first; 
    return 0;
}
```
##### P3879 字符匹配[[TJOI2010] 阅读理解](https://www.luogu.com.cn/problem/P3879 "[TJOI2010] 阅读理解")
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, vector<int>> mp;    //字符对应文章
    for(int i=1; i<=n; i++){
        int l;
        cin >> l;

        unordered_set<string> st;
        while(l--){
            string word;
            cin >> word;          
            st.insert(word);    //去重
        }

        for(auto &w:st){
            mp[w].push_back(i);
        }
    }

    int q;
    cin >> q;
    while(q--){
        string word;
        cin >> word;

        if(mp.count(word)){
            for(int &k:mp[word]){
                cout << k << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
```
#### P1553 [数字反转（升级版）](https://www.luogu.com.cn/problem/P1553 "数字反转（升级版）")
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    char op = ' ';

    // 扫描确定类型
    for(size_t i=0; i<s.size(); i++){
        if(s[i] == '.' || s[i] == '/' || s[i] == '%'){
            op = s[i];
            break;
        }
    }

    if(op == ' '){
        reverse(s.begin(), s.end());

        size_t p = 0;
        while(p + 1 < s.size() && s[p] == '0'){//细节处理防止越界
            p++;
        }

        cout << s.substr(p);
    }
    else if(op == '.'){
        size_t pos = s.find('.');

        string zhen = s.substr(0, pos);
        string xiao = s.substr(pos + 1);

        reverse(zhen.begin(), zhen.end());
        reverse(xiao.begin(), xiao.end());

        size_t p = 0;
        while(p + 1 < zhen.size() && zhen[p] == '0'){
            p++;
        }

        zhen = zhen.substr(p);

        while(xiao.size() > 1 && xiao.back() == '0'){
            xiao.pop_back();
        }

        cout << zhen << '.' << xiao;
    }
    else if(op == '/'){
        size_t pos = s.find('/');

        string fenzi = s.substr(0, pos);
        string fenmu = s.substr(pos + 1);

        reverse(fenzi.begin(), fenzi.end());
        reverse(fenmu.begin(), fenmu.end());

        size_t p = 0;
        while(p + 1 < fenzi.size() && fenzi[p] == '0'){
            p++;
        }
        fenzi = fenzi.substr(p);

        p = 0;
        while(p + 1 < fenmu.size() && fenmu[p] == '0'){
            p++;
        }
        fenmu = fenmu.substr(p);

        cout << fenzi << '/' << fenmu;
    }
    else{
        string n = s.substr(0, s.size() - 1);

        reverse(n.begin(), n.end());

        size_t p = 0;
        while(p + 1 < n.size() && n[p] == '0'){
            p++;
        }

        cout << n.substr(p) << '%';
    }

    return 0;
}
```
#### P1012 [[NOIP 1998 提高组] 拼数](https://www.luogu.com.cn/problem/P1012 "[NOIP 1998 提高组] 拼数")
```cpp
#include<bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b){
    return a+b > b+a;    //最大值排序之后再拼接
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);    //先读入防止垃圾值

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), cmp);

    string ans = a[0];
    for(int i=1; i<n; i++){
        ans += a[i];
    }
    
    cout << ans;
    return 0;
}
```
st.insert(x).second判断是否存在重复插入的情况
