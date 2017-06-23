# FurNature

### 1.简介

#### 简要说明

    该项目是基于虚实融合的家具选择系统, 为WebApp项目, 可在Android和Apple的浏览器中打开并保存为App.

#### 使用说明

- Step1: 通过手机访问ip:2494/
- Step2: 点击 保存到主界面
- Step3: 使用邮箱注册后登陆
- Step4: 拍摄照片并上传
- Step5: 选择墙角点, 确定, 生成室内模型
- Step6: 在房屋内漫游, 选择家具, 添加后查看效果
- Step7: 点击确定, 家具添加到待购列表
- Step8: 可在待购列表中查看选择的家具

### 2.组员

- 1452712 王家慧

### 3.部署

#### 安装说明

- 在更改系统之前，请务必进行备份。 运行以下命令来备份IIS 7.0或更高版本的服务器

```
%windir%\system32\inetsrv\appcmd add backup "PreMsDeploy"
```

- 通过单击开始>运行并键入inetmgr打开IIS管理器。
- 在IIS管理器中，展开“服务器”节点和“站点”节点，然后选择“默认网站”。
- 在右侧的“操作”窗格中，单击“导入应用程序...”链接以启动打包向导。
- 选择Deploy文件夹下的FurNature.zip包。
- 在“安装应用程序包”对话框中，可以看到应用程序和数据库。
- 在“参数”页面上，输入新的应用程序名称，并输入SQL连接字符串。
- 单击下一步安装软件包

#### 数据库: SQL Sever (位于App_Data)

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


### 4.工程

#### 代码

- 主体程序在/FurNature文件夹下, 为MVC架构

- /Assembly中包含:
    - 共享程序集: **StartUp**
    - C++程序集: **GenerateModel**
    - Win32 dll: **Add**
    - COM组件: **MathCom**

#### IDE

- Visual Studio 2015

- x86 / AnyCPU

### 5.答辩

- ppt: Presentation.pptx

### 6.自查

- 系统至少有五个程序集，需要系统进行模块划分
~~用户模块, 家具模块, 用户选择家具(类似购物车)模块, 用户的平面照片模块, 家居模型模块~~

- 需要其中一个是共享程序集
~~网站启动~~

```
csc @StartUp.rsp StartUp.cs
[Admin] cd E:\study\homework\dotNET\final\FurNature\Assembly\StartUp
[Admin] sn -k myStartUpKey.snk

[assembly:AssemblyKeyFileAttribute(@"E:\study\homework\dotNET\final\FurNature\Assembly\StartUp\myStartUpKey.snk")]

[Admin] gacutil -I StartUp.dll

sn -tp StartUp.dll
// 运行引用
Assembly.Load("StartUp,Version=1.0.0.1,Culture=neutral,PublicKeyToken={PublicKey}");
```

- 采用C++/CLI 实现一个程序集，给C#使用
~~家居建模~~
```
OpenCV: VC++目录, 与环境变量INCLUDE对应
_CRT_SECURE_NO_WARNINGS: C/C++预处理器
```

- 使用C++实现一部分功能，输出成一个Win32 DLL，采用多种方式(PInvoke: __stdcall / 互操作)调用其中的函数
~~各数据类型(包括string!!!)的与/连接/加函数 => 获取模型路径~~

- 实现一个简易的COM组件，然后进行使用
~~数学计算~~
```
Any CPU & x86
```

- 要求使用多线程技术和线程池技术
~~多用户访问~~

- 利用ASP.NET、ADO.NET完成基本页面的处理
DONE

- 最好能够利用.NET其他技术(.NET + IIS + SQL Server)进行实践
WebAPI
SQL Server
Entity Framework
LINQ