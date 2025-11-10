-- Procedimiento que agrega marcas de bicis
-- NOTA: Siempre genera un error
-- Autor: Yo
-- Fecha: 10-11-2025

CREATE OR ALTER PROCEDURE sp_add_brand(@id int, @brandName VARCHAR(255))
AS
SET NOCOUNT ON;
BEGIN TRY
    INSERT INTO production.brands(brand_id, brand_name) VALUES(@id, @brandName);
END TRY
BEGIN CATCH
    --print N'Ocurrio un ERROR'
    DECLARE @ErrorMessage NVARCHAR(4000), @ErrorSeverity INT;
    SELECT @ErrorMessage = ERROR_MESSAGE(),@ErrorSeverity = ERROR_SEVERITY();
    RAISERROR(@ErrorMessage, @ErrorSeverity, 1);
END CATCH;
GO