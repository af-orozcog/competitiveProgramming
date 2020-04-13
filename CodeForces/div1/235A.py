# -*- coding: utf-8 -*-
"""
Created on Mon Mar 30 11:12:22 2020

@author: andre
"""

def gcd(a,b):
    if(b == 0):
        return a
    else:
        return gcd(b,a%b)

def lcm(a,b):
    return (a//gcd(a,b))*b

a = int(input())
if(a == 1):
    print(1)
elif(a == 2):
    print(2)
else:
    ans = 0
    who1 = 0
    who2 = 0
    who3 = 0
    for i in range(max(a-55,1),a+1):
        for j in range(i,a+1):
            for k in range(j,a+1):
                ans = max(ans,lcm(lcm(i,j),k))
    print(ans)
    