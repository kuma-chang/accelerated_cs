import random

n = int(input("Enter n: "))
round_count = 0
bottom = (n**2)+2

while round_count < (n-3):
    bottom = 2+(((n-round_count)-2)**2/bottom)
    round_count += 2


print(4/(1+(1/bottom)))

















