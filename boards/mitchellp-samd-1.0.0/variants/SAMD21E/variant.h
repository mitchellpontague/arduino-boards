/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_MITHCELLP_SAMD21E_
#define _VARIANT_MITHCELLP_SAMD21E_

// The definitions here needs a SAMD core >=1.6.6
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10606

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC (32768ul)

/** Master clock frequency */
#define VARIANT_MCK (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT (16u)
#define NUM_DIGITAL_PINS (16u)
#define NUM_ANALOG_INPUTS (9u)
#define NUM_ANALOG_OUTPUTS (1u)
#define analogInputToDigitalPin(p) ((p < PIN_A0) ? (p) + PIN_A0 : -1)

#define digitalPinToPort(P) (&(PORT->Group[g_APinDescription[P].ulPort]))
#define digitalPinToBitMask(P) (1 << g_APinDescription[P].ulPin)
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port) (&(port->OUT.reg))
#define portInputRegister(port) (&(port->IN.reg))
#define portModeRegister(port) (&(port->DIR.reg))
#define digitalPinHasPWM(P)                                                                                            \
  (g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER)

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

/*
 * Analog pins
 */
#define PIN_A0 (7ul)
#define PIN_A1 (8ul)
#define PIN_A2 (9ul)
#define PIN_A3 (10ul)
#define PIN_A4 (11ul)
#define PIN_A5 (12ul)
#define PIN_A6 (13ul)
#define PIN_A7 (14ul)
#define PIN_A8 (15ul)
#define PIN_DAC0 (7ul)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
static const uint8_t A8 = PIN_A8;
static const uint8_t DAC0 = PIN_DAC0;
#define ADC_RESOLUTION 12

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1
// Instead of using SERCOM4, and the SPI-header pins, the Mini Breakout
// uses pins 10-13 for SPI, on the unused sercom1
#define PIN_SPI_MISO (2u)
#define PIN_SPI_MOSI (5u)
#define PIN_SPI_SCK (3u)
#define PIN_SPI_SS (4u)
#define PERIPH_SPI sercom1
// Pad Map:     0       1   2     3
//          MOSI (TX)  SCK  SS  MOSI (RX)
#define PAD_SPI_TX SPI_PAD_0_SCK_1
#define PAD_SPI_RX SERCOM_RX_PAD_3

static const uint8_t SS = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA (16u)
#define PIN_WIRE_SCL (17u)
#define PERIPH_WIRE sercom3
#define WIRE_IT_HANDLER SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (18ul)
#define PIN_USB_DM (19ul)
#define PIN_USB_DP (20ul)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.

#endif /* _VARIANT_MITHCELLP_SAMD21E_ */