EXEC sp_helptext v_marcas;

SELECT * FROM production.brands


INSERT INTO v_marcas values('Apache');

DELETE v_marcas WHERE brand_name = 'Apache';

DROP VIEW v_marcas

CREATE OR ALTER VIEW v_productos AS 
SELECT product_id, product_name, brand_name, category_name, model_year, list_price
FROM production.products T1
JOIN production.brands T2 ON T1.brand_id = T2.brand_id
JOIN production.categories T3 ON T1.category_id = T3.category_id
WITH CHECK OPTION;

SELECT * FROM dbo.v_productos

EXEC sp_sel_productos


select * from sales.customers

EXEC sp_sel_clientesPorNombre 'nita', 'mac'

EXEC sp_sel_clientesPorNombre @apellido = 'n', @nombre = 'nita'


DECLARE @numero INTEGER;

EXEC sp_sel_clientesPorNombre 'nita', '', @numero OUTPUT;

select @numero as Total;