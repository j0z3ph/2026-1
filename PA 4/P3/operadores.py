class Punto:
    def __init__(self, x:int, y:int):
        self.x = x
        self.y = y
        
    def __add__(self, other):
        p = Punto(self.x + other.x, self.y + other.y)
        return p
    
    def __str__(self):
        return f"({self.x}, {self.y})"
    
if __name__ == "__main__":
    p1 = Punto(2,5)
    p2 = Punto(3,4)
    p3 = p1 + p2
    print(p3)
    
    lista = [1,2,3]
    print(len(p3))