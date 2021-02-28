from typing import List
from math import inf as infinity

def mat_chain_bu(p, n):
	m = [ [ (0 if i==j else infinity) for j in range(n+1) ] for i in range(n+1) ]
	s = [ [None for i in range(n+1)] for i in range(n+1) ] 

	for l in range(2, n+1):
		for i in range(1, n-l+2):
			j = i+l-1		# m[i, i+len-1]
			for k in range(i, j):
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
				if q < m[i][j]:
					m[i][j] = q
					s[i][j] = k
	return m, s

def print_paran(s, i, j):
	if i==j:
		print(f" A{i} ", end='')
	else:
		print("(", end='')
		print_paran(s, i, s[i][j])
		print_paran(s, s[i][j]+1, j)
		print(")", end='')


def main():
	p = [30, 35, 15, 5, 10, 20, 25] #p = [int(x) for x in input().split()] [5 10 3 12 5 50 6]
	n = len(p) - 1
	m, s = mat_chain_bu(p, n)
	print("\n\n")
	print_paran(s, 1, n)
	print("\n\n")

if __name__ == '__main__':
	main()