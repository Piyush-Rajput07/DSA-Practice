class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)

        if endWord not in wordSet:
            return 0

        queue = deque([(beginWord, 1)])
        visited = set([beginWord])

        while queue:
            word, level = queue.popleft()

            if word == endWord:
                return level

            for i in range (len(word)):
                for letter in 'abcdefghijklmnopqrstuvwxyz':
                    if letter == word[i]:
                        continue

                    newWord = word[:i] + letter + word[i+1:]
                    if newWord in wordSet and newWord not in visited:
                        visited.add(newWord)
                        queue.append((newWord, level + 1))

        return 0