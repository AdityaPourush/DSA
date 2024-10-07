def printNo(n):
    if n < 10:
        print(n, end=" ")
        n+=1
        printNo(n)

a = 0
printNo(a)