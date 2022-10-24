import cmath_func
import time

def fib_rec(n):
    """Fucntion to get nth Fibonacci number using recursion. For speed test only

    Args:
        n (int): nth fibonacci number you want.

    Returns:
        int: nth Fibonacci number
    """
    if n == 1 or n == 2:
        return 1
    else:
        return fib_rec(n-1) + fib_rec(n-2)


# calling C functions
print(cmath_func.fib_iter(5))
print(cmath_func.isprime(22))

# speed test
n = 35

# Python
s = time.time()
print(fib_rec(n))
print(f"time taken by Python: {time.time() - s}")

# C
s = time.time()
print(cmath_func.fib_rec(n))
print(f"time taken by C: {time.time() - s}")
