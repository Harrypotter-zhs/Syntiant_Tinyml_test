## Funpack第二季第一期：Syntiant TinyML Board活动


**活动主页：https://www.eetree.cn/page/digikey-funpack**

有幸参加硬禾学堂和得捷电子举办的这一期的活动，了解深度学习相关的知识和arduino的使用

## 0、开发板介绍-**Syntiant TinyML Board**



![FujSQTmhWsvAm4RLNF4C6EjvyJlo](./document/picrture/FujSQTmhWsvAm4RLNF4C6EjvyJlo.png)

​	配备超低功耗 Syntiant ® NDP101神经决策处理器™，可以使语音和传感器应用程序分别在 140 和 100 微瓦以下运行，与基于 MCU 的传统 MCU 相比，吞吐量提高 20 倍，系统效率提高 200 倍。Syntiant TinyML 板的尺寸为 24 毫米 x 28 毫米，是一个小型的独立系统，通过微型 USB 连接通过 Edge Impulse 轻松下载经过训练的模型，而无需任何专用硬件。

主要特点：

-   神经决策处理器使用NDP101，连接了两个传感器

    -   BMI160 6轴运动传感器
    -   SPH0641LM4H麦克风

-   主机处理器：

    SAMD21 Cortex-M0+ 32位低功耗48MHz ARM MCU

    -   内置256KB FLASH和32KB SRAM，
    -   5个数字I/O，与Arduino MKR系列板兼容
    -   其中包含1路UART接口和1路I2C接口（包括在数字I/O引脚中）
    -   2MB板载串行闪存
    -   一个用户定义的RGB LED
    -   uSD卡插槽

-   电路板可使用5V micro-USB或3.7V LiPo电池供电

![FvWjGKYbLxTJR_dfHz8-yvvsuRZF](document/picrture/FvWjGKYbLxTJR_dfHz8-yvvsuRZF)

## 1、环境准备

我的编译环境是win10专业版，

我的编译软件：arduino 1.18.19，arduino-cli 0.20.2，串口调试助手-Tera Term和野火串口调试助手

### 1.1、安装arduino编译软件

这个可以参考arduino中文社区安装和配置环境即可

参考资料：

[Arduino IDE下载（2月21日更新到1.8.19）-Arduino中文社区 - Powered by Discuz!](https://www.arduino.cn/thread-5838-1-1.html)

[Arduino教程汇总贴（2020.2.2更新）-Arduino中文社区 - Powered by Discuz!](https://www.arduino.cn/thread-1066-1-1.html)

### 1.2、安装arduino-cli

从github下载自己选择的版本下载即可,我们需要把它解压到一个目录，如E:\Program Files (x86)\arduino\arduino-cli目录下，解压后的截图如下所示。然后，我们需要在“系统变量”中添加这个路径，如下图所示

解压出arduino-cli文件夹，随后打开控制面板->高级系统设置->环境变量->点击系统变量的path，添加刚才安装的arduino-cli的路径即可，随后可以使用cmd命令测试，输入arduino-cli version 查看是否安装成功

![image-20220601004717161](document/picrture/image-20220601004717161.png)

![image-20220601004824954](document/picrture/image-20220601004824954.png)

![image-20220601005053188](document/picrture/image-20220601005053188.png)

```c
C:\Users\Administrator>arduino-cli version
arduino-cli  Version: 0.20.2 Commit: 13783819 Date: 2021-12-09T13:32:05Z


A new release of Arduino CLI is available: 0.20.2 → 0.22.0
https://arduino.github.io/arduino-cli/latest/installation/#latest-packages
```

参考资料：

[安装 - Arduino CLI](https://arduino.github.io/arduino-cli/0.22/installation/)

[基于最新理念TinyML – B0板子下载官方go-stop模型软件（第2讲) - 哔哩哔哩 (bilibili.com)](https://www.bilibili.com/read/cv13301956?spm_id_from=333.999.0.0)

[arduino-cli版本下载Releases · arduino/arduino-cli (github.com)](https://github.com/arduino/arduino-cli/releases)

1.3 安装串口驱动-安装arduino-IDE的时候就可以参考一下怎么安装

[Arduino教程汇总贴（2020.2.2更新）-Arduino中文社区 - Powered by Discuz!](https://www.arduino.cn/thread-1066-1-1.html)

1.4、连接开发板进行测试看是否正常

输入：arduino-cli board list

```c
C:\Users\Administrator>arduino-cli board list
Port  Protocol Type              Board Name      FQBN                 Core
COM25 serial   Serial Port (USB) Arduino MKRZERO arduino:samd:mkrzero arduino:samd
```



## 2、学习使用edge-impulse平台

先跟着官方文档走一遍-基于syntiant开发板的语音识别教程

**一定要先看参考教程**：

[Syntiant 微型 ML 板 - 边缘脉冲文档 (edgeimpulse.com)](https://docs.edgeimpulse.com/docs/development-platforms/officially-supported-mcu-targets/syntiant-tinyml-board)   可使用谷歌翻译翻译网页

[基于最新理念TinyML – 生成官方go-stop模型软件 - 哔哩哔哩 (bilibili.com)](https://www.bilibili.com/read/cv13357192?spm_id_from=333.999.0.0)   B站中文教程

 

## 3、训练自己的语音识别模型

**新建工程选择对应的开发板syntiant开发板，按照参考语音识别教程的采集数据、设置参数和生成模型。**

### 注意事项：

### 3.1、连续说几个关键词的方案选择，此处参考硬禾学堂的教学直播视频给的建议选取的关键词

​	3.1.1、一口气说完关键词。建议四个字的关键字短语：关键词选择 开启绿灯、开启红灯、蓝灯点亮、关闭指示灯。

​	3.1.2、关键词分开说，先说”siri“，给个标志位打开-flag_siri=1，随后再说”开灯“这个关键词同时对应标志位open_led=1，在flag_siri = 1的情况下开灯，如果否则为关灯。如表格所示

| flag_siri | open_led | 识别结果 |
| --------- | -------- | -------- |
| 0         | 0        | 保持     |
| 0         | 1        | 保持     |
| 1         | 0        | 保持     |
| 1         | 1        | 开灯     |

关键词方案选择1.1。

### 3.2、采集数据，我使用的是手机的方式进行数据采集

​	点击show QR code 之后会出现二维码，使用手机或者平板都可以扫码登陆授权使用麦克风。设计标签之后，同时采集的**语音数据长度为10s**，label：标签自定义，类别选择：Split automaticlly(80/20)，含义是采集的语音数据软件自动帮你分配，80%的语音集为training，20%的语音集用于testing。

![image-20220530122346454](document/picrture/image-20220530122346454-165388462780813.png)

![image-20220530121935299](document/picrture/image-20220530121935299-165388437662112.png)

采集之后的语音数据可自行分割选取合适的语音数据

参考教程：[响应您的声音 - Syntiant - RC 命令 - 边缘脉冲文档 (edgeimpulse.com)](https://docs.edgeimpulse.com/docs/tutorials/hardware-specific-tutorials/responding-to-your-voice-syntiant-rc-commands-go-stop)

![image-20220530122723158](document/picrture/image-20220530122723158-165388484435414.png)

可按照参考教程给出的数据集拆分的方式进行对数据处理。

### 3.2、将训练的模型导出并且使用falsh的形式下载开发板之后进行测试

#### 	3.2.1、运行自己训练的edge-impulse项目模型在开发板里面

一定要先看参考文档：[On your Syntiant TinyML Board - Edge Impulse Documentation](https://docs.edgeimpulse.com/docs/deployment/running-your-impulse-locally/on-your-syntiant-tinyml-board)

默认已经可以生成构件固件-Syntiant TinyML的固件文件-点击绿色按键”build“一定要看configure posterior parameters这个选项的Find posterior parameters是否已经训练

<img src="document/picrture/image-20220530115857787.png" alt="image-20220530115857787" style="zoom: 67%;" />

<img src="document/picrture/image-20220530134351248.png" alt="image-20220530134351248" style="zoom: 67%;" />

随后点击生成-Build，如图所以

![image-20220530115956024](document/picrture/image-20220530115956024-165388319724411.png)

下载生成的模型之后点击运行falsh_windows.bat文件即可（默认已经安装arduino-cli）

![image-20220530135413207](document/picrture/image-20220530135413207-165389005459416.png)

**实验结果-使用野火串口调试助手-波特率115200**

```c
Predictions:
    close_led: 	0
    open_blue: 	1
    open_green: 	0
    open_red: 	0
    z_openset: 	0

Predictions:
    close_led: 	0
    open_blue: 	0
    open_green: 	0
    open_red: 	0
    z_openset: 	1

Predictions:
    close_led: 	0
    open_blue: 	1
    open_green: 	0
    open_red: 	0
    z_openset: 	0

Predictions:
    close_led: 	1
    open_blue: 	0
    open_green: 	0
    open_red: 	0
    z_openset: 	0

Predictions:
    close_led: 	0
    open_blue: 	0
    open_green: 	0
    open_red: 	0
    z_openset: 	1

Predictions:
    close_led: 	0
    open_blue: 	0
    open_green: 	0
    open_red: 	1
    z_openset: 	0

Predictions:
    close_led: 	0
    open_blue: 	0
    open_green: 	0
    open_red: 	0
    z_openset: 	1
```

#### 3.2.2、以下步骤是为了生成Syntiant NDP101 library库之后自动下载一个文件：projectname-syntiant-ndp101-lib-vx的文件，可用于自定义的功能实现

![image-20220527165301995](document/picrture/image-20220527165301995.png)

生成的projectname-syntiant-ndp101-lib-vx包含一个模型参数文件夹和两个文件

模型参数文件夹：model-parameters，此文件夹包含三个文件：dsp_blocks.h 和 model_metadata.h

![image-20220527165714366](document/picrture/image-20220527165714366.png)

两个文件：ei_model.bin 和 ei_model.synpkg。

![image-20220527165826551](document/picrture/image-20220527165826551.png)

生成的lib库使用方法：

将model-parameters文件夹的内容替换已经构建arduino工程:

firmware-syntiant-tinyml工程的src文件下的model-parameters需要将sp_blocks.h model_metadata.h和model_variables.h文件放入自定义固件构建目录的src/model-parameters 文件夹中）

![image-20220530110215809-16538804746653](document/picrture/image-20220530110215809-16538804746653.png)

但是也要注意**有可能需要**修改firmware-syntiant-tinyml工程的src文件下model_variables.h这个头文件。

```c++
//这个是我的edge-impulse工程生成的lib库文件中的model_variables.h文件
#ifndef _EI_CLASSIFIER_MODEL_VARIABLES_H_
#define _EI_CLASSIFIER_MODEL_VARIABLES_H_

#include <stdint.h>
#include "model_metadata.h"

//此语句对照平常的模型训练生成的库文件是没有的，不注释编译的会会报错，没安装edge-impulse-sdk这个软件包
//#include "edge-impulse-sdk/classifier/ei_model_types.h"  
//主要是看这个label是否已经改变和参数使用已经改变
const char* ei_classifier_inferencing_categories[] = { "close_led", "open_blue", "open_green", "open_red", "z_openset" };

uint8_t ei_dsp_config_9_axes[] = { 0 };
const uint32_t ei_dsp_config_9_axes_size = 1;
ei_dsp_config_audio_syntiant_t ei_dsp_config_9 = {
    1,
    1,
    0.032f,
    0.024f,
    40,
    512,
    0,
    0,
    0.96875f
};

// 同样对应的注释掉下面的语句-
//const ei_model_performance_calibration_t ei_calibration = {
//   1, /* integer version number */
//    (int32_t)(EI_CLASSIFIER_RAW_SAMPLE_COUNT / ((EI_CLASSIFIER_FREQUENCY > 0) ? EI_CLASSIFIER_FREQUENCY : 1)) * 1000, /* Model window */
//    0.8f, /* Default threshold */
//    (int32_t)(EI_CLASSIFIER_RAW_SAMPLE_COUNT / ((EI_CLASSIFIER_FREQUENCY > 0) ? EI_CLASSIFIER_FREQUENCY : 1)) * 500, /* Half of model window */
//    0   /* Don't use flags */
//};

#endif // _EI_CLASSIFIER_MODEL_METADATA_H_
```

### 3.3、自定义修改的代码部分

我使用的是vscode编辑和查看的源码，使用arduino编译和上传到开发板-**建议看看源码**，有很大修改的空间。完成3.2.2步骤之后即可开始自定义功能使用

我的修改如下

#### 3.3.1、修改firmware-syntiant-tinyml.ino文件

```c++

void on_classification_changed(const char *event, float confidence, float anomaly_score) 
{
    static int8_t count = 0;
    // here you can write application code, e.g. to toggle LEDs based on keywords
    //您可以在此处编写应用程序代码，例如根据关键字切换LED
    if (strcmp(event, "open_blue") == 0) 
    { 
        if (count != 1)   // 如果此时LED灯不是蓝灯亮起。关闭所有LED灯之后重新打开蓝色LED灯
        {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BLUE, LOW);
        }
        digitalWrite(LED_BLUE, HIGH);
        count = 1;
        Serial.println("open_green:open blue led");
    }
    else if (strcmp(event, "open_green") == 0)  //字符串查找是否存在open_green关键词
    {
        if (count != 2)// 如果此时LED灯不是绿亮起。关闭所有LED灯之后重新打开绿色LED灯
        {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BLUE, LOW);
        }
        digitalWrite(LED_GREEN, HIGH);   //打开绿灯
        count = 2;						//标志位-LED灯红、绿、蓝色的选择
        Serial.println("led status:open green led");//串口输出LED灯指示灯状态
    }
    else if (strcmp(event, "open_red") == 0)
    {
        if (count != 3)
        {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BLUE, LOW);
        }
        digitalWrite(LED_RED, HIGH);
        count = 3;
        Serial.println("led status:open red led");
    }
    else if (strcmp(event, "close_led") == 0)
    { 
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_GREEN, LOW);
          digitalWrite(LED_BLUE, LOW);
          count = 4;
          Serial.println("led status:close all led!");
    }
}

void setup(void)
{
    syntiant_setup();  //syntiant硬件和软件初始化函数
}

void loop(void)
{
    syntiant_loop(); //syntiant的软件功能实现，自定义可在该函数里面实现
}
```

随后可以将自己的项目的模型通过arduino编译上传到开发板里面了。如图所示

![image-20220530115033358](document/picrture/image-20220530115033358-16538826355288.png)

![image-20220530115225637](document/picrture/image-20220530115225637-16538827468879.png)

#### 3.3.2、同时也可以使用flash下载

将编译完成之后的自定义的文件使用CMD命令行下载到到开发板里面

**参考教程**：https://docs.edgeimpulse.com/docs/deployment/running-your-impulse-locally/on-your-syntiant-tinyml-board  下载运行自己训练的模型

​	1、自定义代码后，获取Arduino输出的.bin文件并将其重命名为 firmware.ino.bin，arduino生成的.bin文件在C:\Users\Administrator\AppData\Local\Temp\arduino_build_xxxx，如图所示

![image-20220530112758956](document/picrture/image-20220530112758956-16538812806375.png)

​	2、将firmware-syntiant-tinyml.ino.bin文件复制一份并且修改成firmware.ino.bin，放入之前生成的模型训练的syntiant的固件包中，使用flash方式下载到开发板中，如图所示

![image-20220530113236139](document/picrture/image-20220530113236139-16538815576316.png)

这个firmware.ino.bin是重新命名的。可以点击flash_windows.bat进行下载固件。

![image-20220530113448237](document/picrture/image-20220530113448237-16538816894527.png)

串口输出的实验结果-与arduino-IDE 直接 编译上传一样的效果！

```c
setup done
Loaded configuration
Inferencing settings:
	Interval: 0.0625 ms.
	Frame size: 15488
	Sample length: 968 ms.
	No. of classes: 5
Starting inferencing, press 'b' to break

Predictions:
    close_led: 	0				//识别此标签的语音之后match=1
    open_blue: 	0				//识别此标签的语音之后match=2
    open_green: 	0			//识别此标签的语音之后match=3
    open_red: 	0				//识别此标签的语音之后match=4
    z_openset: 	1				//识别此标签的语音之后match=5
match:5							//显示当前识别的关键词序号
Battery = 98%    				//显示电池电量
author: zhs!					//自定义的信息

Predictions:
    close_led: 	0
    open_blue: 	0
    open_green: 	1
    open_red: 	0
    z_openset: 	0
led status:open green led
match:3							//代表当前识别的语音关键词是是“开启绿灯” 标签为open_green
Battery = 99%
author: zhs!

Predictions:
    close_led: 	1
    open_blue: 	0
    open_green: 	0
    open_red: 	0
    z_openset: 	0
led status:close all led!
match:1
Battery = 98%
author: zhs!

Predictions:
    close_led: 	0
    open_blue: 	0
    open_green: 	0
    open_red: 	0
    z_openset: 	1
match:5
Battery = 98%
author: zhs!
```

## 4、问题总结

参考文档：语音识别搭建环境记录中的所遇到的问题

## 5、参考资料

参考文档：参考资料的链接地址
