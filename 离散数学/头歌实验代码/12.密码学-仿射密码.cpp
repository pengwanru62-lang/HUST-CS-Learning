#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    string P;
    getline(cin, P);

    string C = P;

    // ===== begin=====
    // 要求：
    // 1) 遍历字符串 P 的每个字符
    // 2) 若是大写字母 'A'..'Z'：
    //      - 映射为数字 p = ch - 'A'
    //      - 计算 c = (a * p + b) % 26
    //      - 映射回字符 'A' + c，写入 C
    // 3) 若不是大写字母（例如空格），保持原样
    // 4) 最终输出密文字符串 C
    // ===== end=====

    // 1) 遍历字符串 P 的每个字符
    for(int i=0; i<P.size(); i++)
    {
        // 2) 若是大写字母 'A'..'Z'：
        //      - 映射为数字 p = ch - 'A'
        //      - 计算 c = (a * p + b) % 26
        //      - 映射回字符 'A' + c，写入 C
        char ch = P[i];
        if(ch>='A' && ch<='Z')
        {
            int p = ch - 'A';
            int c = (a * p + b) % 26;
            C[i] = 'A' + c;
        }
    }
    // 3) 若不是大写字母（例如空格），保持原样
    // 4) 最终输出密文字符串 C
    cout << C << "\n";
    return 0;
}