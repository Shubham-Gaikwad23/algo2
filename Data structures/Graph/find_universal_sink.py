def find_sink(m, n):
	v = [x for x in range(n)]

	while n != 1:
		i, j = v.pop(), v.pop()
		if m[i][j] == 0:
			n -= 1
		else:
			v.append(j)
		if m[j][i] == 0:
			n -= 1
		else:
			v.append(i)

	return v[0]


def main():
	m = [
		[0,0,0,1,0],
		[1,0,0,1,0],
		[1,0,0,1,0],
		[0,0,0,0,0],
		[0,0,0,1,0],
	]

	print(find_sink(m, 5)+1)


if __name__ == '__main__':
	main()