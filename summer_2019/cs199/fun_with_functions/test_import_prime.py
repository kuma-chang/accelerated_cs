from prime_number import is_prime


n = int(input("Enter a number: "))

if is_prime(n):
    print(n,"is prime!")
else:
    print(n, "is not prime.")


