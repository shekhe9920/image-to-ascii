# Image to ASCII Converter

This program converts an image to ASCII art and saves the result as a text file. 
The program uses the **stb_image** library for image loading and processes the image to grayscale, 
then maps grayscale values to ASCII characters to create a visual representation of the image.
---
## Features

- Convert any RGB image (JPG, PNG, etc.) to ASCII art.
- Save the generated ASCII art to a text file.
- Supports custom images with user-defined names for output files.
---
## Requirements

- C compiler (e.g., GCC)
---

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/image-to-ascii.git
   cd image-to-ascii
2. **Build the project**
   ```bash
   make
3. The program should now be built, and the executable will be available in the ```build/``` directory.
---
## Usage

The program requires two arguments:
1. The path to the image you want to convert.
2. The name of the output text file (without the .txt extension).

Example usage:
```bash
./image_to_ascii <image-path> <output-name>.txt
```
For example:
```bash
./image_to_ascii ../demo_images/parrot.png parrot_ascii.txt
```
---
## Image to ASCII Example

| Original image                                        | The ASCII art generated from the image                                                |
|-------------------------------------------------------------|---------------------------------------------------------------------------------------|
| <img src="demo_images/ferrari.png" alt="Ferrari Image" width="300"> | <img src="saved_ascii_art/ferrari_ascii_image.png" alt="Ferrari ASCII Art" width="300"> |


---

## Example Workflow:
```bash
# Run the program to convert the image
./image_to_ascii ../demo_images/parrot.png parrot_ascii.txt

# Check the output
explorer.exe ../saved_ascii_art
```
---
## Project Structure
```bash
image-to-ascii/
   ├── demo_images/               # Example images
   ├── include/                   # Header files
   ├── saved_ascii_art/           # Saved ASCII files
   ├── src/                       # Source code files
   ├── CMakeLists.txt             # CMake build file
   ├── README.md                  # Project documentation
   └── .gitignore                 # Git ignore file
```
---

## Output

The program will save the resulting ASCII art in a ```.txt``` file inside the ```../saved_ascii_art/``` directory. 
The ASCII art is created by mapping each pixel block of the image to its closest ASCII character.

Once the ASCII art is saved, you may need to adjust the zoom level of your text editor to properly view the result.

