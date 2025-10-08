use BaseDeDatos;

-- Agregamos columnas
ALTER TABLE esquema.Tabla
ADD columna bigint;

-- Modificamos el tipo de dato de una columna
ALTER TABLE esquema.Tabla
ALTER COLUMN columna VARCHAR(MAX);

-- Eliminamos una columna
ALTER TABLE esquema.Tabla
DROP COLUMN nacimiento;

-- Renombrar una columna
EXEC sp_rename 'esquema.Tabla.nombre', 'renombre', 'COLUMN';

-- Eliminamos la base de datos
use master;
DROP DATABASE BaseDeDatos;
use BaseDeDatos;
DROP SCHEMA esquema;
DROP TABLE esquema.Tabla;

-- EJEMPLO DE TRUNCATE
use BaseDeDatos;
CREATE SCHEMA esquema;
CREATE TABLE esquema.Tabla (
    id int NOT NULL,
    renombre VARCHAR(MAX)
);

SELECT * from esquema.Tabla;

TRUNCATE TABLE esquema.Tabla;

ALTER TABLE esquema.Tabla
ALTER COLUMN renombre varchar(max) NOT NULL;


ALTER TABLE esquema.Tabla
ADD CONSTRAINT UC_ID UNIQUE(id);

-- Agregamos un PK
ALTER TABLE esquema.Tabla
ADD CONSTRAINT PK_TABLA PRIMARY KEY(id);

-- Crear restricciones de tipo unique para mas de un campo
ALTER TABLE esquema.Tabla
ADD CONSTRAINT UC_Tabla UNIQUE (id,renombre);

-- Creamos una nueva tabla
CREATE TABLE esquema.Tabla2(
    id2 int NOT NULL PRIMARY KEY,
    renombre2 VARCHAR(50),
    id1 int FOREIGN KEY REFERENCES esquema.Tabla(id)
);
 DROP TABLE esquema.Tabla2;