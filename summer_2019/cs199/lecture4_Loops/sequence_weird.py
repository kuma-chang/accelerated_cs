n = int(input("Enter a positive even number: "))

if n%2 == 1:
    print("Please enter a even number.")
else:
    result = n
    counter = 1
    while counter < n:
        if counter%2 == 1:
            result = result - ((counter+1)/2)
        else:
            result = result + (result-(counter/2))
        counter = counter + 1

print(int(result))


'''
back = n
forward = 1
s = 0

if n % 2 != 0:
    print("Enter an even number please.")
else:
    while back > forward:
        s = s + back - forward
        back = back - 1
        forward = forward + 1
print(s)
'''










