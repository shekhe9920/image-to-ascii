#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <sys/stat.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stdlib.h>

#include "stb_image.h"  // For image loading
#include "image.h"      // Custom image functions (grayscale conversion, etc.)


/**
 * Main function that converts an image to ASCII art and saves it to a text file.
 */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image-path> <new-name>.txt\n", argv[0]);
        return 1;
    }

    int width, height, channel;

    // Load the image using stb_image library (RGB format)
    unsigned char *rgb = stbi_load(
        argv[1],  // image path from command line
        &width,   // store width
        &height,  // store height
        &channel, // store number of channels
        3         // 3 channels (RGB)
    );


    if (!rgb) {
        fprintf(stderr, "failed to load image\n");
        return 1;
    }

    // convert the RGB image to grayscale
    Image gray = rgb_to_grayscale(rgb, width, height);

    // convert the grayscale image to ASCII art
    char *ascii = grayscale_to_ascii(&gray);


    // --- Save ASCII art to file ---

    // Prepare the output file path
    char output_path[512];
    snprintf(output_path, sizeof(output_path),
        "../saved_ascii_art/%s",  // save path
        argv[2]);  // filename from command line argument

    // ensure the filename ends with ".txt"
    if (!strstr(output_path, ".txt")) {
        strcat(output_path, ".txt");
    }

    // open the file for writing
    FILE *f = fopen(output_path, "w");
    if (!f) {
        perror("Could not open output file");
        free(ascii);  // free memory if file opening fails
        return 1;
    }

    // write the ASCII art to the file
    fputs(ascii, f);
    fclose(f);  // close the file

    // Clean up memory
    free(ascii);  // free the ASCII art string
    free(gray.data);  // free the grayscale image data
    stbi_image_free(rgb);  // free the RGB image data

    printf("ASCII image saved to %s\n", output_path);
    return 0;
}
