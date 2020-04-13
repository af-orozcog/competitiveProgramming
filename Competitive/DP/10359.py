# -*- coding: utf-8 -*-
"""
Created on Wed Apr  1 21:37:22 2020

@author: andre
"""

import sys
def main():
    dp = [0]*256
    for line in sys.stdin:
        a = int(line)
        dp[0] = 1
        dp[1] = 1
        dp[2] = 3
        for i in range(3,a+1):
            dp[i] = dp[i-2]*2 + dp[i-1]
        print(dp[a])
if __name__ == '__main__':
    main()