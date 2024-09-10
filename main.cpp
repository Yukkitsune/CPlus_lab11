#include <iostream>

class point {
private:
    double x, y;
public:
    point(double x, double y) { // Конструктор для инициализации полей
        this->x = x;
        this->y = y;
    }
    virtual void print() { // Метод для печати полей
        std::cout << "\nx = " << x << " y = " << y;
    }
};
class point_3d :public point { // Класс наследник точка в пространстве
private:
    double z; 
public:
    point_3d(double x, double y, double z) : // Конструктор
        point(x, y) { // Конструктор базового класса
        this->z = z;
    }
    void print() { // Переопределенный метод печати
        point::print();
        std::cout << " z = " << z;
    }
};
int main()
{
    double x, y, z; // Координаты
    std::cout << "Enter x coordinate: ";
    std::cin >> x;
    std::cout << "Enter y coordinate: ";
    std::cin >> y;
    std::cout << "Enter z coordinate: ";
    std::cin >> z;
    point first(x, y); // Объекты классов
    point_3d second(x, y, z);
    point* p;
    
    /*
    Программа решает на этапе выполнения, какую функцию вызывать
    Выбор переопределенного метода обусловлен типом объекта
    При этом переопределенный метод с virtual
    Создается таблица виртуальных функций со скрытым указателем на неё
    */
    std::cout << "Dynamic polymorphism: " << std::endl;
    p = &first; // Динамический полиморфизм
    std::cout << "Point of plate: ";
    p->print();
    std::cout << std::endl;
    p = &second;
    std::cout << "Point in space: ";
    p->print();
    std::cout << std::endl;
    std::cout << "----------" << std::endl;

    /*
    Вызовы функций фиксируются на этапе компиляции
    Когда указатель одного типа ссылается на объект
    другого типа при наследовании классов, то выбор переопределенного метода
    определяется типом указателя, а не типом объекта
    */
    std::cout << "Static polymorphism: " << std::endl;
    std::cout << "Point of plate: "; // Статический полиморфизм
    first.print();
    std::cout << std::endl;
    std::cout << "Point in space: ";
    second.print();
    return 0;
}
