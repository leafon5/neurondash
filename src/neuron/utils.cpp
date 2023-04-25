#include "./utils.hpp"

using namespace cocos2d;

// haha yoinked the code from cvolton haha

std::string neuron::decodeBase64Gzip(const std::string& input) {
    unsigned char* levelString;
    unsigned char* levelStringFull;
    int levelStringSize = base64Decode((unsigned char *)(input.c_str()), input.size(), &levelString);
    int levelStringSizeDeflated = ZipUtils::ccInflateMemory(levelString, levelStringSize, &levelStringFull);

    if (levelStringSizeDeflated <= 0) {
        std::cout << "epic gamer fail" << std::endl;
        throw std::runtime_error("gzip failed lol");
    }

    std::vector<unsigned char> levelStringFullVec(levelStringFull, levelStringFull + levelStringSizeDeflated);
    std::string levelStringFullStd(levelStringFullVec.begin(), levelStringFullVec.end());

    delete[] levelString;
    delete[] levelStringFull;

    return levelStringFullStd;
}