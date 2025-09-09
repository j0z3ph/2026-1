class Punto:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y
        
    def __add__(self, other):
        p = Punto(self.x + other.x, self.y + other.y)
        return p
    
    def __str__(self):
        return f"({self.x}, {self.y})"
    
p1 = Punto(4,2)
p2 = Punto(8,6)
p3 = p1 + p2
print(p3)