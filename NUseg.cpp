/*
 * This file is part of NUbots Codebase.
 *
 * The NUbots Codebase is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The NUbots Codebase is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the NUbots Codebase.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2015 NUbots <nubots@nubots.net>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>

std::list<std::list<int>> run(std::list<float> weights);

int main()
{
    std::cout << "[NUseg] : Started" << std::endl;

    uint32_t epochs = 0;
    while (epochs < 1)
    {
        std::cout << "[NUseg] : Number of epochs to run $ ";
        std::cin >> epochs;
        if (epochs < 1) std::cout << "[NUseg] [ERROR] : Inappropriate value!" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "[NUseg] : Allocating memory for each of the datasets as doubly linked lists (starting empty)" << std::endl;
    std::list<std::list<int>> train; // A doubly-linked list of doubly linked lists (after loading the images the internal linked list should be of size 1105920 for each pixel brightnesss in a 1024x1080 image)
    std::list<std::list<int>> truth;

    std::cout << "[NUseg] : Loading the model from weights.dat" << std::endl;
    std::list<float> model;
    
    std::ifstream weightsFile{"weights.dat"};
    if (!weightsFile) std::cout << "[NUseg] [404 - ERROR] : The file weights.dat does not exist!" << std::endl;

    while (weightsFile)
    {
        float weight;
        weightsFile >> weight;
        model.emplace_back(weight);
        std::cout << weight << std::endl;
    }


    //TODO Load model and weights w/ error message if the file does not exist

    std::cout << "[NUseg] : Running the loaded model through " << epochs << " epochs!" << std::endl;
    std::list<std::list<int>> genSegmasks = run(model);
    //TODO Run the model weights for the training data and produce another linked list named generatedSegmasks

    for (int cEpoch = 1; cEpoch <= epochs; cEpoch++)
    {
        std::cout << "[NUseg] [Epoch " << cEpoch << "] : Analyzing model performance against truth segmentation masks..." << std::endl;
        float performance = 0; // min 0, max 100 ... This will be a percentage representing the performance of the model in each batch analyzed

        std::cout << "[NUseg] [Epoch " << cEpoch << "] : Performance of current model after analysis " << performance << "% (against provided truth)" << std::endl;

        std::cout << "[NUseg] [Epoch " << cEpoch << "] : Backpropagating the current model" << std::endl;
    }

    std::cout << "[NUseg] : Training complete!" << std::endl;
    std::cout << "[NUseg] : Analyzing model performance against truth segmentation masks..." << std::endl;
    float performance = 0; // min 0, max 100 ... This will be a percentage representing the performance of the model in each batch analyzed

    std::cout << "[NUseg] : Final performance of current model after analysis " << performance << "% (against provided truth)" << std::endl;

    return 0;
}

std::list<std::list<int>> run(std::list<float> weights)
{
    return std::list<std::list<int>>();
}