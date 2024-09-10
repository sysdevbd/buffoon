#pragma once

#include <string>


namespace Buffoon {
  class Buffoon {
  public:
      /**
       * method to find the value keyed by "payload" from JSON-like string
       * @param json_like_string, key(unquoted key)
       * @return payload (null string if "payload" key is not found)
       */
      static std::string findValueByKey(const std::string& json_like_string, const std::string& key);
      /**
       * method to find username (only applicable for mongo client login messages)
       * @param payloadValue
       * @return username
       */
      static std::string findUsername(const std::string& payload_value);
  };
} // namespace Buffoon
