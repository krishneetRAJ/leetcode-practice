from typing import List
import json

def fullJustify(words: List[str], maxWidth: int) -> List[str]:
    result = []
    i = 0

    while i < len(words):
        line = []
        length = 0
        while (i < len(words) and length + len(words[i]) + len(line) <= maxWidth):
            line.append(words[i])
            length += len(words[i])
            i += 1
        if i == len(words) or len(line) == 1: #If last line or only one word in the line, left justify
            s = " ".join(line)
            s += " " * (maxWidth - len(s))
        else:
            spaces = maxWidth - length
            gaps = len(line) - 1
            even_spaces = spaces // gaps
            extra_spaces = spaces % gaps

            s = ""
            for j in range(len(line)):
                s += line[j]
                if j < gaps:
                    if j < extra_spaces:
                        s += " " * (even_spaces + 1)
                    else:
                        s += " " * even_spaces
        result.append(s)
    return result

if __name__ == "__main__":
    print("Testing fullJustify function:")
    print("For the input [\"This\", \"is\", \"an\", \"example\", \"of\", \"text\", \"justification.\"] and maxWidth 16, the output is:", json.dumps(fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16)))
    print("For the input [\"What\",\"must\",\"be\",\"acknowledgment\",\"shall\",\"be\"] and maxWidth 16, the output is:", json.dumps(fullJustify(["What","must","be","acknowledgment","shall","be"], 16)))
    print("For the input [\"Science\",\"is\",\"what\",\"we\",\"understand\",\"well\",\"enough\",\"to\",\"explain\",\"to\",\"a\",\"computer.\",\"Art\",\"is\",\"everything\",\"else\",\"we\",\"do\"] and maxWidth 20, the output is:", json.dumps(fullJustify(["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], 20)))