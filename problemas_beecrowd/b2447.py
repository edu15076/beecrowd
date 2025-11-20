MOD = 1_000_000_007


def arrangement(a: int, b: int) -> int:
    if a < b:
        return 0
    r = 1
    for i in range(a - b + 1, a + 1):
        r = (r * i) % MOD
    return r


def perm(a: int) -> int:
    return arrangement(a, a)


def pow2(num: int) -> int:
    return (1 << num) % MOD


def fatorial_em_intervalo(a, b=0) -> int:
    x = 1

    for i in range(a, b, -1):
        x *= i
        x = x % MOD

    return x


def arranjo(n, k) -> int:
    if k > n:
        return 0

    return fatorial_em_intervalo(n, n - k)


def compute_wining_positions(n: int, g: int) -> int:
    if g:
        return 0
    return perm(pow2(n))


def compute_positions_that_lose_at_k(k: int, n: int, l: int, g: int) -> int:
    if k == n + 1:
        return compute_wining_positions(n, g)
    if l < pow2(k - 1) - 1 or not g:
        return 0

    key = pow2(k - 1)

    x = (arranjo(l, key - 1) * 2 ** n
         * (arranjo(g + l - key + 1, key) - arranjo(l - key + 1, key))
         * fatorial_em_intervalo(2 ** n - 2 ** k))
    print(x % MOD)

    return (arrangement(l, key - 1) * pow2(n) % MOD *
            (arrangement(g + l - key + 1, key) - arrangement(l - key + 1, key)) % MOD *
            perm(pow2(n) - pow2(k)) % MOD)


def main() -> None:
    n, k = map(int, input().split())
    j = int(input())
    l, g = 0, 0
    for i in range(pow2(n) - 1):
        p = int(input())
        if p < j:
            l += 1
        else:
            g += 1
    print(compute_positions_that_lose_at_k(k, n, l, g))


if __name__ == '__main__':
    main()
