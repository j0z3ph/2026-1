for _, j in [(1, "uno"),(2, "dos"),(3, "tres")]:
    print(j)
else:
    print("Termine")
    
cont = 1

while cont <= 10:
    if cont == 5: 
        cont += 1
        continue
        
    print(cont)
    cont += 1
    
else:
    print("Termine while")