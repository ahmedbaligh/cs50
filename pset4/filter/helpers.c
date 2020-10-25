#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int grayColor;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Get average color value in each pixel to use as its gray shade
            grayColor = round((image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / 3);

            // Replace each color in each pixel with a shade on the black-white spectrum
            image[row][col].rgbtRed = grayColor;
            image[row][col].rgbtGreen = grayColor;
            image[row][col].rgbtBlue = grayColor;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue;
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Get the original color values in each pixel
            red = image[row][col].rgbtRed;
            green = image[row][col].rgbtGreen;
            blue = image[row][col].rgbtBlue;

            // Calculate the Sepia filter value for each color in each pixel
            sepiaRed = round((0.393 * red) + (0.769 * green) + (0.189 * blue));
            sepiaGreen = round((0.349 * red) + (0.686 * green) + (0.168 * blue));
            sepiaBlue = round((0.272 * red) + (0.534 * green) + (0.131 * blue));

            // Apply the Sepia filter to each pixel
            // If the filter's color value exceeds 255, cap it to 255
            image[row][col].rgbtRed = (sepiaRed < 255) ? sepiaRed : 255;
            image[row][col].rgbtGreen = (sepiaGreen < 255) ? sepiaGreen : 255;
            image[row][col].rgbtBlue = (sepiaBlue < 255) ? sepiaBlue : 255;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width / 2; col++)
        {
            tmp = image[row][col];
            image[row][col] = image[row][width - col];
            image[row][width - col] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
