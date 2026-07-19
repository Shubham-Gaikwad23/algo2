from typing import List
from math import inf as infinity


def cut_rod(n):
	global r, p
	if r[n] >= 0:
		return r[n]

	if n==0:
		q = 0
	else:
		q = -infinity
		for i in range(1, n+1):
			q = max(q, p[i] + cut_rod(n-i))

	r[n] = q
	return q

def cut_rod_non_rec(p: List[int], n):
	r = [0]
	
	for j in range(1, n+1):
		q = -infinity
		for i in range(1, j+1):
			q = max(q, p[i] + r[j-i])
		r.append(q)

	return r


def main():
	p = [ 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
	n = len(p) - 1
	print(cut_rod_non_rec(p, n))


if __name__ == '__main__':
	main()