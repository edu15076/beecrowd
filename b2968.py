from math import ceil


def main():
    v, n = map(int, input().split())
    placas = v * n
    p = [ceil(placas * (i / 10)) for i in range(1, 10)]
    print(*p)
    
    
if __name__ == '__main__':
    main()
