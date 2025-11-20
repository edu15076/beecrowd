def main() -> None:
    r, g, b = int(input(), 16), int(input(), 16), int(input(), 16)
    total_red = 1
    total_green = (r // g) ** 2
    total_blue = total_green * (g // b) ** 2
    print(hex(total_red + total_green + total_blue)[2:])
    
    
if __name__ == '__main__':
    main()
