def move_disk(n):
    disk_list = list(bin(n))
    disk_list.reverse()
    size = len(disk_list) - 2
    flag = True
    counter = 0
    while counter < size and flag:
        if disk_list[counter] == "1":
            return counter + 1
        counter += 1



print(move_disk(0))
print(move_disk(1))
print(move_disk(2))
print(move_disk(3))
print(move_disk(4))
print(move_disk(5))
print(move_disk(6))
print(move_disk(7))
