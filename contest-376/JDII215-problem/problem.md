# JDII215 背包·能量奇石

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>灵石矿脉深处，N 块上古能量奇石散发着微光。每块奇石有三项属性：吞噬它需要 S_i 息时间，初始蕴含 E_i 点灵力，但每过一息便会自动流失 L_i 点灵力。试炼的目标是：选择吞噬若干块奇石（吞噬期间不可中断），使得最终获得的总灵力最大。</p><p>「这不止是 01 背包——奇石在等待吞噬的过程中会不断流失能量，」李少白观察着灵石，「所以吞噬顺序至关重要。直觉告诉我们——流失速度快的奇石应该优先吞噬，以免能量白白消散。」</p><p>「交换论证证明——若两块奇石 i 和 j，比较 S_i * L_j 与 S_j * L_i，」赵晴儿推演，「若 S_i * L_j &lt; S_j * L_i，即 L_i/S_i &gt; L_j/S_j，则 i 应先于 j 被吞噬。因此按 S_i / L_i 从小到大排序即可得到最优吞噬顺序。」</p><p>「排序后，问题退化为标准 01 背包——dp[t] 表示累计耗时 t 时的最大灵力值，」梁嘉峰写出 DP，「每块奇石在已排序序上倒序 DP：dp[t] = max(dp[t], dp[t - S_i] + max(0, E_i - (t - S_i) * L_i))。最终答案 = max(dp[0..total_time])。」</p><p>能量奇石在排序 + 01 背包的组合下释放出最大灵力。</p>

## 输入描述

<p>第一行包含整数 T，表示共有 T 组测试数据。</p><p>每组数据第一行包含整数 N，表示能量石的数量。</p><p>接下来 N 行，每行包含三个整数 Si,Ei,Li。</p>

## 输出描述

<p>每组数据输出一个结果，每个结果占一行。</p><p>结果表示为 Case #x: y，其中 x 是组别编号（从 1 开始），y 是可以获得的最大能量值。</p><p><strong>数据范围</strong></p><p>1≤T≤10</p><p>1≤N≤100</p><p>1≤Si≤100</p><p>1≤Ei≤105</p><p>0≤Li≤105</p>

## 样例

### 样例 1

#### 输入

```text
3
4
20 10 1
5 30 5
100 30 1
5 80 60
3
10 4 1000
10 3 1000
10 8 1000
2
12 300 50
5 200 0
```

#### 输出

```text
Case #1: 105
Case #2: 8
Case #3: 500
```

## 提示

<p><a href="https://www.acwing.com/problem/content/736/" target="_blank">原题链接</a><br /></p><p><a href="https://www.acwing.com/video/389/" target="_blank">Y总讲解</a><br /></p><p><a href="https://www.acwing.com/solution/content/4639/" target="_blank">参考题解</a><br /></p><p><a href="https://www.acwing.com/activity/content/code/content/120230/" target="_blank">Y总代码</a><br /></p>

本题改编自AcWing 734. 能量石<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E8%83%BD%E9%87%8F%E7%9F%B3" target="_blank">B站视频 — 搜索</a></p>
