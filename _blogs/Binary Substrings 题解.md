---
layout: default
title: Binary Substrings 题解
permalink: /blog/binary-substrings--ti-jie/
---

# Binary Substrings 题解

首先考虑上界：对于长度为 $i$ 的串而言，至多有 $\min(2^i,n-i+1)$ 个。因此上界为唯一且存在的 $k$ 满足 $2^k\le n-k+1\le 2^{k+1}+1$，使得长度 $\le k$ 的所有串都出现，而 $>k$ 的串各不相同，则答案为 $2^{k+1}-1+(n-k)(n+1-k)/2$。

