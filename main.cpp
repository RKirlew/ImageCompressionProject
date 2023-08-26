#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <vector>
#include "C:\Users\Raheem\Downloads\stb_image.h"

int main()
{
    std::string filename = "C:\\Users\\Raheem\\drawing.png";

    int x, y, n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 0);

    if (data != nullptr && x > 0 && y > 0)
    {
        // Initialize the frequency table
        std::vector<int> frequencyTable(256, 0);  // Assuming 8-bit pixel values

        for (int i = 0; i < y; ++i)
        {
            for (int j = 0; j < x; ++j)
            {
                int pixelIndex = (i * x + j) * n;
                if (n == 1)
                {
                    int pixelValue = data[pixelIndex];  // Grayscale image
                    frequencyTable[pixelValue]++;
                }
                else if (n >= 3)  // RGB or RGBA image
                {
                    // Assuming pixelValue is the red component in an RGB image
                    int pixelValue = data[pixelIndex];
                    frequencyTable[pixelValue]++;
                }
            }
        }

        // Print the frequency table
        for (int i = 0; i < 256; ++i)
        {
            if (frequencyTable[i] > 0)
            {
                std::cout << "Pixel value " << i << ": Frequency " << frequencyTable[i] << '\n';
            }
        }
    }
    else
    {
        std::cout << "Error loading the image or invalid dimensions.\n";
    }

    stbi_image_free(data);
}
