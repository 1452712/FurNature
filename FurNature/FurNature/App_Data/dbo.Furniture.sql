CREATE TABLE [dbo].[Table]
(
	[Id] NVARCHAR(50) NOT NULL PRIMARY KEY, 
    [Name] NVARCHAR(50) NOT NULL, 
    [Type] NVARCHAR(50) NOT NULL, 
    [Img] NVARCHAR(50) NOT NULL, 
    [Price] FLOAT NOT NULL, 
    [PurchaseUrl] NVARCHAR(MAX) NOT NULL, 
    [Introduction] NTEXT NULL, 
    [Path] NVARCHAR(MAX) NOT NULL
)
