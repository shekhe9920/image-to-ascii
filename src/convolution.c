#include <stdint.h>
#include <stdlib.h>
#include "image.h"
#include "ascii.h"
#include <limits.h>

/**
 * Finds the best matching ASCII character for an 8x4 pixel block.
 * This function compares the given 8x4 block of grayscale pixels with predefined
 * character matrices and returns the character with the smallest squared error.
 *
 * @param block A 2D array representing an 8x4 pixel block.
 * @return The ASCII character that best matches the block.
 */
char find_best_char(uint8_t block[8][4]) {
    int best_score = INT_MAX;  // initialize with the largest possible value
    char best_char = ' ';      // default to the space character

    // Loop through all 94 printable ASCII characters
    for (int i = 0; i < 94; i++) {
        int score = 0;

        // Loop through the 8x4 block of pixels.
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 4; x++) {
                // Calculate the squared difference between the block pixel and the character matrix pixel
                int diff = (int)block[y][x] - (int)char_matrices[i][y][x];
                score += diff * diff;  // accumulate the squared error
            }
        }

        // update the best character if a better match is found (lower score)
        if (score < best_score) {
            best_score = score;
            best_char = (char) (i + 32);  // convert index to ASCII character (starting from space)
        }
    }

    return best_char;
}

/**
 * Extracts an 8x4 block of pixels from the image starting at the specified coordinates.
 * This function extracts a specific block of pixels from the grayscale image data
 * and stores it in the provided block array.
 *
 * @param img Pointer to the image structure containing the image data.
 * @param start_x The x-coordinate (column) where the block extraction starts.
 * @param start_y The y-coordinate (row) where the block extraction starts.
 * @param block A 2D array (8x4) where the extracted pixel block will be stored.
 */
void extract_block(const Image *img, int start_x, int start_y, uint8_t block[8][4]) {
    // Loop through the 8x4 block and copy the pixel values from the image
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 4; x++) {
            int img_x = start_x + x;   // calculate the x-coordinate in the image
            int img_y = start_y + y;   // calculate the y-coordinate in the image

            // Extract the pixel value and store it in the block
            block[y][x] = img->data[img_y * img->width + img_x];
        }
    }
}


/**
 * Converts the grayscale image to an ASCII art string.
 * This function divides the grayscale image into 8x4 pixel blocks, finds the best
 * matching ASCII character for each block, and creates an ASCII art string
 * representation of the image. The resulting string contains ASCII characters
 * arranged in rows, each corresponding to a row of blocks in the image.
 *
 * @param img Pointer to the grayscale image structure containing the image data.
 * @return A dynamically allocated string containing the ASCII art representation of the image.
 */
char* grayscale_to_ascii(const Image *img) {
    int cols = img->width / 4;
    int rows = img->height / 8;

    // Allocate memory for the ASCII output (including newlines and null terminator)
    int out_size = rows * (cols + 1) + 1;
    char *output = malloc(out_size);

    int pos = 0;  // position in the output string
    uint8_t block[8][4];  // temporary 8x4 block of pixels

    // Loop through each 8x4 block in the image
    for (int by = 0; by < rows; by++) {
        for (int bx = 0; bx < cols; bx++) {
            extract_block(img, bx * 4, by * 8, block);  // extract the block
            char c = find_best_char(block);  // find the best character for this block
            output[pos++] = c;  // add the character to the output
        }
        output[pos++] = '\n';  // add a newline after each row of characters
    }

    output[pos] = '\0';  // null-terminate the string
    return output;
}
