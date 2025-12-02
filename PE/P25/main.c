/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa de nuevo
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
    bool fs = false;
    int rx, ry;
    int cuadradox = 300, cuadradoy = 100;
    int aceleracion = 0;
    bool derecha_pres = false, izquierda_pres = false;
    ventana.tamanioVentana(800, 600);
    ventana.tituloVentana("Hola Windows");
    ventana.colorFondo(COLORES.MAGENTA);

    int tecla = ventana.teclaPresionada();

    while (tecla != TECLAS.ESCAPE)
    {
        aceleracion += GRAVEDAD;
        cuadradoy += aceleracion;

        tecla = ventana.teclaPresionada();

        

        if (tecla == TECLAS.DERECHA)
        {
            derecha_pres = true;
        }

        if (tecla == TECLAS.IZQUIERDA)
        {
            izquierda_pres = true;
        }

        if (derecha_pres)
            cuadradox += 10;
        if (izquierda_pres)
            cuadradox -= 10;

        if (cuadradoy + 100 >= ventana.altoVentana())
        {
            aceleracion = 0;
            cuadradoy = ventana.altoVentana() - 100;
        }
        if (cuadradox <= 0)
        {
            cuadradox = 0;
        }

        ventana.raton(&rx, &ry);

        // ventana.imprimeEnConsola("X=%i - Y=%i\n", rx, ry);

        if (tecla == TECLAS.ENTER)
        {
            fs = !fs;
            ventana.pantallaCompleta(fs);
        }

        if (tecla == TECLAS.ESPACIO)
        {
            aceleracion = -20;
        }

        ventana.limpiaVentana(); // Limpiamos

        ventana.color(COLORES.NEGRO);

        ventana.linea(50, 50, 200, 200); // Dibujamos
        ventana.rectangulo(100, 100, 200, 300);
        ventana.rectanguloRelleno(cuadradox, cuadradoy, cuadradox + 100, cuadradoy + 100);

        ventana.color(COLORES.CYAN);
        ventana.circuloRelleno(rx, ry, 20);

        ventana.texto(100, 100, "Holi XD");
        ventana.texto1(400, 100, "Holi XD", 50, "Ink Free");
        ventana.texto2(400, 200, "Holi XD", 50, "Ink Free", true, true, true);

        ventana.actualizaVentana(); // Mostramos

        int tmp = ventana.teclaSoltada();
        if (tmp == TECLAS.DERECHA)
        {
            derecha_pres = false;
        }
        if (tmp == TECLAS.IZQUIERDA)
        {
            izquierda_pres = false;
        }

        ventana.espera(10);
    }

    ventana.cierraVentana();
    return 0;
}
