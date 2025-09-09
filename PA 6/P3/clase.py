class Persona:
    
    def __init__(self, nombre:str, edad:int, genero:str):
        self._nombre = nombre
        self._edad = edad
        self._genero = genero
        self._protegido = "" # Esto es un atributo protegido
    
    @property    
    def nombre(self):
        return self._nombre
    @nombre.setter
    def nombre(self, nuevo_nombre:str):
        self._nombre = nuevo_nombre
    @property
    def edad(self):
        return self._edad
    @edad.setter
    def edad(self, nueva_edad:int):
        self._edad = nueva_edad
    @property
    def genero(self):
        return self._genero
    @genero.setter
    def genero(self, nuevo_genero:str):
        self._genero = nuevo_genero
    
    def __str__(self):
        return f"Me llamo {self._nombre}, tengo {self._edad} años y soy {self._genero}"
    
    def habla(self):
        print(f"Mi nombre es {self._nombre}")
    
    @classmethod
    def habla_clase(cls):
        print("Desde la clase")
        
    @staticmethod
    def habla_estatico():
        print("Soy estatico")

class Estudiante(Persona):
    pass

persona = Persona("Ian", 20, "RGB")
persona.nombre = "Pancho"
persona.edad = 40

#Persona.habla_clase()
#Persona.habla_estatico()

persona.habla()
print(persona)
print(persona.edad)
print(persona.nombre)

estudiante1 = Estudiante("Gabo", 40, "HDMI")
print(estudiante1)