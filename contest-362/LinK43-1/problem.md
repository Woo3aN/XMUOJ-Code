# LinK43 求二进制中1的个数

- 比赛：2026年程序设计实践例题(05李胜睿班)
- 题型：OI
- 难度：Low
- 语言：C, C++

## 题目描述

<p><span style="color: rgb(51, 51, 51);"><img alt="料理.gif" src="/public/upload/f9ed434226.gif" width="489" height="366" /><br /></span></p><p>为了寻找失去的回忆碎片，林克必须预备足够的料理。能够快速突破数独试炼，熟练运用lowbit，才能把难题转换为美味佳肴。</p><p><span style="color: rgb(51, 51, 51);">请用lowbit解决如下问题：</span></p><p><span style="color: rgb(51, 51, 51);">输入一个32位整数，输出该数二进制表示中1的个数。</span><br /></p><p>注意：</p><ul><li>负数在计算机中用其绝对值的补码来表示。</li></ul>

## 输入描述

<pre><code style="font-family: Menlo, Monaco, Consolas, &quot;Courier New&quot;, monospace; font-size: inherit; padding: 0px; color: inherit; background: transparent; border-radius: 3px; margin: 0px; border: none;">输入：9
输出：2
解释：9的二进制表示是1001，一共有2个1。</code></pre>

## 输出描述

<pre><code style="font-family: Menlo, Monaco, Consolas, &quot;Courier New&quot;, monospace; font-size: inherit; padding: 0px; color: inherit; background: transparent; border-radius: 3px; margin: 0px; border: none;">输入：-2
输出：31
解释：-2在计算机里会被表示成11111111111111111111111111111110，
      一共有31个1。</code></pre>

## 样例

### 样例 1

#### 输入

```text
-2
```

#### 输出

```text
31
```

### 样例 2

#### 输入

```text
9
```

#### 输出

```text
2
```

## 提示

<p><a href="https://www.bilibili.com/video/BV1Kf4y1S7mB" target="_blank">Andy讲解</a><br /></p>
