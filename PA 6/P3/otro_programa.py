from multimethod import multimethod

class A:
    def metodo(self):
        return "Metodo A"
    
class B:
    def metodo(self):
        return "Metodo B"
    
class Hijo(A, B):
    @multimethod
    def metodo(self):
        return "Mi metodo"
    @multimethod
    def metodo(self, msg: str):
        return msg


hijo = Hijo()

print(hijo.metodo("Un mensajito"))