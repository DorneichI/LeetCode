class Solution:
    def possibleLetters(self, i: str) -> List[str]:
        match i:
            case '2':
                return ['a', 'b', 'c']
            case '3':
                return ['d', 'e', 'f']
            case '4':
                return ['g', 'h', 'i']
            case '5':
                return ['j', 'k', 'l']
            case '6':
                return ['m', 'n', 'o']
            case '7':
                return ['p', 'q', 'r', 's']
            case '8':
                return ['t', 'u', 'v']
            case '9':
                return ['w', 'x', 'y', 'z']
            case _:
                raise ValueError('i must be in 2-9')

    def letterCombinations(self, digits: str) -> List[str]:
        output = [""]
        for i in digits:
            letters = self.possibleLetters(i)
            newOutput = []
            for c in letters:
                for s in output:
                    newOutput.append(s + c)
            output = newOutput
        return output
