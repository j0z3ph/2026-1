class Persona:
    
    def __init__(self, nombre:str, edad:int, estatura:float):
        self.nombre = nombre
        self.edad = edad
        self.estatura = estatura 
    
    def habla(self):
        print(f"Holi, yo soy {self.nombre}")

persona = Persona("Pablo", 23, 1.4)


persona.habla()
