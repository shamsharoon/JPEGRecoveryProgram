#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Counter for JPEG file names
    int jpeg_counter = 0;

    // Output file pointer
    FILE *output_file = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if the current block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If we already have an open JPEG file, close it
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create a new JPEG file with a formatted name
            char filename[8];
            sprintf(filename, "%03i.jpg", jpeg_counter++);
            output_file = fopen(filename, "w");

            // Write the current block to the JPEG file
            fwrite(buffer, 1, 512, output_file);
        }
        else if (output_file != NULL)
        {
            // If we're in the middle of writing a JPEG, continue writing
            fwrite(buffer, 1, 512, output_file);
        }
    }

    // Close any remaining open files
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    // Close the memory card
    fclose(card);

    return 0;
}
