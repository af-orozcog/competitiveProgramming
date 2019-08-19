a = int(input())
while(a != 0):
	x,y = input("").split()
	x = int(x)
	y = int(y)
	if(x % (y*y) == 0):
		print("NO")
	else:
		printf("YES")
	a -= 1
