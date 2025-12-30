#ifndef IMAGE_H
#define IMAGE_H

// RGB image is stored like; [R, G, B,  R, G, B,  R, G, B,  ...]
// where;                     pixel 0   pixel 1   pixel 2   ...
typedef struct {
    int width;
    int height;
    unsigned char *data; // pointer to the pixel data
} Image;

Image rgb_to_grayscale(const unsigned char *rgb, int width, int height);
char* grayscale_to_ascii(const Image *img);

#endif //IMAGE_H