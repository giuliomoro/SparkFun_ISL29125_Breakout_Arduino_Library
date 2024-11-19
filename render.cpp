#include <Bela.h>
#include "src/SparkFunISL29125.h"

// Declare sensor object
SFE_ISL29125 RGB_sensor;

// Read sensor values for each color and print them to serial monitor
void loop(void*)
{
	while(!Bela_stopRequested())
	{
		// Read sensor values (16 bit integers)
		unsigned int red = RGB_sensor.readRed();
		unsigned int green = RGB_sensor.readGreen();
		unsigned int blue = RGB_sensor.readBlue();

		printf("Red: %#04x, Green: %04x, Blue: %04x\n", red, green, blue);
		usleep(2000 * 1000);
	}
}

bool setup(BelaContext* context, void*)
{
	if(!RGB_sensor.init())
	{
		fprintf(stderr, "Error initialising sensor\n");
		return false;
	}
	Bela_runAuxiliaryTask(loop);
	return true;
}

void render(BelaContext* context, void*)
{
	// do some audio here
}

void cleanup(BelaContext* context, void*)
{
}
