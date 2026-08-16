# JDII203 01背包·数字组合

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Mid
- 语言：C, C++, Java, Python3

## 题目描述

<p>算学山庄的藏数阁中，n 个正整数刻在玉牌上。试炼的问题是：从中选出若干个数，使得它们的和恰好等于目标值 M。问有多少种不同的选法？每个数至多选一次——01 背包的方案计数版本。</p><p>「计数型 01 背包——dp[j] 表示凑出和为 j 的方案数，」赵晴儿布下阵局，「初始化 dp[0] = 1（空集一种方案）。对每个数 x，倒序更新：dp[j] = (dp[j] + dp[j - x]) % MOD。含义——凑 j 的方案数 = 不选 x 的方案数 + 选 x 的方案数。」</p><p>「倒序保证了每个数至多用一次，」李少白强调，「完全背包的计数版则是正序——dp[j] = dp[j] + dp[j-x]，此时每个数可以用无限次。」</p><p>「O(n * M) 的时间和 O(M) 的空间，」梁嘉峰核算，「若 n 和 M 均达 10^5，则需 bitset 或生成函数优化——但基础数据范围下朴素 DP 足矣。」</p><p>数字组合的方案数在计数型 01 背包下被算出。</p>

## 输入描述

<p>第一行包含两个整数<code>N</code>和<code>M</code>。</p><p>第二行包含<code>N</code>个整数，表示<code>A1</code>,<code>A2</code>, …,<code>AN</code>。</p>

## 输出描述

<p>包含一个整数，表示可选方案数。</p><p><strong>数据范围</strong><code>1≤N≤100</code><code>1≤M≤10000</code><code>1≤Ai≤1000</code>答案保证在<code>int</code>范围内。</p>

## 样例

### 样例 1

#### 输入

```text
4 4
1 1 2 2

```

#### 输出

```text
3
```

## 提示

<p><a href="https://www.acwing.com/problem/content/280/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/429/" target="_blank">Y总讲解</a></p>

本题改编自AcWing 278. 数字组合<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E6%95%B0%E5%AD%97%E7%BB%84%E5%90%88" target="_blank">B站视频 — 搜索</a></p>
