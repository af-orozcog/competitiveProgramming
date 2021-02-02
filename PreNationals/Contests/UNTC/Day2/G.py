t = int(input())
while t != 0:
    t -= 1
    n = int(input())
    lel = bin(n)[3:]
    ans = 100000000000
    temp = 1
    for char in lel:
        if char == '1':
            ans = min(ans,temp)
            temp = 0
        temp += 1
    ans = min(ans,temp)
    print(ans)