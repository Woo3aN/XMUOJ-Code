# JDII205 完全背包·货币体系(一)

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>灵币铸造殿中，n 种面额的灵币琳琅满目——每种灵币可以使用任意数量（完全背包）。试炼要求：凑出总面额恰好为 M 的灵币组合方案有多少种？即求完全背包的方案计数。</p><p>「计数型完全背包——dp[j] 表示凑出 j 面额的方案数，」李少白列出 DP，「初始化 dp[0] = 1。对每种面额 v_i，正序更新：dp[j] = (dp[j] + dp[j - v_i]) % MOD。正序保证每种面额可用无限次——因为 dp[j - v_i] 可能已包含同种面额的贡献。」</p><p>「与计数型 01 背包的唯一区别——循环方向，」赵晴儿强调重点，「倒序→每种至多一次；正序→每种无限次。计数版的本质不变——都是加法原理。」</p><p>「O(n * M) 时间，O(M) 空间，」梁嘉峰核算，「若 M 较大（如 10^5），可加前缀和优化或使用母函数。」</p><p>灵币组合方案在正序 DP 的计数下被全部枚举。</p>

## 输入描述

<p>第一行，包含两个整数n和m。</p><p>接下来n行，每行包含一个整数，表示一种货币的面值。</p><h4>数据范围</h4><p>n≤15,m≤3000</p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">共一行，包含一个整数，表示方案数。</span><br /></p>

## 样例

### 样例 1

#### 输入

```text
3 10
1
2
5

```

#### 输出

```text
10
```

## 提示

<p><a href="https://www.acwing.com/problem/content/1023/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/385/" target="_blank">y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/117235/" target="_blank">参考代码</a></p>

本题改编自AcWing 1021. 货币系统<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E8%B4%A7%E5%B8%81%E7%B3%BB%E7%BB%9F" target="_blank">B站视频 — 搜索</a></p>
