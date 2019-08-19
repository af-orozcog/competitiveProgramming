  
def strr(leng, letter):
	a = "abcdefghijklmnopqrstuvwxyz"
	counter = 0
	answer = ""
	each = leng / letter
	each = int(each)
	actual = 0
	num = 0
	while(counter < leng):
		answer = answer + a[actual]
		num += 1
		if(num == each and actual < letter - 1):
			num = 0
			actual += 1
		counter += 1
	return answer

a = int(input())
for i in range(a):
	b,c = input().split()
	b = int(b)
	c = int(c)
	print(strr(b, c))
