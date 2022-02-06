class Node:
    def __init__(self, probability, char, left=None, right=None):
        self.probability = probability
        self.char = char
        self.left = left
        self.right = right
        self.encoding = ""

    def __str__(self):

        return 'Char: {char}, probability: {probability}, encoding: {encoding}'.format(
            char=self.char,
            probability=self.probability,
            encoding=self.encoding
        )

    def __repr__(self):
        return self.__str__()


codes = {}


def print_encoding(codes ,node, code=""):

    code += str(node.encoding)

    if node.left:
        print_encoding(codes, node.left, code)
    if node.right:
        print_encoding(codes , node.right, code)
    if not node.left and not node.right:
        print("Char: ", node.char, "encoding: ", code)
        codes[node.char] = code


def encode(data, encoding):
    output = ""
    for char in data:
        output += str(encoding[char])
    return output

def decode(data, encoding):
    inv_map = {v: k for k, v in encoding.items()}
    print("Inv_map: ", inv_map)
    output = ""
    buffer = ""
    pos = 0
    l = len(data)
    while pos < l:
        while buffer not in inv_map.keys():
            if pos >= l:
                return -1
            buffer += data[pos]
            pos += 1
        output += inv_map[buffer]
        buffer = ""

    return output


def probabilities(string):
    frequencies = {}
    for char in string:
        if char in frequencies:
            frequencies[char] += 1
        else:
            frequencies[char] = 1

    frequencies = sorted(frequencies.items(), key=lambda x: x[1], reverse=True)
    length = len(string)
    dict_ = {   frequency[0]:float(frequency[1]/length) for frequency in frequencies}

    return dict_

def gain(data, encoded_data):
    l_before = len(data) * 8
    l_after = len(encoded_data)
    return l_after/l_before


def huffman_encode(data):

    prob_dict = probabilities(data)
    nodes = []

    for key, value in prob_dict.items():
        nodes.append(Node(value, key))

    if len(nodes) < 2:
        return -1

    while len(nodes) > 1:

        nodes = sorted(nodes, key=lambda x:x.probability)

        right = nodes[0]
        left = nodes[1]

        right.encoding = 1
        left.encoding = 0

        combinednode = Node(right.probability + left.probability,
                        right.char + left.char,
                        left=left,
                        right=right)
        nodes.remove(right)
        nodes.remove(left)

        nodes.append(combinednode)

    codes_ = {}
    print_encoding(codes_, nodes[0])
    encoded_data = encode(data, codes_)
    print("Encoded data: ", encoded_data)
    decoded_data = decode(encoded_data, codes_)
    print("Decoded data: ", decoded_data)
    print("Gain: ", gain(data, encoded_data))


def main():

    s = "antani"

    huffman_encode(s)

if __name__ == "__main__":
    main()