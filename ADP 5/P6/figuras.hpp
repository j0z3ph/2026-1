/**
 * @file figuras.hpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Biblioteca FIGURAS
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
        double base;
        double altura;

    public:
        Figura(double altura, double base);

        // Getters
        double getBase();
        double getAltura();

        // Metodo Abstracto (metodo virtual puro)
        virtual double area() = 0;
    };

    class Rectangulo : public Figura
    {

    public:
        Rectangulo(double base, double altura) : Figura(altura, base) {}

        // Polimorfismo
        // Sobre escritura

        /// @brief Devuelve el area del rectangulo
        /// @return Un numero de punto flotante de doble precision
        double area(); 

        /// @brief Devuelve el perimetro del rectangulo
        /// @return Un numero de punto flotante de doble precision
        double perimetro();
    };

    class Triangulo : public Figura
    {
    public:
        Triangulo(double base, double altura) : Figura(altura, base)
        {
        }

        // Polimorfismo
        // Sobre escritura

        /// @brief Devuelve el area del triangulo
        /// @return Un numero de punto flotante de doble precision
        double area();
    };

} // namespace fig

#endif
