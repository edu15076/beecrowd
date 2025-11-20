def count_min_parts(sequence: list[int]) -> int:
    if len(sequence) <= 1:
        return 1

    dif = sequence[1] - sequence[0]
    parts_count = 1

    sequence.append(0)

    for i, item in enumerate(sequence[1:-1]):
        if dif == item - sequence[i]:
            continue
        dif = sequence[i + 2] - item
        parts_count += 1

    return parts_count


def main() -> None:
    n = int(input())
    sequence: list[int] = list(map(int, input().split()))

    print(count_min_parts(sequence))
    
    
if __name__ == '__main__':
    main()
