# JDII127 分组背包·初悟

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：High
- 语言：C, C++, Java, Python3

## 题目描述

<p>珍宝阁中——灵物被分为n组——每组内的灵物互斥——最多只能从每组中选一件。第i组有c_i件灵物——每件有其价值v和重量w。灵囊承重W——求最大总价值。</p><p>「分组背包——每组至多选一件，」赵晴儿将灵物按组归位，「外层遍历组——内层倒序遍历容量——最内层遍历组内每件物品。dp[j]=max(dp[j], dp[j−w_k]+v_k) for each item k in group i。」</p><p>「与01背包的区别——」梁嘉峰画出递推表，「01背包每件物品独立决策——选或不选。分组背包是每组内竞争——选A就不能选B。所以组内物品的dp更新必须基于同一组处理前的dp值——即对于每个容量j——先算出max over组内各物品——再更新dp[j]。」</p><p>「实现细节——」李少白执笔，「for each group: for j from W down to 0: for each item k in group: if j≥w_k: dp[j]=max(dp[j], dp[j−w_k]+v_k)。注意——容量j的循环在组内物品循环之外——保证了组内物品互相竞争。」</p><p>「复杂度O(W·Σc_i)——」赵晴儿总结，「与01背包同级——因为每件物品仍只被考虑一次。」</p><p>三人逐组处理灵物。第一组2件——选第2件价值更大。第二组1件——只能选它。第三组1件——选之。最大总价值8。与珍宝阁石碑一致。</p>

## 输入描述

<p>第一行有两个整数 N，V，用空格隔开，分别表示物品组数和背包容量。</p><p>接下来有 N 组数据：</p><p>每组数据第一行有一个整数 S<sub>i</sub>，表示第 i 组的物品数量；</p><p>接下来 S<sub>i</sub> 行，每行有两个整数 w 和 v，用空格隔开，分别表示第 i 组第 j 件物品的重量和价值。</p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">输出一个整数，表示最大价值。</span><br /></p>

## 样例

### 样例 1

#### 输入

```text
3 5
2
1 2
2 4
1
3 4
1
4 5
```

#### 输出

```text
8
```

## 提示

<p><a href="https://www.acwing.com/problem/content/9/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/341/" target="_blank">Y总讲解(基础课)</a></p>

本题改编自AcWing 9. 分组背包问题<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20E16%20%E8%83%8C%E5%8C%85DP%20%E5%88%86%E7%BB%84%E8%83%8C%E5%8C%85" target="_blank">B站视频 — E16 背包DP 分组背包</a></p>
