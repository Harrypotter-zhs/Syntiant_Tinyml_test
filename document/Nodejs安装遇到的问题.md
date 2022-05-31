## NodeJS安装遇到的问题

#### 1、NodeJs安装教程

参考教程

[1]: https://blog.csdn.net/wangpaiblog/article/details/113666666	"Node.js 下载安装教程"
[2]: https://blog.csdn.net/qq_51929833/article/details/123694846	"十分钟掌握Nodejs下载和安装"
[3]: http://t.csdn.cn/NxhoS	"NodeJS安装及环境配置（windows）"

这两个均可以实现，但是对于Edge-impulse这个来时需要勾选 Tools for Native Modules，这个安装页面。第三个可以看看怎配置环境变量!

最后的测试安装软件一定要用管理员身份运行CMD

#### 2、node.js更换镜像源

```
安装  npm install -g nrm
```

```
使用 nrm ls 查看源列表
```

```
然后选择源 nrm use taobao 
```

参考教程

[1]: https://blog.csdn.net/m0_60028455/article/details/122728435	"https://blog.csdn.net/m0_60028455/article/details/122728435"
[2]: http://t.zoukankan.com/netyts-p-14106759.html	"node.js更换镜像源"

#### 3、**win10-nodejs安装&配置&错误解决**

参考教程

[1]: https://blog.csdn.net/Dreammin/article/details/124068048	"win10-nodejs安装&amp;配置&amp;错误解决"

安装之后使用管理员模式运行CMD命令行

```
输入命令进行测试
npm install express -g
```

#### 4、安装edge-impulse-cli的时候一直显示报错gyp ERR! find VS的解决办法

参考教程：

[gyp ERR! find VS的解决办法_吹口琴的喵的博客-CSDN博客](https://blog.csdn.net/qq_36404808/article/details/118384614)

http://t.csdn.cn/4YHfg

在管理员模式下运行CMD命令行输入

```
npm install -g edge-impulse-cli --force
```

 的时候，最后一直在出错，全部都是gyp ERR：

```
gyp ERR! find VS
gyp ERR! find VS msvs_version not set from command line or npm config
gyp ERR! find VS running in VS Command Prompt, installation path is:
gyp ERR! find VS "C:\Program Files (x86)\Microsoft Visual Studio\2017"
gyp ERR! find VS - will only use this version
gyp ERR! find VS could not use PowerShell to find Visual Studio 2017 or newer
gyp ERR! find VS looking for Visual Studio 2015
gyp ERR! find VS - not found
gyp ERR! find VS looking for Visual Studio 2013
gyp ERR! find VS - not found
gyp ERR! find VS
gyp ERR! find VS **************************************************************
gyp ERR! find VS You need to install the latest version of Visual Studio
gyp ERR! find VS including the "Desktop development with C++" workload.
gyp ERR! find VS For more information consult the documentation at:
gyp ERR! find VS https://Github.com/nodejs/node-gyp#on-windows
gyp ERR! find VS **************************************************************
gyp ERR! find VS
gyp ERR! configure error
gyp ERR! stack Error: Could not find any Visual Studio installation to use
gyp ERR! stack     at VisualStudioFinder.fail (D:\rymcu\electron-serialport\node_modules\node-gyp\lib\find-visualstu
dio.js:121:47)
gyp ERR! stack     at D:\rymcu\electron-serialport\node_modules\node-gyp\lib\find-visualstudio.js:74:16
gyp ERR! stack     at D:\rymcu\electron-serialport\node_modules\node-gyp\lib\find-visualstudio.js:372:16
gyp ERR! stack     at D:\rymcu\electron-serialport\node_modules\node-gyp\lib\util.js:54:7
gyp ERR! stack     at D:\rymcu\electron-serialport\node_modules\node-gyp\lib\util.js:33:16
gyp ERR! stack     at ChildProcess.exithandler (child_process.js:310:5)
gyp ERR! stack     at ChildProcess.emit (events.js:315:20)
gyp ERR! stack     at maybeClose (internal/child_process.js:1021:16)
gyp ERR! stack     at Process.ChildProcess._handle.onexit (internal/child_process.js:286:5)
gyp ERR! System Windows_NT 10.0.15063
gyp ERR! command "C:\\Program Files\\nodejs\\node.exe" "D:\\rymcu\\electron-serialport\\node_modules\\node-gyp\\bin
\node-gyp.js" "rebuild" "--target=7.3.2" "--arch=x64" "--dist-url=https://atom.io/download/electron"
gyp ERR! cwd D:\rymcu\electron-serialport\node_modules\@serialport\bindings
gyp ERR! node -v v12.18.2
gyp ERR! node-gyp -v v7.0.0
gyp ERR! not ok

```

解决办法:

1、下载安装visual studio

```

including the \"Desktop development with C++\" workload

注意安装时勾选包含c++的桌面开发选项！！！！
```

2、先修改源，使用官方给的源

```
C:\Windows\system32>nrm ls

  npm ---------- https://registry.npmjs.org/
  yarn --------- https://registry.yarnpkg.com/
  tencent ------ https://mirrors.cloud.tencent.com/npm/
  cnpm --------- https://r.cnpmjs.org/
  taobao ------- https://registry.npmmirror.com/
  npmMirror ---- https://skimdb.npmjs.com/registry/

C:\Windows\system32> nrm use npm
	
   Registry has been set to: https://registry.npmjs.org/

```

当然也可以不修改直接下载visual studio

安装visual studio的教程如下

1、[Visual Studio安装教程-超详细_装作不在意的博客-CSDN博客_visualstudio安装教程](https://blog.csdn.net/bxy0806/article/details/121439332)

2、[Visual Studio安装教程_a只如初见的博客-CSDN博客_visualstudio安装](https://blog.csdn.net/weixin_44788542/article/details/114271126)

注意事项

1、选择coummunity 版本进行下载安装

