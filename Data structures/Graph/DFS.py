import math

from typing import List


class Graph:
    adj_list: list
    n: int
    _time: int

    def __init__(self, n: int):
        self.adj_list = []
        self.n = n
        self._time = 0
        for i in range(n):
            node = {
                "i": i,
                "adj": [],
                "d": math.nan,
                "f": math.nan,
                "c": "white",
                "p": math.nan,
            }
            self.adj_list.append(node)

    def add_edges(self, adj_mat: List[List[int]]) -> None:
        """
        Build adjacency list from the given adjacency matrix
        :param adj_mat: Adjacency matrix of the graph
        :return: None
        """
        for i in range(self.n):
            for j in range(self.n):
                if adj_mat[i][j] == 1:
                    self.adj_list[i]["adj"].append(j)

    def dfs(self) -> None:
        """
        Run DFS and build DFS tree.
        Information is stored in the nodes of the graph as attributes as follows:
        Parent, discovery time, finish time, color,
        :return: None
        """
        for u in self.adj_list:
            if u["c"] == "white":
                self._dfs_visit(u)

    def _dfs_visit(self, u: dict):
        self._time += 1
        u["d"] = self._time
        u["c"] = "grey"
        for index_of_v in u["adj"]:
            v: dict = self.adj_list[index_of_v]
            if v["c"] == "white":
                v["p"] = u["i"]
                self._dfs_visit(v)
        u["c"] = "black"
        self._time += 1
        u["f"] = self._time

    def test(self):
        for node in self.adj_list:
            print(node)


def main():
    adj_mat = [
        [0, 1, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 1, 0],
        [0, 0, 0, 0, 0, 1, 0],
        [0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]
    g = Graph(len(adj_mat))
    g.add_edges(adj_mat)
    g.dfs()
    g.test()


if __name__ == '__main__':
    main()
