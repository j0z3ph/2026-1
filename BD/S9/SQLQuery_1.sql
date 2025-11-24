select * from empleo
select * from EMPLEADO

-- Insertar un nuevo empleo
-- Insertar un nuevo empleado

-- primer insert genera el id 11
-- segundo insert con id 11 de empleo

insert into EMPLEO values(20,'Jefe', 60000); -- ok
--insert into EMPLEO values('Chala', 6); -- ok


BEGIN TRAN losPoryectos 
WITH MARK 'BorradoXD'
delete from EMPLEO
--insert into EMPLEADO values ('Jose Luis', 'Cruz', '2025-11-24', 10) -- ok

COMMIT TRAN losPoryectos
ROLLBACK TRAN

select * from EMPLEADO

 SELECT * FROM msdb.dbo.logmarkhistory

SELECT Operation,
[rowlog contents 0],
[rowlog contents 1],
[rowlog contents 2],
[rowlog contents 3]
FROM sys.fn_dblog(NULL,NULL)
--WHERE operation = ('LOP_MODIFY_ROW')
ORDER BY Operation ASC


DBCC TRACEON (3604, -1)
GO
DBCC PAGE (RecoverFromTransactionLog, 2, 0, 2)
GO
