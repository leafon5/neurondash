#pragma once

#include "../includes.h"

#include "support/base64.h"
#include "support/zip_support/ZipUtils.h"

namespace neuron {
    std::string decodeBase64Gzip(const std::string& input);
}