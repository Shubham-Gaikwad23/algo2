import math
from typing import List


class Graph:
    adj_list = []
    nV: int

    def __init__(self, grid: List[List[int]], p: int, q: int):
        self.nV = p * q
        for i in range(p):
            for j in range(q):
                node = {
                    "adj": set(),
                    "c": "white",
                    "p": math.nan,
                    "d": math.inf,
                    "i": False,
                }
                if grid[i][j] == 1:
                    node["i"] = True
                    if 0 <= j - 1 <= q - 1 and grid[i][j - 1] == 1:
                        node["adj"].add(i * q + (j - 1))
                    if 0 <= j + 1 <= q - 1 and grid[i][j + 1] == 1:
                        node["adj"].add(i * q + (j + 1))
                    if 0 <= i - 1 <= p - 1 and grid[i - 1][j] == 1:
                        node["adj"].add((i - 1) * q + j)
                    if 0 <= i + 1 <= p - 1 and grid[i + 1][j] == 1:
                        node["adj"].add((i + 1) * q + j)
                self.adj_list.append(node)

    def find_regions(self):
        pass



class Solution:
    def containVirus(self, grid: List[List[int]]) -> int:
        p, q = len(grid), len(grid[0])  # Dimensions of graph
        g = Graph(grid, p, q)


def main():
    grid = [[0, 1, 0, 0, 0, 0, 0, 1],
            [0, 1, 0, 0, 0, 0, 0, 1],
            [0, 0, 0, 0, 0, 0, 0, 1],
            [0, 0, 0, 0, 0, 0, 0, 0]]
    s = Solution()
    s.containVirus(grid)


if __name__ == '__main__':
    main()

    # def add_edges(self, p: int, q: int):
    #     for i in range(p):
    #         for j in range(q):
    #             vtx_id = i * q + j
    #             if j != 0:
    #                 self.adj_list[vtx_id]["adj"].append(vtx_id - 1)
    #             if j != q - 1:
    #                 self.adj_list[vtx_id]["adj"].append(vtx_id + 1)
    #     for j in range(q):
    #         for i in range(p):
    #             vtx_id = i * q + j
    #             if i != 0:
    #                 self.adj_list[vtx_id]["adj"].append(vtx_id - q)
    #             if i != p - 1:
    #                 self.adj_list[vtx_id]["adj"].append(vtx_id + q)