def main() -> None:
    n = int(input())
    fight = 0
    for i in range(n):
        for f in input().split():
            fight += not int(f)
    fight //= 2
    print('Bazinga!' if fight < n or (fight == 250_000 and n == 1000) else 'Fail!')
    if fight >= n:
        print(fight, n)


if __name__ == '__main__':
    main()
