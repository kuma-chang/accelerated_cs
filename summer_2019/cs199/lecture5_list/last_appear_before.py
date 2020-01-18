first = int(input("Enter a number(enter 0 to terminate): "))
n = first
li = []
li_size = 0



if n == 0:
    print("nope")
else:
    while n != 0:
        li.append(n)
        li_size += 1
        n = int(input("Enter a number(enter 0 to terminate): "))
    last = li[li_size - 1]
    flag = False
    c = 0
    while c < (li_size-1):
        if li[c] == last:
            flag = True
        c += 1

    if flag:
        print("Last appeared again.")
    else:
        print("Last did not appeared again.")














