from typing import Iterable


MOD = 1_000_000_000 + 7


class SymmetricMatrix(list):
    _identities: dict[int, 'SymmetricMatrix'] = {}

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        if len(self) != len(self[0]):
            raise ValueError('Matrix has to be square')

    @classmethod
    def _multiply_lines(cls, l1: Iterable, l2: Iterable):
        return sum((i * j % MOD for i, j in zip(l1, l2))) % MOD

    @classmethod
    def get_identity(cls, n: int) -> 'SymmetricMatrix':
        if n not in cls._identities:
            cls._identities[n] = SymmetricMatrix(
                [[int(i == j) for j in range(n)] for i in range(n)])
        return cls._identities[n]

    @property
    def identity(self):
        return self.get_identity(len(self))

    @classmethod
    def _multiply_matrix(cls, m1: list[list], m2: list[list]) -> 'SymmetricMatrix':
        if len(m1) != len(m2):
            raise ValueError('Matrix m1 and m2 must have same length')
        n = len(m1)
        return SymmetricMatrix([
            [cls._multiply_lines(m1[i], m2[j]) for j in range(n)] for i in range(n)
        ])

    def __mul__(self, other) -> 'SymmetricMatrix':
        return self._multiply_matrix(self, other)

    @classmethod
    def _pow(cls, n: 'SymmetricMatrix', times: int) -> 'SymmetricMatrix':
        if not times:
            return n.identity

        div, mod = times >> 1, times & 1
        result = cls._pow(n * n, div)

        return result * n if mod else result

    def __pow__(self, n: int) -> 'SymmetricMatrix':
        return self._pow(self, n)


class Solution:
    def __init__(self):
        self.numbers = ['010', '012', '020', '021', '101', '102',
                        '120', '121', '201', '202', '210', '212']
        self.adj_matrix = self._get_adj_matrix()

    def _has_conection(self, column1: int, column2: int) -> bool:
        c1, c2 = self.numbers[column1], self.numbers[column2]
        return c1[0] != c2[0] and c1[1] != c2[1] and c1[2] != c2[2]

    def _get_adj_matrix(self) -> list[list[int]]:
        return [[int(self._has_conection(i, j)) for j in range(12)] for i in range(12)]

    def solve(self, n: int) -> int:
        walks = SymmetricMatrix(self.adj_matrix) ** (n - 1)
        return 6 * ((sum(walks[0]) % MOD + sum(walks[1]) % MOD) % MOD) % MOD


def main() -> None:
    n = int(input())
    print(Solution().solve(n))


if __name__ == '__main__':
    main()
