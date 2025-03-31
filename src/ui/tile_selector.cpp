#include "ui/tile_selector.hpp"

void TileSelector::selectTiles(sf::Vector2f& mouseCoords, std::vector<Tile>& hand_, std::vector<Tile>& flop_) {
    for (auto& tile : hand_) {
        Tile* tileptr = &tile;
        if (tile.contains(mouseCoords)) {
            if ((selectedHand_.find(tileptr) != selectedHand_.end()) && (selectedHand_.size() < selectLimit)) {
                selectedHand_.erase(tileptr);
            }
            else {
                selectedHand_.insert(tileptr);
            }
        }
    }
    for (auto& tile : flop_) {
        Tile* tileptr = &tile;
        if (tile.contains(mouseCoords)) {
            if ((selectedFlop_.find(tileptr) != selectedFlop_.end()) && (selectedFlop_.size() < selectLimit)) {
                selectedFlop_.erase(tileptr);
            }
            else {
                selectedFlop_.insert(tileptr);
            }
        }
    }
}

void TileSelector::swapTiles(std::vector<Tile>& hand_, std::vector<Tile>& flop_) {
    if (!validSwap()) return;

    auto handIterator = selectedHand_.begin();
    auto flopIterator = selectedFlop_.begin();

    while (handIterator != selectedHand_.end()) {
        if (!*handIterator || !*flopIterator) {
            throw std::runtime_error("Null pointer selected during swap!");
        }
        std::swap(**handIterator, **flopIterator);

        (*handIterator)->setSelected(false);
        (*flopIterator)->setSelected(false);

        handIterator++;
        flopIterator++;
    }

    clearSelections();
}

void TileSelector::clearSelections() {
    for (Tile* tile : selectedHand_) {
        if (tile) tile->setSelected(false);
    }
    for (Tile* tile : selectedFlop_) {
        if (tile) tile->setSelected(false);
    }
    selectedHand_.clear();
    selectedFlop_.clear();
}

bool TileSelector::validSwap() const {
    return !selectedHand_.empty() && (selectedHand_.size() == selectedFlop_.size());
}