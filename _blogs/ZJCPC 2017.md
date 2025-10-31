---
layout: default
title: ZJCPC 2017
permalink: /blog/zjcpc-2017/
---

## F. Heap Partition

贪心

## G. Yet Another Game of Stones

如果某一堆是偶数，且要求 Alice 选奇数，那么 Alice 永远也不可能取完这一堆。

方法是：Alice 每取一些，Bob 就取 $1$，这样这一堆始终是偶数。如果 Bob 迫不得已要取这样的堆，就取一个偶数出来。

**所以只要有这样的堆，Alice 就必败。**

同时，可以发现要求 Alice 选奇数且大小不为 $1$ 的堆最多只能有一个，如果有两个及以上 Alice 就必败。因为 Bob 可以把它取成偶数。

对于要求 Alice 选奇数且大小为 $1$ 的堆，可以看作普通 Nim 堆。

同理，对于大小为奇数且要求 Alice 选偶数的堆，Bob 每次在上面取一个偶数即可保证 Alice 不能取完它，除非堆的大小已经变成 $1$。那么这样的堆的最底下一颗石子，Alice 永远取不到，因此只要有一个这样的堆 Alice 必败。

同时，对于大小为偶数且要求 Alice 选偶数的堆，最多只能有一个。这里指的是两种堆的数量之和最多为 $1$。

特判完这些之后就是普通 Nim 游戏了。

## H. Binary Tree Restoring

用第一个 DFS 序给第二个 DFS 序重编号。

然后贪心地放就好了？

