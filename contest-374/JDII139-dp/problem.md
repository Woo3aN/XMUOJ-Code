# JDII139 网格DP·通行费

- 比赛：集训队试炼01 DP基础入门
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>千机城的灵石收费关卡——一座 N*N 的方格阵法。每个方格上刻着一个过路费。试炼者从左上角 (1,1) 出发，只能向右或向下移动，最终抵达右下角 (N,N)。题目要求算出在恰好经过 2N-1 个方格（即不走回头路的最短路径长度）的前提下，最小的总费用。</p><p>「经典网格 DP，」赵晴儿微微一笑，「设 dp[i][j] 表示到达 (i,j) 的最小总费用。由于只能从上方或左方过来，转移方程极简：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j]。」</p><p>「边界处理：第一行只能从左来，第一列只能从上来，」李少白补充道，「dp[1][1] = cost[1][1]，其余初始化为 INF。O(N^2) 填表，答案即 dp[N][N]。」</p><p>「这道题还有一个变体——如果限定在 2N-1 步内到达，恰好等价于只能向右或向下，」梁嘉峰在旁推演，「因为任何绕路都会增加步数。所以看似有限制，实则天然满足。」</p><p>三人缴纳了最少的灵石，顺利穿过千机城。</p>

## 输入描述

<p>第一行是一个整数，表示正方形的宽度N。</p><p>后面N行，每行N个不大于100的正整数，为网格上每个小方格的费用。</p><p><strong>数据范围</strong></p><p>1 ≤ N ≤ 100</p>

## 输出描述

<p>输出一个整数，表示至少需要的费用。</p><p><strong>样例解释</strong></p><p>样例中，最小值为109 = 1 + 2 + 5 + 7 + 9 + 12 + 19 + 21 + 33。</p>

## 样例

### 样例 1

#### 输入

```text
5
1  4  6  8  10
2  5  7  15 17
6  8  9  18 20
10 11 12 19 21
20 23 25 29 33
```

#### 输出

```text
109
```

## 提示

<p><a href="https://www.acwing.com/problem/content/1020/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/solution/content/51101/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/112797/" target="_blank">Y总代码</a></p><p><a href="https://www.acwing.com/video/353/" target="_blank">Y总讲解</a></p>

本题改编自AcWing 1018. 最低通行费<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E6%9C%80%E4%BD%8E%E9%80%9A%E8%A1%8C%E8%B4%B9" target="_blank">B站视频 — 搜索</a></p>
