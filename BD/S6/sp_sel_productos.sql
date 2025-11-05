-- SP que devuelva la lista de productos con su marca y categoria
-- Autor: Yo mero
-- 2025/11/05

CREATE OR ALTER PROCEDURE sp_sel_productos AS
BEGIN
SET NOCOUNT ON

SELECT product_id, product_name, brand_name, category_name, model_year, list_price
FROM production.products T1
JOIN production.brands T2 ON T1.brand_id = T2.brand_id
JOIN production.categories T3 ON T1.category_id = T3.category_id

END
GO