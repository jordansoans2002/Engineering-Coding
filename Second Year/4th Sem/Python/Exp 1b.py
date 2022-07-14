n = int(input("Enter number of rows"))
t = int(n/2)
t += 4
a = [1]
b = []
for i in range(1, n+1, 1):
    for j in range(1, t+1, 1):
        print("   ", end='')
    t -= 1
    for j in range(0, i, 1):
        if j == 0:
            b.append(1)
        elif j == i-1:
            b.append(1)
        else:
            b.append(a[j-1]+a[j])

    a.clear()
    for k in range(0, len(b), 1):
        a.append(b[k])
        c = '  '
        if 100 > b[k] > 9: c += ' '
        elif b[k] < 10: c += '  '
        print(b[k], c, end='')
    print()
    b.clear()
