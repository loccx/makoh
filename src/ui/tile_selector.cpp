#include "ui/tile_selector.hpp"
#include <iostream> // For debug output

void TileSelector::selectTiles(sf::Vector2f& mouseCoords, std::vector<Tile>& hand_, std::vector<Tile>& flop_) {
    std::cout << "--- Checking tile selection at (" << mouseCoords.x << ", " << mouseCoords.y << ") ---\n";

    for (auto& tile : hand_) {
        Tile* tileptr = &tile;
        if (tile.contains(mouseCoords)) {
            if (selectedHand_.find(tileptr) != selectedHand_.end()) {
                if (selectedHand_.size() < selectLimit) {
                    std::cout << "[HAND] Deselecting tile at " << tileptr << "\n";
                    selectedHand_.erase(tileptr);
                    tile.setSelected(false);
                }
            } else {
                if (selectedHand_.size() < selectLimit) {
                    std::cout << "[HAND] Selecting tile at " << tileptr << "\n";
                    selectedHand_.insert(tileptr);
                    tile.setSelected(true);
                } else {
                    std::cout << "[HAND] Selection limit (" << selectLimit << ") reached!\n";
                }
            }
        }
    }

    for (auto& tile : flop_) {
        Tile* tileptr = &tile;
        if (tile.contains(mouseCoords)) {
            if (selectedFlop_.find(tileptr) != selectedFlop_.end()) {
                if (selectedFlop_.size() < selectLimit) {
                    std::cout << "[FLOP] Deselecting tile at " << tileptr << "\n";
                    selectedFlop_.erase(tileptr);
                    tile.setSelected(false);
                }
            } else {
                if (selectedFlop_.size() < selectLimit) {
                    std::cout << "[FLOP] Selecting tile at " << tileptr << "\n";
                    selectedFlop_.insert(tileptr);
                    tile.setSelected(true);
                } else {
                    std::cout << "[FLOP] Selection limit (" << selectLimit << ") reached!\n";
                }
            }
        }
    }

    std::cout << "Current selections - HAND: " << selectedHand_.size() 
              << ", FLOP: " << selectedFlop_.size() << "\n";
}

void TileSelector::swapTiles(std::vector<Tile>& hand_, std::vector<Tile>& flop_) {
    if (!validSwap()) return;

    auto handIterator = selectedHand_.begin();
    auto flopIterator = selectedFlop_.begin();

    while (handIterator != selectedHand_.end()) {
        size_t handIndex = std::distance(&hand_[0], *handIterator);
        size_t flopIndex = std::distance(&flop_[0], *flopIterator);

        sf::Vector2f handPos = hand_[handIndex].getPosition();
        sf::Vector2f flopPos = flop_[flopIndex].getPosition();
        hand_[handIndex].setPosition(flopPos.x, flopPos.y);
        flop_[flopIndex].setPosition(handPos.x, handPos.y);

        std::swap(hand_[handIndex], flop_[flopIndex]);

        hand_[handIndex].setSelected(false);
        flop_[flopIndex].setSelected(false);

        handIterator++;
        flopIterator++;
    }
    clearSelections();
}

void TileSelector::clearSelections() {
    std::cout << "[CLEAR] Resetting selections...\n";
    for (Tile* tile : selectedHand_) {
        if (tile) {
            tile->setSelected(false);
            std::cout << "[CLEAR] Deselected HAND tile at " << tile << "\n";
        }
    }
    for (Tile* tile : selectedFlop_) {
        if (tile) {
            tile->setSelected(false);
            std::cout << "[CLEAR] Deselected FLOP tile at " << tile << "\n";
        }
    }
    selectedHand_.clear();
    selectedFlop_.clear();
}

bool TileSelector::validSwap() const {
    bool isValid = !selectedHand_.empty() && (selectedHand_.size() == selectedFlop_.size());
    if (!isValid) {
        std::cout << "[VALIDATION] Swap check failed: ";
        if (selectedHand_.empty()) std::cout << "No HAND tiles selected. ";
        if (selectedHand_.size() != selectedFlop_.size()) {
            std::cout << "Selection count mismatch (HAND: " << selectedHand_.size() 
                      << ", FLOP: " << selectedFlop_.size() << ")";
        }
        std::cout << "\n";
    }
    return isValid;
}