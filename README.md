NUseg - A segmentation mask generating neural network
====================

NUseg is a neural network which is designed to analyse images provided in the resolution of 1024x1080 to identify specific objects in output segmentation masks. The weights for the network are stored in a .dat file as signed integers.

Based on user provided depth and width, images are passed into the network as well as segmentation masks for acting as truth values in training.

Backpropogation of the network is used in training to improve the performance. A supervisior/evaluator attempts to improve each of the weights in order to optimize the outcome for each of the training images within the model overall within. This repeats