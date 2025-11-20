def main():
    a, b, c = map(int, input().split())
    x, y, z = map(int, input().split())

    r1 = (x // a) * (y // b) * (z // c)
    r2 = (y // a) * (x // b) * (z // c)
    r3 = (y // a) * (z // b) * (x // c)
    r4 = (z // a) * (y // b) * (x // c)
    r5 = (y // a) * (z // b) * (y // c)
    r6 = (z // a) * (y // b) * (y // c)

    print(max(r1, r2, r3, r4, r5, r6))

    
if __name__ == '__main__':
    main()
