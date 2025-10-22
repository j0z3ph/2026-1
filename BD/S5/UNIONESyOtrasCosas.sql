USE BikesDB

-- CASE
SELECT staff_id, first_name, last_name, 
CASE
    WHEN active = 1 THEN 'Activo'
    WHEN active = 0 THEN 'Baja'
END AS status
FROM sales.staffs


-- COALESCE
SELECT staff_id, first_name, last_name, 
COALESCE(manager_id, '') AS manager_id 
FROM sales.staffs

-- COALESCE con CASE
SELECT staff_id, first_name, last_name, 
CASE 
    WHEN manager_id IS NULL THEN 0
    ELSE manager_id
END AS manager_id 
FROM sales.staffs

-- NULLIF
SELECT staff_id, first_name, last_name, 
CASE
    WHEN NULLIF(manager_id, 2) IS NULL THEN 0
    ELSE manager_id
END AS manager_id
FROM sales.staffs


SELECT COALESCE(NULL, 1)

SELECT NULLIF(3,3)



UPDATE sales.staffs
SET active = 0
WHERE staff_id = 7

--- SELF JOIN

SELECT T1.staff_id, T1.first_name, T1.last_name, T2.first_name + ' ' + T2.last_name AS manager_name
FROM sales.staffs AS T1
INNER JOIN sales.staffs AS T2 ON t1.manager_id = T2.staff_id


USE EXAMPLE3
GO

-- UNION
SELECT member_no, firstname, lastname FROM dbo.member 
UNION ALL
SELECT member_no, firstname, lastname FROM dbo.member2

-- Interseccion
SELECT member_no, firstname, lastname FROM dbo.member 
INTERSECT
SELECT member_no, firstname, lastname FROM dbo.member2

-- Resta
SELECT member_no, firstname, lastname FROM dbo.member 
EXCEPT
SELECT member_no, firstname, lastname FROM dbo.member2
