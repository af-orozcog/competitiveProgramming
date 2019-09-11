# -*- coding: utf-8 -*-
"""
Created on Mon Sep  9 09:49:24 2019

@author: Andres
"""

b = int(input())
g = int(input())
n = int(input())
x = 0
y = n
b1 = 0
g1 = 0
ans = 0
while(b >= 0 and g >= 0):
    if(b >g):
        g -= (n-x)
        b -= x
        x += 1
    else:
        b -= y
        g -= (n-y)
        y -= 1
    ans += 1
print(ans)
        
    