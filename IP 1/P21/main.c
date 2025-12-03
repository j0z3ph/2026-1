/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa de nuevo :P
 * @version 0.1
 * @date 2025-12-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "graficos.h"
#define GRAVEDAD 1

int main()
{
    bool fs = false;
    bool izp = false, dep = false;
    int rx, ry;
    int rectx = 300, recty = 300;
    int aceleracion = 0;
    ventana.tituloVentana("Hola Windows :P");
    ventana.tamanioVentana(800, 600);

    ventana.colorFondo(COLORES.CYAN);

    int tecla = ventana.teclaPresionada();

    while(tecla != TECLAS.ESCAPE) {

        tecla = ventana.teclaPresionada();

        if(tecla == TECLAS.ENTER) {
            fs = !fs;
            ventana.pantallaCompleta(fs);
        }
        

        ventana.raton(&rx, &ry);
        //ventana.imprimeEnConsola("X=%i - Y=%i\n", rx, ry);

        aceleracion += GRAVEDAD;
        recty += aceleracion;

        if(recty + 100 >= ventana.altoVentana()) {
            aceleracion = 0;
            recty = ventana.altoVentana() - 100;
        }

        if(tecla == TECLAS.ESPACIO) {
            aceleracion = -20;
        }

        if(tecla == TECLAS.DERECHA) {
            dep = true;
        }

        if(tecla == TECLAS.IZQUIERDA) {
            izp = true;
        }

        if(dep) {
            rectx += 10;
        }

        if(izp) {
            rectx -= 10;
        }



        ventana.limpiaVentana();

        ventana.color(COLORES.NEGRO);

        ventana.linea(100, 100, 300, 300);
        ventana.rectangulo(100,300, 200, 400);

        ventana.color(COLORES.ROJO);

        ventana.rectanguloRelleno(rectx, recty, rectx + 100, recty + 100);

        ventana.circuloRelleno(rx,ry, 10);

        ventana.texto(200,200, "Hola Mundo XD");
        ventana.texto1(400, 200, "Holi XD", 100, "Gabriola");
        ventana.texto2(400, 100, "Holi XD", 100, "Gabriola", true, true, true);



        ventana.actualizaVentana();


        int tmp = ventana.teclaSoltada();

        if(tmp == TECLAS.DERECHA) {
            dep = false;
        }

        if(tmp == TECLAS.IZQUIERDA) {
            izp = false;
        }

        ventana.espera(10);

    }


    ventana.cierraVentana();

    return 0;
}
