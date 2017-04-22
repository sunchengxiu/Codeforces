###前言
最近在接触新知识，也是选择2017年的方向。
其他文集更新会放缓，没有学习就没有心得，肚中无墨就无从下笔。
但是算法练习还是挺好玩的，欢迎关注[algorithm文集](http://www.jianshu.com/nb/5402645)。


###正文
**A. Bus to Udayland**
[题目链接](http://codeforces.com/contest/711/problem/A)
**题目大意：**
 输入n行字符，每行5个字符；
表示公交车上n排位置，X表示有人，O表示空位，|是过道。
问是否能找到两个连续的空位；
如果可以，输出"YES"，并且空位改为++后输出；
如果没有输出"NO";
  n (1 ≤ n ≤ 1000)
 >###Example
#### input
 5
 XX|XX
 XX|XX
 XO|OX
 XO|OO
 OX|XO
#### output
 YES
 XX|XX
 XX|XX
 XO|OX
 XO|++
 OX|XO
  
** 题目解析：**
 只有两种情况，前两个或者最后两个。
分情况讨论即可。

B. Chris and Magic Square
题目链接：http://codeforces.com/contest/711/problem/B
 题目大意：
 输入一个n*n的数组矩阵，在数字为0的位置填入一个正数（只有一个位置为0），让矩阵的行列对角线和相同。
 如果没有答案输出-1；
 如果答案，输出完整的矩形。
 n (1 ≤ n ≤ 500)
 
 >###Example
 #####input
 3
 4 0 2
 3 5 7
 8 1 6
####output
 9
 ####input
 4
 1 1 1 1
 1 1 0 1
 1 1 2 1
 1 1 1 1
 ####output
 -1
 
 
** 题目解析：**
 看似很难，但是因为只有一个位置为0，题目简化许多。
 我们假设存在答案，那么可以：
 根据上一行和当前行的差值，可以计算出0应该填的数字。
 再判断一下结果是否符合即可。


**C. Coloring Trees**
[题目链接](http://codeforces.com/contest/711/problem/C)
**题目大意：**
有n棵树排成一行，m种颜料（数字1~m）；
 输入n个数字，表示n棵树当前的颜色（0为uncolor，其他为当前的颜色）；
 树的排列顺序有一个魅力值， 连续的相同颜色值算1点魅力值，例如：
 树的颜色排列为 [2, 1, 1, 1, 3, 2, 2, 3, 1, 3]，其魅力值为7，分别如下：
 {2}, {1, 1, 1}, {3}, {2, 2}, {3}, {1}, {3}
 
 如果树的颜色是uncolor，代表可以染色；
 输入n*m个数字，表示第i颗树染色成第j种颜色的代价cost[i][j];
 

 问，如果要把树的魅力值变为k，需要的最小代价是多少？（如果无解，输出-1）
  
 n, m and k (1 ≤ k ≤ n ≤ 100, 1 ≤ m ≤ 100)
 
 >###Example
 ####input
 3 2 2
 0 0 0
 1 2
 3 4
 5 6
 ####output
 10
 ####input
 3 2 2
 2 1 2
 1 3
 2 4
 3 5
 ####output
 -1
 
 
** 题目解析：** 
 从给出的数据范围来看，容许时间复杂度比较大的做法。
 从给出的选择来看，每次的抉择只有uncolor的树，假设要染色的树是i，大概的类别有：
 1、color[i-1] != color[i+1]，这时color[i]可以等于color[i-1]或者color[i+1]，或者都不相同；
 2、color[i-1] == color[i+1]，这时color[i]可以等于color[i-1]和color[i+1]，或者都不相同；
 因为题目要求的是特定的魅力值，故而不能用贪心的做法。
 考虑用动态规划来做，
 dp[i][j[k] 表示前i个，color为j，最后一个为颜色k的最小代价；
 对于第i颗树，color为j的状态，考虑以下的状态：
 1、color[i] != 0，不能染色，那么j=color[i]的状态，可以通过dp[i-1]的状态中获得最小代价；
 1、color[i] != 0，不能染色，那么j!=color[i]的状态，不合法，忽略；
 1、color[i] == 0，能染色，那么枚举j的状态，从dp[i-1]转移即可。
 具体的转移方程较多，可以见代码。
 
 
** 思考🤔：
 如果把k去掉，改成最大值，是一道不错的面试题。**


** D. Directed Roads**
[题目链接](http://codeforces.com/contest/711/problem/D)
** 题目大意：**
 给出n个点，每个点有一条从其出发的有向边；
 现在选择一个边的集合，对集合的每条边进行一个翻转的操作；
 要求：让n个点没有形成环。
 问有多少种集合可能，结果对MOD取余。
 n (2 ≤ n ≤ 2·1e5)
 MOD = 1e9 + 7.
 
>###Example
#### input
 3
 2 3 1
#### output
 6
####input
4
2 1 1 1
####output
8
 
 
 **题目解析：**
 注意重点：**每个点初始状态只有一条有向边**，那么每个环都是简单的环（没有重叠的环）。
 那么把所有的点分成两种，环上的点，环外的点。
 不在环上的点有k个，那么有2^k个选择。
 第i个环的数量为num[i]，有2^num[i] - 2个选择。（全选和全不选是不行的）
 结果之乘积就是答案。

###总结
>不知道你们有没有这样一种感觉，当你换到一个新的环境，接触到很多新的知识之后，本能地开始排斥这些新的内容。
表现出来的行为就是焦虑，觉得很多事情未完成，但是仍然注意力不集中。
明知道这些知识很重要，但是就不愿意去学，觉得这个东西很难且以后也很少用到。
这种焦虑就是**人与人的价值观区别**，甚至有的人会抱着好奇心的态度去接受这种新知识。
不去评判价值观的好坏，但如果能怀着好奇的心态迎接新的生活，总归会过的轻松点。