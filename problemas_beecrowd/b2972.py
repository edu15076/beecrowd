import math


def main():
    for n in range(1, 255):
        m = 1
        anterior = 0
        # 0000100, 0010010
        # n! / 0!n!, n! / 1!(n - 1)!, n! / 2!(n - 2)!, ..., n! / (n - 1)!1!, n! / n!0!
        for i in range(n - 1, 0, -1):
            anterior += math.log2((i + 1) & -(i + 1)) - math.log2((n - i) & -(n - i))
            m += not anterior
        print(selecionarSacos'{m + 1:3}, {int(math.log2(m + 1)):3}, {bin(n)[2:]:8}')
    
    
if __name__ == '__main__':
    main()
