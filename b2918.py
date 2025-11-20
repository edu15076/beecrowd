sum_dig0 = [0, 1, 3, 6, 10, 15, 21, 28, 36, 45]


def to_list(n: int):
    nl = []
    if not n:
        nl.append(n)

    while n:
        div, mod = divmod(n, 10)
        nl.append(mod)
        n = div

    return nl


def sum_upper_9_num(len_n: int, pow_n: int) -> int:
    return 45 * len_n * pow_n


def sum_digits_arr_to(nl: list[int]) -> int:
    if len(nl) == 1:
        return sum_dig0[nl[0]]

    pow_i = 10 ** (len(nl) - 1)

    sum_previous = [nl[-1]]

    for i in range(len(nl) - 2, 0, -1):
        sum_previous.insert(0, sum_previous[0] + nl[i])

    sum_all = sum_dig0[nl[0]] + sum_previous[0]

    for i in range(len(nl) - 1, 0, -1):
        pow_d10 = pow_i // 10

        sum_all += nl[i - 1] * pow_d10 * sum_previous[i - 1]

        sum_all += nl[i] * sum_upper_9_num(i, pow_d10)
        for j in range(nl[i] - 1, 0, -1):
            sum_all += j * pow_i

        pow_i = pow_d10

    return int(sum_all)


def sum_digits_to(n: int) -> int:
    nl = to_list(n)
    return sum_digits_arr_to(nl)


def main():
    while True:
        try:
            l, r = (int(i) for i in input().split())
            print((sum_digits_to(r) - sum_digits_to(l - 1)) % 1_000_000_007)
        except EOFError:
            break


if __name__ == '__main__':
    main()
