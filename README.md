# Flow9
Labs written in Flow9

1 LAB:
Write down a function, which transforms an array of integers into an array of strings, e.g: [1, 2, 3] into ["1", "2", "3"]. Print this array. 
Use functions: map, i2s, strGlue, println.

2 LAB:
Write down a function, which computes the sum of all integers in agiven array: on [1, 2, 3] it will yield 6. Use function: fold.

3 LAB:
Write a function fib(n : int) -> [int], which computes the array of first n Fibonacci numbers: 0, 1, 1, 2, 3, 5, .... Make it:
-recursive
-with tail recursion

4 LAB:
Given an array of integers [n1,...,nk] and a number m, find all pairs of indexes (i, j) such that n[i] + n[j] == m. Signature of a function:

inds(a : [int], m : int) -> [Pair<int, int>]

Complication: make this function of complexity O(n log(n)), not O(n2). Use functions: foldi, makeTree, setTree, lookupTree.
