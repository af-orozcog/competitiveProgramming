def solve(x,y,z):
    # print(x,y,z,dp[x][y][z])
    if dp[x][y][z]!=-1:
        return dp[x][y][z]
    elif y==0:
        dp[x][y][z]=0
        return dp[x][y][z]
    else:
        dp[x][y][z] = 0
        if x>0:
            dp[x][y][z] += x*solve(x-1,y-1,z+1)
        dp[x][y][z] += z*solve(x,y-1,z)
        return dp[x][y][z]
f = open("dinner.in","r")
fl =f.readlines()
    for l in fl:
    k,n = l.split(" ")
k =  int(k)
n = int(n)
dp = [[[-1 for z in range(k+1)] for y in range(n+1) ] for x in range(k+1)]
dp[0][0][k]=1
solve(k,n,0)
print(dp[k][n][0])