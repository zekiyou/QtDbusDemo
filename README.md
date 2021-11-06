Qt疫情软件分成Server和Client通过dbus数据总线通信
该Demo用以熟悉Qt插件机制，dbus 和 gsetting

Clinet部分利用正则表达式检测输入，通过Server注册的Dbus服务发送疫情数据给Server，Server判断是否通行

![image](https://user-images.githubusercontent.com/30315297/140595143-25433a9e-cc8e-4e8f-b867-8fa48af95cf4.png)
![image](https://user-images.githubusercontent.com/30315297/140595273-a1ea538d-fb8f-44e1-b020-9ead9d155791.png)

