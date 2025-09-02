edad = int(input("Ingresa tu edad: "))
if edad >= 18:
    print("Ya eres adulto")
elif edad >= 6 and edad < 18:
    print("Otro bloque")
else:
    print("Sigue creciendo")