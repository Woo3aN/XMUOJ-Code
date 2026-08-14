# JDII198 01背包·灵药入囊

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>药王谷的灵药库中，N 种灵药陈列于前，乾坤袋容量为 V。每种灵药有体积 v_i 和价值 w_i——每种灵药仅此一株，取或不取。试炼要求：在总体积不超过 V 的条件下，使得总价值最大化。此乃 01 背包。</p><p>「01 背包——DP 入门第一关，」李少白轻车熟路，「设 dp[j] 表示容量 j 时的最大价值。对于每种灵药 i，倒序更新 dp[j] = max(dp[j], dp[j - v_i] + w_i)，j 从 V 到 v_i。倒序保证了每种灵药最多被选一次——当前轮更新的 dp[j] 不会影响同轮中更大的 j。」</p><p>「初始化 dp 全为 0，」赵晴儿补充，「O(N*V) 时间，O(V) 空间——一维滚动数组。若要追踪具体选了哪些物品，则需二维数组或记录转移路径。」</p><p>「01 是所有背包问题之根本——倒序是区分 01 与完全的唯一标志。」梁嘉峰总结。</p><p>灵药在 01 背包的倒序 DP 下被最优地选入乾坤袋。</p>

## 输入描述

<p>输入文件的第一行有两个整数 (T) 和 (M)，用一个空格隔开，(T) 代表总共能够用来采药的时间，(M) 代表山洞里的草药的数目。接下来的 (M) 行每行包括两个在 (1) 到 (100) 之间（包括 (1) 和 (100)）的整数，分别表示采摘某株草药的时间和这株草药的价值。</p>

## 输出描述

<p>输出文件包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。</p><p><strong>数据范围</strong>(1\leq T\leq1000)，(1\leq M\leq100)</p>

## 样例

### 样例 1

#### 输入

```text
70 3
71 100
69 1
1 2

```

#### 输出

```text
3
```

## 提示

<p><a href="https://www.acwing.com/problem/content/425/" target="_blank">原题链接</a><br /></p><p><a href="https://www.acwing.com/solution/content/6272/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/115169/" target="_blank">参考代码</a></p><p><a href="https://www.acwing.com/video/548/" target="_blank">Y总讲解</a></p>

本题改编自AcWing 2. 01背包问题、AcWing 423. 采药<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20E08%20%E8%83%8C%E5%8C%85DP%2001%E8%83%8C%E5%8C%85" target="_blank">B站视频 — E08 背包DP 01背包</a></p>
