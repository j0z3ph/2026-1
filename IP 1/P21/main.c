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
#include "simplecontroller.h"
#define GRAVEDAD 1
#define JX 15
#define JY 2
#define BTN 4
#define AJUSTE_X 0.44
#define AJUSTE_Y 0.35


int main()
{
    Board *esp32 = connectDevice("COM7", B115200);

    Imagen *kirby = ventana.creaImagenConMascara("kirby.bmp", "kirbymascara.bmp");

    bool fs = false;
    bool izp = false, dep = false;
    float jx, jy;
    int rx = 400, ry = 400;
    bool btn;
    int rectx = 300, recty = 300;
    int aceleracion = 0;
    int ajuste_x, ajuste_y;
    ventana.tituloVentana("Hola Windows :P");
    ventana.tamanioVentana(800, 600);

    ventana.colorFondo(COLORES.CYAN);

    int tecla = ventana.teclaPresionada();

    esp32->pinMode(esp32, JX, INPUT);
    esp32->pinMode(esp32, JY, INPUT);
    esp32->pinMode(esp32, BTN, INPUT_PULLUP);
    

    while (tecla != TECLAS.ESCAPE)
    {

        jx = esp32->analogRead(esp32, JX);
        jy = esp32->analogRead(esp32, JY);
        btn = esp32->digitalRead(esp32, BTN);

        jx -= AJUSTE_X;

        if(jx >= 0.0)
            ajuste_x = jx * (20.0 / (1.0 - AJUSTE_X));
        else 
            ajuste_x = jx * (21.0 / (AJUSTE_X));


        jy -= AJUSTE_Y;

        if(jy >= 0.0)
            ajuste_y = jy * (21.0 / (1.0 - AJUSTE_Y));
        else 
            ajuste_y = jy * (21.0 / (AJUSTE_Y));

        //ventana.imprimeEnConsola("(%f, %f)- %i | %i, %i\n", jx, jy, btn, ajuste_x, ajuste_y);


        tecla = ventana.teclaPresionada();

        if (tecla == TECLAS.ENTER)
        {
            fs = !fs;
            ventana.pantallaCompleta(fs);
        }

        rx += ajuste_x;
        ry += ajuste_y;
        //ventana.raton(&rx, &ry);
        // ventana.imprimeEnConsola("X=%i - Y=%i\n", rx, ry);

        aceleracion += GRAVEDAD;
        recty += aceleracion;

        if (recty + 100 >= ventana.altoVentana())
        {
            aceleracion = 0;
            recty = ventana.altoVentana() - 100;
        }

        if (tecla == TECLAS.ESPACIO)
        {
            aceleracion = -20;
        }

        if (tecla == TECLAS.DERECHA)
        {
            dep = true;
        }

        if (tecla == TECLAS.IZQUIERDA)
        {
            izp = true;
        }

        if (dep)
        {
            rectx += 10;
        }

        if (izp)
        {
            rectx -= 10;
        }

        ventana.limpiaVentana();

        ventana.color(COLORES.NEGRO);

        ventana.linea(100, 100, 300, 300);
        ventana.rectangulo(100, 300, 200, 400);

        ventana.color(COLORES.ROJO);

        // ventana.rectanguloRelleno(rectx, recty, rectx + 100, recty + 100);
        ventana.muestraImagen(rectx, recty, kirby);
        // ventana.muestraImagenEscalada(rectx, recty,100,100, kirby);

        ventana.circulo(rx, ry, 20);
        ventana.linea(rx - 10, ry, rx - 30, ry);
        ventana.linea(rx + 10, ry, rx + 30, ry);
        ventana.linea(rx, ry - 10, rx, ry - 30);
        ventana.linea(rx, ry + 10, rx, ry + 30);

        ventana.texto(200, 200, "Hola Mundo XD");
        if(!btn) {
            ventana.texto1(rx, ry, "Piyuuuu", 100, "Gabriola");
        }
        ventana.texto2(400, 100, "Holi XD", 100, "Gabriola", true, true, true);

        ventana.actualizaVentana();

        int tmp = ventana.teclaSoltada();

        if (tmp == TECLAS.DERECHA)
        {
            dep = false;
        }

        if (tmp == TECLAS.IZQUIERDA)
        {
            izp = false;
        }

        ventana.espera(10);
    }

    ventana.cierraVentana();

    return 0;
}
