def print_all_sub(s: str):
	n = len(s)
	count=0
	for i in range(n):
		for j in range(i+1, n):
			if s[i]=='a' and s[j]=='c':
				count+=1
	print(count)


def main():
	s = "aaaacacacaac"
	print_all_sub(s)

if __name__ == '__main__':
	main()