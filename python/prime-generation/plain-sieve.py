
def prime_generator(N):
    a = [True]*N
    a[0] = a[1] = False
    for k, isprime in enumerate(a):
        if isprime:
            yield k
            for i in range(k*k, N, k):
                a[i] = False

for i, p in enumerate(prime_generator(1299710), start=1):
    print(i, p)

