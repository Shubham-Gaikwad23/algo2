def main():
	a = [
		[1,  2,  3,  4],
		[5,  6,  7,  8],
		[9,  10, 11, 12],
		[13, 14, 15, 16],
		[-1, -2, -3, -5],
	]

	while a:
		# print first row and delete it
		for x in a[0]:
			print(x, end=' ')
		del a[0]

		# print last col and delete it
		if a:
			for x in a:
				print(x[-1], end=' ')
				del x[-1]

		# print last row and delete it
		if a:
			stk = []
			for x in a[-1]:
				stk.append(x)
			del a[-1]
			while stk:
				print(stk.pop(), end=' ')

		# print first col and delete it
		if a:
			stk = []
			for x in a:
				stk.append(x[0])
				del x[0]
			while stk:
				print(stk.pop(), end=' ')

	
if __name__ == '__main__':
	main()














	# #init
	# i=j=0
	# print(a[i][j])
	# i=i-1
	
	# limit = 3
	# while limit:
	# 	lim = limit
	# 	i=i+1
	# 	j=j+1
	# 	# go right
	# 	while lim:
	# 		print(a[i][j])
	# 		j+=1
	# 		lim-=1

	# 	lim = limit
	# 	j=j-1
	# 	i=i+1
	# 	# down
	# 	while lim:
	# 		print(a[i][j])
	# 		i+=1
	# 		lim-=1

	# 	lim = limit
	# 	i=i-1
	# 	j=j-1
	# 	# left
	# 	while lim:
	# 		print(a[i][j])
	# 		j-=1
	# 		lim-=1
		
	# 	lim = limit-1
	# 	j=j+1
	# 	i=i-1
	# 	# up
	# 	while lim:
	# 		print(a[i][j])
	# 		i-=1
	# 		lim-=1
		
	# 	limit = limit - 1