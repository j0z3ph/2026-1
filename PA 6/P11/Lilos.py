import time
import threading


def la_lenta():
    print("Inicia la Lenta")
    time.sleep(2)
    print("Termina la Lenta")
    
if __name__ == "__main__":
    print("Inicia Main")
    h = threading.Thread(target=la_lenta, daemon=True)
    h.start()
    h.join()
    print("Termina Main")