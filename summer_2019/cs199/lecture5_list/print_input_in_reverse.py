n = int(input("Enter a number(enter 0 to terminate): "))
li = []
li_size = 0


while n != 0:
    li.append(n)
    li_size += 1
    n = int(input("Enter a number(enter 0 to terminate): "))
    
print_counter = 0

if n == 0:
    while print_counter < li_size:
        print(li[li_size -1 - print_counter])
        print_counter += 1














