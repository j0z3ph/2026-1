-- Ejemplo de INNER JOIN

SELECT T1.staff_id, T1.first_name, T1.last_name, store_name,
T3.first_name + ' ' + T3.last_name AS manager_name 
FROM sales.staffs AS T1
INNER JOIN sales.stores AS T2 ON T1.store_id = T2.store_id
INNER JOIN sales.staffs AS T3 ON T1.manager_id = T3.staff_id

-- Ejemplo de LEFT JOIN

SELECT T1.staff_id, T1.first_name, T1.last_name, store_name,
T3.first_name + ' ' + T3.last_name AS manager_name 
FROM sales.staffs AS T1
LEFT JOIN sales.stores AS T2 ON T1.store_id = T2.store_id
LEFT JOIN sales.staffs AS T3 ON T1.manager_id = T3.staff_id


-- Ejemplo de RIGHT JOIN

SELECT T1.staff_id, T1.first_name, T1.last_name, store_name,
T3.first_name + ' ' + T3.last_name AS manager_name 
FROM sales.staffs AS T1
RIGHT JOIN sales.stores AS T2 ON T1.store_id = T2.store_id
RIGHT JOIN sales.staffs AS T3 ON T1.manager_id = T3.staff_id

-- Ejemplo de FULL OUTER JOIN

SELECT T1.staff_id, T1.first_name, T1.last_name, store_name,
T3.first_name + ' ' + T3.last_name AS manager_name 
FROM sales.staffs AS T1
FULL JOIN sales.stores AS T2 ON T1.store_id = T2.store_id
FULL JOIN sales.staffs AS T3 ON T1.manager_id = T3.staff_id


select * from sales.staffs

USE EXAMPLE3
GO

select * from dbo.member
CROSS JOIN dbo.member2

