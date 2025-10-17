USE BaseDeDatos
GO

INSERT INTO Esquema.Tabla VALUES(2,100)
GO

INSERT INTO Esquema.Tabla(edad) VALUES(3,100)
GO


SELECT * FROM Esquema.Tabla

-- Cambio de base de datos
USE BikesDB
GO

SELECT brand_name, brand_id, brand_name FROM production.brands

SELECT *, list_price - DESCUENTO AS oferta FROM (
SELECT *, list_price * 0.25 AS DESCUENTO FROM production.products) AS T

SELECT MIN(list_price) FROM production.products

SELECT GETDATE() - 1



SELECT product_id AS 'ID de Producto', product_name AS 'Nombre', model_year Modelo, list_price AS 'Precio de Lista' FROM production.products

SELECT product_id AS 'ID de Producto', 'Nombre: ' + product_name AS 'Nombre', model_year Modelo, list_price AS 'Precio de Lista' FROM production.products


SELECT DISTINCT model_year FROM production.products

SELECT * FROM production.products
WHERE list_price >= 1000 AND list_price <= 2000

SELECT * FROM production.products
WHERE list_price BETWEEN 1000 AND 2000
AND model_year = 2017


SELECT * FROM sales.customers
WHERE first_name LIKE '%e_'

SELECT * FROM production.products
WHERE model_year = 2016 OR model_year = 2018

SELECT * FROM production.products
WHERE model_year IN (2016, 2018)

SELECT * FROM production.products
WHERE model_year <> 2018

UPDATE production.products
SET product_name = 'Trek Checkpoint ALR 6 Men`s - 2019'

--SELECT * FROM production.products
WHERE product_id = 318


SELECT * FROM sales.orders
ORDER BY 1 DESC

DELETE FROM sales.orders
WHERE order_id = 1615


UPDATE production.products
SET list_price = (
SELECT list_price - (list_price*0.25) FROM production.products
WHERE product_id = 1
)
WHERE product_id = 1