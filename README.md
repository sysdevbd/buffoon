# buffoon
This name ever surprises you?

While my whinning for working by drilling a pointer through a sprawling lists of classes hit its verge, I gave birth to this tiny stupid parsing library. It solves my problem—now I don't need to drill a parameter down to tens of layers of classes of BSON parser to maintain a state for each mongodb client-to-server connection in [envoyproxy/envoy](https://github.com/envoyproxy/envoy). I give it the JSON-like strings that I can generate by using the outputs of BSON library and it finds any key and its value out of it.


