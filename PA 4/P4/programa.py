from abc import ABCMeta, abstractmethod
class Figura(metaclass=ABCMeta):
    @abstractmethod
    def area(self):
        pass
    
class Rectangulo(Figura):
    pass

if __name__ == "__main__":
    rect = Rectangulo()
    print(rect.area())