#include <stdbool.h>
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

    // Buffer to hold blocks of data
    uint8_t buffer[512];

    // Flag to indicate if a JPEG file has been found
    bool foundJpeg = false;

    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            foundJpeg = true;
        }

        if (foundJpeg == true)
        {
            // Close the previous JPEG file if it is open
            if (counter != 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            foundJpeg = false;
            counter++;
        }
        else if (counter != 0)
        {
            // If not the start of a new JPEG file, continue writing to the current file
            fwrite(buffer, 1, 512, img);
        }
    }


    fclose(img);
    fclose(card);

    return 0;
}
