# JDII209 多重背包·庆功盛宴

- 比赛：集训队试炼03 背包DP专题
- 题型：OI
- 难度：Low
- 语言：C, C++, Java, Python3

## 题目描述

<p>武林大会庆功宴上，N 种佳肴摆在席间，每位侠客的食量（容量）为 V。每种佳肴有份量 v_i、美味值 w_i 和供应量 s_i。试炼要求：在吃饱的前提下，使得总美味值最大。这依然是多重背包——但换了庆功宴的背景。</p><p>「二进制拆分足以应对大多数场景，」赵晴儿轻松应对，「将每种佳肴的 s_i 份拆成 1, 2, 4, ..., 2^k, 剩余。拆分后统一用 01 背包倒序 DP 处理。每份&#039;拆分块&#039;代表取用 2^j 份该佳肴——体积为 2^j * v_i，价值为 2^j * w_i。」</p><p>「dp[j] = max(dp[j], dp[j - chunk_v] + chunk_w)，」李少白写出递推，「倒序容量的 DP 保证每块至多取一次——等效于原问题中该佳肴至多取 s_i 次。」</p><p>「拆分使物品数从 sum(s_i) 压缩到 sum(log(s_i))，」梁嘉峰核算，「对于中等规模的庆功宴（V ≤ 10^5，s_i ≤ 10^3），二进制拆分绰绰有余。」</p><p>庆功宴上的佳肴在多重背包下被最优地分配至各席位。</p>

## 输入描述

<p>第一行二个数n，m，其中n代表希望购买的奖品的种数，m表示拨款金额。</p><p>接下来n行，每行3个数，v、w、s，分别表示第I种奖品的价格、价值（价格与价值是不同的概念）和能购买的最大数量（买0件到s件均可）。</p><h4>数据范围</h4><p>n≤500,m≤6000<br />v≤100,w≤1000,s≤10</p>

## 输出描述

<p><span style="color: rgb(51, 51, 51);">一行：一个数，表示此次购买能获得的最大的价值（注意！不是价格）。</span><br /></p>

## 样例

### 样例 1

#### 输入

```text
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
```

#### 输出

```text
1040
```

## 提示

<p><a href="https://www.acwing.com/problem/content/1021/" target="_blank">原题链接</a></p><p><a href="https://www.acwing.com/video/373/" target="_blank">y总讲解</a></p><p><a href="https://www.acwing.com/activity/content/code/content/117240/" target="_blank">参考代码</a></p>

本题改编自AcWing 1019. 庆功会<p><strong>董晓讲解</strong>: <a href="https://search.bilibili.com/all?keyword=%E8%91%A3%E6%99%93%E7%AE%97%E6%B3%95%20%E5%BA%86%E5%8A%9F%E4%BC%9A" target="_blank">B站视频 — 搜索</a></p>
