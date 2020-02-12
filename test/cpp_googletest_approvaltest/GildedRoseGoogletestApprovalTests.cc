// Include header files for test frameworks 
#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

// Include code to be tested
#include "GildedRose.h"

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
        << "name: " << obj.name
        << ", sellIn: " << obj.sellIn
        << ", quality: " << obj.quality;
}

TEST(GildedRoseApprovalTests, VerifyCombinations) {

    std::vector<string> names { "Foo", "Aged Brie", "Backstage passes to a TAFKAL80ETC concert", "Sulfuras, Hand of Ragnaros" };
    std::vector<int> sellIns { 1, -1, 10, 11, 12, 5, 6, 7, 0 };
    std::vector<int> qualities { 1, 0, -1, 49, 50, 51 };

    auto f = [](string name, int sellIn, int quality) {
        vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            names, sellIns, qualities);

}
