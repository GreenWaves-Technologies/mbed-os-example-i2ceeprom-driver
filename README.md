# Getting Started With The mbed-os Example for the I2C EEPROM Block Device

This is the mbed-os example for the I2CEEBlockDevice driver.
See the [i2cee-driver](https://github.com/GreenWaves-Technologies/i2cee-driver) repository for more information.

This guide outlines the steps to get the I2C EEPROM part working on an mbed OS platform fitted with the CI Test Shield.

Please install [mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

## Hardware Requirements

This example can be used on an mbedos platform with a CI Test Shield inserted into the Arduino header.

This document uses the GAP8 as an example. Simply change the relevant options (e.g. -m GAP8) to be appropriate for your target.

## Create the Example Application

From the command-line, import the example:

```
mbed import https://github.com/GreenWaves-Technologies/mbed-os-example-i2ceeprom-driver
```

You should see:

	[mbed] Importing program "mbed-os-example-i2ceeprom-driver" from "https://github.com/GreenWaves-Technologies/mbed-os-example-i2ceeprom-driver" at latest revision in the current branch
	[mbed] Adding library "i2cee-driver" from "https://github.com/GreenWaves-Technologies/i2cee-driver" at rev #e9f7c0eea67f
	[mbed] Adding library "mbed-os" from "https://github.com/GreenWaves-Technologies/mbed-os" at rev #b0f31ea774ac

Move into the newly created directory:

```
cd mbed-os-example-i2ceeprom-driver
```

If the mbed-os library was not automatically added (see trace above), do the following to import mbed-os:

```
mbed new .
```

## Build the Example

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_RISCV`, `GCC_ARM`, `ARM`, `IAR`). For example, for the GCC_ARM toolchain:

```
mbed compile -m GAP8 -t GCC_RISCV
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

```
Elf2Bin: mbed-os-example-i2ceeprom-driver
+-----------------+-------+-------+------+
| Module          | .text | .data | .bss |
+-----------------+-------+-------+------+
| BUILD/GAP8      | 20638 |   380 | 1183 |
| [fill]          |     2 |     4 |    9 |
| [lib]/c.a       |  9542 |  2096 |   60 |
| [lib]/gcc.a     |  1798 |     0 |    0 |
| mbed-os/targets |   288 |     4 |   28 |
| Subtotals       | 32268 |  2484 | 1280 |
+-----------------+-------+-------+------+
Total Static RAM memory (data + bss): 3764 bytes
Total Flash memory (text + data): 34752 bytes
```

## <a name="run-the-example-binary-on-the-GAP8"></a> Run the Example Binary on the GAP8


1. Connect your device (with sensor board) to the computer over USB.
1. Execute the script (make sure you have already install the [gap_sdk](https://github.com/GreenWaves-Technologies/gap_sdk)) :

```
source ./USER_PATH/gap_sdk/sourceme.sh
run_mbed ./BUILD/GAP8/GCC_RISCV/mbed-os-example-i2ceeprom-driver.elf
```

After connecting a serial console and resetting the target, the following trace should be seen:

	i2cee size: 262144
	i2cee read size: 1
	i2cee program size: 1
	i2cee erase size: 1
	Hello World!


# Troubleshooting

1. Make sure `mbed-cli` is working correctly and its version is newer than `1.0.0`.

 ```
 mbed --version
 ```

 If not, update it:

 ```
 pip install mbed-cli --upgrade
 ```
