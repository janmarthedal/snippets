import heapq

def prime_generator(N):
    a = [True]*N
    a[0] = a[1] = False
    for (k, isprime) in enumerate(a):
        if isprime:
            yield k
            for i in range(k*k, N, k):
                a[i] = False

#print(','.join(map(str, prime_generator(10000))))

class PriQueue:
    def __init__(self):
        self.heap = []

    def peek(self):
        return self.heap[0]

    def push(self, item):
        heapq.heappush(self.heap, item)

    def pop(self):
        return heapq.heappop(self.heap)


def primes2():
    queue = PriQueue()
    yield 2
    queue.push((4, 2))
    n = 3
    while True:
        while n < queue.peek()[0]:
            yield n
            queue.push((n*n, n))
            n += 1
        while queue.peek()[0] == n:
            top = queue.pop()
            queue.push((top[0] + top[1], top[1]))
        n += 1

for p in primes2():
    if p > 10000000:
        break
    print(p)
