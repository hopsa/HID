/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

//modified GamepadAPI.h to match the simpit by SKOS

// Include guard
#pragma once

#include <Arduino.h>
#include "HID-Settings.h"

// Dpad directions
#define SIMPIT_DPAD_CENTERED 0
#define SIMPIT_DPAD_UP 1
#define SIMPIT_DPAD_RIGHT 3
#define SIMPIT_DPAD_DOWN 5
#define SIMPIT_DPAD_LEFT 7
#define SIMPIT_DPAD_PUSH 8


typedef union ATTRIBUTE_PACKED {
	// 64 Buttons, 5 16bit axis, 
	uint8_t whole8[0];
	uint16_t whole16[0];
	uint32_t whole32[0];
	uint32_t buttons[2];
	
	struct ATTRIBUTE_PACKED {
		//64buttons as bit fields (that's what the :1 does)
		uint8_t button1 : 1;
		uint8_t button2 : 1;
		uint8_t button3 : 1;
		uint8_t button4 : 1;
		uint8_t button5 : 1;
		uint8_t button6 : 1;
		uint8_t button7 : 1;
		uint8_t button8 : 1;

		uint8_t button9 : 1;
		uint8_t button10 : 1;
		uint8_t button11 : 1;
		uint8_t button12 : 1;
		uint8_t button13 : 1;
		uint8_t button14 : 1;
		uint8_t button15 : 1;
		uint8_t button16 : 1;

		uint8_t button17 : 1;
		uint8_t button18 : 1;
		uint8_t button19 : 1;
		uint8_t button20 : 1;
		uint8_t button21 : 1;
		uint8_t button22 : 1;
		uint8_t button23 : 1;
		uint8_t button24 : 1;

		uint8_t button25 : 1;
		uint8_t button26 : 1;
		uint8_t button27 : 1;
		uint8_t button28 : 1;
		uint8_t button29 : 1;
		uint8_t button30 : 1;
		uint8_t button31 : 1;
		uint8_t button32 : 1;
		
		uint8_t button33 : 1;
		uint8_t button34 : 1;
		uint8_t button35 : 1;
		uint8_t button36 : 1;
		uint8_t button37 : 1;
		uint8_t button38 : 1;
		uint8_t button39 : 1;
		uint8_t button40 : 1;

		uint8_t button41 : 1;
		uint8_t button42 : 1;
		uint8_t button43 : 1;
		uint8_t button44 : 1;
		uint8_t button45 : 1;
		uint8_t button46 : 1;
		uint8_t button47 : 1;
		uint8_t button48 : 1;

		uint8_t button49 : 1;
		uint8_t button50 : 1;
		uint8_t button51 : 1;
		uint8_t button52 : 1;
		uint8_t button53 : 1;
		uint8_t button54 : 1;
		uint8_t button55 : 1;
		uint8_t button56 : 1;

		uint8_t button57 : 1;
		uint8_t button58 : 1;
		uint8_t button59 : 1;
		uint8_t button60 : 1;
		uint8_t button61 : 1;
		uint8_t button62 : 1;
		uint8_t button63 : 1;
		uint8_t button64 : 1;

		//thumb joystick
		int16_t	thumbXAxis; //x
		int16_t	thumbYAxis; //y
		//throttle
		int16_t	throttleAxis; //z
		//base joystick
		int16_t	joyXAxis; //rx
		int16_t	joyYAxis; //ry
		//zoomwheel
		int16_t zoomAxis; //rz
		
		//dpad
		uint8_t	dPad1 : 4;
		//dummy so we're byte aligned. In the descriptor we pretend it is a second dpad
		uint8_t dPad2 : 4;
	};
} HID_SimpitReport_Data_t;

class SimpitAPI{
public:
	inline SimpitAPI(void);

	inline void begin(void);
	inline void end(void);
	inline void write(void);
	inline void press(uint8_t b);
	inline void release(uint8_t b);
	inline void releaseAll(void);

	inline void buttonsL(uint32_t b);
	inline void buttonsH(uint32_t b);

	inline void thumbXAxis(int16_t a);
	inline void thumbYAxis(int16_t a);
	inline void joyXAxis(int16_t a);
	inline void joyYAxis(int16_t a);
	inline void throttleAxis(int16_t a);
	inline void zoomAxis(int16_t a);
	
	inline void dPad1(int8_t d);

	// Sending is public in the base class for advanced users.
	virtual void SendReport(void* data, int length) = 0;

protected:
	HID_SimpitReport_Data_t _report;
};

// Implementation is inline
#include "SimpitAPI.hpp"
