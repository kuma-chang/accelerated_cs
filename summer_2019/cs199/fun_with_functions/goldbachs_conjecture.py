from prime_number import is_prime


def goldbach(n):
    flag = True
    if not n > 2 or not n%2 == 0:
        return "Invalid input"
    else:
        for x in range(2, n):
            if flag:
                y = n-x
                if is_prime(x) and is_prime(y):
                    flag = False
                    return [x,(n-x)]

n = int(input("Enter a even number: "))

print(goldbach(n))

                
