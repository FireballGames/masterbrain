#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

sf::String gameTitle = "Master Brain";
 int winSize[2] = {800, 600};
// int winSize[2] = {256, 192};

const int M = 256;
const int N = 192;
int boxPos[2] = {(winSize[0] - M)/2, (winSize[1] - N)/2};
int boxSize[2] = {M, N};
// int pointSize[2] = {18, 18};
int fps = 60;

int backgroundsCount = 10;
sf::String backgrounds[10] = {
    "res/background/1.png",
    "res/background/2.png",
    "res/background/3.png",
    "res/background/4.png",
    "res/background/5.png",
    "res/background/6.png",
    "res/background/7.png",
    "res/background/8.png",
    "res/background/9.png",
    "res/background/10.png",
};

int logoTitlePos[2] = {boxPos[0], boxPos[1]};
sf::String logoTitle = "res/title.bmp";

int logoCreditsPos[2] = {boxPos[0], boxPos[1] + N - 40};
sf::String logoCredits = "res/credits.bmp";

sf::String fontFile = "res/zx_spectrum-7.ttf";
int fontSize = 24;
sf::Color fontColor = sf::Color::Yellow;

sf::String cardSetFile = "res/cardset.bmp";


int blocksCount = 1000;
int blockCols = 10;
int blockRows = 10;
int blockW = 43;
int blockH = 20;
int posNowhere[2] = {-100, 0};
sf::String blocks[5] = {
    "res/block01.png",
    "res/block02.png",
    "res/block03.png",
    "res/block04.png",
    "res/block05.png",
};

int ballPos[2] = {300, 300};
int ballSpeed[2] = {6, 5};
int paddlePos[2] = {300, 440};

sf::String ball = "res/ball.png";
sf::String paddle = "res/paddle.png";

// sf::String interface = "res/frame.png";

int level = 2;
int cardSetId = 1;
bool sound = true;
bool cardMove = false;

sf::String cardSets[4] = {
    "NUMBERS",
    "SPECTRUM HEROES",
    "KIDS",
    "COLOUR MASTER",
};

#endif // SETTINGS_HPP_INCLUDED
