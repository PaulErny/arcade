/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLMenu
*/

#include "SFMLMenu.hpp"

SFMLMenu::SFMLMenu(SFMLLib *lib)
{
    this->graphics = lib;
}

SFMLMenu::~SFMLMenu()
{
}

int SFMLMenu::menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
{
    int bgID = graphics->createImageFromFile("resources/background.png");
    int fontID = graphics->createFontFromFile("resources/ARCADE_I.TTF");

    int nibblerImgID = graphics->createImageFromFile("games/nibbler/preview.jpg");
    int pacmanImgID = graphics->createImageFromFile("games/pacman/preview.png");

    // create play btn
    this->buttons.push_back(graphics->createText("PLAY", fontID));
    graphics->setTextCharSize(this->buttons[0], 50);
    graphics->setTextPos(this->buttons[0], 440, 760);

    // create highscore btn
    this->buttons.push_back(graphics->createText("Highscores", fontID));
    graphics->setTextCharSize(this->buttons[1], 20);
    graphics->setTextPos(this->buttons[1], 440, 860);

    // creates games btn
    std::vector<int> gamesNamesID;
    for (int i = 0; i < gamesNames.size(); i++)
        this->buttons.push_back(graphics->createText(gamesNames[i], fontID));
    graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);

    graphics->setImagePos(pacmanImgID, 355, 590);
    graphics->setImagePos(nibblerImgID, 592, 590);
    
    int xPos = 335;
    for (int i = 2; i < gamesNames.size() + 2; i++) { // i = 2 bcs i=0 is the play btn and i=1 is highscores btn
        graphics->setTextPos(this->buttons[i], xPos, 548);
        xPos += 220;
    }

    // create high scores
    std::vector<std::vector<std::string>>::iterator it;
    std::vector<std::vector<int>> scoreTextID;
    xPos = 335;
    int yPos = 625;
    int j = 0;
    for (it = highScores.begin(); it < highScores.end(); it++) {
        scoreTextID.resize(j+1);
        for (int i = 0; i < it->size(); i++) {
            scoreTextID[j].push_back(graphics->createText(highScores[j][i], fontID));
            graphics->setTextPos(scoreTextID[j][i], xPos, yPos);
            graphics->setTextCharSize(scoreTextID[j][i], 13);
            yPos += 35;
        }
        j++;
        yPos = 625;
        xPos += 220;
    }

    bool isHighscoresMenu = false;

    this->getPseudo(pgState, pseudo, bgID, fontID);

    while (graphics->isWindowOpen()) {
        while (graphics->events()) {
            if (graphics->closeWindowEvent())
                pgState = NOTHING;
            if (graphics->keyReleasedEvent())
                this->isKeyDown = false;
        }
        graphics->clearWindow();
        // check btn
        if (this->chosenGame == -1)
            this->chooseGame();
        else {
            if (!isHighscoresMenu)
                this->rechoose();
            if (this->chosenAction == -1) {
                this->chooseAction();
                if (this->chosenAction == 1)
                    isHighscoresMenu = true;
            }
        }
        
        graphics->drawImage(bgID);
        if (this->chosenAction == -1) {
            // draw buttons
            for (int i = 0; i < this->buttons.size(); i++)
                graphics->drawText(this->buttons[i]);
            graphics->drawImage(pacmanImgID);
            graphics->drawImage(nibblerImgID);
        } else if (this->chosenAction == 0) {
            pgState = GAME;
            return (this->chosenGame);
        } else if (this->chosenAction == 1) {
            this->displayHighScores(scoreTextID, this->buttons, isHighscoresMenu);
        }
        graphics->update();
    }
    graphics->deleteFont(fontID);
    graphics->deleteImage(bgID);
    return (-1);
}

void SFMLMenu::chooseGame()
{
    graphics->setTextColor(this->buttons[this->currentBtn], 255, 255, 255);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->isKeyDown = true;
        if (this->currentBtn < this->buttons.size() - 1)
            this->currentBtn++;
        else
            this->currentBtn = 2;
    }
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->isKeyDown = true;
        if (this->currentBtn > 2)
            this->currentBtn--;
        else
            this->currentBtn = this->buttons.size() - 1;
    }
    graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        graphics->setTextColor(this->buttons[this->currentBtn], 30, 230, 30);
        this->isKeyDown = true;
        this->chosenGame = this->currentBtn - 2;
        this->currentBtn = 0;
        graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);
        return;
    }
    this->chosenGame = -1;
}

void SFMLMenu::rechoose()
{
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && this->chosenGame != -1) {
        this->isKeyDown = true;
        graphics->setTextColor(this->buttons[this->currentBtn], 255, 255, 255);
        graphics->setTextColor(this->buttons[2 + this->chosenGame], 230, 230, 0);
        this->currentBtn = 2 + chosenGame;
        this->chosenGame = -1;
    }
}

void SFMLMenu::chooseAction()
{
    graphics->setTextColor(this->buttons[this->currentBtn], 255, 255, 255);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->isKeyDown = true;
        if (this->currentBtn < 1)
            this->currentBtn++;
        else
            this->currentBtn = 0;
    }
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->isKeyDown = true;
        if (this->currentBtn > 0)
            this->currentBtn--;
        else
            this->currentBtn = 1;
    }
    graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        this->isKeyDown = true;
        this->graphics->setTextColor(this->buttons[this->currentBtn], 30, 230, 30);
        this->chosenAction = this->currentBtn;
        return;
    }
    this->chosenAction = -1;
}

void SFMLMenu::displayHighScores(std::vector<std::vector<int>> scoreTextID, std::vector<int> gamesNamesID, bool &isHighscoresMenu)
{
    // draw games high scores
    int i = 0;

    graphics->drawText(gamesNamesID[this->chosenGame + 2]);
    for (i = 0; i != this->chosenGame && i < scoreTextID.size(); i++);
    for (int j = 0; j < scoreTextID[i].size(); j++) {
        graphics->drawText(scoreTextID[i][j]);
    }
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        this->isKeyDown = true;
        graphics->setTextColor(gamesNamesID[1], 230, 230, 0);
        this->chosenAction = -1;
        isHighscoresMenu = false;
    }
}

void SFMLMenu::getPseudo(state pgState, std::string &pseudo, int bgID, int fontID)
{
    sf::Event event;
    int textID = graphics->createText("enter your name :", fontID);
    int pseudoID = graphics->createText(pseudo, fontID);

    graphics->setTextPos(textID, 380, 660);
    graphics->setTextCharSize(textID, 20);
    graphics->setTextPos(pseudoID, 440, 700);

    while (graphics->isWindowOpen()) {
        while (graphics->events()) {
            if (graphics->closeWindowEvent())
                pgState = NOTHING;
            event = graphics->getEvt();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && !this->isKeyDown) {
                    this->isKeyDown = true;
                    if (event.text.unicode == 13 || event.text.unicode == 10) { // enter key
                        return;
                    } else if (event.text.unicode == 8) { // backspace
                        if (pseudo.size() > 0) 
                            pseudo.resize(pseudo.size() - 1);
                    } else {
                        pseudo += static_cast<char>(event.text.unicode);
                    }
                }
            } else if (event.type == sf::Event::KeyReleased) {
                this->isKeyDown = false;
            }
        }
        graphics->clearWindow();

        graphics->setTextString(pseudoID, pseudo);
        graphics->drawImage(bgID);
        graphics->drawText(textID);
        graphics->drawText(pseudoID);

        graphics->update();
    }
}