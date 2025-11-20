def main():
    n = int(input())
    bolos = [input() for _ in range(n)]

    print('S' if max(bolos) == bolos[0] else 'N')
    
    
if __name__ == '__main__':
    main()
