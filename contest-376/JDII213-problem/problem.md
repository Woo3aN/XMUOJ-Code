# JDII213 背包·方案计数

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>灵器阁的库房中，N 件灵器各有体积 v_i 和灵力值 w_i，乾坤袋容量为 V。试炼的要求与前不同——不求最大价值本身，而是问：有多少种不同的选取方案（每个灵器至多选一次，01 背包）恰好达到了最大总价值？答案对 10^9+7 取模。</p><p>「两趟 DP——第一趟求最大价值，第二趟统计方案数，」赵晴儿分步规划，「第一趟：标准 01 背包 DP，dp[j] = max(dp[j], dp[j-v_i] + w_i)，得到 max_val = dp[V]。」</p><p>「第二趟：计数 DP，」李少白接道，「cnt[j] 表示当前容量为 j 时达到 dp[j] 的最优方案数。初始化 cnt[0] = 1。对每件物品倒序更新——若 dp[j] &lt; dp[j-v_i] + w_i，则 dp[j] 更新、cnt[j] = cnt[j-v_i]；若 dp[j] == dp[j-v_i] + w_i，则 cnt[j] = (cnt[j] + cnt[j-v_i]) % MOD。」</p><p>「两趟 DP 均在 O(N*V) 内完成，」梁嘉峰敲定，「关键——cnt 必须与 dp 同步更新，保证方案数始终对应最优值。」</p><p>方案总数在双重 DP 下被精确计数。</p>

## 输入描述

<p>第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。</p><p>接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。</p>

## 输出描述

<p>输出一个整数，表示 方案数 模 10^9+7 的结果。</p><p>数据范围</p><p>0&lt;N,V≤1000</p><p>0&lt;vi,wi≤1000</p>

## 样例

### 样例 1

#### 输入

```text
4 5
1 2
2 4
3 4
4 6
```

#### 输出

```text
2
```

## 提示

<p><a href="https://www.acwing.com/problem/content/11/" target="_blank">原题链接</a><br /></p><p><a href="https://www.acwing.com/video/387/" target="_blank">Y总讲解</a><br /></p><p><a href="https://www.acwing.com/solution/content/3999/" target="_blank">参考题解</a><br /></p><p><a href="https://www.acwing.com/activity/content/code/content/120228/" target="_blank">Y总代码</a><br /></p>

本题改编自AcWing 11. 背包问题求方案数<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20E19%20%E8%83%8C%E5%8C%85DP%20%E6%B1%82%E6%96%B9%E6%A1%88%E6%95%B0" target="_blank">B站视频 — E19 背包DP 求方案数</a></p>
