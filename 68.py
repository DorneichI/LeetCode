class Solution:
    def getWordsNextLine(self, words: List[str], maxWidth: int, index: int) -> int:
        charCount = -1
        wordCount = 0
        while True:
            if index + wordCount < len(words) and charCount + 1 + len(words[index + wordCount]) <= maxWidth:
                charCount += 1 + len(words[index + wordCount])
                wordCount += 1
            else:
                break
        return wordCount

    def getNextLine(self, words: List[str], maxWidth: int, index: int, wordsNextLine: int) -> str:
        charCount = 0
        for i in range(index, index + wordsNextLine):
            charCount += len(words[i])
        if index + wordsNextLine == len(words) or wordsNextLine == 1:
            wordsNextLine -= 1
            endSpaces = (maxWidth - charCount - wordsNextLine)
            nextLine = ""
            while wordsNextLine >= 0:
                nextLine += words[index]
                index += 1
                if wordsNextLine > 0:
                    nextLine += " "
                else:
                    nextLine += " " * endSpaces
                wordsNextLine -= 1
        else:
            totalWhiteSpaces = maxWidth - charCount
            wordsNextLine -= 1
            nextLine = ""
            while wordsNextLine >= 0:
                nextLine += words[index]
                index += 1
                if wordsNextLine > 0:
                    spaces = math.ceil(totalWhiteSpaces / wordsNextLine)
                    totalWhiteSpaces -= spaces
                    nextLine += " " * spaces
                wordsNextLine -= 1
        return nextLine



    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        lines = []
        index = 0
        while index < len(words):
            wordsNextLine = self.getWordsNextLine(words, maxWidth, index)
            line = self.getNextLine(words, maxWidth, index, wordsNextLine)
            lines.append(line)
            index += wordsNextLine
        return lines
