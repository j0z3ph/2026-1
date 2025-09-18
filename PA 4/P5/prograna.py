import tkinter as tk
import tkinter.messagebox as msgbox
from PIL import ImageTk, Image

def click(event):
    print(entrada.get())
    
def click2():
    msgbox.showinfo("Mensaje", entrada.get())
    msgbox.askyesnocancel("Pregunta", "Estas seguro?")


ventanita = tk.Tk()
amlito = ImageTk.PhotoImage(Image.open("amlito.png"))
ventanita.wm_minsize(800,600)
ventanita.wm_title("Aplicacion del Bienestar")
etiqueta = tk.Label(master=ventanita, image=amlito)
etiqueta.pack(fill=tk.BOTH, side=tk.LEFT)



entrada = tk.Entry(ventanita, width=43)
entrada.place(x=350, y=100) #.pack(fill=tk.X)

boton = tk.Button(ventanita, text="Cliqueame!!", command=click2)
boton.place(x=500, y=300)#.pack()

#boton.bind("<Button-1>", click)

ventanita.mainloop()