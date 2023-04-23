#include "GameLevel.hpp"

namespace neuron {

    // i will finish this later
    
    GameLevel::GameLevel(gd::GJGameLevel* level, bool isOfficial) {
        this->isOfficial = isOfficial;
        this->decodeLevel(level->levelString);
    }
    void GameLevel::decodeLevel(gd::string levelstring) {
        std::string decodedString = decodeBase64Gzip(levelstring.to_str());

        std::cout << decodedString << std::endl;

        return;
    }
}