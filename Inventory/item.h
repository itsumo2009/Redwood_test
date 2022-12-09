#pragma once

#include <QString>

class Item
{
public:
    enum Type
    {
        APPLE
    };
public:
    Item() : _image(":/apple_256px.png"), _type(APPLE) { }

public:
    const QString& image() const { return _image; }
    Type type() const { return _type;}

private:
    const QString _image;
    const Type _type;
};
