import math


class Graph:
    no_of_vertices: int
    nodes = list()

    def __init__(self, no_of_vertices: int):
        self.no_of_vertices = no_of_vertices
        for x in range(no_of_vertices):
            self.nodes.append({"adj_nodes": list(), "color": "white", "d": math.inf, "p": math.nan})

    def add_edge(self, src: int, dst: int):
        self.nodes[src]["adj_nodes"].append(dst)
    #
    # def get_adj_nodes(self, x:int):
    #     return self.nodes[x]
    #
    # def __str__(self):
    #     return str(self.nodes)


if __name__ == '__main__':
    g = Graph(5)

    g.add_edge(0, 1)
    g.add_edge(0, 4)

    g.add_edge(1, 0)
    g.add_edge(1, 2)
    g.add_edge(1, 4)

    g.add_edge(2, 1)

    g.add_edge(3, 4)

    g.add_edge(4, 0)
    g.add_edge(4, 1)
    g.add_edge(4, 3)

    src_vertex = 0
    g.nodes[0]["color"] = "gray"
    g.nodes[0]["d"] = 0
    g.nodes[0]["p"] = math.nan

    q = [src_vertex]

    while len(q) != 0:
        u = q[0]
        q.remove(u)
        for v in g.nodes[u]["adj_nodes"]:
            if g.nodes[v]["color"] == "white":
                g.nodes[v]["color"] = "gray"
                g.nodes[v]["d"] = g.nodes[u]["d"] + 1
                g.nodes[v]["p"] = u
                q.append(v)
        g.nodes[u]["color"] = "black"

    x = 2
    while x is not math.nan:
        print(x)
        x = g.nodes[x]["p"]
