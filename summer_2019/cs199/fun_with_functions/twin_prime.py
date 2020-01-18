from prime_number import is_prime


def twin_prime(x):
    if is_prime(x):
        if is_prime(x + 2) or is_prime(x -2):
            return True
        else:
            return False
    else:
        return False

n = int(input("Enter a number: "))

if twin_prime(n):
    print(n, "is twin prime!")
else:
    print(n, "is not twin prime.")



