# To print from n to 1
def printToOne(n):
    if n > 0:
        print(n, end=" ")
        printToOne(n-1)

k = int(input("Enter a no: "))
printToOne(k)