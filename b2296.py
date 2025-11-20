def medir_esforco_de_subida(trilha: list[int]) -> int:
    esforco1, esforco2 = 0, 0
    for i in range(1, len(trilha)):
        if trilha[i - 1] > trilha[i]:
            esforco1 += trilha[i - 1] - trilha[i]
        else:
            esforco2 += trilha[i] - trilha[i - 1]
    return min(esforco1, esforco2)


def main():
    trilha_mais_facil: int | None = None
    menor_esforco: int = 10000000000

    n = int(input())
    for i in range(n):
        trilha = list(int(v) for v in input().split())
        trilha.pop(0)
        menor_esforco_trilha = medir_esforco_de_subida(trilha)
        if menor_esforco_trilha < menor_esforco:
            menor_esforco = menor_esforco_trilha
            trilha_mais_facil = i + 1

    print(trilha_mais_facil)
    
    
if __name__ == '__main__':
    main()
