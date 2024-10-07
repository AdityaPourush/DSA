#check if palindrome or not

def reverseString(s, start, end):
    if start < end:
        s[start], s[end-1] = s[end-1], s[start]
        reverseString(s, start+1, end-1)

n = input()
original = n
n = list(n)
reverseString(n, 0, len(n))
n = ''.join(n)

if n == original:
    print("palindrome")
else:
    print("not palindrome")