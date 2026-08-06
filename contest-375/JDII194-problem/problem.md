# JDII194 最长升序·登山览胜

- 比赛：集训队试炼02 线性DP
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>九曲回廊深处，一条险峻山道蜿蜒而上。赵晴儿仰望云雾中若隐若现的群峰，轻声道：「这条山道共有 N 座观景台由西向东一字排开，每座观景台都有一个海拔高度。剑道宗的登山规矩是——从西向东行，先上山后下山。也就是说，先经过海拔严格递增的若干观景台，到达某个最高点后，再经过海拔严格递减的若干观景台。」</p><p>「这就是最长双调子序列——也叫登山问题，」李少白在沙盘上画出N个高度，「设 inc[i] 为以第i个位置结尾的最长上升子序列长度，dec[i] 为以第i个位置开头的最长下降子序列长度。那么以第i个观景台为峰顶时，能游览的总观景台数 = inc[i] + dec[i] - 1。」</p><p>「inc 和 dec 都可以用 O(N²) 的朴素 DP 求解——当然，若能二分优化到 O(N log N) 更好，」赵晴儿补充道，「最终答案取所有位置作为峰顶的最大值。」</p><p>「注意——不允许只上升不下降，也不允许只下降不上升。所以峰值两侧至少各有一个点。」梁嘉峰提醒，「不过若山顶恰在两端，答案即是 inc[N]+dec[1]-1。」</p><p>三人拾级而上，在双调登山算法的指引下登顶览胜。</p>

## 输入描述

<p>第一行包含整数 N，表示观景台数量。</p><p>第二行包含 N 个整数，表示每座观景台的海拔高度。</p><p><strong>数据范围</strong></p><p>2 ≤ N ≤ 1000</p>

## 输出描述

<p>输出一个整数，表示最多能游览的观景台数量。</p>

## 样例

### 样例 1

#### 输入

```text
8
186 186 150 200 160 130 197 220
```

#### 输出

```text
4
```

## 提示

<p style="margin-left: 0px;"><a href="https://www.acwing.com/problem/content/1016/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/solution/content/51645/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/video/357/" target="_blank">Y总讲解</a><br /></p><p><a href="https://www.acwing.com/activity/content/code/content/112800/" target="_blank">Y总代码</a></p>

本题改编自AcWing 1014. 登山<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E7%99%BB%E5%B1%B1" target="_blank">B站视频 — 搜索</a></p>
