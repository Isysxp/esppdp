/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

int main(int argc, char **argv);

void app_main(void) {
    printf("Hello world!\n");
	char *args[]={"simh", 0};
	main(1, args);
    fflush(stdout);
    esp_restart();
}

int nanosleep(const struct timespec *req, struct timespec *rem) {
	//We don't have signals; no need to write to rem
	int wait_ms=req->tv_nsec/1000000L+req->tv_sec*1000;
//	printf("sleep %d ms (%ld ns)\n", wait_ms, req->tv_nsec);
	int wait_ticks=wait_ms/portTICK_PERIOD_MS;
	if (wait_ticks==0) wait_ticks=1;
	vTaskDelay(wait_ticks);
	return 0;
}

