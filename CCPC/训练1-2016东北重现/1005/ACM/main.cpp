//
//  main.cpp
//  ACM
//
//  Created by 林伟池 on 16/9/4.
//  Copyright &#169; 2016年 林伟池. All rights reserved.
/************************** 题解 **********************
 题目链接：http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=5924
 题目大意：
 给出n*m的数据矩阵，按照连连看的规则（连线最多由三条直线组成），判断矩阵是否存在解；（不需要消除完毕，只需判断第一步是否有解即可）
 n and m (1≤n,m≤30)
 
 
 Sample Input
 2
 3 3
 1 2 1
 2 1 2
 1 2 1
 3 3
 1 2 3
 2 1 2
 3 2 1
 
 
 Sample Output
 Case #1: Yes
 Case #2: No
 
 样例解释：
 样例1可以消去[1, 3] 和 [3, 3]。
 
 
 题目解析：
 
 签到题。每个数字只能和上下左右相连，最左最右最上最下可以在同一列/行内相连。
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
const int N = 33, M = 33, inf = 0x7fffffff;

lld a[N][M];



int main(int argc, const char * argv[]) {
    // insert code here...
    lld t;
    cin >> t;
    for (int z = 1; z <= t; ++z) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        printf("Case #%d: ", z);
        bool ok = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i + 1 < n) {
                    ok = ok || a[i][j] == a[i+1][j];
                }
                if (j + 1 < m) {
                    ok = ok || a[i][j] == a[i][j+1];
                }
                if (i == 0 || i == n-1) {
                    for (int k = j + 1; k < m; ++k) {
                        ok = ok || a[i][j] == a[i][k];
                    }
                }
                if (j == 0 || j == m-1) {
                    for (int k = i + 1; k < n; ++k) {
                        ok = ok || a[i][j] == a[k][j];
                    }
                }
            }
        }
        
        if (ok) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    
    
    return 0;
}
