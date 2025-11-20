def main():
    n, c = (int(num) for num in input().split())

    quantidade_pessoas = 0
    quantidade_maxima_pessoas = 0

    for i in range(n):
        s, e = (int(num) for num in input().split())
        quantidade_pessoas += e - s
        quantidade_maxima_pessoas = max(quantidade_maxima_pessoas, quantidade_pessoas)

    print('S' if quantidade_maxima_pessoas > c else 'N')
    
    
if __name__ == '__main__':
    main()
