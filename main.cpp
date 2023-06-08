/*
 * В представленном коде есть нарушение принципа открытости/закрытости (Open/Closed Principle).
 *  Принцип открытости/закрытости гласит, что программные сущности (классы, модули, функции и т.д.) должны быть открыты для расширения,
 *  но закрыты для модификации. Он помогает создавать гибкую архитектуру, которая может быть
 *  легко расширена новым функционалом без необходимости изменения существующего кода.
 *  В данном случае, класс DrwManager содержит жестко закодированные условия для рисования фигур.
 *  Когда добавляется новый тип фигуры (например, треугольник), необходимо изменять код внутри метода drawShapes,
 *  добавлять новое условие и соответствующую логику рисования. Это нарушает принцип открытости/закрытости,
 *  так как при добавлении нового типа фигуры нужно модифицировать существующий код.
 *  Для исправления этой проблемы можно применить принцип полиморфизма и использовать виртуальные функции.
 *  Вместо жестко закодированных условий для каждого типа фигуры, можно определить виртуальную функцию draw в базовом классе Shape,
 *  которую каждый дочерний класс будет переопределять по своему.
 *  Затем, в цикле drawShapes можно вызывать эту виртуальную функцию для каждого элемента в списке shapeList,
 *  и правильная реализация draw будет автоматически выбрана в соответствии с типом объекта.
*/

#include<iostream>
#include<memory>
#include <vector>
#include<list>

// Структура описывающая точку
struct Point
{
    int x;
    int y;
    Point(int _x = 0, int _y = 0) { x = _x; y = _y; }
};
// Базовый класс фигура
class Shape {
public:
    // Здесь конструкторы, геттеры и сеттеры Get / Set
    Shape(Point c) { center = c; type = "BaseFigure"; }
    virtual ~Shape() {} // Виртуальный деструктор для полиморфного удаления объектов

    std::string GetType() const { return type; }

    // Виртуальная функция рисования, будет переопределена в дочерних классах
    virtual void Draw() const = 0;

protected:
    Point center;
    std::string type;
};

class Circle : public Shape {
public:
    // Здесь конструкторы, геттеры и сеттеры Get / Set
    Circle(Point cnt, int r) : Shape(cnt) { radius = r; type = "Circle"; }

    void Draw() const override {
        std::cout << "Draw Circle!\n";
    }

private:
    int radius;
};

class Square : public Shape {
public:
    // Здесь конструкторы, геттеры и сеттеры Get / Set
    Square(Point cnt, int r) : Shape(cnt) { side = r; type = "Square"; }

    void Draw() const override {
        std::cout << "Draw Square!\n";
    }

private:
    int side;
};

class DrwManager {
private:
    std::list<std::shared_ptr<Shape>> shapeList; // Используем умные указатели для управления памятью объектов

public:
    // Здесь различные конструкторы
    DrwManager() {
        // Такая инициализация только для примера
        Point p(0, 0);
        shapeList.push_back(std::make_shared<Square>(p, 3));
        shapeList.push_back(std::make_shared<Circle>(p, 3));
    }

    // Метод рисует все фигуры из списка shapeList
    void drawShapes() {
        for (const auto& shape : shapeList) {
            shape->Draw();
        }
    }
};

/*В исправленном коде добавлен виртуальный деструктор в базовый класс Shape,
 *  чтобы обеспечить правильное удаление объектов при полиморфном использовании.
 *  Класс DrwManager теперь использует список указателей на базовый класс Shape с помощью std::unique_ptr,
 *  что позволяет автоматически управлять памятью объектов. В методе drawShapes вызывается полиморфная функция Draw,
 *  которая рисует каждую фигуру соответствующим образом, и не требует изменений при добавлении новых типов фигур.
*/
#include <iostream>
#include <string>
#include <memory>

// интерфейс Phone
class Phone {
public:
    virtual std::string getName() = 0;
};

// Абстрактный продукт Smartphone, наследующийся от Phone
class Smartphone : public Phone {
};

// Абстрактный продукт BasicPhone, наследующийся от Phone
class BasicPhone : public Phone {
};

// Абстрактная фабрика PhoneFactory
class PhoneFactory {
public:
    virtual std::shared_ptr<Smartphone> createSmartphone(std::string name) = 0;
    virtual std::shared_ptr<BasicPhone> createBasicPhone(std::string name) = 0;
};

// Конкретный продукт NokiaSmartphone, наследующийся от Smartphone
class NokiaSmartphone : public Smartphone {
    std::string name;

public:
    NokiaSmartphone(std::string name) : name(name) {}

    std::string getName() override {
        return name;
    }
};

// Конкретный продукт NokiaBasicPhone, наследующийся от BasicPhone
class NokiaBasicPhone : public BasicPhone {
    std::string name;

public:
    NokiaBasicPhone(std::string name) : name(name) {}

    std::string getName() override {
        return name;
    }
};

// Конкретный продукт SamsungSmartphone, наследующийся от Smartphone
class SamsungSmartphone : public Smartphone {
    std::string name;

public:
    SamsungSmartphone(std::string name) : name(name) {}

    std::string getName() override {
        return name;
    }
};

// Конкретный продукт SamsungBasicPhone, наследующийся от BasicPhone
class SamsungBasicPhone : public BasicPhone {
    std::string name;

public:
    SamsungBasicPhone(std::string name) : name(name) {}

    std::string getName() override {
        return name;
    }
};

// Конкретный продукт HTCSmartphone, наследующийся от Smartphone
class HTCSmartphone : public Smartphone {
    std::string name;

public:
    HTCSmartphone(std::string name) : name(name) {}

    std::string getName() override {
        return name;
    }
};

// Конкретный продукт HTCBasicPhone, наследующийся от BasicPhone
class HTCBasicPhone : public BasicPhone {
    std::string name;

public:
    HTCBasicPhone(std::string name) : name(name) {}

    std::string getName() override {
        return name;
    }
};

// Конкретная фабрика NokiaFactory, наследующаяся от PhoneFactory
class NokiaFactory : public PhoneFactory {
public:
    std::shared_ptr<Smartphone> createSmartphone(std::string name) override {
        return std::make_shared<NokiaSmartphone>(name);
    }

    std::shared_ptr<BasicPhone> createBasicPhone(std::string name) override {
        return std::make_shared<NokiaBasicPhone>(name);
    }
};

// Конкретная фабрика SamsungFactory, наследующаяся от PhoneFactory
class SamsungFactory : public PhoneFactory {
public:
    std::shared_ptr<Smartphone> createSmartphone(std::string name) override {
        return std::make_shared<SamsungSmartphone>(name);
    }

    std::shared_ptr<BasicPhone> createBasicPhone(std::string name) override {
        return std::make_shared<SamsungBasicPhone>(name);
    }
};

// Конкретная фабрика HTCFactory, наследующаяся от PhoneFactory
class HTCFactory : public PhoneFactory {
public:
    std::shared_ptr<Smartphone> createSmartphone(std::string name) override {
        return std::make_shared<HTCSmartphone>(name);
    }

    std::shared_ptr<BasicPhone> createBasicPhone(std::string name) override {
        return std::make_shared<HTCBasicPhone>(name);
    }
};

int main() {
    std::string man;
    for (int i = 0; i < 3; ++i) {
        std::shared_ptr<PhoneFactory> factory;
        std::shared_ptr<Smartphone> smartphone;
        std::shared_ptr<BasicPhone> basicPhone;

        switch (i) {
            case 0:
                factory = std::make_shared<NokiaFactory>();
                smartphone = factory->createSmartphone("Nokia Smartphone");
                basicPhone = factory->createBasicPhone("Nokia Basic Phone");
                man = "Nokia";
                break;
            case 1:
                factory = std::make_shared<SamsungFactory>();
                smartphone = factory->createSmartphone("Samsung Smartphone");
                basicPhone = factory->createBasicPhone("Samsung Basic Phone");
                man = "Samsung";
                break;
            case 2:
                factory = std::make_shared<HTCFactory>();
                smartphone = factory->createSmartphone("HTC Smartphone");
                basicPhone = factory->createBasicPhone("HTC Basic Phone");
                man = "HTC";
                break;
        }

        std::cout << "Manufacturer: " << man << "\n";
        std::cout << "Smarphone: " << smartphone->getName() << "\n";
        std::cout << "Basic phone: " << basicPhone->getName() << "\n";
    }

    return 0;
}

