def fibo(x):
    if x == 1:
        return 1
    elif x == 2:
        return 1 
    else:
        return fibo(x-1) +fibo(x-2)

'''
def fibo(x):
    li = []
    counter = 0
    while counter < x:
         if counter <= 1:
             li.append(1)
         else:
             li.append((li[counter-2] + li[counter-1]))
         counter += 1
    return li[(x-1)]
'''

print(fibo(6))
for n in range(1,11):
    print(fibo(n))





























