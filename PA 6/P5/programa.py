import tkinter as tk
from PIL import Image, ImageTk
import tkinter.messagebox as msgbox


def click(event):
    print(entrada.get())

def click2():
    msgbox.showerror("ERROR!!", entrada.get())
    msgbox.askyesno("Pregunta?", "Las quesadillas llevan queso?")

ventana = tk.Tk()

gato = ImageTk.PhotoImage(Image.open("gato.jpg"))

ventana.wm_title("Mi primer imagen")
ventana.wm_minsize(800, 600)

imagen = tk.Label(ventana, image=gato)
imagen.grid(row=0, column=0, rowspan=1)#.pack(side=tk.LEFT, expand=False)

entrada = tk.Entry(ventana, width=50)
entrada.grid(row=0, column=1)#.place(x=300, y=200)#.pack(fill=tk.X)

boton = tk.Button(ventana, text="Cliqueame", command=click2)
boton.grid(row=1, column=1)#.place(x=475, y=250)#.pack()

#boton.bind("<Button-1>", click)

ventana.mainloop()

