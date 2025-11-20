def is_possible_position(cifer: str, crib: str, start: int) -> bool:
    for c1, c2 in zip(cifer[start:], crib):
        if c1 == c2:
            return False
    return True


def count_possible_positions(cifer: str, crib: str) -> int:
    count = 0

    for i in range(len(cifer) - len(crib) + 1):
        count += is_possible_position(cifer, crib, i)
    return count


def main() -> None:
    cifer, crib = input(), input()
    print(count_possible_positions(cifer, crib))
    
    
if __name__ == '__main__':
    main()
