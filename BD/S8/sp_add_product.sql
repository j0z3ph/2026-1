-- sp_add_product
-- Agrega una marca
-- Autor: Yo
-- Fecha: Hoy

--EXEC sp_add_product 'Bichicleta', 'Apache', 'Deportes eXtremos', 2025, 1000000.5

--select * from production.products order by 1 desc

--select * from production.categories
--SELECT brand_id from production.brands where brand_name = 'AApache'

CREATE OR ALTER PROCEDURE sp_add_product(@nombre VARCHAR(255),
@marca VARCHAR(255), @categoria VARCHAR(255), @anio SMALLINT, 
@precio DECIMAL(10,2))
AS
SET NOCOUNT ON;
BEGIN TRY
    DECLARE @id_marca INT
    DECLARE @id_categoria INT

    SET @id_marca = (SELECT brand_id from production.brands where brand_name = @marca)
    SET @id_categoria = (SELECT category_id from production.categories where category_name = @categoria)
    
    IF @id_marca IS NULL 
    BEGIN
        THROW 77777, 'La marca no existe.', 1;
    END
    IF @id_categoria IS NULL 
    BEGIN
        THROW 77778, 'La categoria no existe.', 1;
    END
    IF @precio <= 0
    BEGIN
        THROW 77779, 'No regalamos bicis >:[', 1;
    END
    IF @anio < 2000 OR @anio > YEAR(CURRENT_TIMESTAMP)
    BEGIN
        THROW 77780, 'Año invalido T-T', 1;
    END
    IF @nombre IS NULL
    BEGIN
        THROW 77781, 'Ya estuvo no >:|', 1;
    END

    INSERT INTO production.products VALUES(
        @nombre, @id_marca, @id_categoria, @anio, @precio
    )

END TRY 
BEGIN CATCH
    DECLARE @ErrorMessage NVARCHAR(4000), @ErrorSeverity INT;
    SELECT @ErrorMessage = ERROR_MESSAGE(),@ErrorSeverity = ERROR_SEVERITY(); 
    RAISERROR(@ErrorMessage, @ErrorSeverity, 1);
END CATCH; 
GO