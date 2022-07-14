word = input("Enter a word ").lower()
freq = []; letters = []
for i in word:
    letters.append(i)
setOfLetters = list(set(letters))
print(letters)
for i in range(0, len(setOfLetters), 1):
    k = 0
    for j in range(0, len(letters), 1):
        if setOfLetters[i] == letters[j]:
            k += 1
    freq.append([setOfLetters[i], k])
    print('frequency of ', setOfLetters[i], ' is', k)
