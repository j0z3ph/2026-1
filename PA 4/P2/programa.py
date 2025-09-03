edad = int(input("Ingresa tu edad: "))

if edad >= 18:
    print("Viejon")
elif edad >= 5 and edad < 18:
    print("Chavo")
else:
    print("Chaval")
print("Fuera del if")