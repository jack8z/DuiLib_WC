## 说明
- 自己用的duilib，在原版的基础上进行完善优化
- 默认编译为静态链接库

## 编译
- 使用cmake 3.11，在windows10上VS2017环境下，编译通过

#### 使用NMake编译(VS2017)
```BASH
cmake .. -G"NMake Makefiles"
```
或者：
```BASH
cmake .. -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release
```

然后运行以下命令：
```BASH
nmake
```

#### 使用VS2017编译
```BASH
cmake .. -G"Visual Studio 15 2017"
```

然后运行以下命令：
```BASH
msbuild.exe DemoDuiLib.sln /t:Rebuild /p:Configuration=Release
```
