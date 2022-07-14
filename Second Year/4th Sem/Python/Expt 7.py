import os
print(os.getcwd())
os.mkdir('test.txt')
#os.remove('test.txt')
os.mkdir('experiment')
os.rename('experiment','expt 7.txt')
os.walk(os.getcwd())
os.chdir('expt 7.txt')
print(os.getcwd())

