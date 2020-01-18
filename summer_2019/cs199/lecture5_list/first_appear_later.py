first = int(input("Enter a positive number: "))
n = first
flag = False

if n == 0:
    print("No")
else:
    while n != 0:
        n = int(input("Enter a positive number: "))
        if n == first:
            flag = True
    
    if flag:
        print("The first number have appeared again.")
    else:
        print("The first number did nor appear again.")

