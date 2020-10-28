#include "helpers.h"
#include <math.h>

// Function Prototypes
int *calculateSobel(RGBTRIPLE grid[]);

// Define convolutional matrices
const int Gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
const int Gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

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
            upperLeft = upper = upperRight = left = right = bottomLeft = bottom = bottomRight = ignore;

            // Corner case: top-left
            if (row == 0 && col == 0)
            {
                right = image[row][col + 1];
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
                count = 4;
            }
            // Corner case: bottom-left
            else if (row == height - 1 && col == 0)
            {
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                right = image[row][col + 1];
                count = 4;
            }
            // Corner case: top-right
            else if (row == 0 && col == width - 1)
            {
                left = image[row][col - 1];
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
                count = 4;
            }
            // Corner case: bottom-right
            else if (row == height - 1 && col == width - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                left = image[row][col - 1];
                count = 4;
            }
            // Edge case: top
            else if (row == 0)
            {
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
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                right = image[row][col + 1];
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
                count = 6;
            }
            // Edge case: right
            else if (col == width - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                left = image[row][col - 1];
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
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
            blurred[row][col].rgbtRed = round((upperLeft.rgbtRed + upper.rgbtRed + upperRight.rgbtRed + left.rgbtRed + middle.rgbtRed + 
                                               right.rgbtRed + bottomLeft.rgbtRed + bottom.rgbtRed + bottomRight.rgbtRed) / count);

            blurred[row][col].rgbtGreen = round((upperLeft.rgbtGreen + upper.rgbtGreen + upperRight.rgbtGreen + left.rgbtGreen +
                                                 middle.rgbtGreen + right.rgbtGreen + bottomLeft.rgbtGreen + bottom.rgbtGreen + bottomRight.rgbtGreen) / count);

            blurred[row][col].rgbtBlue = round((upperLeft.rgbtBlue + upper.rgbtBlue + upperRight.rgbtBlue + left.rgbtBlue +
                                                middle.rgbtBlue + right.rgbtBlue + bottomLeft.rgbtBlue + bottom.rgbtBlue + bottomRight.rgbtBlue) / count);
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Variables to hold the pixels in the 3x3 grid
    RGBTRIPLE upperLeft, upper, upperRight, left, middle, right, bottomLeft, bottom, bottomRight;

    // Define zero values to ignore pixels that are beyond the borders
    RGBTRIPLE ignore;
    ignore.rgbtRed = ignore.rgbtGreen = ignore.rgbtBlue = 0;

    // Array to hold the all the pixels with Edges filter
    RGBTRIPLE edged[height][width];

    // Pointer to returned array with Sobel magnitudes
    int *sobel;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Store target pixel and its surronding pixels in the
            // 3x3 grid based on its position in the image array
            middle = image[row][col];
            upperLeft = upper = upperRight = left = right = bottomLeft = bottom = bottomRight = ignore;

            // Corner case: top-left
            if (row == 0 && col == 0)
            {
                right = image[row][col + 1];
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
            }
            // Corner case: bottom-left
            else if (row == height - 1 && col == 0)
            {
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                right = image[row][col + 1];
            }
            // Corner case: top-right
            else if (row == 0 && col == width - 1)
            {
                left = image[row][col - 1];
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
            }
            // Corner case: bottom-right
            else if (row == height - 1 && col == width - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                left = image[row][col - 1];
            }
            // Edge case: top
            else if (row == 0)
            {
                left = image[row][col - 1];
                right = image[row][col + 1];
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
            }
            // Edge case: left
            else if (col == 0)
            {
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                right = image[row][col + 1];
                bottom = image[row + 1][col];
                bottomRight = image[row + 1][col + 1];
            }
            // Edge case: bottom
            else if (row == height - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                upperRight = image[row - 1][col + 1];
                left = image[row][col - 1];
                right = image[row][col + 1];
            }
            // Edge case: right
            else if (col == width - 1)
            {
                upperLeft = image[row - 1][col - 1];
                upper = image[row - 1][col];
                left = image[row][col - 1];
                bottomLeft = image[row + 1][col - 1];
                bottom = image[row + 1][col];
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
            }

            // Store 3x3 grid for each pixel into an array to calculate Sobel magnitudes
            RGBTRIPLE grid[9] = {upperLeft, upper, upperRight, left, middle, right, bottomLeft, bottom, bottomRight};
            
            // Calculate the Sobel magnitude for each color
            sobel = calculateSobel(grid);
            edged[row][col].rgbtRed = *(sobel + 0);
            edged[row][col].rgbtGreen = *(sobel + 1);
            edged[row][col].rgbtBlue = *(sobel + 2);
        }
    }

    // Store the pixels of the edged image in the original image 
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = edged[row][col];
        }
    }
}

// Calculate edges based on Sobel operator
int *calculateSobel(RGBTRIPLE grid[]) {
    int sumXRed, sumYRed, sumXGreen, sumYGreen, sumXBlue, sumYBlue;
    sumXRed = sumYRed = sumXGreen = sumYGreen = sumXBlue = sumYBlue = 0; 

    // Calculate Gx and Gy for each color
    for (int i = 0; i < 9; i++) {
        sumXRed += (grid[i].rgbtRed * Gx[i]);
        sumYRed += (grid[i].rgbtRed * Gy[i]);
        sumXGreen += (grid[i].rgbtGreen * Gx[i]);
        sumYGreen += (grid[i].rgbtGreen * Gy[i]);
        sumXBlue += (grid[i].rgbtBlue * Gx[i]);
        sumYBlue += (grid[i].rgbtBlue * Gy[i]);
    }

    static int magnitude[3];

    // Calculate the gradient magnitude for each color
    int magnitudeRed = round(sqrt(pow(sumXRed, 2) + pow(sumYRed, 2)));
    int magnitudeGreen = round(sqrt(pow(sumXGreen, 2) + pow(sumYGreen, 2)));
    int magnitudeBlue = round(sqrt(pow(sumXBlue, 2) + pow(sumYBlue, 2)));

    // Cap the values of colors at 255 and store them in array of magnitudes
    magnitude[0] = (magnitudeRed < 255) ? magnitudeRed : 255;
    magnitude[1] = (magnitudeGreen < 255) ? magnitudeGreen : 255;
    magnitude[2] = (magnitudeBlue < 255) ? magnitudeBlue : 255;

    return magnitude;
}