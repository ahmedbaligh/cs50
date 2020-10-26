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
            grayColor = round((image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / 3.0);

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
            // Substitute corresponding pixels arround the vertical axis
            tmp = image[row][col];
            image[row][col] = image[row][width - col - 1];
            image[row][width - col - 1] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Variables to hold the blur box pixels for each pixel
    float count;
    RGBTRIPLE upperLeft, upper, upperRight, left, middle, right, bottomLeft, bottom, bottomRight;

    // Define a zero value to ignore pixels that are not avaliable
    // in the blur box, in the cases of edge and corner pixels
    RGBTRIPLE ignore;
    ignore.rgbtRed = ignore.rgbtGreen = ignore.rgbtBlue = 0;

    // Initialize an array to hold the all the blurred pixels
    RGBTRIPLE blurred[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Store target pixel and its surronding blur box
            // pixels based on its position in the image array
            middle = image[row][col];

            // Corner case: top-left
            if (row == 0 && col == 0)
            {
                upperLeft = ignore;
                upper = ignore;
                upperRight = ignore;
                left = ignore;
                right = image[row][col + 1];
                bottomLeft = ignore;
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
                count = 4;
            }
            // Corner case: bottom-left
            else if (row == height - 1 && col == 0)
            {
                upperLeft = ignore;
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                left = ignore;
                right = image[row][col + 1];
                bottomLeft = ignore;
                bottom = ignore;
                bottomRight = ignore;
                count = 4;
            }
            // Corner case: top-right
            else if (row == 0 && col == width - 1)
            {
                upperLeft = ignore;
                upper = ignore;
                upperRight = ignore;
                left = image[row][col - 1];
                right = ignore;
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
                bottomRight = ignore;
                count = 4;
            }
            // Corner case: bottom-right
            else if (row == height - 1 && col == width - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                upperRight = ignore;
                left = image[row][col - 1];
                right = ignore;
                bottomLeft = ignore;
                bottom = ignore;
                bottomRight = ignore;
                count = 4;
            }
            // Edge case: top
            else if (row == 0)
            {
                upperLeft = ignore;
                upper = ignore;
                upperRight = ignore;
                left = image[row][col - 1];
                right = image[row][col + 1];
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
                count = 6;
            }
            // Edge case: left
            else if (col == 0)
            {
                upperLeft = ignore;
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                left = ignore;
                right = image[row][col + 1];
                bottomLeft = ignore;
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
                count = 6;
            }
            // Edge case: bottom
            else if (row == height - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                left = image[row][col - 1];
                right = image[row][col + 1];
                bottomLeft = ignore;
                bottom = ignore;
                bottomRight = ignore;
                count = 6;
            }
            // Edge case: right
            else if (col == width - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                upperRight = ignore;
                left = image[row][col - 1];
                right = ignore;
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
                bottomRight = ignore;
                count = 6;
            }
            // Regular (middle) case
            else
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                left = image[row][col - 1];
                right = image[row][col + 1];
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
                count = 9;
            }

            // Calculate the average color value for each pixel based on 'blur box'
            blurred[row][col].rgbtRed = round((upperLeft.rgbtRed + upper.rgbtRed + upperRight.rgbtRed + left.rgbtRed + middle.rgbtRed + right.rgbtRed + bottomLeft.rgbtRed + bottom.rgbtRed + bottomRight.rgbtRed) / count);

            blurred[row][col].rgbtGreen = round((upperLeft.rgbtGreen + upper.rgbtGreen + upperRight.rgbtGreen + left.rgbtGreen + middle.rgbtGreen + right.rgbtGreen + bottomLeft.rgbtGreen + bottom.rgbtGreen + bottomRight.rgbtGreen) / count);

            blurred[row][col].rgbtBlue = round((upperLeft.rgbtBlue + upper.rgbtBlue + upperRight.rgbtBlue + left.rgbtBlue + middle.rgbtBlue + right.rgbtBlue + bottomLeft.rgbtBlue + bottom.rgbtBlue + bottomRight.rgbtBlue) / count);
        }
    }

    // Store the pixels of the blurred image in the original image 
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = blurred[row][col];
        }
    }
}
