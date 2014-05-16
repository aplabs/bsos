BSOS
===

Experimental \*nix-like OS.

## Building
As of right now, BSOS is incredibly simple and only builds on Linux  platforms.
However, once built, the "os-image" file (included in the repo), can be run on any x86 system.

To build, make sure that you have gcc and nasm installed:
```
git clone https://github.com/aplabs/bsos.git
cd bsos
make
```

## Running
With bochsrc and bochs CPU emulator installed the image file can be emulated.

After it has been built with the instructions above, simply run:
```
bochs -q
```

## Contributing
Want to contribute to BSOS? Feel free to fork, modify, and issue pull requests.

Please follow our [coding conventions](docs/STANDARDS.md) in your contributions.
Also, feel free to look at our [To Do list](docs/TODO.md).

## Resources
* [Building a Simple Operating System -from Scratch](http://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf)
* [Keyboard Scancodes](http://flint.cs.yale.edu/cs422/doc/art-of-asm/pdf/APNDXC.PDF)
* [BrokenThorn Entertainment](http://www.brokenthorn.com/Resources/)
* [Basic Kernel in C](http://www.cs.vu.nl/~herbertb/misc/basickernel.pdf)
* And, of course, the [OSDev Wiki](http://wiki.osdev.org/)
* [NASM](http://www.nasm.us/) -The Netwide Assembler
* [Bochs](http://bochs.sourceforge.net/) Emulator
