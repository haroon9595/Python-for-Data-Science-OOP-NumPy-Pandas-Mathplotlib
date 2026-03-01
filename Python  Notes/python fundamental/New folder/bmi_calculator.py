weight = float(input("Enter your weight in kg: "))

print("Select height unit:")
print("1. Feet & Inches")
print("2. Meters")
choice = int(input("Enter choice (1 or 2): "))

if choice == 1:
    feet = int(input("Enter your height (feet): "))
    inches = int(input("Enter remaining inches: "))
    total_feet = feet + inches / 12
    meters = total_feet * 0.3048   # 1 foot = 0.3048 meters
elif choice == 2:
    meters = float(input("Enter your height in meters: "))
else:
    print("❌ kaka sahi number daal")
    exit()

# BMI calculation
bmi = weight / (meters ** 2)

print(f"\nYour BMI is: {bmi:.2f}")

# BMI Categories
if bmi < 18.5:
    print("Underweight – khao piyo sehat banao 🍗🥛")
elif bmi < 25:
    print("Normal weight ✅")
elif bmi < 30:
    print("Overweight ⚠️")
else:
    print("Obese – mota sand 🐂")
