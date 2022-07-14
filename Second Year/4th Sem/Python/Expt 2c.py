s = list(input("enter a sentence\n"))
print(s)
for i in s:
    if i == '.' or i == ',' or i == '?' or i == '!':
        s.remove(i)
for i in s:
    print(i, end='')
