from math import log


def main() -> None:
    n = int(input())
    sups = [e * log(b) for b, e in (map(int, input().split()) for _ in range(n))]
    print(sups.index(max(sups)))
    
    
if __name__ == '__main__':
    main()
