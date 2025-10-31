---
layout: default
title: Petrozavodsk Winter 2025. Day 2. National Taiwan U Contest
permalink: /blog/petrozavodsk-winter-2025-day-2-national-taiwan-u-contest/
---

# Petrozavodsk Winter 2025. Day 2. National Taiwan U Contest

## AmazingTalker

首先显然「互为师生」的关系是好的，我们优先选完这样的关系。

我们把问题聚焦到在前面没有连边的点上，我们决定给他找**一个**先生。

但是，一个先生有了过多的学生是不行的。

显然这些要找先生的学生，有两种决策，不妨记作 $x$ 和 $y$。

发现形如二分图匹配，考虑 Hall 定理。

每个学生向 $x$ 或者 $y$ 比他小的先生连边，我们已知每个先生最多允许的度数，求是否存在完美匹配。

那么合法当且仅当，对于每个第一象限内的左下角矩形 $(x,y)$，$(x,y)$ 内的先生的度数之和，都 $\ge$ 学生的个数。

好像很难做，但是我们的学生是有特殊性质的——只有左下角和右上角有点。

所以可以直接排成一排，从小到大地贪心匹配即可。

## Bob and Alice

Bob 终于当了一回先手！！！真是不容易。

显然每一堆是独立的，甚至每一堆的每个质因子都是独立的。

设 $x$ 在 $p$ 上的指数为 $\nu_p(x)$，则每一堆在 $p$ 上最多取走 $\nu_p(x)$。

于是我们转化为了一个 $n$ 堆的 Nim 游戏 $\{a_i\}$，每堆每次能取一个 $0\le x_i\le b_i$，但是不能全部选 $0$。

貌似没有简单的结论



## Checkered Fabric

这不是噗唧组题吗

## Dangerous Numbers

AC 自动机板子。

首先你特判以下是否存在一个长度，所有串都不能选。

然后你找到最早的匹配位置即可

## Election Campaign

~~我会追忆 $\sout{O(n^2/w)}$~~

考虑环基。

然后你发现只要存在奇环，答案就是 $0$，否则为 $1$。

特判全部同色的情况，此时答案为最短路。

## Flappy Bird

宝宝题

## Game Manipulation

每次选掉最大值肯定是最优的。

## Humorous Teacher T NeVeR LosEs

直接 DP 就做完了

设 $f_{i,j}$ 表示做了前 $i$ 次，其中前缀和的最大值为 $j$，前面都是合法的，的概率。

## Inversion Revisit

考虑如何快速判断 **NO**。

也就是看是否存在 $p_j>p_i$ 但是 $q_j<q_i$。

也就是求出所有 $p_j>p_i$ 的元素中 $q_j$ 的最小值，不难用树状数组维护前缀 min。

## Judge Error

众所周知带花树是 $O(nm^2)=O(n^5)$ 的，但是跑不满，所以有可能过！（不是

根据[Kotzig's theorem on perfect matchings](https://arxiv.org/pdf/1402.0949)，一个点双连通图如果存在完美匹配，那么至少存在两个完美匹配。

考虑圆方树，或者其实没有必要。有一个很聪明的想法。

考虑一个生成树，如果子树内结点个数为奇数，且**没有**连出子树外的边，那么我们可以发现这个点与父亲的边是*必选的*。

然后就可以把这两个点删掉了，递归继续做。

由于上面的定理，我们必然可以找到这样的边。

怎么判断这个东西呢？有一个很巧妙的方法——异或哈希。

给每条边赋一个随机权值，每个点的权值是所有邻边的权值的异或值。

我们算出子树异或和，然后判断其是否等于父边即可。

## Kalends, Nones, and Ides

感觉比儒略历简单

## Legendary Counting Problem

拆贡献宝宝题

## Malus' Law

排序即可