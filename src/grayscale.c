#include <stdlib.h>
#include "image.h"


/**
 * Converts an RGB image to grayscale by applying the luminance formula.
 * The grayscale value is calculated as: gray = 0.299 * R + 0.587 * G + 0.114 * B.
 *
 * @param rgb Pointer to the RGB image data. The data should be in the format of
 *            width * height * 3 (RGB channels).
 * @param w The width of the image (in pixels).
 * @param h The height of the image (in pixels).
 * @return An `Image` struct containing the grayscale image data.
 *         The grayscale values are stored as unsigned char (0-255).
 */
Image rgb_to_grayscale(const unsigned char *rgb, int w, int h) {
    Image img;
    img.width = w;
    img.height = h;

    // Allocate memory for grayscale image data
    img.data = malloc(w * h);  // each pixel is 1 byte (grayscale)

    // Loop through all pixels in the input RGB image.
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int i = (y * w + x) * 3;    // index in the RGB array (3 channels per pixel)

            // Extract RGB channels for current pixel
            int r = rgb[i];         // Red channel
            int g = rgb[i + 1];     // Green channel
            int b = rgb[i + 2];     // Blue channel

            // Calculate grayscale value using the luminance formula
            float gray = 0.299f * r + 0.587f * g + 0.114f * b;

            // Assign the grayscale value to the corresponding pixel in the image.
            img.data[y * w + x] = gray;  // store grayscale value (1 byte per pixel)
        }
    }

    return img;
}
