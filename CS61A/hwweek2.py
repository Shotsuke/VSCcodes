from operator import add, mul


def square(x): return x * x
def identity(x): return x
def triple(x): return 3 * x
def increment(x): return x + 1


def product(n, term):
    i, result = 1, 1
    while i <= n:
        result *= term(i)
        i = i+1
    return result


def accumulate(merger, start, n, term):
    total, k = start, n
    while k >= 1:
        total, k = merger(total, term(k)), k - 1
    return total


def summation_using_accumulate(n, term):
    return accumulate(add, 0, n, term)


def product_using_accumulate(n, term):
    return accumulate(mul, 1, n, term)


def funception(func1, start):
    def func2(stop):
        i, product = start, 1
        if start < 0:
            return None
        elif start >= stop:
            return func1(start)
        else:
            while i < stop:
                product *= func1(i)
                i += 1
            return product
    return func2


def mul_by_num(num):
    return lambda x: x*num


def mod_maker():
    return lambda x, y: x % y or True


def add_results(f1, f2):
    return lambda x: f1(x) + f2(x)
