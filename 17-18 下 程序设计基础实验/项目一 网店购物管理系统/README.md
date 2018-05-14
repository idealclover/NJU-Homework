# 网点购物管理系统

-----

## 实现功能

### 管理员功能

*   管理员登录、注销

*   商品系统信息查询

*   商品增加、修改、删除

*   售出清单查看

### 用户功能

*   登录、注册、注销
*   查看商品
*   商品搜索
*   查看购物车、添加商品至购物车、删除购物车商品
*   结账，完成购物

## 程序架构

### Model

*   User：负责用户信息的存储，更改
*   Item：负责商品信息的存储，更改
*   Bill：负责交易信息的存储，更改

### Presenter

*   CartCtrl：购物车控制器，负责对购物车信息的控制
*   ItemCtrl：商品控制器，负责对商品信息的控制
*   UserCtrl：用户控制器，负责对用户信息的控制
*   FileCtrl：文件控制器，负责文件的读写

### View

*   v1.0：命令行视图
*   v2.0：基于Qt的GUI


## 程序展示

### 用户视图

![additemnum](Pics\logindialog.png)

![additemnum](Pics\userhasbenused.png)

![additemnum](Pics\cantregisteradmin.png)

![additemnum](Pics\usermainwindow.png)

![additemnum](Pics\addtocart.png)

![additemnum](Pics\cart.png)

### 管理员视图

![additemnum](Pics\adminmainwindow.png)

![additemnum](Pics\additemnum.png)

![additemnum](Pics\logindialog.png)

![additemnum](Pics\list.png)