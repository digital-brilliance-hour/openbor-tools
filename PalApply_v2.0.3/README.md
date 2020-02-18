# PalApply v2

PalApply v2 is a complete rewrite of PalApply, a program that converts RGBA, RGB, grayscale, or indexed images to indexed images with a user-specified palette. Like its predecessor, PalApply v2 is meant for people making games with the [OpenBOR](https://github.com/DCurrent/openbor) engine, but others working with indexed images may find it useful for their own purposes.

## Differences from the original

PalApply v2 has some key differences from the original PalApply:
* If the source image has non-trivial alpha (partial transparency), then in addition to the usual indexed image, PalApply v2 will save a corresponding *alpha mask* that can be used with OpenBOR's `alphamask` command.
* If the source image has any transparency at all, fully transparent pixels will be mapped to the transparent color (the first color in the palette).
* The palette must be an image in PNG or GIF format or a palette in .act format; there is no longer support for palettes in .pal/.gpl format.
* All output is in PNG format. GIF, PCX, and BMP are still supported as input formats, just not for output.
* As a tradeoff for the above, the PNGs written by PalApply v2 are compressed to a small file size and optimized for fast loading. This is in sharp contrast to the poorly encoded PNGs written by the original PalApply, which were often larger than the equivalent GIFs.
* The user interface of PalApply v2 is similar to that of its predecessor, but is more polished in various ways.
* PalApply v2 is written in C rather than Java, so it doesn't require the Java runtime to be installed.

## Version history
### v2.0.1
* Added support for palettes in .act format.

### v2.0.0
* Initial release.

## Compiling
### Windows
Using MSYS2, install pkg-config and the development packages for GTK+3, SDL2_image, and libpng. Then compile with:

    gcc -O2 -Wall -o "PalApply v2.exe" gui.c palapply.c `pkg-config --cflags --libs gtk+-3.0 SDL2_image | sed 's/-lSDL2main//g'` -lpng

### Linux
Install pkg-config and the development packages for GTK+3, SDL2_image, and libpng using your distribution's package manager. Then compile with:

    gcc -O2 -Wall -o palapply-v2 gui.c palapply.c `pkg-config --cflags --libs gtk+-3.0 SDL2_image` -lpng

## License
Copyright (c) 2010-2019 Bryan Cain

PalApply v2 is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. See the full text of the license in gpl-3.0.txt for more details.
