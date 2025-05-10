# README

### OLED显示图像

实现在OLED上显示一个竖中指的自嘲熊。

<img src="C:\Users\23249\AppData\Roaming\Typora\typora-user-images\image-20250510214328262.png" alt="image-20250510214328262" style="zoom:50%;" />

## OLED显示动图

尝试创建三帧画面，循环播放，形成竖中指的动画。像这样：

![image-20250510214602127](C:\Users\23249\AppData\Roaming\Typora\typora-user-images\image-20250510214602127.png)

刚开始一直不成功。始终如此显示，没有动画：

<img src="C:\Users\23249\AppData\Roaming\Typora\typora-user-images\image-20250510214732043.png" alt="image-20250510214732043" style="zoom:33%;" />

来时路：

- 以为在修改三张图片时线条不够粗，黑白的阈值不够高。

  - 补救方案：在`[image2cpp](https://javl.github.io/image2cpp/)`上修改图片参数的代码。修改 `setup()` 分别单独显示bear123，确认它们在OLED上看起来是什么样子，确认它们之间有明显的不同。任然不能解决问题。

- 以为三帧图片间隔时间太短，来不及反应。补救方案：间隔改成5s，任然不能解决问题（后来证明不是这个的问题）。在main.cpp中设置`Serial.println("Loop: Drawing bear1 (from loop)");`等串口检测函数检测。

- 考虑到如果在绘制新图像之前没有清除屏幕，新的图像会叠加在旧的图像之上。在 `loop()` 函数中，每次调用 `OLED.drawBitmap()` 之前，都调用一次 `OLED.clearDisplay()`。成功！！！

  

  ### 恭喜自嘲熊稳健地竖起中指！

  但是有一个问题，三帧图像线条粗细有所不同。应该是[image2cpp](https://javl.github.io/image2cpp/)网站不精准的问题。如果要设置连续性好的动画，应参考  [OLED屏实现GIF动画展示教程-CSDN博客](https://blog.csdn.net/moshanghuaw/article/details/113933190?ops_request_misc=%7B%22request%5Fid%22%3A%2280c750ec245f1bdb688c1779c7c8f676%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=80c750ec245f1bdb688c1779c7c8f676&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-4-113933190-null-null.142^v102^pc_search_result_base5&utm_term=OLED显示动画&spm=1018.2226.3001.4187)  的内容，使用针对动图的网站。

  