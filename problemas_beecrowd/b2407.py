def are_items_from_1_to_n(square: list[list[int]]) -> bool:
    area = len(square) ** 2

    items = set()

    for line in square:
        for item in line:
            if item > area or item in items:
                return False
            items.add(item)

    return True


def sum_main_diagonal(square: list[list[int]]) -> int:
    return sum(square[i][i] for i in range(len(square)))


def sum_secondary_diagonal(square: list[list[int]]) -> int:
    n = len(square)
    return sum(square[i][n - i - 1] for i in range(n))


def sum_line(square: list[list[int]], i: int) -> int:
    return sum(square[i])


def sum_column(square: list[list[int]], j: int) -> int:
    return sum(line[j] for line in square)


def is_square_magical(square: list[list[int]]) -> int:
    if not are_items_from_1_to_n(square):
        return 0

    k = sum_main_diagonal(square)

    if sum_secondary_diagonal(square) != k:
        return 0

    for i in range(len(square)):
        if sum_line(square, i) != k or sum_column(square, i) != k:
            return 0

    return k


def main():
    n = int(input())
    square = [[int(item) for item in input().split()] for _ in range(n)]
    print(is_square_magical(square))
    
    
if __name__ == '__main__':
    main()
