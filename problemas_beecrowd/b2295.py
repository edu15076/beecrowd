def main():
    a, g, ra, rg = (float(v) for v in input().split())
    if a / ra < g / rg:
        print('A')
    else:
        print('G')


if __name__ == '__main__':
    main()
