import random


n1 = int(input("Please enter the first number: "))
n2 = int(input("Please enter the second number: "))
rounds = int(input("How many rounds do you wish to test: "))
round_counter = 0
test_counter = 0

while round_counter < rounds:
    t1 = random.randint(1,6)
    t2 = random.randint(1,6)
    test = t1 + t2
    round_counter += 1
    '''
    print(round_counter,t1,t2,test,test_counter)
    '''
    if test == n1 or test == n2:
        test_counter += 1

print(test_counter/rounds)






