import fractions

from sys import stdin as inp

n, m, c = map(int, inp.readline().split())

N = c**(n*n)

def phi(d):
    tot = 0        
    for i in range(1, d + 1):
        if fractions.gcd(d, i) == 1:
            tot += 1
    return tot

def collar(N, k):
    res = 0

    for d in range(1, int(N**0.5)+1):
        if N%d != 0:
            continue
        
        #print(d)
        res += phi(d) * k**(N/d)

        d2 = N//d
        if d**2 != N:
            res += phi(d2) * k**(N/d2)

    return int(res / N)

print(collar(m, N))