from multimethod import multimethod

class Madre:
    def metodo(self):
        print("Chanclazo")

class Padre:
    def metodo(self):
        print("Voy por cigarros")
    
class Morrillo(Madre, Padre):
    @multimethod
    def habla(self):
        print("Hola")
    @multimethod
    def habla(self, msg:str):
        print(msg)

morrillo = Morrillo()

morrillo.habla()