# Write your code below this line 👇
def isLeapYear(y):
  if y%4 != 0:
    return False
  if y%100 != 0:
    return True
    
  return (y%400 == 0)


y = int(input())
isLeap = isLeapYear(y)
if isLeap:
  print("Leap year")
else:
  print("Not leap year")