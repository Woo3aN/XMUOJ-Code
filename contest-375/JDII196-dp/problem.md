# JDII196 线性DP·友好城邦

- 比赛：集训队试炼02 线性DP
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>南北两岸各有 n 座城邦，南岸第 i 座城邦与北岸第 a_i 座城邦之间有一条古老的灵道。试炼要求：选出尽可能多的灵道，使得任意两条选中的灵道不相交——即若 i &lt; j，则 a_i &lt; a_j 也必须成立。</p><p>「这本质上是求 a 数组的最长上升子序列（LIS），」李少白一眼看穿，「因为无交条件等价于——选出的配对 (i, a_i) 在两维上同时递增。当 i 自然排序后，a_i 必须也递增。」</p><p>「O(N log N) 的耐心排序法——维护 tails 数组，」赵晴儿快速展开，「遍历 a_i，在 tails 中二分查找第一个 ≥ a_i 的位置并替换；若无，则追加到末尾。tails 的最终长度即为 LIS 长度——也就是最多不相交的灵道数。」</p><p>「南北城邦的友好灵道——正是 LIS 最经典的应用场景之一，」梁嘉峰点头，「N ≤ 2*10^5 时 O(N log N) 从容应对。」</p><p>灵道在 LIS 算法下选出最多的不相交配对。</p>

## 输入描述

<p>第1行，一个整数N，表示城市数。</p><p>第2行到第n+1行，每行两个整数，中间用1个空格隔开，分别表示南岸和北岸的一对友好城市的坐标。</p><p><strong>数据范围</strong>1≤N≤5000</p>

## 输出描述

<p>仅一行，输出一个整数，表示政府所能批准的最多申请数。</p>

## 样例

### 样例 1

#### 输入

```text
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2
```

#### 输出

```text
4
```

## 提示

<p style="margin-left: 0px;"><a href="https://www.acwing.com/problem/content/1014/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/solution/content/51858/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/video/357/" target="_blank">Y总讲解</a><br /></p><p><a href="https://www.acwing.com/solution/content/51858/" target="_blank">Y总代码</a></p>

本题改编自AcWing 1012. 友好城市<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E5%8F%8B%E5%A5%BD%E5%9F%8E%E5%B8%82" target="_blank">B站视频 — 搜索</a></p>
