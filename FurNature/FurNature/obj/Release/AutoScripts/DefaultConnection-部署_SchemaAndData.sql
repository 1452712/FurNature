SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[__MigrationHistory](
	[MigrationId] [nvarchar](150) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[ContextKey] [nvarchar](300) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Model] [varbinary](max) NOT NULL,
	[ProductVersion] [nvarchar](32) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
 CONSTRAINT [PK_dbo.__MigrationHistory] PRIMARY KEY CLUSTERED 
(
	[MigrationId] ASC,
	[ContextKey] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetRoles](
	[Id] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Name] [nvarchar](256) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
 CONSTRAINT [PK_dbo.AspNetRoles] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUserClaims](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[UserId] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[ClaimType] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[ClaimValue] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
 CONSTRAINT [PK_dbo.AspNetUserClaims] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUserLogins](
	[LoginProvider] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[ProviderKey] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[UserId] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
 CONSTRAINT [PK_dbo.AspNetUserLogins] PRIMARY KEY CLUSTERED 
(
	[LoginProvider] ASC,
	[ProviderKey] ASC,
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUserRoles](
	[UserId] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[RoleId] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
 CONSTRAINT [PK_dbo.AspNetUserRoles] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC,
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AspNetUsers](
	[Id] [nvarchar](128) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Email] [nvarchar](256) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[EmailConfirmed] [bit] NOT NULL,
	[PasswordHash] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[SecurityStamp] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[PhoneNumber] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[PhoneNumberConfirmed] [bit] NOT NULL,
	[TwoFactorEnabled] [bit] NOT NULL,
	[LockoutEndDateUtc] [datetime] NULL,
	[LockoutEnabled] [bit] NOT NULL,
	[AccessFailedCount] [int] NOT NULL,
	[UserName] [nvarchar](256) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
 CONSTRAINT [PK_dbo.AspNetUsers] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Furnitures](
	[Id] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Name] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Type] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Img] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Price] [decimal](8, 2) NOT NULL,
	[PurchaseUrl] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Introduction] [ntext] COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[Path] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Models](
	[ID] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[UserID] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[Name] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[ImgTop] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[ImgBottom] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[ImgLeft] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[ImgRight] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[ImgBack] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Photos](
	[ID] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[UserID] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[ModelID] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NULL,
	[Path] [nvarchar](max) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[x1] [int] NULL,
	[y1] [int] NULL,
	[x2] [int] NULL,
	[y2] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)

GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[User_Fur](
	[UserId] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL,
	[FurId] [nvarchar](50) COLLATE SQL_Latin1_General_CP1_CI_AS NOT NULL
)

GO
INSERT [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'0774970d-7f96-44bf-ad3b-1af8a9960915', N'1452712@gmail.com', 0, N'AEgGA30bekHdP714syICIb4sF4je93Q3T376/i3xh7j8Q5/lQNtFpio+k8oNUx9q3w==', N'45b4e0d7-97a5-4a46-93e2-ac1678ebbd47', NULL, 0, 0, NULL, 1, 0, N'1452712@gmail.com')
GO
INSERT [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'0f4ebc0a-5686-4cdf-9df5-ea196f6f4691', N'1452712@tongji.edu.cn', 0, N'AE+kp3v5p3sO7vJDJ5AXoEHAGtDtaSlmmzMrkkeXipLKTn9JJIcqsCoKBE7JCiId7g==', N'da5723be-c8d5-40a4-9f3b-f92bd3ca2c9c', NULL, 0, 0, NULL, 1, 0, N'1452712@tongji.edu.cn')
GO
INSERT [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'4860c607-ed8a-4811-b142-5f7562244cb1', N'nbwjh@126.com', 0, N'AKxB44LU/rYpWjnI1okEDEC0CfBfqrJvDKliVTb3CnZKAtiVGsWQ8DAcISE9U8Edqg==', N'b713c059-b23c-47b2-bef2-bfac779026ea', NULL, 0, 0, NULL, 1, 0, N'nbwjh@126.com')
GO
INSERT [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'd205e41e-79f3-4223-b861-c18158655313', N'1452712@126.com', 0, N'AHnDb+lHhQlYmubzakxEG5IlWSI1G2feRBAE4OlLQx85UhNOxhEbGepyzLnyDDiTLQ==', N'f83a790e-42e1-4b33-b273-fd87153c82c1', NULL, 0, 0, NULL, 1, 0, N'1452712@126.com')
GO
INSERT [dbo].[Furnitures] ([Id], [Name], [Type], [Img], [Price], [PurchaseUrl], [Introduction], [Path]) VALUES (N'1', N'White Sofa', N'sofa', N'/Image/Furnitures/sofa/1.jpg', CAST(4799.00 AS Decimal(8, 2)), N'http://www.ikea.com/cn/zh/catalog/products/S59124980/', N'选择适合家中空间的尺寸和形状，为每位家庭成员打造一个最爱的角落。侧边触手可及的口袋可存放遥控器，避免遥控器埋在枕头和休闲毯下面。', N'http://www.ikea.com/cn/zh/catalog/products/S59124980/')
GO
INSERT [dbo].[Models] ([ID], [UserID], [Name], [ImgTop], [ImgBottom], [ImgLeft], [ImgRight], [ImgBack]) VALUES (N'01', N'nbwjh@126.com', N'Room1', N'/Image/hsides/01/htop.jpg', N'/Image/hsides/01/hbottom.jpg', N'/Image/hsides/01/hleft.jpg', N'/Image/hsides/01/htop.jpg', N'/Image/hsides/01/hback.jpg')
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'01', N'nbwjh@126.com', N'01', N'/Image/hsides/01/house.jpg', 1, 1, 1, 1)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'146364', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'164287', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'206138', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'241257', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'296650', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'429163', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'511588', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'547197', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'679613', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'79281', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'814539', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'858817', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'876865', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'911828', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'946648', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
INSERT [dbo].[Photos] ([ID], [UserID], [ModelID], [Path], [x1], [y1], [x2], [y2]) VALUES (N'99394', N'nbwjh@126.com', NULL, N'\Image\hsides\nbwjh@126.com\house.jpg', 0, 0, 0, 0)
GO
SET ANSI_PADDING ON

GO
CREATE UNIQUE NONCLUSTERED INDEX [RoleNameIndex] ON [dbo].[AspNetRoles]
(
	[Name] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
GO
SET ANSI_PADDING ON

GO
CREATE NONCLUSTERED INDEX [IX_UserId] ON [dbo].[AspNetUserClaims]
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
GO
SET ANSI_PADDING ON

GO
CREATE NONCLUSTERED INDEX [IX_UserId] ON [dbo].[AspNetUserLogins]
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
GO
SET ANSI_PADDING ON

GO
CREATE NONCLUSTERED INDEX [IX_RoleId] ON [dbo].[AspNetUserRoles]
(
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
GO
SET ANSI_PADDING ON

GO
CREATE NONCLUSTERED INDEX [IX_UserId] ON [dbo].[AspNetUserRoles]
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
GO
SET ANSI_PADDING ON

GO
CREATE UNIQUE NONCLUSTERED INDEX [UserNameIndex] ON [dbo].[AspNetUsers]
(
	[UserName] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
GO
ALTER TABLE [dbo].[AspNetUserClaims]  WITH CHECK ADD  CONSTRAINT [FK_dbo.AspNetUserClaims_dbo.AspNetUsers_UserId] FOREIGN KEY([UserId])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserClaims] CHECK CONSTRAINT [FK_dbo.AspNetUserClaims_dbo.AspNetUsers_UserId]
GO
ALTER TABLE [dbo].[AspNetUserLogins]  WITH CHECK ADD  CONSTRAINT [FK_dbo.AspNetUserLogins_dbo.AspNetUsers_UserId] FOREIGN KEY([UserId])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserLogins] CHECK CONSTRAINT [FK_dbo.AspNetUserLogins_dbo.AspNetUsers_UserId]
GO
ALTER TABLE [dbo].[AspNetUserRoles]  WITH CHECK ADD  CONSTRAINT [FK_dbo.AspNetUserRoles_dbo.AspNetRoles_RoleId] FOREIGN KEY([RoleId])
REFERENCES [dbo].[AspNetRoles] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserRoles] CHECK CONSTRAINT [FK_dbo.AspNetUserRoles_dbo.AspNetRoles_RoleId]
GO
ALTER TABLE [dbo].[AspNetUserRoles]  WITH CHECK ADD  CONSTRAINT [FK_dbo.AspNetUserRoles_dbo.AspNetUsers_UserId] FOREIGN KEY([UserId])
REFERENCES [dbo].[AspNetUsers] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[AspNetUserRoles] CHECK CONSTRAINT [FK_dbo.AspNetUserRoles_dbo.AspNetUsers_UserId]
GO
