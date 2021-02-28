from typing import List

def activity_sel(s: List[int], f: List[int]):
	n = len(s)
	def act_sel_rec(k: int):
		m = k + 1
		while m < n and s[m] < f[k]:
			m += 1
		if m < n:
			return [m] + act_sel_rec(m)
		else:
			return []
	return act_sel_rec(0)

def activity_sel_iterative(s: List[int], f: List[int]):
	act = [1]
	n = len(s)
	k = 1
	for m in range(2, n):
		if s[m] >= f[k]:
			act.append(m)
			k = m
	return act

def act_sel_DP(s: List[int], f: List[int]):
	s.append(f[-1] + 1)
	f.append(s[-1] + 1)
	n = len(s)
	c = [ [None]*n for _ in range(n) ]
	def act_sel_DP_aux(i, j):
		if c[i][j] is not None:
			return c[i][j]

		S = []
		for x in range(i+1, j):
			if s[x] > f[i] and f[x] < s[j]:
				S.append(x)
		if not S:
			return 0
		else:
			q = 0
			for k in S:
				c[i][k] = act_sel_DP_aux(i, k)
				c[k][j] = act_sel_DP_aux(k, j)
				q = max(q, c[i][k] + c[k][j] + 1)
			return q
	return act_sel_DP_aux(0, n-1)



def main():
	s = [-1, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
	f = [0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]

	max_set = act_sel_DP(s, f)
	print(max_set)

if __name__ == '__main__':
	main()