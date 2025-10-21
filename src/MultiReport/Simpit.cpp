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

#include "Simpit.h"


static const uint8_t _hidMultiReportDescriptorSimpit[] PROGMEM = {
	/* describe the simpit*/
	0x05, 0x01,							/* USAGE_PAGE (Generic Desktop) */
	0x09, 0x04,							/* USAGE (Joystick) */
	0xa1, 0x01,							/* COLLECTION (Application) */
	0x85, HID_REPORTID_SIMPIT,			/*   REPORT_ID */
	/* 64 Buttons */
	0x05, 0x09,							/*   USAGE_PAGE (Button) */
	0x19, 0x01,							/*   USAGE_MINIMUM (Button 1) */
	0x29, 0x40,							/*   USAGE_MAXIMUM (Button 64) */
	0x15, 0x00,							/*   LOGICAL_MINIMUM (0) */
	0x25, 0x01,							/*   LOGICAL_MAXIMUM (1) */
	0x75, 0x01,							/*   REPORT_SIZE (1) */
	0x95, 0x40,						    /*   REPORT_COUNT (64) */
	0x81, 0x02,							/*   INPUT (Data,Var,Abs) */
	/* 6 16bit Axis */
	0x05, 0x01,							/*   USAGE_PAGE (Generic Desktop) */
	0xa1, 0x00,							/*   COLLECTION (Physical) */
	0x09, 0x30,							/*     USAGE (X) */
	0x09, 0x31,							/*     USAGE (Y) */
	0x09, 0x32,							/*     USAGE (Z) */
	0x09, 0x33,							/*     USAGE (Rx) */
	0x09, 0x34,							/*     USAGE (Ry) */
	0x09, 0x35,							/*     USAGE (Rz) */
	0x16, 0x00, 0x80,					/*     LOGICAL_MINIMUM (-32768) */
	0x26, 0xFF, 0x7F,					/*     LOGICAL_MAXIMUM (32767) */
	0x75, 0x10,							/*     REPORT_SIZE (16) */
	0x95, 0x06,							/*     REPORT_COUNT (6) */
	0x81, 0x02,							/*     INPUT (Data,Var,Abs) */
	0xc0,								/*   END_COLLECTION */
	
	/* 1 Hat Switch, we pretend it is 2 hats so we get byte aligned */
	0x05, 0x01,							/*   USAGE_PAGE (Generic Desktop) */
	0x09, 0x39,							/*   USAGE (Hat switch) */
	0x09, 0x39,							/*   USAGE (Hat switch) */
	0x15, 0x01,							/*   LOGICAL_MINIMUM (1) */
	0x25, 0x08,							/*   LOGICAL_MAXIMUM (8) */
	0x95, 0x02,							/*   REPORT_COUNT (2) */
	0x75, 0x04,							/*   REPORT_SIZE (4) */
	0x81, 0x02,							/*   INPUT (Data,Var,Abs) */
	
	0xc0								/* END_COLLECTION */
};

Simpit_::Simpit_(void) 
{
	static HIDSubDescriptor node(_hidMultiReportDescriptorSimpit, sizeof(_hidMultiReportDescriptorSimpit));
	HID().AppendDescriptor(&node);
}

void Simpit_::SendReport(void* data, int length)
{
	HID().SendReport(HID_REPORTID_SIMPIT, data, length);
}

Simpit_ Simpit;

