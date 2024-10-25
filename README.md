# buffoon
This name ever surprises you?

While my whinning for working by drilling a pointer through a sprawling lists of classes hit its verge, I gave birth to this tiny stupid parsing library. It solves my problem—now I don't need to drill a parameter down to tens of layers of classes of BSON parser to maintain a state for each mongodb client-to-server connection in [envoyproxy/envoy](https://github.com/envoyproxy/envoy). I give it the JSON-like strings that I can generate by using the outputs of BSON library and it finds any key and its value out of it.

### Buffoonism: what buffoon can getchu done 🤡 
Say, you are given the following string
```json
{"opcode": "OP_QUERY", "id": 1, "response_to": 0, "flags": "0x0", "collection": "admin.$cmd", "skip": 0, "return": -1, "query": {"ismaster": 1, "helloOk": true, "client": {"application": {"name": "mongosh 2.3.0"}, "driver": {"name": "nodejs|mongosh", "version": "6.8.0|2.3.0"}, "platform": "Node.js v20.16.0, LE", "os": {"name": "linux", "architecture": "x64", "version": "3.10.0-327.22.2.el7.x86_64", "type": "Linux"}}, "compression": {"0": "none"}}, "fields": {}}
```
and, it is not guaranteed to be a valid JSON string and, as such, you can't load it as JSON using some libraries like [nlohmann/json](https://github.com/nlohmann/json) and such. Moreover, you need to check if the the key "payload" exists in the string and find its value. This is where _Buffoon_ can assist you—**Buffoonism**.

### How to use it?
#### A. Without any build system
So far, _Buffoon_ is a single header library with only a single implementation file (.cc). We can build the object file directly and link it with our programs.
1. Build the object file
   ```bash
   $ g++ -c -I ./  buffoon.cc -o buffoon.o
   ```
2. Include the header file (_buffoon.h_) in your program to use the library. Below is a sample program file. Let's call it _main.cc_.
   ```cpp
    #include "buffoon.h"
    #include <string>
    #include <iostream>
    
    int main() {
      std::string str = "{\"payload\": \"value\"}";
      
      const auto payload = Buffoon::Buffoon::findValueByKey(str, "payload");
      if(payload.empty()) {
          std::cout << "payload not found\n";
      }
      else {
          std::cout << payload << std::endl;
      }
      
      return 0;   
    }
   ```
3. Build your program linking with object file we built in step 1 and run it.
   ```bash
   $ g++ main.cc buffoon.o -o main
   $ ./main
   value
   ```
#### B. Using with Bazel
##### Use by cloning the repo
1. Clone the repo; say, in /home/user/
2. Add the repo to the WORKSPACE file of your existing bazel project like the following:
   ```
   local_repository(
    name = "buffoon",
    path = "/home/user/buffoon",  # Absolute or relative path to buffoon repo in your machine
   )
   ```
3. Refer this buffoon in your target BUILD file. Sample:
   ```
   cc_binary(
    name = "prog",
    srcs = ["main.cc"],
    deps = [
        "@buffoon//:buffoon"
         ]
   )
   ```
##### Use it by fetching as a remote git repository
It is quite similar to the above discussed method except that you add it in your **WORKSPACE** file as a git repository:
```
git_repository(
    name = "buffoon",
    remote = "https://github.com/sysdevbd/buffoon.git",
    branch = "main",
)
```
##### Use it as a remote http_archive
Please refer to [Use by cloning the repo](Use-by-cloning-the-repo) except that in step 2, instead of local repository we add this repo as a remote `http_archive` from Github release. Add this in your **WORKSPACE** file:

```
http_archive(
    name = "buffoon",
    urls = ["https://github.com/sysdevbd/buffoon/archive/refs/tags/v1.0.tar.gz"],
    strip_prefix = "buffoon-1.0",
    sha256 = "9f8cf50ec49cbe570732dcbdc27ca24ac973a7b954da510a5a8e06ed73a9692b",
)
```


#### C. Using CMake
##### Easiest way
Download/build `libbuffoon.a`/`libbuffoon.so` for a release. Then, link it in your existing cmake project this way:
```cmake
# find the library file
find_library(BUFFOON buffoon paths <path-to-libbuffoon.so>)

# link the library with your executable
target_link_libraries(<executable> PUBLIC ${BUFFOON})

# don't forget to include the header
target_include_directories(<executable> PUBLIC <path-to-buffoon.h>)
```
