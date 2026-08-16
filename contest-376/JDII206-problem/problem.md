# JDII206 完全背包·货币体系(二)

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Mid
- 语言：C, C++, Java, Python3

## 题目描述

<p>货币试炼的第二重更为深刻——给定 n 种面额的灵币（每种无限使用），试炼的问题是：用这 n 种面额能否表示出任意的正整数面额？若能，最小的无法表示的正整数面额是多少？这触及了货币体系的完备性。</p><p>「此乃数论中的 Frobenius 硬币问题（Frobenius Coin Problem）的变体，」赵晴儿沉思道，「更直接的做法是 DP + 贪心——将面额从小到大排序。设当前能连续表示的最大面额为 cur。对于每个面额 v：若 v &gt; cur + 1，则 cur + 1 无法被表示——它就是答案。否则 cur += v（因为 v ≤ cur+1 意味着我们可以用 v 和之前的硬币表示 cur+1 到 cur+v 的所有面额）。」</p><p>「前提是所有面额的最大公约数 GCD = 1——否则只能表示 GCD 的倍数，」李少白补充关键条件，「若 GCD=1 且所有 v 都 ≤ cur+1 逐一接续，则体系完备。」</p><p>「面额排序、贪心拓展、GCD 判基——」梁嘉峰收剑入鞘，「cur 从 0 起步，逐枚灵币推进：若能接续则扩展，若遇断层则 cur+1 即为答案。灵币体系之完备性，三步定矣。」</p><p>货币体系的完备性在贪心 + 排序下被判定。</p>

## 输入描述

<p>输入文件的第一行包含一个整数T，表示数据的组数。</p><p>接下来按照如下格式分别给出T组数据。</p><p>每组数据的第一行包含一个正整数n。</p><p>接下来一行包含n个由空格隔开的正整数a[i]。</p><h4>数据范围</h4><p>1≤n≤100,<br />1≤a[i]≤25000,<br />1≤T≤20</p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">输出文件共有</span><span style="color: rgb(51, 51, 51);">T</span><span style="color: rgb(51, 51, 51);">行，对于每组数据，输出一行一个正整数，表示所有与</span><span style="color: rgb(51, 51, 51);">(</span><span style="color: rgb(51, 51, 51);">n</span><span style="color: rgb(51, 51, 51);">,</span><span style="color: rgb(51, 51, 51);">a</span><span style="color: rgb(51, 51, 51);">)</span><span style="color: rgb(51, 51, 51);">等价的货币系统</span><span style="color: rgb(51, 51, 51);">(</span><span style="color: rgb(51, 51, 51);">m</span><span style="color: rgb(51, 51, 51);">,</span><span style="color: rgb(51, 51, 51);">b</span><span style="color: rgb(51, 51, 51);">)</span><span style="color: rgb(51, 51, 51);">中，最小的</span><span style="color: rgb(51, 51, 51);">m</span><span style="color: rgb(51, 51, 51);">。</span><br /></p>

## 样例

### 样例 1

#### 输入

```text
2 
4 
3 19 10 6 
5 
11 29 13 19 17 
```

#### 输出

```text
2
5
```

## 提示

<p><a href="https://www.acwing.com/problem/content/534/" target="_blank">原题连接</a></p><p><a href="https://www.acwing.com/video/388/" target="_blank">y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/120226/" target="_blank">参考代码</a></p>

本题改编自AcWing 532. 货币系统<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E8%B4%A7%E5%B8%81%E7%B3%BB%E7%BB%9F%20II" target="_blank">B站视频 — 搜索</a></p>
