from math import sqrt
n = int(input())
n = 2*n
ans = 0
upTo = sqrt(n)
for i in range(1,int(upTo+1)):
    if(n % i == 0):
        check = n - (i*i)+i
        if(check % (2*i) == 0): ans += 1
        ot = n // i
        if(ot != i):
            check = n - (ot*ot)+ot
            if(check % (2*ot) == 0): ans += 1

print(ans)