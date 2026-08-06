# JDII193 最长升序·滑翔之翼

- 比赛：集训队试炼02 线性DP
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>苍穹之上，三人御剑飞行。剑道的高度沿着一条山脉起伏——n 座山峰由西向东排列，高度分别为 h_1, h_2, ..., h_n。从某座山峰出发向东滑翔——每座山只能比前一座更高——问从哪座山出发能滑翔最远？</p><p>「最长上升子序列——不过需要求从每个位置出发的结果，」李少白俯瞰山脉，「正向 LIS——dp1[i] 表示以 i 结尾的最长上升子序列长度。反向 LIS——从右向左做一次，dp2[i] 表示以 i 开头的最长上升子序列长度。」</p><p>「从 i 出发的最远滑翔距离 = dp2[i]，」赵晴儿计算，「正向 dp1 需要 O(N log N) 的耐心排序法——tails 数组维护。反向 dp2 只需将数组反转后同样处理。」</p><p>「两遍 LIS O(N log N)，」梁嘉峰确定起点，「找到 dp2[i] 最大的那个 i 即为最佳起点。若需要求从每个点出发的结果，dp2 数组即是答案。」</p><p>滑翔之翼在双向 LIS 的指引下找到最远的翱翔路线。</p>

## 输入描述

<p>输入数据第一行是一个平行的整数K，代表有K组测试数据。</p><p>每组测试数据包含两行：第一行是一个整数N，代表有N幢建筑。第二行包含N个不同的整数，每一个对应一幢建筑的高度h，按照建筑的排列顺序给出。</p><p><strong>数据范围</strong></p><p>1≤K≤100</p><p>1≤N≤100</p><p>0&lt;h&lt;10000</p>

## 输出描述

<p>对于每一组测试数据，输出一行，包含一个整数，代表怪盗基德最多可以经过的建筑数量。</p>

## 样例

### 样例 1

#### 输入

```text
3
8
300 207 155 299 298 170 158 65
8
65 158 170 298 299 155 207 300
10
2 1 3 4 5 6 7 8 9 10
```

#### 输出

```text
6
6
9
```

## 提示

<p style="margin-left: 0px;"><a href="https://www.acwing.com/problem/content/1019/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/solution/content/51431/" target="_blank">参考题解</a></p><p><a href="https://www.acwing.com/video/359/" target="_blank">Y总讲解</a><br /></p><p><a href="https://www.acwing.com/activity/content/code/content/112799/" target="_blank">Y总代码</a><br /></p>

本题改编自AcWing 1017. 怪盗基德的滑翔翼<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E6%80%AA%E7%9B%97%E5%9F%BA%E5%BE%B7%E7%9A%84%E6%BB%91%E7%BF%94%E7%BF%BC" target="_blank">B站视频 — 搜索</a></p>
