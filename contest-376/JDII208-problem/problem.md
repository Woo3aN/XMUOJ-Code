# JDII208 多重背包·单调优化

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：High
- 语言：C, C++, Java, Python3

## 题目描述

<p>多重背包单调队列优化的应用试炼——与上一题思路一致，但更侧重于实战。N 种矿产，乾坤袋容量 V。每种矿产有体积 v_i、价值 w_i 和数量 s_i。s_i 可达 10^4，V 可达 10^5。</p><p>「单调队列优化的精髓，」赵晴儿画出示意图，「对每种物品 i，将容量 j 按余数 r = j % v_i 分为 v_i 个独立的组。对于余数为 r 的那组：dp[r], dp[r+v_i], dp[r+2*v_i], ... 形成等差数列状的容量序列。」</p><p>「对每组用滑动窗口求最大值——窗口大小 = min(s_i, 背包剩余容量/v_i)，」李少白接道，「队首始终是窗口内的最优候选。维护队列单调递减（按 dp[k*v_i+r] - k*w_i 的值），新值入队前弹出队尾所有不优的。」</p><p>「O(N*V) 总时间——每种物品 O(V)，N 种物品合计 O(N*V)，」梁嘉峰核算，「相较于二进制拆分的 O(V * sum(log s_i))，单调队列在 s_i 极大时优势显著。」</p><p>矿产在单调队列优化的多重背包下被最优装载。</p>

## 输入描述

<p>第一行两个整数，N，V(0&lt;N≤1000 0&lt;V≤20000)，用空格隔开，分别表示物品种数和背包容积。</p><p>接下来有N行，每行三个整数vi,wi,si用空格隔开，分别表示第i种物品的体积、价值和数量。</p><h4>数据范围</h4><p>0&lt;N≤1000<br />0&lt;V≤20000<br />0&lt;vi,wi,si≤20000</p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">输出一个整数，表示最大价值。</span><br /></p>

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

<h5>提示</h5><p>本题考查多重背包的单调队列优化方法。</p><p><a href="https://www.acwing.com/problem/content/6/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/218/" target="_blank">y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/117236/" target="_blank">参考代码</a></p>

本题改编自AcWing 6. 多重背包问题 III<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20E13%20%E8%83%8C%E5%8C%85DP%20%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85%20%E5%8D%95%E8%B0%83%E9%98%9F%E5%88%97%E4%BC%98%E5%8C%96" target="_blank">B站视频 — E13 背包DP 多重背包 单调队列优化</a></p>
