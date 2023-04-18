# neurondash
not finished, ignore pls

warning: really bad code ahead

## Currently working on:
- the mod thing that will get the values i need for the input nodes
    - most of the player value reading stuff is done
    - i need to do stuff like region of interest and play a bit with the levels info sooo
## To do:
- im lazy

## Building

MSVC 2017 and cmake is perfect for this

just build in x86 Release in your prefered editor, unless if you prefer doing it yourself then:

type these 2 commands:

```bash
cmake -B build -A win32 
```
-
that configures the project

and then
```bash
cmake --build build --config Release
```
builds it
