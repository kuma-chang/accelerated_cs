p = 6
n = p

change = [0, 0, 0]


def find_change(p, n, change):
    coin = p - n
    if coin == 4:
        change[0] += 1
    elif coin == 3:
        change[1] += 1
    elif coin == 1:
        change[2] += 1

    if p == 0:
        return 0
    else:
        return min(find_change(n, n - 4, change), find_change(n, n - 3, change), find_change(n, n - 1, change))

def find_change_(p, n, change):
    coin = p - n
    if coin == 4:
        change[0] += 1
    elif coin == 3:
        change[1] += 1
    elif coin == 1:
        change[2] += 1

    if p == 0:
        return 0
    else:
        return min(find_change(n, n - 4, change), find_change(n, n - 3, change), find_change(n, n - 1, change))





print("The total amount of money is: ", p)
find_change(p, n, change)
print("4: ", change[0])
print("3: ", change[1])
print("1: ", change[2])

