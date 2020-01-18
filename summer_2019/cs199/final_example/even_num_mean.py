# Allow the user to enter positive integers, terminated with a -1. Print out how many of the numbers entered areeven numbers that are within 10 of the mean of the users input.

def get_mean(n):
    summ = sum(n)
    mean = summ/(len(n))
    return mean


n = int(input("Enter a positive interger(terminate with a -1): "))
nums = []
while n != -1:
    if n < 1:
        print("Please enter a positive number.")
    else:
        nums.append(n)
    n = int(input("Enter a positive interger(terminate with a -1): "))

nums_mean = get_mean(nums)
counter = 0
for x in nums:
    if x % 2 == 0:
        if x >= (nums_mean - 10) and x <= (nums_mean + 10):
            counter += 1
print(counter)



