# JDII201 01背包·精装巧纳

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>剑阁库房中，N 件灵器体积庞大，乾坤袋容量为 V。与寻常 01 背包不同——每件灵器的体积 v_i 和价值 w_i 完全相同（即价值密度为 1）。看似简单，但 N 和 V 均可大至 10^6，O(N*V) 的 DP 数组根本无法开出。</p><p>「价值=体积时的特殊 01 背包——等价于用体积块拼出尽量接近 V 的总和，」李少白洞察本质，「直接用 bitset 优化——bitset 的每一位表示该容量是否可达。初始 bitset[0] = 1。对每个物品 v_i：bitset = bitset | (bitset &lt;&lt; v_i)。」</p><p>「bitset 的移位和或运算每次 O(V/wordsize)，」赵晴儿补充，「若用 C++ bitset，V=10^6 时每件物品的操作仅需 ~15,625 次 word 运算。总复杂度 O(N*V/64)，在 N 和 V 均为 10^6 时勉强可通过。」</p><p>「bitset 是处理可达性背包的利器，」梁嘉峰总结，「简洁、高效、常数极小。」</p><p>灵器在 bitset 优化的背包下完美填满乾坤袋。</p>

## 输入描述

<p>第一行是一个整数 V，表示箱子容量。</p><p>第二行是一个整数 n，表示物品数。</p><p>接下来 n 行，每行一个正整数（不超过10000），分别表示这 n 个物品的各自体积。</p><h4>数据范围</h4><p>0&lt;V≤20000<br />0&lt;n≤30</p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">一个整数，表示箱子剩余空间。</span><br /></p>

## 样例

### 样例 1

#### 输入

```text
24
6
8
3
12
7
9
7
```

#### 输出

```text
0
```

## 提示

<p><a href="https://www.acwing.com/problem/content/description/1026/" target="_blank">原题连接</a></p><p><a href="https://www.acwing.com/video/369/" target="_blank">y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/115329/" target="_blank">参考代码</a></p>

本题改编自AcWing 1024. 装箱问题<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E9%87%87%E8%8D%AF" target="_blank">B站视频 — 搜索</a></p>
