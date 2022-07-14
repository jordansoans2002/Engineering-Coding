t1=('intellij','eclipse')
t2=('python','java','c')
t3=('html','javascript','css')
listOfTuples=list(t1)
listOfTuples.append(t2)
listOfTuples.append(t3)
print(sorted(listOfTuples))

def lastElement(t):
    return string(t[len(t)-1])
def sorted(l):
    for i in range(0,len(l),1):
        for j in range(0,len(l)-1-i,1):
            if(lastElement(l[j])>lastElement(l[j+1])):
                t=l[j]
                l[j]=l[j+1]
                l[j+1]=t
    return l
