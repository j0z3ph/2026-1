-- SIN PIVOTES
SELECT category_name, COUNT(product_id) 
FROM production.products AS T
JOIN production.categories AS T2 ON T.category_id = T2.category_id
GROUP BY category_name


-- CON PIVOTES
SELECT * FROM(
    SELECT product_id, category_name
    FROM production.products AS T
    JOIN production.categories AS T2 ON T.category_id = T2.category_id
) AS Tabla
PIVOT (
    COUNT(product_id)
    FOR category_name IN (
        [Children Bicycles], 
        [Comfort Bicycles], 
        [Cruisers Bicycles], 
        [Cyclocross Bicycles], 
        [Electric Bikes], 
        [Mountain Bikes], 
        [Road Bikes]
    )
) AS Tabla_Final


SELECT category_name FROM production.categories


SELECT * FROM production.categories