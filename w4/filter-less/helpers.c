#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the average of the RGB values
            int averageRGB =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Set each color component to the average value to achieve grayscale
            image[i][j].rgbtBlue = averageRGB;
            image[i][j].rgbtGreen = averageRGB;
            image[i][j].rgbtRed = averageRGB;
        }
    }

    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate the sepia values for each color component
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);

            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);

            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);

            // Cap the values at 255 to prevent overflow
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }

    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row of the image
    for (int i = 0; i < height; i++)
    {
        // Swap pixels horizontally across the midpoint
        for (int j = 0; j < width / 2; j++)
        {
            // Temporarily store the current pixel
            RGBTRIPLE temp = image[i][j];

            // Swap the pixels
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }

    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image to store the blurred result
    RGBTRIPLE temp[height][width];

    // Iterate over each pixel in the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the sum of the color values and the counter
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            float counter = 0;

            // Iterate over the 3x3 grid surrounding the pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // Check if the neighboring pixel is within the image bounds
                    if (i + x < 0 || i + x > height - 1 || j + y < 0 || j + y > width - 1)
                    {
                        continue;
                    }

                    // Accumulate the color values and increment the counter
                    totalRed += image[i + x][j + y].rgbtRed;
                    totalGreen += image[i + x][j + y].rgbtGreen;
                    totalBlue += image[i + x][j + y].rgbtBlue;
                    counter++;
                }
            }

            // Calculate the average color values
            temp[i][j].rgbtRed = round(totalRed / counter);
            temp[i][j].rgbtGreen = round(totalGreen / counter);
            temp[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }

    // Copy the blurred values from the temporary image back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}
