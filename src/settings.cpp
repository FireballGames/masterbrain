#include "settings.hpp"

#include <SFML/Graphics.hpp>

sf::String gameTitle = "Master Brain";
int winSize[2] = {800, 600};
// int winSize[2] = {256, 192};

const int M = 256;
const int N = 192;
int boxPos[2] = {(winSize[0] - M)/2, (winSize[1] - N)/2};
int boxSize[2] = {M, N};

sf::String cardSetFile = "res/cardset.bmp";
