def max_subarray(d_chng):
	


def main():
	price = [10, 22, 5, 75, 65, 80]
	d_chng = [ 0 ]
	for i in range(1, len(price)):
		d_chng.append(price[i]-price[i-1])

	print(d_chng)


if __name__ == '__main__':
	main()