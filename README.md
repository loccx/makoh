deck: 144 tiles
    36 tong : 4x 1-9
    36 bamboo : 4x 2-9
    36 wan : 4x 1-9
    16 ESWN : 4x
    12 dragons : 4x red, green, white
        zhong, fu, bai pi
    8 flowers : 2x 1-4

init deal 13 tiles

flip 5 tiles at a time
    pick up to 3? or something
rest is discarded

swap until you declare a win
you only get a certain # of swaps

features:
tiles should make combos
    be able to distinguish between types and values of tiles quickly


design doc:

class Tile:
public:
    enum Type; // tong, wan, tiao, wind, dragon, flower
    int number; // if type == tong/wan/tiao , or flower
    enum direction; // if type == wind
    enum dragon; // if type == dragon

mahjong hand features:
quickly detect sequences and 3 of a kind
efficiently swap out tiles

game flow:
press button to deal hand
    callback to deal hand
deck lays out 5 tiles
select up to 3 tiles to swap out
    callback to deal spread
button to submit hand
    callback to submit
return point count

deck needs:
    keep track of count, and if empty, change sprite

hand needs:
    keep track of combinations
    keep track of winning or not


animation manager??
move_tile_to(Tile tile,vector2f destination, float time);
discard_tile(Tile tile);

was considering making tilecontainer but that seems to be overengineering;
    i think i only need the flop and the hand

using vector over unorderedset for some of these operations since linear scan on such small sets of data should be faster than the constant overhead of hashing

optimize tile selection with bitset viable tbh

TODO:
done - swap once per flop, flp resets after swap
scoring button, get score and evaluate beauty of the hand
    hand rn is just vector
    score can be calculated .......

idea 1:
    traditional 3 x 3 x 3 x 2 scoring check
    design this ^ to be scalable to idea 2

idea 2:
    longest straight >= 3, many types of same kind >= 3, whatever

1. check 3x3x3x2
2. check types of straights and 3 of a kind for the win


scoring design ideas:
unordered set of types?
    type counter works for quick flush checks
unordered_map check?

lowkey you can just sort the vector... it's like 13 tiles