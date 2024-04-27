# Pseudorandom number generators - Khan Academy

# Python random module
import random as module
import mymodule

x = module.randint(1, 100) # includes 1 and 100
print(x)

# random floating point number - only [0,1)
y = module.random()
y = y*5
# Format Specification Mini-Language
#   print("{:.2f}".format(y))
# or
print(f"{y:.2f}")

mymodule.printHelloWorld(5)