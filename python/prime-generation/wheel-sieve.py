
WHEEL = (4, 2, 4, 2, 4, 6, 2, 6)

def prime_generator(N):
    for k in [2, 3, 5]:
        if k < N:
            yield k 
    a = [True]*N
    k = 7
    wheel_index = 0
    while k < N:
        if a[k]:
            yield k
            i = k*k
            wi = wheel_index
            while i < N:
                a[i] = False
                i += k*WHEEL[wi]
                wi = (wi + 1) % len(WHEEL)
        k += WHEEL[wheel_index]
        wheel_index = (wheel_index + 1) % len(WHEEL)

if True:
    for i, p in enumerate(prime_generator(1299710), start=1):
        print(i, p)
else:
    import timeit
    def test():
        for i, p in enumerate(prime_generator(1299710), start=1):
            pass
    print(timeit.timeit('test()', setup='from __main__ import test', number=10))

