MAX = 1_000
MOD = 1_000_000_007


def main() -> None:
    m = [[1 for j in range(MAX + 1)] for i in range(MAX + 1)]

    for i in range(1, MAX + 1):
        m[i][i] = (i * m[i - 1][i - 1]) % MOD

    for i in range(2, MAX + 1):
        for j in range(i + 1, MAX + 1):
            m[i][j] = (i * m[i - 1][j - 1] % MOD + i * m[i][j - 1] % MOD) % MOD

    b, g = map(int, input().split())
    while b and g:
        print(m[g][b])
        b, g = map(int, input().split())


if __name__ == '__main__':
    main()
