IF EXISTS (SELECT name FROM master.dbo.sysdatabases WHERE name = N'Bank')
	DROP DATABASE [Bank]
GO

CREATE DATABASE [Bank]  ON (NAME = N'Bank_Data', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL\data\Bank_Data.MDF' , SIZE = 1, FILEGROWTH = 10%) LOG ON (NAME = N'Bank_Log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL\data\Bank_Log.LDF' , SIZE = 1, FILEGROWTH = 10%)
 COLLATE Korean_Wansung_CI_AS
GO

exec sp_dboption N'Bank', N'autoclose', N'false'
GO

exec sp_dboption N'Bank', N'bulkcopy', N'false'
GO

exec sp_dboption N'Bank', N'trunc. log', N'false'
GO

exec sp_dboption N'Bank', N'torn page detection', N'true'
GO

exec sp_dboption N'Bank', N'read only', N'false'
GO

exec sp_dboption N'Bank', N'dbo use', N'false'
GO

exec sp_dboption N'Bank', N'single', N'false'
GO

exec sp_dboption N'Bank', N'autoshrink', N'false'
GO

exec sp_dboption N'Bank', N'ANSI null default', N'false'
GO

exec sp_dboption N'Bank', N'recursive triggers', N'false'
GO

exec sp_dboption N'Bank', N'ANSI nulls', N'false'
GO

exec sp_dboption N'Bank', N'concat null yields null', N'false'
GO

exec sp_dboption N'Bank', N'cursor close on commit', N'false'
GO

exec sp_dboption N'Bank', N'default to local cursor', N'false'
GO

exec sp_dboption N'Bank', N'quoted identifier', N'false'
GO

exec sp_dboption N'Bank', N'ANSI warnings', N'false'
GO

exec sp_dboption N'Bank', N'auto create statistics', N'true'
GO

exec sp_dboption N'Bank', N'auto update statistics', N'true'
GO

use [Bank]
GO

if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[Account]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Account]
GO

CREATE TABLE [dbo].[Account] (
	[AccountID] [int] NOT NULL ,
	[Balance] [int] NOT NULL 
) ON [PRIMARY]
GO

ALTER TABLE [dbo].[Account] WITH NOCHECK ADD 
	CONSTRAINT [PK_Account] PRIMARY KEY  CLUSTERED 
	(
		[AccountID]
	)  ON [PRIMARY] 
GO

use [Bank]
GO
insert into [dbo].[Account] values(1, 1000000)
GO
insert into  [dbo].[Account] values(2, 1000000)
GO