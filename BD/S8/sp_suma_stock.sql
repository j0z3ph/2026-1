-- sp_suma_stock
-- Agrega stock a un producto en una tienda determinada
-- Autor: yo
-- Fecha: Hoy

--EXEC sp_suma_stock 1, 1001, 100

--select * FROM production.stocks where store_id = 1 ORDER by 2 DESC

CREATE OR ALTER PROCEDURE sp_suma_stock(
    @idTienda INT, @idProducto INT, @cantidad INT
)
AS
SET NOCOUNT ON;
BEGIN TRY
    DECLARE @existe INT

    IF @cantidad <= 0
    BEGIN
        THROW 77777, 'La cantidad debe ser mayor a 0.', 1;
    END

    SET @existe = (SELECT COUNT(store_id) FROM production.stocks WHERE store_id = @idTienda AND product_id = @idProducto)

    IF @existe = 1 
    BEGIN -- UPDATE
        UPDATE production.stocks SET quantity = quantity + @cantidad 
        WHERE store_id = @idTienda AND product_id = @idProducto;
    END
    ELSE
    BEGIN -- INSERT
        SET @existe = (SELECT COUNT(product_id) FROM production.products WHERE product_id = @idProducto)
        IF @existe = 0
        BEGIN
            THROW 77778, 'El producto no existe :c', 1;
        END
        ELSE
        BEGIN
            SET @existe = (SELECT COUNT(store_id) FROM sales.stores WHERE store_id = @idTienda)
            IF @existe = 0
            BEGIN
                THROW 77779, 'La tienda no existe :c', 1;
            END
            ELSE 
            BEGIN
                INSERT INTO production.stocks VALUES(@idTienda, @idProducto, @cantidad);
            END
        END
    END

END TRY 
BEGIN CATCH
    DECLARE @ErrorMessage NVARCHAR(4000), @ErrorSeverity INT;
    SELECT @ErrorMessage = ERROR_MESSAGE(),@ErrorSeverity = ERROR_SEVERITY(); 
    RAISERROR(@ErrorMessage, @ErrorSeverity, 1);
END CATCH; 
GO