-- sp_add_category
-- Agrega categorias de bicicletas
-- Autor: Yo
-- Fecha: Hoy

CREATE OR ALTER PROCEDURE sp_add_category(@name VARCHAR(255))
AS
SET NOCOUNT ON;
BEGIN TRY
    -- Verificamos si ya existe la categoria
    DECLARE @YA_EXISTE INT;
    DECLARE @ERROR_MESSAGE VARCHAR(200);
    SET @ERROR_MESSAGE = 'La categoria ' + @name + ' ya existe.';

    SET @YA_EXISTE = (SELECT COUNT(category_id) FROM production.categories
                      WHERE category_name = @name)

    IF @YA_EXISTE = 0
    BEGIN
        INSERT INTO production.categories VALUES(@name);
    END
    ELSE 
    BEGIN
        THROW 66666, @ERROR_MESSAGE, 1;
    END
END TRY
BEGIN CATCH
    DECLARE @ErrorMessage NVARCHAR(4000), @ErrorSeverity INT;
    SELECT @ErrorMessage = ERROR_MESSAGE(),@ErrorSeverity = ERROR_SEVERITY();
    RAISERROR(@ErrorMessage, @ErrorSeverity, 1);
END CATCH;
GO




