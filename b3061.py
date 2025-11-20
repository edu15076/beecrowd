import sys


sys.setrecursionlimit(10000000)


moves = (0, 1), (0, -1), (1, 0), (-1, 0)


def pos_in_matrix(matrix: list, pos: tuple):
    return len(matrix) > pos[0] >= 0 and len(matrix[0]) > pos[1] >= 0


def apaga_mancha(pele: list, pos: tuple):
    if not pos_in_matrix(pele, pos) or not pele[pos[0]][pos[1]]:
        return False

    pele[pos[0]][pos[1]] = 0

    for move in moves:
        apaga_mancha(pele, (pos[0] + move[0], pos[1] + move[1]))
    return True


def main():
    n, m = tuple(int(number) for number in input().split())
    pele = [[int(item) for item in input().split()] for _ in range(n)]

    manchas = 0

    for i in range(n):
        for j in range(m):
            manchas += apaga_mancha(pele, (i, j))
            
    print(manchas)


if __name__ == '__main__':
    main()
