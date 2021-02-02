import sys
def binExp(n,x):
    ans = 1
    while x != 0:
        if(x % 2 == 1): ans = ans * n
        n *= n
        x = x//2
    return ans

def fraction(val):
    if val == 1:
        return 1
    imp = 10
    ans = "0."
    while imp != 0:
        if imp < val:
            ans += "0"
        else:
            ans += str(imp//val)
            imp = imp % val
        imp *= 10
    return ans

i = 1
seen = {}
while i <= 100:
    j = 1
    while j*i <= 100:
        seen[j*i] = fraction(j*i)
        j *= 5
    i *= 2

for line in sys.stdin:
    a,n = line.split()
    a = int(a)
    n = int(n)
    if a == 1 or n == 0:
        print(0,1)
        continue
    elif a not in seen:
        print("Precision Error")
        continue
    imp = seen[a]
    imp = int(seen[a][2:])
    ansL = (len(seen[a])-2)*n
    check = binExp(imp,n)
    print(ansL,check)