#include <SFML/Graphics.hpp>
#include <iostream>
#include "huffman.h"
using namespace std;
using namespace sf;

int main()
{
    Image photo;
    if (!photo.loadFromFile("sample.png"))
        return -1;

    Vector2<unsigned int> size = photo.getSize();
    HuffmanTree<int> t;
    HashMap<int> hf;
    int height = size.y, width = size.x;
    Color **photoArr = new Color *[width];
    for (int i = 0; i < width; i++)
        photoArr[i] = new Color[height];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
            photoArr[i][j] = photo.getPixel(i, j);
    }

    // bool **arr = new bool *[width];
    // for (int i = 0; i < width; i++)
    //     arr[i] = new bool[height];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Color temp = photoArr[i][j];
            int vals[3] = {temp.r, temp.g, temp.b};

            if (hf.search(vals))
            {
                // cout << "a";
                int *freq = hf.search(vals);
                hf.insert(vals, *(freq) + 1);
            }
            else
                hf.insert(vals, 1);
        }
    }

    // RenderWindow window(VideoMode(200, 200), "SFML works!");
    // CircleShape shape(100.f);
    // shape.setFillColor(Color::Green);

    // while (window.isOpen())
    // {
    //     Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    return 0;
}