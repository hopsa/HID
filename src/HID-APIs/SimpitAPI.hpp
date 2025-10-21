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


//modified GamepadAPI.hpp to match the simpit by SKOS

// Include guard
#pragma once

SimpitAPI::SimpitAPI(void)
{
	// Empty
}

void SimpitAPI::begin(void){
	// release all buttons
	end();
}

void SimpitAPI::end(void){
	memset(&_report, 0x00, sizeof(_report));
	SendReport(&_report, sizeof(_report));
}

void SimpitAPI::write(void){ 
	SendReport(&_report, sizeof(_report)); 
}

void SimpitAPI::press(uint8_t b){
	uint32_t hi=(b&0x20)>>5;
	uint32_t lo=((~b)&0x20)>>5;	
	_report.buttons[0] |= lo << (b - 1); 
	_report.buttons[1] |= hi << (b - 1); 
}

void SimpitAPI::release(uint8_t b){ 
	uint32_t hi=(b&0x20)>>5;
	uint32_t lo=((~b)&0x20)>>5;	
	_report.buttons[0] &= ~(lo << (b - 1)); 
	_report.buttons[1] &= ~(hi << (b - 1)); 
}

void SimpitAPI::releaseAll(void){ 
	memset(&_report, 0x00, sizeof(_report)); 
}

void SimpitAPI::buttonsL(uint32_t b){ 
	_report.buttons[0] = b; 
}

void SimpitAPI::buttonsH(uint32_t b){ 
	_report.buttons[1] = b; 
}

void SimpitAPI::thumbXAxis(int16_t a){ 
	_report.thumbXAxis = a; 
}

void SimpitAPI::thumbYAxis(int16_t a){ 
	_report.thumbYAxis = a; 
}

void SimpitAPI::joyXAxis(int16_t a){ 
	_report.joyXAxis = a; 
}

void SimpitAPI::joyYAxis(int16_t a){ 
	_report.joyYAxis = a; 
}

void SimpitAPI::throttleAxis(int16_t a){ 
	_report.throttleAxis = a; 
}

void SimpitAPI::zoomAxis(int16_t a){ 
	_report.zoomAxis = a; 
}

void SimpitAPI::dPad1(int8_t d){ 
	_report.dPad1 = d; 
	_report.dPad2 = d;
}