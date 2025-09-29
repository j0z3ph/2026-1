
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

        // Metodo abstracto
        virtual float area() = 0;
    };

    class Rectangulo : public Figura
    {
    public:
        Rectangulo(float base, float altura) : Figura(base, altura)
        {
        }

        // Sobreescritura
        // Polimorfismo

        /// @brief Calcula el area del rectangulo
        /// @return El area
        float area() override;
    };

    class Triangulo : public Figura
    {

    public:
        Triangulo(float base, float altura) : Figura(base, altura)
        {
        }

        // Sobre escritura
        // Polimorfismo
        float area() override;
    };

} // namespace fig

#endif