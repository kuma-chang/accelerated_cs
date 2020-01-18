n = int(input("Enter a positive odd number: "))
counter = 0
summ = n 

if n%2 == 1:
    while counter < n:
        if counter%2 == 1:
            summ = summ - counter
            counter = counter + 1
        else:
            counter = counter + 1
else:
    print("Please enter a odd positive number.")


print(summ)





