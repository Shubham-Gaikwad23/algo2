def make_palindrome(s: str):
	table = dict()
	n = int(len(s)/2)
	for c in s:
		count = table.get(c)
		if count:
			table[c] += 1
		else:
			table[c] = 1

	pal = ""
	mid = ""
	odd=False
	for c, count in table.items():
		if count%2==0:
			pal = c*int(count/2) + pal + c*int(count/2)
		else:
			if count==1:
				if odd:
					return None
				odd=True
				mid = c
			else:
				return None
	return pal[:n] + mid + pal[n:]
				

def main():
	s = input()
	print(make_palindrome(s))


if __name__ == '__main__':
	main()