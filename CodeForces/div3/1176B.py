#Why the fuck am i doing this shit
t = int(input())
while(t > 0):
	n = int(input())
	see = map(int,input().split(" "))
	mods = [0,0,0]
	for i in see:
		mods[i%3] +=1
	ans = min(mods[1],mods[2])
	mods[1] -= ans
	mods[2] -= ans
	#print(mods[1])
	#print(mods[2])
	print(ans + mods[0] +mods[2]//3 + mods[1]//3)
	t-=1
