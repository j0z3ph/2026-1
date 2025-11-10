select COUNT(category_id) from production.categories
where category_name = 'deportes extremos'

select * from production.categories

insert into production.brands(brand_id, brand_name) values(1, 'Apache')

EXEC sp_add_category '';