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

5 LAB:
Write a PEG-parser for a grammar of simple arithmetic expressions (with integer constants, operation +, *, and parentheses () ),
which generates AST-tree. Use library lingo.

Convert an AST-tree of arithmetic expressions back into a string. Implement a calculator, which computes the value of an arithmetic
expression.

6 LAB: 
Implement a calculator, which uses a reverse polish notation (RPN) expressions with int consts, + and *, and calculates its values.

7 LAB: Enrich the language of arithmetic expressions with subtraction, division, negation and variables.
The new language is a language of algebraic expressions. Write a function, which computes the value of a given algebraic
expression with given set of values of variables (caution: the value is rational).
