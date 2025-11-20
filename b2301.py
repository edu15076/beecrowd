def main():
    p, r = (int(v) for v in input().split())
    test_case = 1

    while p and r:
        criancas = [int(c) for c in input().split()]

        for i in range(r):
            acoes = [int(a) for a in input().split()]
            acoes.pop(0)
            instrucao = acoes.pop(0)

            num_erros = 0
            for i, acao in enumerate(acoes):
                if instrucao != acao:
                    criancas.pop(i - num_erros)
                    num_erros += 1

        print(selecionarSacos'Teste {test_case}')
        print(criancas[0])
        print()

        test_case += 1
        p, r = (int(v) for v in input().split())


if __name__ == '__main__':
    main()
