def LIS(S):
	n = len(S)
	maximum = 0
	length = [None]*n
	length[0] = 1
	l = [None]*n
	l[0] = 0
	for i in range(1, n):
		curr_max = 0
		curr_index = None
		for j in range(i):
			if S[l[j]] <= S[i] and curr_max < length[j]+1:
				curr_max = length[j]+1

		if length[i-1] < curr_max:
			length[i] = curr_max
			l[i] = i
		else:
			length[i] = length[i-1]
			l[i] = l[i-1]

		if maximum < length[i]:
			maximum = length[i]	

	return maximum



def main():
	S = [10, 22, 9, 33, 21, 50, 41, 60, 80]
	print(LIS(S))

if __name__ == '__main__':
	main()