# JDII200 分组背包·机阵分派

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>机关城中，三人面对 m 组机关阵眼。每组阵眼中有若干种灵器——同组内的灵器互斥，至多选一件。乾坤袋容量为 V。每种灵器有体积 v 和灵力值 w。试炼要求：在容量限制下最大化总灵力。</p><p>「分组背包——01 背包的变体，」赵晴儿分派阵眼，「策略——对于每组，倒序容量 j，然后在组内遍历所有灵器选最优：dp[j] = max(dp[j], max_{k in group}(dp[j - v_k] + w_k))。」</p><p>「关键是先枚举容量（倒序），再枚举组内物品，」李少白强调顺序，「这个顺序保证了每组至多选一件——因为 dp[j - v_k] 来自上一组的结果，不会引入同组的多个物品。」</p><p>「三重循环：组 → 容量(V..0) → 组内物品。O(m * V * avg_group_size)，」梁嘉峰核算，「与 01 背包的区别仅在于多了一层组内枚举。」</p><p>各组阵眼在分组背包 DP 下被最优地选取一件灵器。</p>

## 输入描述

<p>第一行有两个数，第一个数是分公司数 N，第二个数是设备台数 M；</p><p>接下来是一个 N×M 的矩阵，矩阵中的第 i 行第 j 列的整数表示第 i 个公司分配 j 台机器时的盈利。</p>

## 输出描述

<p>第一行输出最大盈利值；</p><p>接下 N 行，每行有 2 个数，即分公司编号和该分公司获得设备台数。</p><p>答案不唯一，输出任意合法方案即可。</p><p>数据范围</p><p>1≤N≤10,1≤M≤15</p>

## 样例

### 样例 1

#### 输入

```text
3 3
30 40 50
20 30 50
20 25 30
```

#### 输出

```text
70
1 1
2 1
3 1
```

## 提示

<p><a href="https://www.acwing.com/problem/content/1015/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/solution/content/53963/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/video/378/" target="_blank">Y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/118706/" target="_blank">Y总代码</a></p>

本题改编自AcWing 1013. 机器分配、AcWing 1020. 潜水员<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E6%9C%BA%E5%99%A8%E5%88%86%E9%85%8D" target="_blank">B站视频 — 搜索</a></p>
