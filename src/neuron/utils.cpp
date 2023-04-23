#include "./utils.hpp"

using namespace cocos2d;

// haha yoinked the code from cvolton haha

std::string neuron::decodeBase64Gzip(const std::string& input) {
        unsigned char* levelString;
        unsigned char* levelStringFull;
        int levelStringSize = base64Decode((unsigned char *)(input.c_str()), input.size(), &levelString);
        int levelStringSizeDeflated = ZipUtils::ccInflateMemory(levelString, levelStringSize, &levelStringFull);

        if (levelStringSizeDeflated <= 0) {
            throw std::runtime_error("gzip failed lol");
        }

        std::string levelStringFullStd((char*)levelStringFull, levelStringSizeDeflated);

        delete levelString;
        delete levelStringFull;

        return levelStringFullStd;
}
