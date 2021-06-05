
#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "include1.h"  // include from source/component1
#include "include2.h"  // include from source/component2

#define TASK1_DELAY_PARAM	(CONFIG_COM1_TASK_DELAY_MS)

static void task1(void *pvParams);

extern void foo1(void) 
{
	int a = 10;
	int b = 10;
	
	int c = 0;
	
	c = a + b;
	
	(void)c;
	
	xTaskCreate(task1, "task - inc1", 2048, NULL, 5, NULL);
	
	foo2();
}

static void task1(void *pvParams)
{
	(void)pvParams;
	
	uint32_t i = 0;
	
	while(1)
	{
		i++;
		
		printf("Execution Count1 - %d \r\n", i);
		
		vTaskDelay(pdMS_TO_TICKS(TASK1_DELAY_PARAM));
	}
	
	vTaskDelete(NULL);
}

