# FurNature

### 1.Introduction

#### Overview

This is a furniture selection & preview VR WebApp, which can be accessed from both Android and iOS:
- Five components in this application: User, Furniture, Selection ("Shopping Cart"), Environment (Original Picture), Home Model;
- Using thread pool to support concurrent multiple user accessing;
- Using ASP.NET、ADO.NET to complete the processing of the basic page.

Techs applied:
- .NET (.NET + IIS + SQL Server)
- WebAPI
- SQL Server
- Entity Framework
- LINQ

#### Usage

- Step1: Access ip:2494/ via browser
- Step2: Click "Save to Home"
- Step3: Login (you can register by email when first time logon)
- Step4: Take a picture then upload
- Step5: Manually select the corners of the wall and the indoor model will be generated automatically
- Step6: Roam in the house, select furniture, and preview
- Step7: Click OK if you like the furniture, and then it will be added to the shopping cart
- Step8: You can review and modify all the selected furnitures anytime

### 2. Deployment

#### HOW TO: Install

Please backup before modifying system config. For IIS >= 7.0:
 
```
%windir%\system32\inetsrv\appcmd add backup "PreMsDeploy"
```

- Run.exe (win+r) then input `inetmgr` to open IIS Manager.
- In the IIS Manager, expand the "Server" node and then the "Site" node, select "Default Website".
- In "Actions" on the right, click the "Import Application..." to start packaging guide.
- Select \Deploy\FurNature.zip
- Now you can view application and database in the pop-up.
- In tab “parameter”，enter a name for the app, and the SQL connection string.
- Clike "Next" to install.

#### HOW TO: Startup Server

```
csc @StartUp.rsp StartUp.cs
[Admin] cd E:\study\homework\dotNET\final\FurNature\Assembly\StartUp
[Admin] sn -k myStartUpKey.snk

[assembly:AssemblyKeyFileAttribute(@"E:\study\homework\dotNET\final\FurNature\Assembly\StartUp\myStartUpKey.snk")]

[Admin] gacutil -I StartUp.dll

sn -tp StartUp.dll
// Execute reference
Assembly.Load("StartUp,Version=1.0.0.1,Culture=neutral,PublicKeyToken={PublicKey}");
```

#### Database: SQL Sever (under \App_Data)

- user
`id, name, pwd`

- furniture
`id, name, type, img, price, purchase_url, introduction, path`

- user_furniture
`user_id, fur_id`

- model
`id, user_id, name, img_top, img_bottom, img_left, img_right, img_back`

- photo
`id, user_id, model_id, x1, y1, x2, y2, path`


### 3.Program

#### Code Tree

- /FurNature: The core of application, using MVC arch

- /Assembly:
    - Shared assembly: **StartUp**
    - C++ assembly: **GenerateModel**, setting up 3d model via OpenCV
    - Win32 dll: **Add**
    - COM: **MathCom**

#### IDE

- Visual Studio 2015

- x86 / AnyCPU

#### Slides

- Presentation.pptx
