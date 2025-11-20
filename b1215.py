import re


def add_words(line: str, words: set) -> None:
    line = line.lower()
    words.update(word for word in re.split(r'[^a-z]+', line) if word)


def main() -> None:
    words = set()
    while True:
        try:
            line = input()
            add_words(line, words)
        except EOFError:
            break
    print(*sorted([word for word in words]), sep='\n')

    
if __name__ == '__main__':
    main()
