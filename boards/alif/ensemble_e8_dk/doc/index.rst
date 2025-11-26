.. zephyr:board:: ensemble_e8_dk

Overview
********

The Alif Ensemble E8 Development Kit is a development board featuring the
Alif Semiconductor Ensemble E8 SoC (AE822FA0E5597LS0).

The Ensemble is a fusion processor family with heterogeneous compute capabilities
designed for AI/ML-enabled edge applications. SoCs within the family scale from
single-core Cortex-M55 MCUs to multicore devices with multiple Cortex-M55 cores.

The Ensemble E8 SoC includes two Arm Cortex-M55 cores with Arm Helium (MVE)
vector extensions, DSP and FPU capabilities, along with Arm Ethos-U55 and
Ethos-U85 NPUs for efficient neural network inference:

* **RTSS-HP** (High Performance): Cortex-M55 running at up to 400 MHz
* **RTSS-HE** (High Efficiency): Cortex-M55 running at up to 160 MHz

The SoC features up to 5.5 MB of on-chip MRAM and 9.75 MB of SRAM for
application code and data storage.

The ``ensemble_e8_dk/ae822fa0e5597ls0/rtss_hp`` build target provides support for
the High Performance Cortex-M55 core.
The ``ensemble_e8_dk/ae822fa0e5597ls0/rtss_he`` build target provides support for
the High Efficiency Cortex-M55 core.

More information about the board can be found at the
`Ensemble E8 DevKit Product Page`_.

Hardware
********

The Ensemble E8 Development Kit provides the following hardware components:

- **SoC**: Ensemble E8 (AE822FA0E5597LS0)

  - Dual Cortex-M55 cores (400 MHz HP, 160 MHz HE) with Arm Helium (MVE)
  - On-chip MRAM

- **Memory**

  - 64 MB Octal SPI HyperRAM PSRAM
  - 32 MB Octal SPI Flash
  - Micro SD card slot

- **Debug Interfaces**

  - 20-pin Arm Coresight JTAG connector (1.27 mm)
  - 10-pin Arm Coresight JTAG connector (1.27 mm)

- **Connectors**

  - 1 x High-Speed USB Device (Micro-AB)
  - 1 x High-Speed USB Host (Type-A)
  - 1 x USB-to-UART bridge for programming and debug
  - 1 x 100 Mbit/s Ethernet (RJ-45)
  - 4 x SPI interfaces
  - 4 x I2C interfaces
  - 1 x CAN-FD controller

- **Sensors**

  - ICM-42670-P: 3-axis accelerometer and gyroscope
  - BMI323: 3-axis accelerometer, gyroscope, and temperature sensor
  - 2 x I2S digital microphones
  - 2 x PDM digital microphones

- **Display and Camera**

  - 4.3-inch 1280x800 color TFT LCD with capacitive touchscreen
  - 2-lane MIPI CSI connector for camera module

- **User Interface**

  - 5-position joystick
  - Reset push-button
  - 2 x Multicolor LEDs

- **Power**

  - 4.75 V to 5.25 V power supply
  - CR2032 battery for RTC and VBAT peripherals

- **Other**

  - 38.4 MHz crystal oscillator
  - Multiple GPIO headers with 1.8V/3.3V/5.0V I/O support

Supported Features
==================

.. zephyr:board-supported-hw::

Connections and IOs
===================

Default UART Console
--------------------

- **RTSS-HP**: UART4 (accessible via USB-to-UART bridge)
- **RTSS-HE**: UART2 (accessible via USB-to-UART bridge)

Programming and Debugging
*************************

.. zephyr:board-supported-runners::

Flashing
========

Alif Ensemble E8 Development Kit can be programmed using the Alif Security
Toolkit (SETOOLS). Refer to the `Ensemble E8 DevKit Product Page`_ for detailed
instructions on using SETOOLS to program the board.

Alternatively, the board can be flashed using a SEGGER J-Link debug probe with
``west flash``. Connect the board to your host computer using the J-Link debug
interface. The sample application :zephyr:code-sample:`hello_world` is used for
this example.

Building and flashing for the High Performance core (RTSS-HP):

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :board: ensemble_e8_dk/ae822fa0e5597ls0/rtss_hp
   :goals: build flash

Building and flashing for the High Efficiency core (RTSS-HE):

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :board: ensemble_e8_dk/ae822fa0e5597ls0/rtss_he
   :goals: build flash

.. note::
   ``west flash`` requires `SEGGER J-Link software`_ and `pylink`_ Python module
   to be installed on your host computer.

Open a serial terminal (minicom, putty, etc.) with the following settings:

- Speed: 115200
- Data: 8 bits
- Parity: None
- Stop bits: 1

Reset the board and you should see the following message:

.. code-block:: console

   Hello World! ensemble_e8_dk/ae822fa0e5597ls0/rtss_hp

Debugging
=========

You can debug an application using ``west debug``. For example:

.. code-block:: console

   west build -b ensemble_e8_dk/ae822fa0e5597ls0/rtss_hp samples/hello_world
   west debug

This will start a GDB server and connect to the target.

References
**********

- `Alif Semiconductor Website`_
- `Ensemble E8 DevKit Product Page`_
- `SEGGER J-Link software`_

.. _Alif Semiconductor Website:
   https://alifsemi.com/

.. _Ensemble E8 DevKit Product Page:
   https://alifsemi.com/support/kits/ensemble-e8devkit/

.. _SEGGER J-Link software:
   https://www.segger.com/downloads/jlink

.. _pylink:
   https://github.com/Square/pylink
