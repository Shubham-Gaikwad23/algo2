# https://www.hackerearth.com/problem/algorithm/the-one-with-the-knights-move-1/
import math


class Graph:
    adj_list: list
    col_trans = {"a": 0, "b": 1, "c": 2, "d": 3, "e": 4, "f": 5, "g": 6, "h": 7}

    def __init__(self):
        self.adj_list = [
            {"c": "white", "p": math.nan, "d": math.inf, "adj": []} for i in range(64)
        ]

    def add_edges(self, n: int):
        for i in range(8):
            for j in range(8):
                vertices = list()
                vertices.append((i - n, j - 1))
                vertices.append((i - n, j + 1))
                vertices.append((i - 1, j + n))
                vertices.append((i + 1, j + n))
                vertices.append((i + n, j + 1))
                vertices.append((i + n, j - 1))
                vertices.append((i + 1, j - n))
                vertices.append((i - 1, j - n))
                current_vtx = i * 8 + j
                for vertex in vertices:
                    if 0 <= vertex[0] <= 7 and 0 <= vertex[1] <= 7:
                        self.adj_list[current_vtx]["adj"].append(vertex[0] * 8 + vertex[1])

    def bfs(self, start: str, end: str):
        src_i, src_j = 8 - int(start[1]), self.col_trans[start[0]]
        dst_i, dst_j = 8 - int(end[1]), self.col_trans[end[0]]
        src = (src_i * 8) + src_j
        dst = (dst_i * 8) + dst_j
        if src == dst:
            return 0

        self.adj_list[src]["d"] = 0
        self.adj_list[src]["c"] = "grey"
        q = [src]
        while q:
            c_vtx = q.pop(0)
            for neighbor in self.adj_list[c_vtx]["adj"]:
                if self.adj_list[neighbor]["c"] == "white":
                    if neighbor == dst:
                        return self.adj_list[c_vtx]["d"] + 1
                    self.adj_list[neighbor]["p"] = c_vtx
                    self.adj_list[neighbor]["d"] = self.adj_list[c_vtx]["d"] + 1
                    self.adj_list[neighbor]["c"] = "grey"
                    q.append(neighbor)
            self.adj_list[c_vtx]["c"] = "black"
        return -1


def main():
    t = int(input())
    while t:
        n = int(input())
        g = Graph()
        g.add_edges(n)
        start, end = input().split()
        print(g.bfs(start, end))
        t = t - 1


if __name__ == '__main__':
    main()
