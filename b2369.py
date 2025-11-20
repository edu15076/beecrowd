def main():
    n = int(input())

    if n <= 10:
        print(7)
    elif n <= 30:
        print(7 + n - 10)
    elif n <= 100:
        print(27 + (n - 30) * 2)
    else:
        print(167 + (n - 100) * 5)


if __name__ == '__main__':
    main()
