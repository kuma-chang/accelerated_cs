n = int(input("Enter a non zero number: "))
palindrome = []

while n != 0:
    palindrome.append(n)
    n = int(input("enter a non zero number: "))

size = len(palindrome)
ind1 = 0
ind2 = size - 1

flag = True
while ind1 <= ind2 and flag:
    if palindrome[ind1] != palindrome[ind2]:
        flag = False
    ind1 += 1
    ind2 -= 1

if flag:
    print(palindrome, "is a palindrome")
else:
    print(palindrome, "is not a palindrome")







