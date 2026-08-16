# JDII207 多重背包(三)

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：High
- 语言：C, C++, Java, Python3

## 题目描述

<p>多重背包的第三重试炼——N 种灵石，每种有体积 v_i、灵力值 w_i 和数量 s_i。乾坤袋容量 V。s_i 可以很大（可达 10^5 甚至更大），二进制拆分后物品数仍然庞大。</p><p>「单调队列优化多重背包——达到 O(N*V) 的理论下界，」赵晴儿展开进阶技法，「将容量 j 按模 v_i 的余数分为 v_i 组。对每一组，维护一个关于 dp 值的单调递减队列——队列中存储 (dp 值, 对应容量)。当窗口滑动时，队首过期的出队，新候选入队前剔除队尾不优的。」</p><p>「具体——对于每个容量 j（按组遍历），」李少白推演细节，「候选值 = dp[j] - (j/v_i)*w_i。它可以等价比较当前最优。当前 dp[j] = 队首值 + (j/v_i)*w_i。窗口大小为 min(s_i, V/v_i)。」</p><p>「单调队列将内层 O(s_i) 降为均摊 O(1)，」梁嘉峰完成推导，「三重循环 → O(N*V)，完美解决大 s_i 场景。」</p><p>多重背包在单调队列的优化下达到了最优效率。</p>

## 输入描述

<p>第一行两个整数，N，V(0&lt;N≤1000,0&lt;V≤20000)，用空格隔开，分别表示物品种数和背包容积。</p><p>接下来有N行，每行三个整数vi,wi,si，用空格隔开，分别表示第i种物品的体积、价值和数量。</p><h4>数据范围</h4><p>0&lt;N≤1000<br />0&lt;V≤20000<br />0&lt;vi,wi,si≤20000</p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">输出一个整数，表示最大价值。</span></p><p>注意：本题考查多重背包的单调队列优化方法。</p>

## 样例

### 样例 1

#### 输入

```text
4 5
1 2 3
2 4 1
3 4 3
4 5 2
```

#### 输出

```text
10
```

## 提示

<p><a href="https://www.acwing.com/problem/content/6/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/218/" target="_blank">y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/117236/" target="_blank">参考代码</a></p>

本题改编自AcWing 5. 多重背包问题 II<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20E13%20%E8%83%8C%E5%8C%85DP%20%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85%20%E5%8D%95%E8%B0%83%E9%98%9F%E5%88%97%E4%BC%98%E5%8C%96" target="_blank">B站视频 — E13 背包DP 多重背包 单调队列优化</a></p>
