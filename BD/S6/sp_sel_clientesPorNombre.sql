-- SP que permite filtrar por nombre los clientes de la tienda
-- Autor: Yo
-- Fecha: Ahorita

CREATE OR ALTER PROCEDURE sp_sel_clientesPorNombre(@nombre VARCHAR(100),
@apellido VARCHAR(100) = '', @contador INTEGER OUTPUT) AS
BEGIN
SET NOCOUNT ON

SELECT customer_id, first_name, last_name, phone, email,
street, city, [state], zip_code 
FROM sales.customers
WHERE first_name LIKE '%' + @nombre + '%'
AND last_name LIKE '%' + @apellido + '%';


SET @contador = (SELECT COUNT(customer_id)
FROM sales.customers
WHERE first_name LIKE '%' + @nombre + '%'
AND last_name LIKE '%' + @apellido + '%')

END
GO