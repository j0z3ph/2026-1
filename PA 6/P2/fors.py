for _, j in [(1, "Hola"),(2, "2"),(3, "3"), (4, "4")]:
    if j == "2":
        continue
    print(j)
    
else:
    print("Termino For")
    
cont = 1
while cont <= 10:
    print(cont)
    cont += 1
else:
    print("Termino While")