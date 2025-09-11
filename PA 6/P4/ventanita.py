import tkinter as tk

ventana = tk.Tk()
ventana.wm_title("Mi primer ventana 🥰")
ventana.wm_minsize(800, 100)

etiqueta = tk.Label(ventana, text="Hola Mundo 👻👾")
etiqueta.pack()

boton = tk.Button(ventana, text="Push Me 😈😏")
boton.pack()

ventana.mainloop() 