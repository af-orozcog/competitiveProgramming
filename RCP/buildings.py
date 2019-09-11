import fractions

M = 1000000007

from sys import stdin as inp

n, m, c = map(int, inp.readline().split())

N = c**(n*n)

def phi(d):
    tot = 0        
    for i in range(1, d + 1):
        if fractions.gcd(d, i) == 1:
            tot += 1
    return tot

def gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = gcd(b % a, a)
        return (g, x - (b // a) * y, y)

def inversemod(n, M): 
    g, x, y = gcd(n, M)
    return x % M

def collar(k, n):
    res = 0

    for d in range(1, int(n**0.5)+1):
        if n%d != 0:
            continue
        
        #print(d)
        res += phi(d) * k**(n//d)

        if d**2 != n:
            d2 = n//d
            res += phi(d2) * k**(n//d2)
            res %= M

    return (res * inversemod(n, M)) % M

#print(inversemod(N, M))

print(collar(N%M, m))