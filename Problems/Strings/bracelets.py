from typing import List

def check_bracelets(lst, N):
	if N%2!=0:
		return 0
	lim = int(N/2)
	i=2
	while i <= lim:
		pattern = lst[:i]
		for x in range(i, N, i):
			if pattern != lst[x:x+i]:
				flag = 1
				continue
			else:
				flag = -1
				break
		if flag == 1:
			return 1
		i=i+1
	return 0

def check2(lst: List[int], N: int):
	if N < 4:
		return 0
	else:
		lim = int(N/2) + 1
		for p_len in range(2, lim): # O(n)
			pattern = lst[:p_len]
			for i in range(p_len, N, p_len): # verify pattern is valid
				if pattern != lst[i:i+p_len]:
					break
			else:
				return 1 # detected pattern exists
		return 0 # tried all p_len, found no pattern.

def main():
	a = [1, 2, 1, 1]
	print(check2(a, len(a)))


if __name__ == "__main__":
	main()
