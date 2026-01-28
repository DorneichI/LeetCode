class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        secretDict = {}
        guessDict = {}
        bulls = 0
        cows = 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
                continue
            if secret[i] in guessDict and guessDict[secret[i]] > 0:
                guessDict[secret[i]] -= 1
                cows += 1
            elif secret[i] in secretDict:
                secretDict[secret[i]] += 1
            else:
                secretDict[secret[i]] = 1

            if guess[i] in secretDict and secretDict[guess[i]] > 0:
                secretDict[guess[i]] -= 1
                cows += 1
            elif guess[i] in guessDict:
                guessDict[guess[i]] += 1
            else:
                guessDict[guess[i]] = 1
            
        return f"{bulls}A{cows}B"
