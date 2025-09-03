

variable = 5

def funcion():
    global variable
    variable = 10
    print(variable)
    
def otra_funcion():
    var = 3
    
    def funcion2():
        nonlocal var
        var = 5
    
    funcion2()
    print(var)

funcion()
print(variable)
otra_funcion()