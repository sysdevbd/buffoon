# buffoon
This name ever surprises you?

While my whinning for working by drilling a pointer through a sprawling lists of classes hit its verge, I gave birth to this tiny stupid parsing library. It solves my problem—now I don't need to drill a parameter down to tens of layers of classes of BSON parser to maintain a state for each mongodb client-to-server connection in [envoyproxy/envoy](https://github.com/envoyproxy/envoy). I give it the JSON-like strings that I can generate by using the outputs of BSON library and it finds any key and its value out of it.

### Buffoonism: what buffon can getchu done 🤡 
Say, you are given the following string
```json
{"opcode": "OP_QUERY", "id": 1, "response_to": 0, "flags": "0x0", "collection": "admin.$cmd", "skip": 0, "return": -1, "query": {"ismaster": 1, "helloOk": true, "client": {"application": {"name": "mongosh 2.3.0"}, "driver": {"name": "nodejs|mongosh", "version": "6.8.0|2.3.0"}, "platform": "Node.js v20.16.0, LE", "os": {"name": "linux", "architecture": "x64", "version": "3.10.0-327.22.2.el7.x86_64", "type": "Linux"}}, "compression": {"0": "none"}}, "fields": {}}
```
and, it is not guaranteed to be a valid JSON string and, as such, you can't load it as JSON using some libraries like [nlohmann/json](https://github.com/nlohmann/json) and such. Moreover, you need to check if the the key "payload" exists in the string and find its value. This is where _Buffoon_ can assist you—**Buffoonism**.
