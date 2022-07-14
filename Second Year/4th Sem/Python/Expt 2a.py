s = input("Enter a sentence ").lower()
words = s.split(' ')
setOfWords = list(set(words))
freq = []
for i in range(0, len(setOfWords), 1):
    k = 0
    for j in range(0, len(words), 1):
        if setOfWords[i] == words[j]:
            k += 1
    freq.append([setOfWords[i], k])
    print('Frequency of ', setOfWords[i], ' is ', k)
