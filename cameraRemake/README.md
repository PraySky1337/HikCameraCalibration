### 海康相机标定模块

###### *Ubuntu22.04*

如果连接了海康相机，程序开始后 Shift + s 保存要标定的图片，然后摁esc退出相机取流模式，图片会保存在程序的上一级目录的picture文件夹中。

如果没有连接海康相机模块，有先前的相机标定的素材图片，放入picture文件夹中，直接打开程序，即可输出结果，*以像素误差为参考*，*0.3 - 0.4 像素的误差即标定成功*。

需要位于/opt/MVS/路径下的海康sdk，如果未安装海康sdk或海康相机sdk未位于opt/MVS，请前往海康相机官网进行sdk下载或更新cmake配置

依赖如下

```bash
sudo apt update
sudo apt install cmake
sudo apt install -y libopencv-dev
```

@author AT PraySky

@latest update 2024.12.14

