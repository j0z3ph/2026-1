import threading
import time

def lenta():
    print("Inicie")
    time.sleep(2)
    print("Termine")
    
    
if __name__ == "__main__":
    print("Main iniciado")
    x = threading.Thread(target=lenta, daemon=True)
    x.start()
    x.join()
    #lenta()
    print("Main terminado")