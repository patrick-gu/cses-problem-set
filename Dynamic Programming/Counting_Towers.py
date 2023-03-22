"""
Inefficient solution for exploring answers
"""
import functools

@functools.cache
def solve(a, b):
    if a == 0 and b == 0:
        return 1
    if a == b:
        return sum(solve(i, i) for i in range(a)) + sum(solve(i, a) for i in range(a))
    if a > b:
        a, b = b, a
    return 2 ** (b - a - 1) * sum(solve(i, a) for i in range(a + 1))
 
for i in range(10):
    print(f"{i=} {solve(i, i)=}")