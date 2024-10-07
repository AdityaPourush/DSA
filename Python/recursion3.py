# print linearly from 1 to n
def printToN(n):
    if n>0:
        printToN(n-1)
        print(n)

# def printToN(i,n):
#     if i<=n:
#         print(i)
#         printToN(i+1,n)

num = int(input("Enter a number: "))
printToN(num)