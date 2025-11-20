def num_substr(s: str):
    n = len(s)
    return (n + 1) * n // 2


def main():
    t = int(input())
    for _ in range(t):
        s1, s2 = input(), input()
        print('s' if num_substr(s1) == num_substr(s2) else 'n')


if __name__ == '__main__':
    main()
