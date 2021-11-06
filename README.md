Qt疫情软件分成Server和Client通过dbus数据总线通信
该Demo用以熟悉Qt插件机制，dbus 和 gsetting

Clinet部分利用正则表达式检测输入，通过Server注册的Dbus服务发送疫情数据给Server，Server判断是否通信

![image](https://user-images.githubusercontent.com/30315297/140595143-25433a9e-cc8e-4e8f-b867-8fa48af95cf4.png)
![image](https://user-images.githubusercontent.com/30315297/140595218-f55d35a0-199d-40e3-b8ad-5c2544c2593e.png)

