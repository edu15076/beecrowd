def main():
    fib = [1, 1, 1]
    for i in range(3, 1_000_000_001):
        fib.append(fib[i - 1] + fib[i - 2])
    print(fib[-1])

    # while True:
    #     try:
    #         n, m = map(int, input().split())
    #         print(fib[fib[n]] % m)
    
    
if __name__ == '__main__':
    main()
