from typing import List
from math import inf as infinity

def mat_chain(i, j):
	global p, n
	global m, s
	if m[i][j] != infinity:
		return m[i][j]
	else:
		for k in range(i, j):
			q = mat_chain(i, k) + mat_chain(k+1, j) + p[i-1]*p[k]*p[j]
			if q < m[i][j]:
				m[i][j] = q
				s[i][j] = k

		return m[i][j]

def print_paran(s, i, j):
	if i==j:
		print(f" A{i} ", end='')
	else:
		print("(", end='')
		print_paran(s, i, s[i][j])
		print_paran(s, s[i][j]+1, j)
		print(")", end='')


def main():
	global p, n
	global m, s
	p = [30, 35, 15, 5, 10, 20, 25] #p = [int(x) for x in input().split()] [5 10 3 12 5 50 6]
	n = len(p) - 1

	m = [ [ (0 if i==j else infinity) for j in range(n+1) ] for i in range(n+1) ]
	s = [ [None for i in range(n+1)] for i in range(n+1) ] 

	mat_chain(1, n)

	print("\n\n")
	print_paran(s, 1, n)
	print("\n\n")

if __name__ == '__main__':
	main()



















