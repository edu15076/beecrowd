def main():
    n, k = tuple(int(i) for i in input().split())
    seq = [int(item) for item in input().split()]

    prefix_sum = {0: 1}

    qtd = 0
    curr_sum = 0

    for item in seq:
        curr_sum += item

        sum_before = curr_sum - k  # sum_before is if the sum of the range equals to k
        if sum_before in prefix_sum.keys():
            qtd += prefix_sum[sum_before]

        prefix_sum[curr_sum] = prefix_sum[curr_sum] + 1 if curr_sum in prefix_sum.keys() else 1

    print(qtd)


if __name__ == '__main__':
    main()
