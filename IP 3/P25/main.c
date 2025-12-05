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
#include "simplecontroller.h"
#define GRAVEDAD 1
#define BTN 4
#define JX 15
#define JY 2
#define MTR 13

#define AJUSTE_X 0.5
#define AJUSTE_Y 0.36

int main()
{
    Imagen *trex = ventana.creaImagenConMascara("trex.bmp", "trexmascara.bmp");
    Board *esp32 = connectDevice("COM6", B115200);
    esp32->pinMode(esp32, JX, INPUT);
    esp32->pinMode(esp32, JY, INPUT);
    esp32->pinMode(esp32, BTN, INPUT_PULLUP);
    esp32->pinMode(esp32, MTR, OUTPUT);

    int rx = 400, ry = 300;
    int rectx = 100, recty = 100;
    int ajustex, ajustey;
    int aceleracion = 0;
    bool izquierda_presionada = false;
    bool derecha_presionada = false;
    bool btn = false;
    float jx, jy;

    ventana.tituloVentana("Hola Windows :D");

    ventana.tamanioVentana(800, 600);

    int tecla = ventana.teclaPresionada();
    bool fs = false;

    while (tecla != TECLAS.ESCAPE)
    {
        btn = esp32->digitalRead(esp32, BTN);
        jx = esp32->analogRead(esp32, JX);
        jy = esp32->analogRead(esp32, JY);

        jx -= AJUSTE_X;
        if (jx >= 0)
            ajustex = (int)(jx * (10.0 / (1.0 - AJUSTE_X)));
        else
            ajustex = (int)(jx * (11.0 / AJUSTE_X));

        jy -= AJUSTE_Y;
        if (jy >= 0)
            ajustey = (int)(jy * (10.0 / (1.0 - AJUSTE_Y)));
        else
            ajustey = (int)(jy * (11.0 / AJUSTE_Y));

        //ventana.imprimeEnConsola("(%f, %f) - %i | %i, %i\n", jx, jy, btn, ajustex, ajustey);

        rx += ajustex;
        ry += ajustey;

        aceleracion += GRAVEDAD;
        recty += aceleracion;

        tecla = ventana.teclaPresionada();
        //ventana.raton(&rx, &ry);

        if (recty >= ventana.altoVentana() - 100)
        {
            aceleracion = 0;
            recty = ventana.altoVentana() - 100;
        }

        if (tecla == TECLAS.ESPACIO)
        {
            aceleracion = -20;
        }

        if (tecla == TECLAS.DERECHA)
            derecha_presionada = true;
        if (tecla == TECLAS.IZQUIERDA)
            izquierda_presionada = true;

        if (derecha_presionada)
        {
            rectx += 10;
        }

        if (izquierda_presionada)
        {
            rectx -= 10;
        }

        // ventana.imprimeEnConsola("X=%i - Y=%i\n", rx, ry);

        if (tecla == TECLAS.ENTER)
        {
            fs = !fs;
            ventana.pantallaCompleta(fs);
        }

        ventana.limpiaVentana(); // Borra


        if(!btn) {
            ventana.texto1(rx, ry, "Piyum!!", 50, "MV Boli");
            esp32->digitalWrite(esp32, MTR, true);
        } else {
            esp32->digitalWrite(esp32, MTR, false);
        }

        ventana.colorFondo(COLORES.VERDE); // Dibujamos

        ventana.color(COLORES.ROJO);

        ventana.linea(50, 50, 200, 200);

        ventana.rectangulo(100, 100, 200, 200);

        // ESTE ES EL BUENO
        // ventana.rectanguloRelleno(rectx, recty, rectx + 100, recty + 100);
        ventana.muestraImagen(rectx, recty, trex);
        // ventana.muestraImagenEscalada(rectx, recty, 100, 100, trex);

        ventana.colorRGB(28, 50, 123);

        ventana.circulo(rx, ry, 20);
        ventana.linea(rx - 10, ry, rx - 30, ry);
        ventana.linea(rx + 10, ry, rx + 30, ry);
        ventana.linea(rx, ry - 10, rx, ry - 30);
        ventana.linea(rx, ry + 10, rx, ry + 30);

        ventana.color(COLORES.ROJO);
        ventana.texto(100, 50, "Holi XD");
        ventana.texto2(300, 200, "Holi de Nuevo XD", 50, "MV Boli", true, true, true);

        ventana.actualizaVentana(); // Mostramos

        int tmp = ventana.teclaSoltada();

        if (tmp == TECLAS.DERECHA)
            derecha_presionada = false;
        if (tmp == TECLAS.IZQUIERDA)
            izquierda_presionada = false;

        ventana.espera(1);
    }

    ventana.cierraVentana();

    return 0;
}
