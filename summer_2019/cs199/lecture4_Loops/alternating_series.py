n = int(input("Enter a positive interger: "))

neg_pos = 1
counter = 1
summ = 0

while counter <= n:
    summ = summ + (neg_pos*(counter**2))
    counter = counter + 1
    neg_pos = neg_pos * (-1)


print(summ)


print(neg_pos)
print(counter)

























