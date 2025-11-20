from queue import Queue


class Entrada:
    def __init__(self, chegada, tempo):
        self.chegada = chegada
        self.tempo = tempo


def main() -> None:
    c, n = map(int, input().split())
    entradas = [
        Entrada(chegada, tempo)
        for chegada, tempo in [map(int, input().split()) for _ in range(n)]
    ]

    entradas_per_chegada: dict[int, list[Entrada]] = {}
    for entrada in entradas:
        if entrada.chegada not in entradas_per_chegada:
            entradas_per_chegada[entrada.chegada] = [entrada]
        else:
            entradas_per_chegada[entrada.chegada].append(entrada)

    caixas = [0 for _ in range(c)]

    q: Queue[Entrada] = Queue()
    count = 0

    for t in range(20_000):  # se todos esperarem 20 min
        if t in entradas_per_chegada:
            [q.put(entrada) for entrada in entradas_per_chegada[t]]

        for i, caixa in enumerate(caixas):
            if q.empty():
                break
            if caixa > t:
                continue
            entrada = q.get()
            count += t - entrada.chegada > 20
            caixas[i] = t + entrada.tempo

    print(count)
    
    
if __name__ == '__main__':
    main()
