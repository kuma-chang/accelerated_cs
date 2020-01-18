n = int(input("Enter a positive interger: "))

n_bi = n
li_n = []
flag = True
while flag:
    li_n.append((n_bi % 2))
    if (n_bi // 2) == 0:
        flag = False
    n_bi = n_bi // 2

li_n_size = len(li_n)
print_counter = 0
while print_counter < li_n_size:
    print(li_n[li_n_size - 1 - print_counter], end="")
    print_counter += 1

print(end = "\n")


