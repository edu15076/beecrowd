def main():
    jogos = []

    for i in range(15):
        resultado = tuple(int(gols) for gols in input().split())
        jogos.append(resultado[0] > resultado[1])

    jogos.reverse()
    jogos.insert(0, None)

    index = 1
    for i in range(4):
        index = index * 2 + 1 if jogos[index] else index * 2
    index -= 16
    index = 15 - index

    print(chr(index + ord('A')))
    
    
if __name__ == '__main__':
    main()
