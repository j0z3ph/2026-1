/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa
 * @version 0.1
 * @date 2025-12-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "graficos.h"
#define GRAVEDAD 1

int main()
{
    int rx, ry;
    int rectx = 100, recty = 100;
    int aceleracion = 0;
    bool izquierda_presionada = false;
    bool derecha_presionada = false;
    
    ventana.tituloVentana("Hola Windows :D");
    
    ventana.tamanioVentana(800, 600);

    int tecla = ventana.teclaPresionada();
    bool fs = false;
    
    while(tecla != TECLAS.ESCAPE) {
        aceleracion += GRAVEDAD;
        recty += aceleracion;


        tecla = ventana.teclaPresionada();
        ventana.raton(&rx, &ry);

        if(recty >= ventana.altoVentana() - 100) {
            aceleracion = 0;
            recty = ventana.altoVentana() - 100;
        }
        
        if(tecla == TECLAS.ESPACIO) {
            aceleracion = -20;
        }

        if(tecla == TECLAS.DERECHA) derecha_presionada = true;
        if(tecla == TECLAS.IZQUIERDA) izquierda_presionada = true;
        


        if(derecha_presionada) {
            rectx += 10;
        }

        if(izquierda_presionada) {
            rectx -= 10;
        }




        //ventana.imprimeEnConsola("X=%i - Y=%i\n", rx, ry);

        if(tecla == TECLAS.ENTER) {
            fs = !fs;
            ventana.pantallaCompleta(fs);
        }

        ventana.limpiaVentana(); // Borra

        ventana.colorFondo(COLORES.VERDE); // Dibujamos

        ventana.color(COLORES.ROJO);

        ventana.linea(50, 50, 200, 200);

        ventana.rectangulo(100,100, 200,200);


        // ESTE ES EL BUENO
        ventana.rectanguloRelleno(rectx, recty, rectx + 100, recty + 100);

        ventana.colorRGB(28,50,123);
        ventana.circuloRelleno(rx,ry, 20);

        ventana.color(COLORES.ROJO);
        ventana.texto(100,50, "Holi XD");
        ventana.texto1(300,50, "Holi de Nuevo XD", 50, "MV Boli");
        ventana.texto2(300,200, "Holi de Nuevo XD", 50, "MV Boli", true, true, true);



        ventana.actualizaVentana(); // Mostramos

        int tmp = ventana.teclaSoltada();

        if(tmp == TECLAS.DERECHA) derecha_presionada = false;
        if(tmp == TECLAS.IZQUIERDA) izquierda_presionada = false;
        

        ventana.espera(1);
    }


    ventana.cierraVentana();
    
    return 0;
}
