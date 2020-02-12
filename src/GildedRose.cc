#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> &items) : items(items) {}

void GildedRose::updateQuality() {

    for (auto &item : items) {
        if (item.name == "Aged Brie")
        {
            item.increaseQuality();
            item.decreaseSellIn();
            if (item.sellIn < 0) {
                item.increaseQuality();
            }
        } else if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
            if (item.quality < MAX_QUALITY) {
                if(item.sellIn <=5) {
                    item.increaseQuality( 3);
                }
                else if(item.sellIn <=10) {
                    item.increaseQuality( 2);
                }
                else{
                    item.increaseQuality();
                }
            }
            item.decreaseSellIn();
            if (item.sellIn < 0) {
                item.quality = 0;
            }
        } else if (item.name == "Sulfuras, Hand of Ragnaros") {

        } else {
            item.updateQuality();
        }
    }
}

void Item::increaseQuality(const int value)
{
    if (quality < MAX_QUALITY) {
        quality = min(quality + value, MAX_QUALITY);
    }
}

void Item::decreaseSellIn() {
    sellIn = sellIn - 1;
}

void Item::decreaseQuality() {
    if (quality > 0) {
        quality = quality - 1;
    }
}

void Item::updateQuality() {
    decreaseQuality();
    decreaseSellIn();
    if (sellIn < 0) {
        decreaseQuality();
    }
}

void Sulfuras::updateQuality() {
}

void AgedBrie::updateQuality() {
    increaseQuality();
    decreaseSellIn();
    if (sellIn < 0) {
        increaseQuality();
    }
}

void Backstage::updateQuality() {
    if (quality < MAX_QUALITY) {
        if(sellIn <=5) {
            increaseQuality( 3);
        }
        else if(sellIn <=10) {
            increaseQuality( 2);
        }
        else{
            increaseQuality();
        }
    }
    decreaseSellIn();
    if (sellIn < 0) {
        quality = 0;
    }
}

