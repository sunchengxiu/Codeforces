//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/746/problem/A)
 **题目大意：**
 1、整数求出1的数字
 2、二叉树的深度
 3、Https
 4、DNS劫持
 5、property；
 6、category属性；
 7、iOS装载；
 
 1、职责；
 2、什么部门过来；
 3、薪酬；
 4、工时；

 snapchat  +  glass
 
 CoreCemara Team
 10 -
 英文
 Snap 
 
 
 输入：
 输出：
 
 **Examples**
 **input**
 **output**
 
 **题目解析：**
 
 **思考🤔：**
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 101000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];


string transfrom(string str) {
    string ret;
    int n = (int)str.length();
    int index = 0;
    while (index < n) {
        if (str[index] >= '1' && str[index] <= '9') { // number
            int sum = str[index] - '0';
            ++index;
            while (str[index] >= '0' && str[index] <= '9') {
                sum = sum * 10 + str[index] - '0';
                ++index;
            }
            // str[index] = '['
            int match = 1;
            ++index;
            int left = index, right = 0;
            
            while (match) {
                if (str[index] == '[') {
                    ++match;
                }
                else if (str[index] == ']') {
                    --match;
                }
                ++index;
            }
            // str[index] = ']'
            right = index - 1;
            string subStr = transfrom(string(str.begin() + left, str.begin() + right));
            for (int i = 0; i < sum; ++i) {
                ret.append(subStr);
            }
        }
        else {
            ret.append(string(str.begin() + index, str.begin() + index + 1));
            ++index;
        }
    }
    return ret;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    string str;
    cin >> str;
    cout << transfrom(str) << endl;
    
    return 0;
}
