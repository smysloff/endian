# Endian
Determine and print the endianness of a system

## Synopsys
```endian [OPTION]```

## Description
The **endian** utility is used to determine and print the endianness of the current system. Endianness refers to the order in which bytes are stored in memory.

The **endian** utility prints the endianness of the system in a human-readable format. It outputs "little-endian" or "big-endian" depending on the system's byte order.

## Options
* **-h** - Displays the given man page.
* **-n** - Disables line break printing.

## Exit status
The **endian** utility returns the following exit status codes:
* **0**	- Endianness successfully determined and printed.
* **1**	- An error occurred while determining the endianness.

## Compilation
`make build` - in current directory compiles the utility from sources

## Authors
The **endian** utility was written by Alexander Smyslov <kokoc.smyslov@yandex.ru>.

## Bugs
Please report any bugs or issues to <kokoc.smyslov@yandex.ru>.

## Copyright
The **endian** utility is available under the GPLv3+: GNU GPL version 3 or later license <https://gnu.org/licenses/gpl.html>.
This is free software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law.

## See also
**byteorder**(3)
