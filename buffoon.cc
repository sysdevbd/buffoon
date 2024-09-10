#include "buffoon.h"
#include <regex>

namespace Buffoon {

    std::string Buffoon::findValueByKey(const std::string &json_like_string, const std::string &key) {
      std::regex key_value_pattern("\"" + key + R"("\s*:\s*("[^"]*"|\d+|\-?\d+\.\d+|true|false|null))");
      std::smatch match;

      if (std::regex_search(json_like_string, match, key_value_pattern)) {
        std::string value = match[1].str();

        // If value is inside quotes, strip them
        if (value.front() == '"' && value.back() == '"') {
          return value.substr(1, value.length() - 2);
        }

        return value;  // return the value as is (for numeric, boolean, or null)
      }

      return "";
    }

    std::string Buffoon::findUsername(const std::string &payload_value) {
      size_t nPos = payload_value.find("n=");
      if (nPos != std::string::npos) {
        nPos += 2;
        size_t commaPos = payload_value.find(',', nPos);

        return payload_value.substr(nPos, commaPos - nPos);
      }
      return "";
    }
} // namespace Buffoon
