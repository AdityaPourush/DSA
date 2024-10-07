# print something n times
def printName(n):
    if n > 0:
        print("Hello")
        n = n-1
        printName(n)

n = int(input("Enter a number: "))
printName(n)