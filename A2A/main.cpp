#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <exception>
#include <fstream>
#include <sstream>
#define STB_IMAGE_IMPLEMENTATION
#include "./include/stb_image.h"

using namespace std;

/*
Function to see all pixels
*/
void savePixelData(vector<vector<tuple<int, int, int>>> pixels, const string &filename)
{
    // ofstream used to write to files

    ofstream file(filename);
    if (file.is_open())
    {
        for (size_t x = 0; x < pixels.size(); ++x)
        {
            for (size_t y = 0; y < pixels[x].size(); ++y)
            {
                auto pixel = pixels[x][y];
                file << get<0>(pixel) << " " << get<1>(pixel) << " " << get<2>(pixel) << endl;
            }
        }
        file.close();
    }
    else
    {
        cerr << "Error opening file for writing." << endl;
    }
}
void saveBrightnessData(vector<vector<int>> brightness_, const string &filename)
{
    // ofstream used to write to files

    ofstream file(filename);
    if (file.is_open())
    {
        for (size_t x = 0; x < brightness_.size(); ++x)
        {
            for (size_t y = 0; y < brightness_[x].size(); ++y)
            {

                file << brightness_[x][y] << endl;
            }
        }
        file.close();
    }
    else
    {
        cerr << "Error opening file for writing." << endl;
    }
}

void saveASCIIData(vector<vector<char>> ascii_image, const string &filename)
{
    // ofstream used to write to files

    ofstream file(filename);
    if (file.is_open())
    {
        for (size_t x = 0; x < ascii_image.size(); ++x)
        {
            for (size_t y = 0; y < ascii_image[x].size(); ++y)
            {

                file << ascii_image[x][y] << endl;
            }
        }
        file.close();
    }
    else
    {
        cerr << "Error opening file for writing." << endl;
    }
}
//--------------------------------------MAIN----------------------------------------------------------------------------

int main()
{
    int width, height, channels;
    unsigned char *image = stbi_load("./img/rabbit.jpg", &width, &height, &channels, 1);

    //--------------------------------------TEST: IMG LOADED----------------------------------------------------------------------------
    if (image == nullptr)
    {
        cerr << "Failed to load image: " << stbi_failure_reason() << endl;
        return 1;
    }
    else
    {
        // cout << "Successfully loaded image!" << endl;
        // cout << "Image size: " << width << " x " << height << endl;
    }
    //--------------------------------------LOADING PIXELS INTO VECTOR----------------------------------------------------------------------------

    vector<vector<tuple<int, int, int>>> pixels(height, vector<tuple<int, int, int>>(width));
    int index = 0; // index since [0],[1],[2] are needed to get rgb values
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            using std::make_tuple;
            pixels[y][x] = make_tuple(image[index], image[index + 1], image[index + 2]);
            index += 3;
        }
    }

    //--------------------------------------TEST: PIXELS LOADED---------------------------------------------------------------------------------
    // for (size_t x = 0; x < pixels.size(); ++x)
    // {
    //     for (size_t y = 0; y < pixels[x].size(); ++y)
    //     {
    //         auto pixel = pixels[x][y];
    //         cout << get<0>(pixel) << " " << get<1>(pixel) << " " << get<2>(pixel) << endl;
    //     }
    // }

    // savePixelData(pixels, "./data/pixels.txt");

    //--------------------------------------LOADING BRIGHTNESS INTO VECTOR----------------------------------------------------------------------------

    // Average: average the R, G and B values - (R + G + B) / 3
    // Lightness: average the maximum and minimum values out of R, G and B - max(R, G, B) + min(R, G, B) / 2
    // Luminosity: take a weighted average of the R, G and B values to account for human perception - 0.21 R + 0.72 G + 0.07 B
    vector<vector<int>> brightness_(height, vector<int>(width));

    // for (size_t x = 0; x < brightness_.size(); ++x)
    // {
    //     for (size_t y = 0; y < brightness_[x].size(); ++y)
    //     {
    //         auto pixel = pixels[x][y];
    //         int brightness_level = (get<0>(pixel) + get<1>(pixel) + get<2>(pixel)) / 3;
    //         brightness_[x][y] = (brightness_level);
    //     }
    // }

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            auto pixel = pixels[y][x];
            int brightness_level = (get<0>(pixel) + get<1>(pixel) + get<2>(pixel)) / 3;
            brightness_[y][x] = (brightness_level);
        }
    }

    //--------------------------------------TEST: BRIGHTNESS MATRIX---------------------------------------------------------------------------------

    // cout << "Successfully constructed brightness matrix!" << endl;
    // cout << "Brightness matrix size : " << brightness_.size() << " x " << brightness_[0].size() << endl;

    // for (size_t x = 0; x < brightness_.size(); ++x)
    // {
    //     for (size_t y = 0; y < brightness_[x].size(); ++y)
    //     {
    //         cout << "avg brightness at pixel " << (x * (width) + y) << ": " << brightness_[x][y] << endl;
    //     }
    // }
    // saveBrightnessData(brightness_, "./data/brightness.txt");

    //--------------------------------------CONVERTING BRIGHTNESS TO ASCII---------------------------------------------------------------------------------
    /*
    scale: 0 - 255
           0 - 68
    for every pixel:
        float percenb = (avg brightness of pixel) / 255;
        int ascii brightness = percnb * 68
    */
    string ascii_ = "`^\\\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    vector<vector<char>> ascii_image(height, vector<char>(width));

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            float percent_ = brightness_[y][x] / 255.0f;
            int asc_index = percent_ * (ascii_.length() - 1);

            ascii_image[y][x] = ascii_[asc_index];
        }
    }

    //--------------------------------------TEST: BRIGHTNESS MATRIX---------------------------------------------------------------------------------

    // cout << "Successfully constructed ASCII matrix!" << endl;
    // cout << "Brightness matrix size : " << ascii_image.size() << " x " << ascii_image[0].size() << endl;

    // for (size_t x = 0; x < ascii_image.size(); ++x)
    // {
    //     for (size_t y = 0; y < ascii_image[x].size(); ++y)
    //     {
    //         cout << ascii_image[x][y] << endl;
    //     }
    // }

    // saveASCIIData(ascii_image, "./data/ascii.txt");

    //--------------------------------------PRINTING ASCII ART TO TERMINAL---------------------------------------------------------------------------------
    // system("clear");
    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            // cout << ascii_image[y][x] << ascii_image[y][x] << ascii_image[y][x];
            cout << ascii_image[y][x];
        }
        cout << '\n';
    }
}