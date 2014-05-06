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
Please follow our [coding conventions](./STANDARDS.md) in your contributions.
