height = int(input("Towee heigh: "))

for i in range(height):
    print(" "*(height-i) + "#" * (1 + 2*i))