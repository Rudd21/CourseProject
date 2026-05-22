/****** Object:  Table [dbo].[Collection]    Script Date: 12.05.2026 20:28:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Collection](
	[idCollection] [int] IDENTITY(1,1) NOT NULL,
	[title] [nvarchar](100) NULL,
	[targetAmount] [money] NULL,
	[report] [nvarchar](255) NULL,
	[idReceipient] [int] NULL,
	[idEvent] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[idCollection] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Donat]    Script Date: 12.05.2026 20:28:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Donat](
	[idDonat] [int] IDENTITY(1,1) NOT NULL,
	[sum] [money] NULL,
	[donationDate] [datetime] NULL,
	[idPerson] [int] NULL,
	[idCollection] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[idDonat] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Event]    Script Date: 12.05.2026 20:28:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Event](
	[IdEvent] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](255) NULL,
	[Description] [nvarchar](max) NULL,
	[StartDate] [datetime] NULL,
	[EndDate] [datetime] NULL,
	[Goal] [nvarchar](50) NULL,
	[Status] [nvarchar](50) NULL,
PRIMARY KEY CLUSTERED 
(
	[IdEvent] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Person]    Script Date: 12.05.2026 20:28:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Person](
	[idPerson] [int] IDENTITY(1,1) NOT NULL,
	[fullName] [nvarchar](100) NULL,
	[phone] [nvarchar](20) NULL,
	[email] [nvarchar](100) NULL,
	[address] [nvarchar](255) NULL,
PRIMARY KEY CLUSTERED 
(
	[idPerson] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Receipient]    Script Date: 12.05.2026 20:28:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Receipient](
	[idReceipient] [int] IDENTITY(1,1) NOT NULL,
	[fullName] [nvarchar](100) NULL,
	[description] [nvarchar](255) NULL,
	[contactInfo] [nvarchar](100) NULL,
PRIMARY KEY CLUSTERED 
(
	[idReceipient] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Collection] ON 

INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (1, N'Збір на Mavic 3T', 85000.0000, N'Чекаємо на поставку', 1, 2)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (2, N'Корм для 100 собак', 15000.0000, N'Куплено 50 мішків', 3, 3)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (3, N'Турнікети CAT', 40000.0000, N'Відвантажено 100 шт', 5, 6)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (4, N'Зимова гума для пікапа', 25000.0000, NULL, 2, 2)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (5, N'Планшети для артилерії', 60000.0000, N'В процесі закупівлі', 10, 9)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (6, N'Ноутбуки для штабу', 45000.0000, NULL, 2, 10)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (7, N'Медикаменти загальні', 12000.0000, N'Звіт на сайті', 9, 6)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (8, N'Генератор 5кВт', 35000.0000, NULL, 7, 10)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (9, N'Рації Motorola', 70000.0000, N'Передано на фронт', 10, 2)
INSERT [dbo].[Collection] ([idCollection], [title], [targetAmount], [report], [idReceipient], [idEvent]) VALUES (10, N'Рюкзаки військові', 20000.0000, NULL, 2, 7)
SET IDENTITY_INSERT [dbo].[Collection] OFF
GO
SET IDENTITY_INSERT [dbo].[Donat] ON 

INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (1, 500.0000, CAST(N'2025-03-10T12:30:00.000' AS DateTime), 1, 1)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (2, 1000.0000, CAST(N'2025-03-10T14:20:00.000' AS DateTime), 2, 1)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (3, 200.0000, CAST(N'2025-03-11T09:15:00.000' AS DateTime), 3, 2)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (4, 5000.0000, CAST(N'2025-03-11T18:45:00.000' AS DateTime), 5, 3)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (5, 150.0000, CAST(N'2025-03-12T11:00:00.000' AS DateTime), 7, 4)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (6, 300.0000, CAST(N'2025-03-12T15:30:00.000' AS DateTime), 4, 1)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (7, 2000.0000, CAST(N'2025-03-13T10:20:00.000' AS DateTime), 9, 5)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (8, 100.0000, CAST(N'2025-03-13T12:00:00.000' AS DateTime), 10, 2)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (9, 450.0000, CAST(N'2025-03-14T16:40:00.000' AS DateTime), 6, 9)
INSERT [dbo].[Donat] ([idDonat], [sum], [donationDate], [idPerson], [idCollection]) VALUES (10, 800.0000, CAST(N'2025-03-14T20:10:00.000' AS DateTime), 8, 3)
SET IDENTITY_INSERT [dbo].[Donat] OFF
GO
SET IDENTITY_INSERT [dbo].[Event] ON 

INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (1, N'Марафон Добрa', N'Благодійний забіг', CAST(N'2025-05-01T00:00:00.000' AS DateTime), CAST(N'2025-05-02T00:00:00.000' AS DateTime), N'100000', N'Заплановано')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (2, N'Збір на Дрони', N'Закупівля FPV', CAST(N'2025-06-10T00:00:00.000' AS DateTime), CAST(N'2025-07-10T00:00:00.000' AS DateTime), N'500000', N'Активно')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (3, N'Допомога тваринам', N'Корм для притулків', CAST(N'2025-01-15T00:00:00.000' AS DateTime), CAST(N'2025-02-15T00:00:00.000' AS DateTime), N'50000', N'Завершено')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (4, N'Шкільний портфель', N'Підготовка дітей до школи', CAST(N'2025-08-01T00:00:00.000' AS DateTime), CAST(N'2025-08-30T00:00:00.000' AS DateTime), N'80000', N'Заплановано')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (5, N'Різдвяне диво', N'Подарунки сиротам', CAST(N'2024-12-01T00:00:00.000' AS DateTime), CAST(N'2024-12-31T00:00:00.000' AS DateTime), N'120000', N'Завершено')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (6, N'Тактична медицина', N'Аптечки для фронту', CAST(N'2025-03-01T00:00:00.000' AS DateTime), CAST(N'2025-04-01T00:00:00.000' AS DateTime), N'200000', N'Активно')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (7, N'Книги для ЗСУ', N'Бібліотека в окопи', CAST(N'2025-02-20T00:00:00.000' AS DateTime), CAST(N'2025-03-20T00:00:00.000' AS DateTime), N'10000', N'Активно')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (8, N'Чиста річка', N'Прибирання берегів Дніпра', CAST(N'2025-09-10T00:00:00.000' AS DateTime), CAST(N'2025-09-11T00:00:00.000' AS DateTime), N'5000', N'Заплановано')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (9, N'Окуляри нічного бачення', N'Прилади для ТРО', CAST(N'2025-04-15T00:00:00.000' AS DateTime), CAST(N'2025-05-15T00:00:00.000' AS DateTime), N'300000', N'Активно')
INSERT [dbo].[Event] ([IdEvent], [Name], [Description], [StartDate], [EndDate], [Goal], [Status]) VALUES (10, N'Відбудова житла', N'Ремонт після обстрілів', CAST(N'2025-07-01T00:00:00.000' AS DateTime), CAST(N'2025-12-31T00:00:00.000' AS DateTime), N'1000000', N'Активно')
SET IDENTITY_INSERT [dbo].[Event] OFF
GO
SET IDENTITY_INSERT [dbo].[Person] ON 

INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (1, N'Іваненко Іван', N'+38 (067) 111-22-33', N'ivan@email.com', N'Київ, вул. Політехнічна 5')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (2, N'Петренко Петро', N'+38 (050) 222-33-44', N'petro@email.com', N'Львів, вул. Свободи 10')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (3, N'Марія Сидоренко', N'+38 (093) 333-44-55', N'mariya@email.com', N'Одеса, вул. Дерибасівська 1')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (4, N'Олександр Коваль', N'+38 (066) 444-55-66', N'oleks@email.com', N'Харків, вул. Сумська 12')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (5, N'Олена Мельник', N'+38 (067) 555-66-77', N'olena@email.com', N'Дніпро, пр. Яворницького 50')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (6, N'Андрій Бондар', N'+38 (095) 666-77-88', N'bondar@email.com', N'Вінниця, вул. Соборна 22')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (7, N'Наталія Шевченко', N'+38 (063) 777-88-99', N'natasha@email.com', N'Полтава, вул. Миру 4')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (8, N'Сергій Кравченко', N'+38 (099) 888-99-00', N'serg@email.com', N'Запоріжжя, пр. Соборний 101')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (9, N'Тетяна Ткаченко', N'+38 (097) 999-00-11', N'tanya@email.com', N'Чернігів, вул. Київська 8')
INSERT [dbo].[Person] ([idPerson], [fullName], [phone], [email], [address]) VALUES (10, N'Дмитро Мороз', N'+38 (068) 000-11-22', N'dmytro@email.com', N'Івано-Франківськ, вул. Франка 3')
SET IDENTITY_INSERT [dbo].[Person] OFF
GO
SET IDENTITY_INSERT [dbo].[Receipient] ON 

INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (1, N'БФ "Повернись живим"', N'Допомога війську', N'+38 (044) 123-45-67')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (2, N'72-га ОМБр', N'Військова частина', N'+38 (067) 720-00-72')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (3, N'Притулок "Сіріус"', N'Допомога тваринам', N'+38 (093) 555-44-33')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (4, N'Дитячий будинок №5', N'Соціальна допомога', N'+38 (050) 444-55-66')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (5, N'Госпітальєри', N'Медичний батальйон', N'+38 (063) 111-22-33')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (6, N'ГО "Чисте місто"', N'Екологічні ініціативи', N'+38 (044) 999-88-77')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (7, N'Харківський волонтерський центр', N'Гуманітарна допомога', N'+38 (057) 333-22-11')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (8, N'Пласт', N'Скаутська організація', N'+38 (067) 100-20-30')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (9, N'Червоний Хрест', N'Міжнародна допомога', N'+38 (044) 500-50-50')
INSERT [dbo].[Receipient] ([idReceipient], [fullName], [description], [contactInfo]) VALUES (10, N'АЗОВ', N'Спецпідрозділ', N'+38 (067) 430-12-22')
SET IDENTITY_INSERT [dbo].[Receipient] OFF
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [UQ__tmp_ms_x__AB6E6164BAFCCD26]    Script Date: 12.05.2026 20:28:02 ******/
ALTER TABLE [dbo].[Person] ADD UNIQUE NONCLUSTERED 
(
	[email] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Collection]  WITH CHECK ADD FOREIGN KEY([idEvent])
REFERENCES [dbo].[Event] ([IdEvent])
GO
ALTER TABLE [dbo].[Collection]  WITH CHECK ADD FOREIGN KEY([idReceipient])
REFERENCES [dbo].[Receipient] ([idReceipient])
GO
ALTER TABLE [dbo].[Donat]  WITH CHECK ADD FOREIGN KEY([idCollection])
REFERENCES [dbo].[Collection] ([idCollection])
GO
ALTER TABLE [dbo].[Donat]  WITH CHECK ADD FOREIGN KEY([idPerson])
REFERENCES [dbo].[Person] ([idPerson])
GO
USE [master]
GO
ALTER DATABASE [Charity] SET  READ_WRITE 
GO
