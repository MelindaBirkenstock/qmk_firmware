# cheem

![cheem](imgur.com image replace me!)

A short description of the keyboard/project

* Keyboard Maintainer: [Richard Head](https://github.com/yourusername)
* Hardware Supported: The PCBs, controllers supported
* Hardware Availability: Links to where you can find this hardware

Make example for this keyboard (after setting up your build environment):

    make cheem:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


The PHYSICAL rows and columns are connected as such :

on left hand (slave) :

              I2C mcp23018
           .-------   --------.
      GND -| 1 VSS \_/  NC 28 |
           | 2 NC       A7 27 |-
     COL2 -| 3 B0       A6 26 |-
     COL3 -| 4 B1       A5 25 |-
     ROW3 -| 5 B2       A4 24 |-
     ROW2 -| 6 B3       A3 23 |-
     ROW1 -| 7 B4       A2 22 |-
     COL4 -| 8 B5       A1 21 |-
     COL5  | 9 B6       A0 20 |- ROW4  
     COL6  | 10 B7    INTA 19 |
      VCC -| 11 VDD   INTB 18 |
      SCL -| 12 SCL     NC 17 |
      SDA -| 13 SDA    RST 16 |- VCC
           | 14 NC    ADDR 15 |- GND
           `------------------'
