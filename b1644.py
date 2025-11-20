def find_pos_cycle(pos: int, seed: list[int]) -> int:
    current_pos = seed[pos]
    cycle = 1

    while current_pos != pos:
        current_pos = seed[current_pos]
        cycle += 1
    return cycle


def shift_pos(pos: int, m: int, seed: list[int]) -> int:
    for i in range(m):
        pos = seed[pos]
    return pos


def unhash(m: int, seed: list[int], s: str) -> str:
    unhased_s = []
    for i, p in enumerate(seed):
        pos_cycle = find_pos_cycle(p, seed)
        shifted_pos = shift_pos(i, (pos_cycle - m % pos_cycle) % pos_cycle, seed)
        unhased_s.append(s[shifted_pos])
    return ''.join(unhased_s)


def main() -> None:
    while True:
        n, m = map(int, input().split())
        if not n and not m:
            break
        seed = list(map(lambda x: int(x) - 1, input().split()))
        s = input()
        print(unhash(m, seed, s))
    
    
if __name__ == '__main__':
    main()
