#include <string>
#include <vector>

static const int MAX_QUALITY = 50;
using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}

    virtual void updateQuality();

    void increaseQuality(const int value = 1);
    void decreaseQuality();
    void decreaseSellIn();
};

class Sulfuras : public Item
{
public:
    Sulfuras(int sellIn, int quality) :  Item("Sulfuras, Hand of Ragnaros", sellIn, quality)
    {}
    virtual void updateQuality() override;
};

class AgedBrie : public Item
{
public:
    AgedBrie(int sellIn, int quality) :  Item("Aged Brie", sellIn, quality)
    {}
    virtual void updateQuality() override;
};

class Backstage : public Item
{
public:
    Backstage(int sellIn, int quality) :  Item("Backstage passes to a TAFKAL80ETC concert", sellIn, quality)
    {}
    virtual void updateQuality() override;
};


class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
};

