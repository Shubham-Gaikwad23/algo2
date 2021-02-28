class Graph:
	def __init__(self, n: int):
		self.n = n
		self.adj = [ [] for _ in range(n) ]

	def add_edge(self, u: int, v: int):
		self.adj[u].append(v)

	def is_adj(self, u: int, v: int):
		return v in self.adj[u]



def main():
	g = Graph(7)
	g.add_edge(0, 1)
	g.add_edge(0, 2)
	g.add_edge(1, 3)
	g.add_edge(1, 4)
	g.add_edge(2, 5)
	g.add_edge(2, 6)

	adj_mat = [ [0]*g.n for _ in range(g.n) ]
	for i in range(g.n):
		for j in g.adj[i]:
			adj_mat[i][j] = 1

	h = Graph(g.n)
	for i in range(g.n):
		for j in g.adj[i]:
			h.add_edge(j, i)

	for row in h.adj:
		print(row)



	# g = Graph(5)
	# g.add_edge(0, 1)
	# g.add_edge(1, 2)
	# g.add_edge(1, 4)
	# g.add_edge(3, 0)
	# g.add_edge(3, 2)
	# g.add_edge(4, 3)

	# for row in g.adj:
	# 	print(row)



if __name__ == '__main__':
	main()