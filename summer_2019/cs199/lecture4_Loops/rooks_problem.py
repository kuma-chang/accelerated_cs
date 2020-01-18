import random

rounds = int(input("How many rounds do you want to test: "))


round_counter = 0
test_counter = 0
same_counter = 0

while round_counter < rounds:
    x1 = random.randint(1,8)
    y1 = random.randint(1,8)
    x2 = random.randint(1,8)
    y2 = random.randint(1,8)
    if x1 == x2 or y1 == y2:
        test_counter += 1
    if (abs(x2-x1)+abs(y2-y1)) == 0:
        same_counter += 1
    round_counter += 1


print((test_counter-same_counter)/(rounds-same_counter))

