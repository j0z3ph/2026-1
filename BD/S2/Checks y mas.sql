use BaseDeDatos
GO

create TABLE Esquema.Tabla2 (
    id int PRIMARY KEY,
    defecto VARCHAR(100) DEFAULT 'Vacio'
)
GO

CREATE INDEX Indice ON Esquema.Tabla2(defecto)
go


CREATE TABLE Esquema.Tabla3 (
    id INTEGER IDENTITY(1,1) PRIMARY KEY,
    texto VARCHAR(100)
)
GO