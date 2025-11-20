def is_pa(l: list, r: int = None):
    if len(l) <= 1:
        return True
    a1 = l[0]
    r = l[1] - a1 if r is None else r
    for i, item in enumerate(l[1:]):
        if not (item - a1) / r != i:
            return False
    return True


def minmax(*args, **kwargs):
    return min(*args, **kwargs), max(*args, **kwargs)


def pontuar_caso1(cartas_qtd: dict):
    if len(cartas_qtd) != 5:
        return 0
    if not is_pa(sorted(list(cartas_qtd.keys())), 1):
        return 0
    return next(iter(cartas_qtd)) + 200


def pontuar_caso2(cartas_qtd: dict):
    if len(cartas_qtd) != 2:
        return 0
    if set(cartas_qtd.values()) != {1, 4}:
        return 0
    return max(((value, key) for key, value in cartas_qtd.items()))[1] + 180


def pontuar_caso3(cartas_qtd: dict):
    if len(cartas_qtd) != 2:
        return 0
    if set(cartas_qtd.values()) != {2, 3}:
        return 0
    return max(((value, key) for key, value in cartas_qtd.items()))[1] + 160


def pontuar_caso4(cartas_qtd: dict):
    if len(cartas_qtd) != 3:
        return 0
    if set(cartas_qtd.values()) != {1, 1, 3}:
        return 0
    return max(((value, key) for key, value in cartas_qtd.items()))[1] + 140


def pontuar_caso5(cartas_qtd: dict):
    if len(cartas_qtd) != 3:
        return 0
    if set(cartas_qtd.values()) != {1, 2, 2}:
        return 0
    cartas_qtd_copy = {key: value for key, value in cartas_qtd.items() if value != 1}
    y, x = (item[1] for item in minmax(tuple((value, key) for key, value in cartas_qtd_copy.items())))

    return 3 * x + 2 * y + 20


def pontuar_caso6(cartas_qtd: dict):
    if len(cartas_qtd) != 4:
        return 0
    for key, value in cartas_qtd.items():
        if value == 2:
            return key
    return 0


def calcular_pontos(cartas: list[int]):
    cartas_qtd = {}
    for carta in cartas:
        if carta not in cartas_qtd:
            cartas_qtd[carta] = 1
        else:
            cartas_qtd[carta] += 1

    return max(pontuar_caso1(cartas_qtd), pontuar_caso2(cartas_qtd), pontuar_caso3(cartas_qtd), pontuar_caso4(cartas_qtd),
               pontuar_caso5(cartas_qtd), pontuar_caso6(cartas_qtd))


def main():
    n = int(input())

    for i in range(1, n + 1):
        print(selecionarSacos'Teste {i}')
        print(calcular_pontos([int(v) for v in input().split()]))
        print()


if __name__ == '__main__':
    main()
