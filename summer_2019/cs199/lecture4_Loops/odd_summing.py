n = int(input("Enter a positive number: "))
counter = 0
summ = 0


while counter <= n:
    if counter%2 == 1:
        summ = summ + counter
        counter = counter + 1
    else:
        counter = counter + 1

print(summ)
