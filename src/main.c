#include "main.h"
#include "gpio.h"

// 函数声明
void SystemClock_Config(void);
void Error_Handler(void);

// 全局变量用于调试
volatile uint32_t counter = 0;
volatile uint8_t led_state = 0;

// 使用STM32CubeMX生成的代码
int main(void)
{
    HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  // 调试断点：在这里设置断点可以检查初始化是否完成
  counter = 0;

  while (1)
  {
    // 主循环 - 在这里设置断点可以逐步执行
    counter++;
    
    // 简单的延时和LED切换逻辑（如果有LED的话）
    if (counter >= 100000) {
      counter = 0;
      led_state = !led_state;
      // 在这里设置断点可以观察变量变化
    }
    
    // 可以在这里添加更多功能
    HAL_Delay(1);
  }
}

// SystemClock_Config函数应该从原始main.c复制过来，但现在先用一个简单的版本
void SystemClock_Config(void)
{
  // 简化的时钟配置
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
