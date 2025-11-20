def main() -> None:
    n, k = map(int, input().split())
    quantidades_por_rotulo = [0 for _ in range(k)]
    for rotulo in map(int, input().split()):
        quantidades_por_rotulo[rotulo - 1] += 1
    print(min(quantidades_por_rotulo))
    
    
if __name__ == '__main__':
    main()
