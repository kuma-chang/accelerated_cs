
def is_prime(c):
    if c < 2:
        return False
    if c == 2 or c == 3:
        return True
    for x in range(c-3):
        if c % (x + 2) == 0:
            return False
        else:
            return True
'''
n = int(input("Enter a number: "))

if is_prime(n):
    print(n,"is prime!")
else:
    print(n, "is not prime.")

if n < 2:
    print(n,"prime!")
else:
    count = 2
    prime = True
    while count < n:
        if n % count == 0:
            prime = False
        count += 1
'''
