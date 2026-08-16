# JDII214 背包·方案追溯

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>灵器阁的最终试炼——不仅要求最大总价值，还要输出达到该最大价值的具体选取方案（即选哪些灵器）。若有多种方案，输出字典序最小的那组（按灵器编号排序）。N 件灵器各具 v_i 和 w_i，容量 V，01 背包。</p><p>「方案追溯——在 DP 完成后反向推导，」赵晴儿布下列阵，「先用二维 dp[i][j]（而非一维滚动）跑完 01 背包——dp[i][j] 表示前 i 件、容量 j 的最大价值。然后从 i=N、j=V 开始倒推：若 dp[i][j] == dp[i-1][j]，说明第 i 件未选，i -= 1；若 dp[i][j] == dp[i-1][j-v_i] + w_i，说明第 i 件被选——记录 i，然后 j -= v_i，i -= 1。」</p><p>「若两种转移都可行（价值相等），」李少白补充关键，「优先选择&#039;选 i&#039;的分支——这样可以确保字典序最小。因为从后往前推，优先选编号大的物品意味着最终方案中编号小的物品更可能被保留。」</p><p>「二维 DP O(N*V)，回溯 O(N)，」梁嘉峰完成推导，「空间 O(N*V)——若 N 和 V 较大可优化，但基础范围下清晰直白。」</p><p>最优方案在 DP 表上被反向追溯，字典序最小的选取组合跃然而出。</p>

## 输入描述

<p>第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。</p><p>接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。</p>

## 输出描述

<p>输出一行，包含若干个用空格隔开的整数，表示最优解中所选物品的编号序列，且该编号序列的字典序最小。</p><p>物品编号范围是 1…N。</p><p><strong>数据范围</strong></p><p>0&lt;N,V≤1000</p><p>0&lt;vi,wi≤1000</p>

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
1 4
```

## 提示

<p><a href="https://www.acwing.com/problem/content/12/" target="_blank">原题链接</a><br /></p><p><a href="https://www.acwing.com/video/380/" target="_blank">Y总讲解</a><br /></p><p><a href="https://www.acwing.com/solution/content/2687/" target="_blank">参考题解</a><br /></p><p><a href="https://www.acwing.com/activity/content/code/content/119629/" target="_blank">Y总代码</a><br /></p>

本题改编自AcWing 12. 背包问题求具体方案<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20E20%20%E8%83%8C%E5%8C%85DP%20%E6%B1%82%E5%85%B7%E4%BD%93%E6%96%B9%E6%A1%88" target="_blank">B站视频 — E20 背包DP 求具体方案</a></p>
