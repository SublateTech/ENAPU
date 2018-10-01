CREATE TABLE [dbo].[Atendido] (
	[Item] [char] (2) NULL ,
	[Prioridad_Mensaje] [char] (10) NULL ,
	[Detalle] [char] (140) NULL ,
	[Usuario] [char] (10) NULL ,
	[Fecha_Reg] [char] (8) NULL ,
	[Hora] [char] (8) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Brevete] (
	[Licencia] [char] (10) NULL ,
	[Agencia] [char] (60) NULL ,
	[Apellido] [char] (20) NULL ,
	[LE_DNI] [char] (8) NULL ,
	[Nombre] [char] (25) NULL ,
	[LM] [char] (10) NULL ,
	[Estado] [char] (50) NULL ,
	[Fecha_Reg] [char] (8) NULL ,
	[Fecha_Exp] [char] (8) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Carga_Rodante] (
	[BL_Master] [char] (25) NOT NULL ,
	[BL_Hijo] [char] (25) NOT NULL ,
	[Total_Bultos] [char] (4) NOT NULL ,
	[Total_Peso] [char] (4) NOT NULL ,
	[Chasis] [char] (25) NOT NULL ,
	[Modelo] [char] (25) NOT NULL ,
	[Manifiesto] [char] (9) NOT NULL ,
	[Nave] [char] (50) NOT NULL ,
	[Area] [char] (4) NOT NULL ,
	[Ubicacion] [char] (2) NOT NULL ,
	[Nueva_Ubic] [char] (2) NOT NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Consulta_Muelles] (
	[Codigo_de_1] [char] (4) NULL ,
	[Descripcion_1] [char] (100) NULL ,
	[Codigo_de_2] [char] (5) NULL ,
	[Descripcion_2] [char] (100) NULL ,
	[Codigo_de_3] [char] (6) NULL ,
	[Descripcion] [char] (100) NULL ,
	[Codigo_de_4] [char] (7) NULL ,
	[Descripcion_4] [char] (30) NULL ,
	[Codigo_de_5] [char] (8) NULL ,
	[Descripcion_5] [char] (100) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Informacion] (
	[Placa] [char] (8) NULL ,
	[Agencia] [char] (60) NULL ,
	[Dueno] [char] (40) NULL ,
	[Modelo] [char] (25) NULL ,
	[Nro_Ejes] [char] (4) NULL ,
	[Carreta] [char] (10) NULL ,
	[Nro_Ejes_1] [char] (4) NULL ,
	[Estado] [char] (50) NULL ,
	[Fecha_Reg] [char] (8) NULL ,
	[Fecha_Exp] [char] (8) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Tareas] (
	[Nro_Atencion] [char] (4) NULL ,
	[Autorizacion] [char] (10) NULL ,
	[Contenedor] [char] (13) NULL ,
	[Ubicacion] [char] (8) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Tareas_Embarque_Contenedores] (
	[Nro_Atencion] [char] (4) NULL ,
	[Autorizacion] [char] (10) NULL ,
	[Contenedor] [char] (13) NULL ,
	[Ubicacion] [char] (8) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Ticket_Balanza] (
	[Nro_Ticket] [char] (10) NULL ,
	[Chofer] [char] (10) NULL ,
	[Placa] [char] (8) NULL ,
	[Autorizacion] [char] (10) NULL ,
	[Operacion] [char] (3) NULL ,
	[Balanza] [char] (4) NULL ,
	[Fecha_Reg] [char] (8) NULL ,
	[Embalaje] [char] (3) NULL ,
	[Tot_Peso_Vehiculo] [char] (4) NULL ,
	[Usuario] [char] (10) NULL ,
	[Hora_Reg] [char] (8) NULL ,
	[Area] [char] (15) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Tickets_Balanza] (
	[Nro_Ticket] [char] (10) NULL ,
	[Contenedor] [char] (13) NULL ,
	[Precinto] [char] (16) NULL ,
	[Tara] [char] (4) NULL ,
	[Condicion] [char] (3) NULL ,
	[Balanza] [char] (4) NULL ,
	[Fecha_Reg] [char] (8) NULL ,
	[Tamano] [char] (2) NULL ,
	[Tipo] [char] (2) NULL ,
	[Peso] [char] (4) NULL ,
	[Estado] [char] (3) NULL ,
	[Pesador] [char] (10) NULL ,
	[Hora_Reg] [char] (8) NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Ubicacion_Carga] (
	[BL_Master] [char] (25) NOT NULL ,
	[BL_Hijo] [char] (25) NOT NULL ,
	[Total_Bultos] [char] (4) NOT NULL ,
	[Total_Peso] [char] (4) NOT NULL ,
	[Cod_Embalaje] [char] (3) NOT NULL ,
	[Manifiesto] [char] (9) NOT NULL ,
	[Nave] [char] (50) NOT NULL ,
	[Area] [char] (50) NOT NULL ,
	[Ubicacion] [char] (2) NOT NULL ,
	[Marca_Numero] [char] (8) NOT NULL ,
	[Producto] [char] (8) NOT NULL
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Ubicacion_Contenedores] (
	[Contenedor] [char] (13) NOT NULL ,
	[Condicion] [char] (5) NOT NULL ,
	[Precinto] [varchar] (16) NOT NULL ,
	[Tamano] [char] (4) NOT NULL ,
	[Tipo] [char] (4) NOT NULL ,
	[Estado] [char] (4) NOT NULL ,
	[Tara] [char] (4) NOT NULL ,
	[Peso] [char] (5) NOT NULL ,
	[Manifiesto] [char] (9) NOT NULL ,
	[Nave] [varchar] (50) NOT NULL ,
	[Area] [varchar] (50) NOT NULL ,
	[Ubi_1] [char] (8) NOT NULL ,
	[Ubi_2] [char] (8) NOT NULL
) ON [PRIMARY]
GO

