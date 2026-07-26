# JDII138 网格DP·摘取花生

- 比赛：集训队试炼01 DP基础入门
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>回廊旁有一片花生田，田地被分成一行行的垄。每株花生下面标着它结了几颗花生——有些肥硕，有些瘦小。梁嘉峰指着田地西北角说：「从这儿出发，走到东南角。每次只能向东或向南走一步。路过一株花生就拿走——最多能摘多少？」</p><p>李少白试着走了一遍：「这还不简单？贪心——每次都往花生多的方向走。」</p><p>赵晴儿摇头，在地上画了一个 2×2 的格子：「看——左上 1，右上 100，左下 10，右下 1。贪心会先往右走拿到 100，但这样一共只能拿到 1+100+1=102。如果先往下拿 10，再往右拿 1……等等，那也只有 12。不对，应该是 1+100+1=102……不对不对——」</p><p>梁嘉峰笑道：「你也算乱了。这就是为什么需要 DP——不是每一步选最大，而是<strong>整体最优</strong>。dp[i][j] = 走到 (i,j) 时最多摘的花生数 = max(dp[i-1][j], dp[i][j-1]) + a[i][j]。第一行和第一列只有一种走法，单独初始化。」</p><p>「这个 DP 和数字三角形如出一辙，只是方向从顶到底变成了从西北到东南。」李少白恍然大悟，「都是二维网格上的递推。」</p><p>给定一个 R 行 C 列的花生田，从左上角走到右下角，每次只能向东或向南。求能摘到的花生总数最大值。</p>

## 输入描述

<p>第一行是一个整数<code>T</code>，代表一共有多少组数据。</p><p>接下来是<code>T</code>组数据。</p><p>每组数据的第一行是两个整数，分别代表花生苗的行数<code>R</code>和列数<code>C</code>。</p><p>每组数据的接下来<code>R</code>行数据，从北向南依次描述每行花生苗的情况。每行数据有<code>C</code>个整数，按从西向东的顺序描述了该行每株花生苗上的花生数目<code>M</code>。</p><p><strong>数据范围</strong></p><p>1 ≤<code>T</code>≤ 100</p><p>1 ≤<code>R</code>，<code>C</code>≤ 100</p><p>0 ≤<code>M</code>≤ 1000</p>

## 输出描述

<p>对每组输入数据，输出一行，内容为Hello Kitty能摘到得最多的花生颗数。</p>

## 样例

### 样例 1

#### 输入

```text
2
2 2
1 1
3 4
2 3
2 3 4
1 6 5
```

#### 输出

```text
8
16
```

## 提示

<p><a href="https://www.acwing.com/problem/content/1017/" target="_blank">原题链接</a></p><p><a href="http://www.example.comhttps://www.acwing.com/video/2332/" target="_blank">Y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/112796/" target="_blank">Y总代码</a></p>

本题改编自AcWing 1015. 摘花生<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E6%91%98%E8%8A%B1%E7%94%9F" target="_blank">B站视频 — 搜索</a></p>
