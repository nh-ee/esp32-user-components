
#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "include2.h"

static void sampleTask(void *pvParams);

extern void foo2(void) 
{
	xTaskCreate(sampleTask, "task - inc2", 2048, NULL, 2, NULL);
}

static void sampleTask(void *pvParams)
{
	(void)pvParams;
	
	uint32_t i = 0;
	
	while(1)
	{
		i++;
		
		printf("Execution Count2 - %d \r\n", i);
		
		vTaskDelay(pdMS_TO_TICKS(500));
	}
	
	vTaskDelete(NULL);
}