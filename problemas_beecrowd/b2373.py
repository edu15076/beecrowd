def main():
    n = int(input())
    broken = 0

    for _ in range(n):
        l, c = (int(num) for num in input().split())
        if l > c:
            broken += c

    print(broken)

    
if __name__ == '__main__':
    main()
