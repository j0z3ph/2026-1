import math


def funcion(primer=1, segundo=2, tercer=3, cuarto=4):
    return primer + segundo + tercer + cuarto

def divide(a, b):
    return a / b

def suma(a:int|float, b:int|float, c:int = 0) -> float|int:
    """Suma dos numeros

    Args:
        a (int | float): El primer numero
        b (int | float): El segundo numero

    Returns:
        float|int: La suma
    """
    return a+b+c

def la_suma(*n):
    s = 0
    for i in n:
        s += i
    return s

multiplicacion = lambda a, b: a * b

if __name__ == "__main__":
    print(suma(3,3.5, 6))

    a = 7
    b = 2

    print(divide(b=a,a=b))

    print(funcion(tercer=10, primer=0))

    print(la_suma(1,2,3,4,5,6,7,8,9,10.5))

    print(multiplicacion(5,6))

    print(__name__)