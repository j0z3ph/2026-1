DECLARE @RC int
DECLARE @id int
DECLARE @brandName varchar(255)

-- TODO: Set parameter values here.

EXECUTE @RC = [dbo].[sp_add_brand] 
   @id
  ,@brandName
GO


EXEC dbo.sp_add_brand 'Apache'