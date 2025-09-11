import tkinter as tk

ventana = tk.Tk()
ventana.wm_title("Ventanita")
ventana.wm_minsize(400, 500)

# Creamos una nueva etiqueta
etiqueta = tk.Label(ventana, text="Hola Mundo 😍")
etiqueta.pack()

boton = tk.Button(ventana, text="😈")
boton.pack()
ventana.mainloop()