class Graph:
	def __init__(self, n: int):
		self.n = n
		for x in range(n):
			self.nodes.append({"adj": [], "key": math.inf, "p": math.nan})

	def add_edge(self, src: int, dst: int):
		self.nodes[src]["adj"].append(dst)


def main():
	g = Graph(9)
	w = [ [0]*9 ]*9
	
	g.add_edge(0,1)
	w[0][1] = 4

	g.add_edge(1,2)
	w[0][1] = 8

	g.add_edge(2,3)
	w[0][1] = 7

	g.add_edge(3,4)
	w[0][1] = 9

	g.add_edge(4,5)
	w[0][1] = 10

	g.add_edge(5,6)
	w[0][1] = 2

	g.add_edge(6,7)
	w[0][1] = 1

	g.add_edge(7,0)
	w[0][1] = 8

	g.add_edge(7,1)
	w[0][1] = 11

	g.add_edge(7,8)
	w[0][1] = 7

	g.add_edge(0,1)
	w[0][1] = 4

	g.add_edge(0,1)
	w[0][1] = 4

	g.add_edge(0,1)
	w[0][1] = 4

	g.add_edge(0,1)
	w[0][1] = 4




if __name__ == '__main__':
	main()