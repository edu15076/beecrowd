from math import factorial


def main() -> None:
    while True:
        n, q = map(int, input().split())
        if not n and not q:
            break
        t = int(input())
        word_count = factorial(n - (q - 1))  # agrupam as palavras

        print(word_count if word_count <= t else "descartado")
    
    
if __name__ == '__main__':
    main()
