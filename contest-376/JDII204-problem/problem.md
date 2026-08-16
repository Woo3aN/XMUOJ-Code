# JDII204 完全背包·书山有径

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>藏经阁的账房内，四种典籍分门别类，售价分别为 <b>10、20、50、100</b> 两银子，每种典籍数量充足、可反复购置。李少白怀揣 n 两银子走进来，立志把这笔钱一分不剩地全部买书。试炼要求：算出一共有多少种不同的买书方案。</p><p>「完全背包求方案数，」赵晴儿展开推演，「先令 dp[0] = 1，表示『一本都不买』也是一种方案；然后对每一种书，正序枚举金额 j，令 dp[j] += dp[j - 价格]。正序的意义——同一本书可以反复纳入方案，于是每种书都能买任意多本。」</p><p>「这与求最大价值的完全背包同构，」李少白点头，「区别仅在于 dp 的含义从『最优值』变为『方案数』，转移也从取最大值变为累加。」</p><p>「四种书正序各扫一遍，O(4 × n) 时间、O(n) 空间，」梁嘉峰补充，「最终的 dp[n] 即为所求。」</p><p>四种典籍在完全背包的正序递推下被反复纳入方案，买书方案数由此尽数算出。</p>

## 输入描述

<p><span style="color: rgb(51, 51, 51);">一个整数 n，代表总共钱数。</span><br /></p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">一个整数，代表选择方案种数。</span><br /></p><h4>数据范围</h4><p>0≤n≤1000</p>

## 样例

### 样例 1

#### 输入

```text
20
```

#### 输出

```text
2
```

### 样例 2

#### 输入

```text
15
```

#### 输出

```text
0
```

### 样例 3

#### 输入

```text
0
```

#### 输出

```text
1
```

## 提示

<p><a href="https://www.acwing.com/problem/content/1025/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/374/" target="_blank">y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/117232/" target="_blank">参考代码</a></p>

本题改编自AcWing 1023. 买书<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E4%B9%B0%E4%B9%A6" target="_blank">B站视频 — 搜索</a></p>
