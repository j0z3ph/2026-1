class Persona:
    
    def __init__(self, nombre:str, edad:int, genero:str):
        self.nombre = nombre
        self.edad = edad
        self.genero = genero
    
    def habla(self):
        print(f"Mi nombre es {self.nombre}")
        

persona = Persona("Ian", 20, "RGB")
persona.genero = "HDR"


persona.habla()