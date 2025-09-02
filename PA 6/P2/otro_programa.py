import math

suma2 = lambda a,b: a+b
variable = 5

def resta(a:int|float, b:int|float) -> int | float:
    """Resta dos numeros

    Args:
        a (int | float): El primer numero
        b (int | float): El segundo numero

    Returns:
        int | float: La resta
    """
    
    global variable
    variable = 3
    
    var = 7
    def otro_funcion():
        nonlocal var
        var = 8
    
    otro_funcion()
    #print(var)
    
    return a - b


def suma(*numeros):
    s = 0
    for n in numeros:
        s += n
    return s

def division(a, b, otro=0, otro2 = 6, otro3 = "str"):
    return a / b

if __name__ == "__main__":
    a = 3
    b = 8

    print(resta(5,6.7 ))
    print(variable)

    print(__name__)