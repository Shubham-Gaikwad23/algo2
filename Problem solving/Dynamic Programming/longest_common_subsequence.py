from typing import List
# X = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"
# Y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA"  #"GTCGTCGGAAGCCGGCCGAA"

def LCS(X: str, Y: str) -> int:
	m = len(X)
	n = len(Y)
	t = [[0 for i in range(n+1)] for i in range(m+1) ] 

	for i in range(1, m+1):
		for j in range(1, n+1):
			if X[i-1] == Y[j-1]:
				t[i][j] = t[i-1][j-1] + 1
			else:
				t[i][j] = max( t[i][j-1], t[i-1][j] )
	return t

def LCS_rec(X, Y):
	m = len(X)
	n = len(Y)
	t = [ [0 if x==0 or y==0 else None for y in range(n+1)] for x in range(m+1) ] 
	def LCS_aux(i, j): 
		if t[i][j] is not None:
			return t[i][j]
		else:
			if X[i-1] == Y[j-1]:
				t[i-1][j-1] = LCS_aux(i-1, j-1)
				t[i][j] = t[i-1][j-1] + 1
			else:
				t[i][j-1] = LCS_aux(i, j-1)
				t[i-1][j] = LCS_aux(i-1, j)
				t[i][j] = max(t[i][j-1], t[i-1][j])
			return t[i][j]
	return LCS_aux(m, n)


def print_lcs(X: str, Y: str, t: List[List[int]], i, j):
	if i==0 or j==0:
		return
	elif X[i-1] == Y[j-1]:
		print_lcs(X, Y, t, i-1, j-1)
		print(X[i-1], end='')
	else:
		up = t[i-1][j]
		left = t[i][j-1]
		if up > left:
			print_lcs(X, Y, t, i-1, j)
		else:
			print_lcs(X, Y, t, i, j-1)


def main():
	X ='abcba'
	X = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"
	Y ='abcbcba'
	Y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA"
	t = LCS(X, Y)
	print_lcs(X, Y, t, len(X), len(Y))

if __name__ == '__main__':
	main()



