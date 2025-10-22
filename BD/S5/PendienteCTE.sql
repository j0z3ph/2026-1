SELECT order_id, item_id, product_name, brand_name, category_name,
model_year, t1.list_price, quantity, discount, 
(t1.list_price * quantity) - (t1.list_price * quantity * discount) total
FROM sales.order_items AS T1
JOIN production.products AS t2 ON t1.product_id = t2.product_id
JOIN production.brands AS t3 ON t2.brand_id = t3.brand_id
JOIN production.categories AS t4 ON t2.category_id = t4.category_id