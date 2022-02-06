SEPARATORS = ["CD","XL","IV"]
SYMBOLS = ["MDC", "CLX", "XVI"]

def findFirstIndex(string, separators):
    index_list = []
    separators = "".join(separators)
    for char in separators:
        index_list.append(string.find(char))
    idx = min([i for i in index_list if i >= 0])
    return idx

def separate(string, separators):
    old_idx = 0
    separated_str = []
    for i in range(len(separators)):
        idx = findFirstIndex(string, separators[i:])
        separated_str.append(string[old_idx:idx])
        old_idx = idx

    separated_str.append(string[old_idx:])
    return separated_str

def parseRomanNumber(string, separators):

    separated_str = separate(string, separators)
    result = 1000 * len(separated_str[0])

    if parseDecimalPlaces(separated_str[1], SYMBOLS[0]) is not None:
        result += 100 * parseDecimalPlaces(separated_str[1], SYMBOLS[0])
    if parseDecimalPlaces(separated_str[2], SYMBOLS[1]) is not None:
        result += 10 * parseDecimalPlaces(separated_str[2], SYMBOLS[1])
    if parseDecimalPlaces(separated_str[3], SYMBOLS[2]) is not None:
        result += 1 * parseDecimalPlaces(separated_str[3], SYMBOLS[2])

    return result

def parseDecimalPlaces(str, sym):

    if str is None or str == "":
        return 0
    if str == sym[2]:
        return 1
    elif str == sym[2]*2:
        return 2
    elif str == sym[2]*3:
        return 3
    elif str == sym[2]+ sym[1]:
        return 4
    elif str == sym[1]:
        return 5
    elif str ==  sym[1] + sym[2]:
        return 6
    elif str == sym[1] + 2*sym[2]:
        return 7
    elif str == sym[1] + 3*sym[2]:
        return 8
    elif str == sym[2] + sym[0]:
        return 9
    else:
        raise NameError("Found an invalid symbol")

def main():
    str = "MLXVI"
    separators = ["CD","XL","IV"]
    print(separate(str, separators))
    print(parseRomanNumber(str, SEPARATORS))


if __name__ == "__main__":
    main()