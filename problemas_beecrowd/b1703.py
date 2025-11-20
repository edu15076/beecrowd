def cfor(start, stop: callable, step: callable = lambda i: 1):
    i = start
    while stop(i):
        yield i
        i = step(i)


def lowest_prime_factor(n: int, start: int = 2) -> int:
    if start <= 3:
        if not n & 1:
            return 2
        if not n % 3:
            return 3
        start = 5

    for i in cfor(start, lambda i: i * i <= n, lambda i: i + (i - 3) % 6):
        if not n % i:
            return i

    return n


def is_prime(n: int) -> bool:
    return 1 < n and (n <= 3 or not (n + 1) % 6 or not (n - 1) % 6) and n == lowest_prime_factor(n)


def factorize(n: int) -> dict[int, int]:
    prime_factors = {}
    low = 2

    while n != 1:
        low = lowest_prime_factor(n, low)
        prime_factors[low] = 1
        n //= low
        while not n % low:
            prime_factors[low] += 1
            n //= low

    return prime_factors


def number_of_factors_less_or_equal_to_k(n: int, k: int) -> int:
    count = 0
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            if i <= k:
                count += 1
            pair_factor = n // i
            if pair_factor != i and pair_factor <= k:
                count += 1
    return count


def main() -> None:
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        print(f'{number_of_factors_less_or_equal_to_k(k, n) / n:.12f}')
    
    
if __name__ == '__main__':
    main()
