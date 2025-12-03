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
#include "simplecontroller.h"
#define GRAVEDAD 1
#define JX 15
#define JY 2
#define SW 4
#define MOTOR 13

#define AJUSTEX 0.45
#define AJUSTEY 0.35

int main()
{
    Board *esp32 = connectDevice("COM7", B115200);

    Imagen *carro = ventana.creaImagenConMascara("carro.bmp", "carromascara.bmp");
    bool fs = false;
    int rx = 300, ry = 300;
    int cuadradox = 300, cuadradoy = 100;
    int aceleracion = 0;
    bool derecha_pres = false, izquierda_pres = false;
    float joyX, joyY;
    bool btn;
    int ajusteX, ajusteY;

    esp32->pinMode(esp32, JX, INPUT);
    esp32->pinMode(esp32, JY, INPUT);
    esp32->pinMode(esp32, SW, INPUT_PULLUP);   
    esp32->pinMode(esp32, MOTOR, OUTPUT); 


    ventana.tamanioVentana(800, 600);
    ventana.tituloVentana("Hola Windows");
    ventana.colorFondo(COLORES.AZUL);

    int tecla = ventana.teclaPresionada();

    while (tecla != TECLAS.ESCAPE)
    {
        joyX = esp32->analogRead(esp32, JX);
        joyY = esp32->analogRead(esp32, JY);
        btn = esp32->digitalRead(esp32, SW);


        joyX -= AJUSTEX;

        if(joyX >= 0.0)
            ajusteX = joyX * (10.0 / (1.0 - AJUSTEX));
        else 
            ajusteX = joyX * (11.0 / (AJUSTEX));


        joyY -= AJUSTEY;

        if(joyY >= 0.0)
            ajusteY = joyY * (11.0 / (1.0 - AJUSTEY));
        else 
            ajusteY = joyY * (11.0 / (AJUSTEY));


        //ventana.imprimeEnConsola("(%f, %f) - %i | %i, %i\n", joyX, joyY, btn, ajusteX, ajusteY);

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

        //ventana.raton(&rx, &ry);
        rx += ajusteX;
        ry += ajusteY;

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

        ventana.muestraImagen(cuadradox, cuadradoy, carro);
        // ventana.muestraImagenEscalada(cuadradox, cuadradoy,200,100, carro);

        // ventana.rectanguloRelleno(cuadradox, cuadradoy, cuadradox + 100, cuadradoy + 100);

        ventana.color(COLORES.CYAN);
        ventana.circulo(rx, ry, 20);
        ventana.linea(rx - 10, ry, rx - 30, ry);
        ventana.linea(rx + 10, ry, rx + 30, ry);
        ventana.linea(rx, ry - 10, rx, ry - 30);
        ventana.linea(rx, ry + 10, rx, ry + 30);
        ventana.circuloRelleno(rx, ry, 2);

        ventana.texto(100, 100, "Holi XD");

        if(!btn) {
            ventana.texto1(rx, ry, "Piyum", 50, "Ink Free");
            esp32->digitalWrite(esp32, MOTOR, true);
        } else {
            esp32->digitalWrite(esp32, MOTOR, false);
        }
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
