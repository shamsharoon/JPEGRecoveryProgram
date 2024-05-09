# JPEG Recovery Program

This program is a simple tool for recovering JPEG images from a memory card. It reads the memory card block by block, identifies the start of JPEG files based on their signatures, and extracts them into individual JPEG files.

## Features

- Recovers JPEG images from a memory card.
- Supports memory cards formatted with the FAT file system.
- Outputs recovered JPEG files with automatically generated filenames.

## Usage

### Compilation

Compile the program using a C compiler. For example, with GCC:

```bash
gcc recover.c -o recover
```

### Execution

Run the compiled program with a single command-line argument specifying the memory card image file:

```bash
./recover CARD.raw
```

Replace `CARD.raw` with the path to your memory card image file.

### Output

The program will create a number of JPEG files in the current directory, named `001.jpg`, `002.jpg`, etc., corresponding to the recovered images.

## Note

- This program assumes that the memory card contains only JPEG images and that the file system of the memory card is not corrupted. It may not work correctly with other types of files or with corrupted memory cards.
- It's recommended to make a copy of the memory card image file and work on the copy to avoid accidental data loss.
