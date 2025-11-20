def main():
    n, m = map(int, input().split())

    while n != -1:
        c = [int(i) for i in input().split()]
        tempo = 0
        for i in c:
            tempo += m * i
        print(tempo)
        n, m = map(int, input().split())


if __name__ == '__main__':
    main()
