def main() -> None:
    n, m = map(int, input().split())
    stop_before = 0
    for stop in map(int, input().split()):
        dist = stop - stop_before
        stop_before = stop
        if dist > m:
            print('N')
            return
    print('S' if 42195 - stop_before <= m else 'N')
    
    
if __name__ == '__main__':
    main()
