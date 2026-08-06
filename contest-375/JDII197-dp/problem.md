# JDII197 线性DP·升序极和

- 比赛：集训队试炼02 线性DP
- 题型：OI
- 难度：Mid
- 语言：C, C++, Java, Python3

## 题目描述

<p>数列试炼场中，n 个整数排列成一行。试炼要求：选出一个严格递增的子序列，使得子序列中所有元素之和最大。这与求最长升序不同——有时一个较大的数可以替换掉几个小数，和反而更大。</p><p>「最大上升子序列和（Maximum Sum Increasing Subsequence），」赵晴儿定义 DP，「dp[i] 表示以第 i 个数结尾的上升子序列的最大和。dp[i] = a[i] + max{ dp[j] | j &lt; i 且 a[j] &lt; a[i] }。若不存在这样的 j，则 dp[i] = a[i]。」</p><p>「BIT 优化——以 a[i] 值为下标（离散化后），BIT 维护前缀 dp 最大值，」李少白展开，「遍历 i，查询值小于 a[i] 的最大 dp 值 + a[i] = dp[i]，然后用 dp[i] 更新 BIT 中位置 a[i]。」</p><p>「O(N log N)，BIT 将 O(N^2) 的查询优化为 O(log N)，」梁嘉峰核算，「答案 = max(dp[1..N])。」</p><p>升序极和在 BIT 优化下达到了子序列总和的巅峰。</p>

## 输入描述

<p>输入的第一行是序列的长度$N$。</p><p>第二行给出序列中的$N$个整数，这些整数的取值范围都在0到10000（可能重复）。</p><p><strong>数据范围</strong></p><p>1 ≤ N ≤ 1000</p>

## 输出描述

<p>输出一个整数，表示最大上升子序列和。</p>

## 样例

### 样例 1

#### 输入

```text
7
1 7 3 5 9 4 8
```

#### 输出

```text
18

```

## 提示

<p style="margin-left: 0px;"><a href="https://www.acwing.com/problem/content/1018/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/solution/content/51969/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/video/359/" target="_blank">Y总讲解</a><br /></p><p><a href="https://www.acwing.com/activity/content/code/content/112803/" target="_blank">Y总代码</a></p>

本题改编自AcWing 1016. 最大上升子序列和<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E6%9C%80%E5%A4%A7%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97%E5%92%8C" target="_blank">B站视频 — 搜索</a></p>
