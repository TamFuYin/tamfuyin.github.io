---
layout: default
title: The 3rd Universal Cup. Stage 1 St. Petersburg
permalink: /blog/the-3rd-universal-cup-stage-1-st-petersburg/
---

# The 3rd Universal Cup. Stage 1: St. Petersburg

前言：由于胡乱鼓捣 git，把 The 3rd Universal Cup. Stage 2: Zielona Góra.md 给删掉了，沉痛悼念

## A. Element-Wise Comparison

看到这种神秘的判断条件和神秘的数据范围首先想到 bitset。然后用一个 baka's trick 维护即可。

## B. Schoolgirls

神秘几何题，不想做。

## C. Cherry Picking

从大到小插入元素，维护连续段长度。用一个 ODT 状物维护即可

## D. Dwarfs' Bedtime

思路：每隔 $25$ 次问一次，那么在第一次碰到这个点之后可以确定在一个长为 $25$ 的区间内，第二次快到这个点的时候挨着问即可。然后加一点随机化大概就能过了（$25±2$

## E. Fake Coin and Lying Scales

最抽象，或许读一些信息论会有益

假设我们进行了 $l$ 次称重操作，其中有 $v$ 次谎言（我们不知道谎言的分布），我们能得到什么信息？

我们本能得到 $3^l$ 的信息（左边重、右边重、一样重）。但是如果两种假币分布，在这 $l$ 次操作中，如果存在一种谎言分布，使其得到的「观测序列」完全相同，那么我们不能把这两种情况区分。

我们设 $p(l,v)$ 表示当假币分布固定时，对于所有谎言的可能性，其产生的所有观测序列的数量。可以看作谎言对信息的影响。

满足
$$
p(l,v)=2p(l-1,v-1)+p(l-1,v)
$$

意思是：如果这一次不说谎，那么本该是多少就是多少，否则会多两种。

那么答案即为信息的总量，即
$$
f(n,k)=\frac{(3k+1)3^n}{p(n,k)}
$$

身为 CNOI 选手，你大概一眼就能看出 $p(n,k)=\sum_{j=0}^k\binom nj2^j$。

这道题只需要求出来答案的量级，所以取 $p(n,k)\approx \binom nk2^k$ 即可。math.h 里面有一个 lgamma 的函数，顾名思义就是 $\ln \Gamma(n)$。用这个算阶乘就可以了。

特别地，如果 $k$ 比较大，那么最大那一项不在 $k$，而是 $(2n-1)/3$ 左右。

## F. The Whole World

根据《混凝土数学》里面的一个~~可能~~经典的结论，所有在整点取整值的多项式必然可以表示为：
$$
f(x)=\sum_{i=0}^da_i\binom xi
$$
其中 $a_i\in\Z$。

然后高斯消元就完了。

## G. Unusual Case

挑 战 N P C

图随机，感觉直接爆搜就完了

## H. Page on vdome.com

注意到 $10$ 就是不可能出现的数字了，答案比 $10$ 还小只有 $N$ 为个位数的情况，此时答案为 $N+1$

## I. Spin & Rotate!

~~没看懂，感觉会很水？~~ 很困难

## J. First Billion

挑 战 N P C

想法：类似 meet in the middle，注意到比较小的数比较灵活，所以枚举前 $20$ 个数的所有集合和，然后在后 $N-20$ 个数里面随机抽样。但是过不了。

正解：贪心地把数字分到 $B=36$ 个桶里面，使其尽量均匀。然后做 meet in the middle

## K. Tasks and Bugs

这不噗叽组题吗

## L. Candies

这不噗叽组题吗

## M. Toilets

依题意模拟即可，注意如果碰到一个人进厕所的时间比自己还晚，就把他踢出来。用线段树维护。

## N. (Un)labeled graphs

通信题。

首先给的 $\lceil \log_2 n\rceil$ 个点显然是要你把点的标号表示出来。

然后再新添一个点连向所有原图的结点，这个点一定是度数最大的点，解码时找到这个点后就能找到原图的点。

但是我们不知道二进制位之间的顺序，考虑按顺序连成一条链，再新增一个点连向除最后一个点外的所有点。

## O. Mysterious Sequence

？？？我能加 10 个零

直接矩阵乘法就好了