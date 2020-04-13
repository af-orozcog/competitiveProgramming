# -*- coding: utf-8 -*-
"""
Created on Sun Mar 29 16:02:22 2020

@author: andre
"""

n = int(input())

ans = []
ans.append(10)
su = 10
imp = 10
less = 10
for i in range(2,n+1):
    less += su
    #print("less is ", less)
    less %= 998244353
    imp *= 10
    imp = imp % 998244353
    see = (i*imp)%998244353
    see = (see - less)
    if(see < 0): 
        see += 998244353
    ans.append(see)
    su += see
    less += see
ans.reverse()
for i in ans:
    print(i, end = " ")