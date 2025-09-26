/**
 * @file figuras.hpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi biblioteca de clases
 * @version 0.1
 * @date 2025-09-25
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef __FIGURAS_HPP__
#define __FIGURAS_HPP__

namespace fig
{
    class Figura
    {
    protected:
        float base;
        float altura;

    public:
        Figura(float base, float altura);

        // Getters
        float getBase();
        float getAltura();

        // Metodo abstracto (aka virtual puro)
        virtual float area() = 0;
    };

    class Rectangulo : public Figura
    {
    public:
        Rectangulo(float base, float altura) : Figura(base, altura)
        {
        }

        // Polimorfismo
        // Sobreescritura

        /// @brief Devuelve el area del rectangulo.
        /// @return Un flotante
        float area();

        /// @brief Devuelve el perimetro de un rectangulo
        /// @return Un flotante
        float perimetro();
    };

    class Triangulo : public Figura
    {
    public:
        Triangulo(float base, float altura) : Figura(base, altura)
        {
        }
        // Polimorfismo
        // Sobreescritura
        float area();
    };

};

#endif