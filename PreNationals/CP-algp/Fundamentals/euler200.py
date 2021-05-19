import bisect
t = int(input(""))

sums = []
vals = []
MAX = 4*(10**16)
fi,se = 0,1
while(fi <= MAX):
    temp = fi+se
    if(fi%2 == 0):
        vals.append(fi)
        add = fi
        if(len(sums)):
            add += sums[-1]
        sums.append(add)
    fi = se
    se = temp

while t > 0:
    n = int(input(""))
    pos = bisect.bisect_right(vals,n,0,len(sums))-1
    print(sums[pos])
    t -= 1
