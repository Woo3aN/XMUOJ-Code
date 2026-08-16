# JDII211 背包·金明欣悦

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>金明小侠初入江湖，带着 N 两银子的预算去灵器阁置办装备。阁中有 m 件灵器，每件标价 v 两银子，且有重要度 p（1 到 5 级）。灵器的实际价值 = v * p——价格与重要度之乘积。每件灵器至多买一件（01 背包），金明的目标是在预算内使总价值最大化。</p><p>「这是 NOIP 2006 普及组的经典题目——&#039;开心的金明&#039;，」李少白会心一笑，「标准的 01 背包，只是每件物品的价值不是独立给出的，而是 w_i = v_i * p_i。明白了这一点，直接套 01 背包模板即可。」</p><p>「dp[j] = max(dp[j], dp[j - v_i] + v_i * p_i)，倒序更新，」赵晴儿写出递推，「N ≤ 30000，m ≤ 25，O(m*N) 的 DP 轻松通过。一维滚动数组空间 O(N)。」</p><p>「虽是最简单的 01 背包，但价值 = 价格 * 重要度 的设计赋予了它实际意义，」梁嘉峰点评道，「金明的预算方案——多少 OIer 的入门第一题。」</p><p>金明小侠在 01 背包的指引下花光了预算，总价值达到最大。</p>

## 输入描述

<p><font>输入文件</font><font>的第</font>1行，为两个正整数，用一个空格隔开：<br />N m<br /><font>（其中</font>N（&lt;30000）表示总钱 数，m（&lt;25）为希望购买物品的个数。）<br /><font>从第</font>2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有2个非负整数<br />v p<br /><font>（其中</font>v表示该物品的价格(v&lt;=10000)，p表示该物品的重要度(1~5)）<br /></p>

## 输出描述

<p><font>输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（</font>&lt;100000000）。<br /></p>

## 样例

### 样例 1

#### 输入

```text
1000 5
800 2
400 5
300 5
400 3
200 2
```

#### 输出

```text
3900
```

## 提示

<p><a href="https://www.acwing.com/problem/content/428/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/2340/" target="_blank">Y总讲解</a></p><p><a href="https://www.acwing.com/solution/content/4538/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/118713/" target="_blank">Y总代码</a></p>

本题改编自AcWing 426. 开心的金明<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E5%BC%80%E5%BF%83%E7%9A%84%E9%87%91%E6%98%8E" target="_blank">B站视频 — 搜索</a></p>
