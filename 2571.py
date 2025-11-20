import math


def main():
    m, p, j, x = input().split()
    m = int(m)
    p = -float(p) / 100
    j = float(j) / 100
    x = int(x)
    t = int(math.log(x / (j * m), 1 + p))
    print(t if t >= 0 else 0)


if __name__ == '__main__':
    main()
