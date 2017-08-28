"""
    Fibonacci number Series
"""


def fib_memorized_version(lookup, n):
    if n == 0 or n == 1:
        lookup[n] = n
    if lookup[n] is None:
        lookup[n] = fib_memorized_version(lookup, n-1) + fib_memorized_version(lookup, n-2)

    return lookup[n]


def fib_tabulated_version(n):
    f = [0]*(n+1)

    f[1] = 1

    # calculating the fibonacci and storing the values
    for i in range(2, n+1):
        f[i] = f[i-1] + f[i-2]
    return f[n]


n = 4
lookup = [None]*100
print("Memorized Version")
print("Fibonacci Number is", fib_memorized_version(lookup, n))
print("Tabulated Version")
print("Fibonacci Number is", fib_tabulated_version(n))
