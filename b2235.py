def main():
    creditos = [int(num) for num in input().split()]
    creditos.sort()

    print('S' if creditos[0] == creditos[1] or creditos[1] == creditos[2] or creditos[0] + creditos[1] == creditos[2] else 'N')
    
    
if __name__ == '__main__':
    main()
