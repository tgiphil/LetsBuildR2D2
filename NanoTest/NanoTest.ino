// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            10

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100;
int posOffset = 0;
int speed = 1;
int red[NUMPIXELS];
int blue[NUMPIXELS];
int green[NUMPIXELS];

void setup() {
	pixels.begin(); // This initializes the NeoPixel library.
	pixels.setBrightness(100);

	for (int i = 0; i < NUMPIXELS; i++)
	{
		red[i] = 0;
		green[i] = 0;
		blue[i] = 0;
	}

	green[0] = 2; red[0] = 8;
	green[1] = 2; red[1] = 10;
	green[2] = 5; red[2] = 35;
	red[3] = 50;

	green[12] = 2; red[12] = 8;
	green[13] = 2; red[13] = 10;
	green[14] = 5; red[14] = 35;
	red[15] = 50;

	speed = -1; //# of pix to move per update (neg is clockwise, pos is cunterclockwise)
	posOffset = 0; // inital offset in array
}



void loop()
{

	for (int i = 0; i < NUMPIXELS; i++)
	{
		int pos = i+posOffset;
		if (pos >= NUMPIXELS) pos -= NUMPIXELS;
		if (pos < 0) pos += NUMPIXELS;
		pixels.setPixelColor(i, pixels.Color(red[pos], green[pos], blue[pos]));
	}
	posOffset+=speed;

	if (posOffset >= NUMPIXELS) posOffset -= NUMPIXELS;
	if (posOffset < 0) posOffset += NUMPIXELS;
	pixels.show(); // This sends the updated pixel color to the hardware.

	delay(delayval); // Delay for a period of time (in milliseconds).
}

