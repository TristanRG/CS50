#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

 // Open forensic image file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Buffer to hold each 512-byte block
    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;  // File pointer for current JPEG
    int file_count = 0; // File counter for naming
    char filename[8];   // Buffer to hold filename "###.jpg"

    // Read forensic image until end
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Check if start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If there's an open JPEG file, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create image file.\n");
                fclose(file);
                return 1;
            }

            file_count++;
        }

        // Write to current JPEG if one is open
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, img);
        }
    }

    // Close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(file);

    return 0;
}
