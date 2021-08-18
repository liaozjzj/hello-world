## 绿小萝助手评分

scored by  廖子健，丁思宇




---

项目为硬件自选题目，整体功能为：根据湿度和照明和时间等因素实现自动灌溉、补光，项目基准分400

总体实现较为完整，能够读取环境温度、土壤湿度和环境光强，并结合时间因素，根据条件做出动作，完成度100%

使用了oled显示屏进行完整的信息指示，完成度增加10%

考虑到了水箱水位的因素，有完整的水位预警措施，但作为实际产品来讲，能增加更易发现的警报声音最好。完成度增加25%

照明设备使用了光立方，并用锁存器芯片辅助控制，这一独立单元也具有较高完成度，增加30%

代码清晰、逻辑分明，可读性高，增加5%

整体功能完善，如果能够进一步做好包装，并结合更科学的补水补光条件/措施，能成为一件不错的家用小产品。

评分=400x170% = 680

---

该项目使用了Arduino开发板和多种硬件模块，实现了一个较为自动化的绿萝浇水、补光系统，基准分400分。

使用了土壤湿度传感器、水泵、温湿度传感器、光敏电阻实现了在不同条件下为植物自动浇水，同时也可以手动；同时组合使用了多种硬件模块，并在调试过程中不断尝试解决bug，系统整体能有效运行，完成度80%；

OLED屏显示土壤湿度，环境温度和光照，完成度增加10%；

使用超声测距，剩余水量不足时会停止浇水并触发提示，完成度增加15%；

手工制作光立方，实现了有一定规律的光补偿，完成度增加20%；

由单独电源为水泵供电，并由继电器控制，避免了用Arduino为水泵供电导致板子烧掉的风险，设置较为合理，完成度增加10%；

主动阅读相关头文件，了解原理并作合理修正，使得测量更正确，完成度增加20%；

按键防抖，完成度增加5%；

建议：光补偿采用24小时周期性地光补偿实际上不是很合理，可以考虑利用光敏电阻，为避免补光的影响可以将补光部分与光敏电阻分开或短暂关闭补光测量环境光强；

评分400*160%=640

---

平均分：660