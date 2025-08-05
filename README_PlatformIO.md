# STM32H723 PlatformIO Project

这是一个从STM32CubeMX生成的项目转换为PlatformIO的配置。

## 硬件信息
- 微控制器: STM32H723VGT6
- 内核: ARM Cortex-M7
- Flash: 1024KB
- RAM: 560KB
- FPU: 双精度浮点单元

## 项目结构
```
├── Core/
│   ├── Inc/          # 头文件
│   └── Src/          # 源文件
├── Drivers/          # STM32 HAL驱动
├── platformio.ini    # PlatformIO配置文件
├── STM32H723XG_FLASH.ld  # 链接脚本
└── startup_stm32h723xx.s  # 启动文件
```

## 使用方法

### 1. 安装PlatformIO
如果还没有安装PlatformIO，请先安装：
```bash
# 通过pip安装
pip install platformio

# 或者通过VS Code扩展安装
# 在VS Code中搜索并安装 "PlatformIO IDE" 扩展
```

### 2. 编译项目
```bash
pio run
```

### 3. 上传到开发板
```bash
pio run --target upload
```

### 4. 清理编译文件
```bash
pio run --target clean
```

### 5. 串口监控
```bash
pio device monitor
```

## 配置说明

### 开发板配置
默认配置使用的是 `nucleo_h723zg` 开发板。如果您使用的是其他开发板，请修改 `platformio.ini` 中的 `board` 选项：

- `nucleo_h723zg` - Nucleo-H723ZG开发板
- `disco_h723vg` - STM32H723G-DISCO开发板
- `genericSTM32H723VG` - 通用STM32H723VG配置

### 调试配置
项目已配置为使用ST-Link调试器。确保您的开发板已正确连接。

### 自定义配置
如果您需要修改时钟频率、Flash大小等参数，请编辑 `platformio.ini` 文件中的相应配置项。

## 注意事项

1. **保持STM32CubeMX兼容性**: 该配置保持了与原始STM32CubeMX项目的兼容性，您仍然可以使用STM32CubeMX重新生成代码。

2. **链接脚本**: 使用了STM32CubeMX生成的原始链接脚本 `STM32H723XG_FLASH.ld`。

3. **HAL库**: 项目使用STM32 HAL库，所有相关的驱动文件都包含在 `Drivers/` 目录中。

4. **编译标志**: 编译标志与原始Makefile保持一致，包括FPU和优化设置。

## 故障排除

### 编译错误
- 确保所有必要的头文件路径都已正确配置
- 检查 `platformio.ini` 中的build_flags设置

### 上传失败
- 检查ST-Link驱动是否正确安装
- 确认开发板已正确连接
- 尝试重新连接开发板或重启ST-Link

### 调试问题
- 确保使用debug版本编译: `pio run -e stm32h723vg`
- 检查调试器连接状态
