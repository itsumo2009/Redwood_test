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
    ///
    /// \brief image Изображение предмета
    /// \return Путь в ресурсах к изображению предмета.
    ///
    const QString& image() const { return _image; }
    ///
    /// \brief type Тип предмета
    /// \return Тип предмета
    ///
    Type type() const { return _type;}

private:
    const QString _image;
    const Type _type;
};
