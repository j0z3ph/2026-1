class Persona:
    def __init__(self, nombre:str, edad:int, estatura:float):
        self._nombre = nombre
        self._edad = edad
        self._estatura = estatura 
    
    #Getter
    @property
    def nombre(self):
        return self._nombre
    #Setter
    @nombre.setter
    def nombre(self, nombre:str):
        self._nombre = nombre
    
    @property
    def edad(self):
        return self._edad
    
    @edad.setter
    def edad(self, edad:int):
        self._edad = edad
        
    @property
    def estatura(self):
        return self._estatura
    
    @estatura.setter
    def estatura(self, estatura:float):
        self._estatura = estatura
    
    def __str__(self):
        return f"Mi nombre es {self._nombre}, tengo {self._edad} años y mido {self._estatura:.2f}."
    
    def habla(self):
        print(f"Holi, yo soy {self._nombre}");
        
    @classmethod
    def de_clase(cls):
        print("Soy un metodo de clase")
        
    @staticmethod
    def estatico():
        print("Soy estatico")

class Estudiante(Persona):
    pass


est1 = Estudiante("Rodolfo", 20, 6)
print(est1)
