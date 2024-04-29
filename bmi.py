def calc(height, weight):
    bmi = weight / (height**2)
    return bmi

def interp(bmi):
    if bmi < 18.5:
        return("underweight")
    if bmi < 25:
        return("normal weight")
    if bmi < 30:
        return("slightly overweight")
    if bmi < 35:
        return("obese")
    
    return("clinically obese")


print("Body Mass Index (BMI) calculator!\nPlease, insert the person's height and weight:")
height = float(input("Height (in m): "))
weight = float(input("Weight (in kg): "))
bmi = round(calc(height, weight), ndigits=2)
print("BMI: " + str(bmi))
print("Interpretation: " + interp(bmi))