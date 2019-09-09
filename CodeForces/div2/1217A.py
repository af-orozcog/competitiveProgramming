# -*- coding: utf-8 -*-
"""
Created on Mon Sep  9 10:10:39 2019

@author: Andres
"""
#I do it because of Valentina, she motivates me :)

T = int(input())
while(T != 0):
    re = input()
    s = int(re.split(" ")[0])
    i = int(re.split(" ")[1])
    e = int(re.split(" ")[2])
    hi = e
    lo = 0
    ans = -1
    while(hi >= lo):
        mid = (hi+lo)//2
        if(s + mid > (e-mid)+i and s + (mid-1) <= (e-mid+1)+ i ):
            ans = mid
            break
        elif(s + mid > (e-mid)+i):
            #print(s+mid)
            hi = mid - 1
        else:
            lo = mid + 1
        #print(lo)
        #print(hi)
    if(ans == -1 and s <= e):
        print(0)
    elif(ans == -1):
        print(1)
    else:
        #print(ans)
        print((e-ans)+1)
    T -= 1