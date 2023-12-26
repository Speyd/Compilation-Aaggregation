#include <iostream>
#include <initializer_list>
#include <list>
using namespace std;

//Aaggreagation class example
#pragma region AaggreagationClass

const int sizeVector{ 2 }, amountPoint{ 2 };

template <typename T>
class Point
{
private:

    T x;
    T y;

public:

    Point(const T xP, const T yP) : x{ xP }, y{ yP } {}

    Point() : Point(0, 0){}

    T getX()const { return x; }
    T getY()const { return y; }

    ~Point() { x = 0; y = 0; }

};

template <typename T>
class Vector
{
private:
    Point<T> points[sizeVector];

public:

    Vector(const initializer_list<T> pointsP)
    {
        int count{ 1 }, allAmountPoint{ sizeVector * amountPoint };
        T tempValue{};

        for (T i : pointsP)
        {
            if (count % 2 == 0 && count <= allAmountPoint)points[count / 2 - 1] = Point<T>{ tempValue, i };
            else if (count > allAmountPoint)break;

            tempValue = i; count++;
        }

        if(count < allAmountPoint)
        {
            for (; count <= allAmountPoint; count++)
            {
                if (count % 2 == 0)points[count - 2] = Point<T>{ 0, 0 };
            }
        }
    }

    Vector(const T fisrtX, const T firstY, const T secondX, const T secondY)
    {
        //cout << "g";
        points[0] = Point<T>{ fisrtX, firstY };
        points[1] = Point<T>{ secondX, secondY };
    }

    Vector() : Vector{0, 0, 0, 0}{}

    void print() const;
};

template <typename T>
void Vector<T>::print()const
{
    int countingPoints{ 1 };
    for (Point<T> point : points)
    {
            cout << countingPoints++ << "-th point: (x:" << point.getX() << "; y: " << point.getY() << ')' << endl;
    }
}

template <typename T>
class Figure
{
private:

    list<Point<T>> points;

public:

    Figure(const initializer_list<T> pointsP)
    {
        int count{ 1 };
        const size_t size{ pointsP.size() };
        T tempValue{};
        for(T i : pointsP)
        {
            if (count % 2 == 0)points.push_back(Point<T>{ tempValue, i });
            else if(size == count)points.push_back(Point<T>{ i, 0 });
            tempValue = i;
            count++;
        }
    }

    Figure(const list<Point<T>>& pointsP) : points{ pointsP } {}

    Figure(const list<Point<T>>&& pointsP) = delete;

    ~Figure() { points.clear(); }

    void print()const;


};

template <typename T>
void Figure<T>::print()const
{
    if (points.size() == 0) cout << "No points!" << endl;
    else
    {
        int countingPoints{ 1 };
        for(Point<T> point : points)
        {
            cout << countingPoints++ << "-th point: (x:" << point.getX() << "; y: " << point.getY() << ')' << endl;
        }
    }
}
#pragma endregion

//Compilation class example
#pragma region CompilationClass

enum Direction
{
    None,
    Up,
    Down,
    Right,
    Left
};

class Human
{
private:

    string name;

    class Heart
    {
    private:

        int pulse;
        float length;

    public:

        Heart(const int pulseP, const float lengthP) 
            : pulse{ pulseP }, length{ lengthP }
        {}

        Heart() = delete;

        void printCharacteristics() const
        {
            cout << "Pulse: " << pulse << endl 
                 << "Length heart: " << length << " centimeters" << endl;
        }
    
    };
    Heart heart;

    class Hand
    {
    private:

        Direction direction;
        float length;

        string definitionDirection(Direction direction) const
        {
            if (direction == 0)return "None";
            else if (direction == 1)return "Up";
            else if (direction == 2)return "Down";
            else if (direction == 3)return "Right";
            else if (direction == 4)return "Left";
            else return "None";
        }

    public:

        Hand(const Direction directionP, const float lengthP)
             : direction{ directionP }, length{ lengthP }
        {}

        Hand() = delete;

        void setDirection(const Direction directionP) { direction = directionP; }

        void printHand() const
        {
            cout << "Hand direction: " << definitionDirection(direction) << endl
                 << "Hand length: " << length << " centimeters" << endl;
        }
    };
    Hand hand;

public:

    Human(const string nameP, const int pulseP, const float lengthHeartP,
          const Direction directionP, const float lengthHandP) 
          : name{ nameP }, heart{ pulseP, lengthHeartP }, hand{ directionP,lengthHandP }
    {}

    void print() const
    {
        cout << "\t" << name << endl;
        heart.printCharacteristics();
        hand.printHand();
    }
};


#pragma endregion


int main()
{
    //Aaggreagation example
    #pragma region AaggreagationExample

    list<Point<int>> p{};
    p.push_front(Point<int>{ 100, 12 });

    Figure<int> figuresFisrt{ p };
    cout << "Points figuresFisrt:" << endl;
    figuresFisrt.print();

    cout << endl;

    Figure<int> figuresSecond{ 1,2,3,4 };
    cout << "Points figuresSecond:" << endl;
    figuresSecond.print();

    cout << endl;

    Vector<int> vector{ 1, 2, 3, 4, 5, 6 };
    cout << "Vector: " << endl;
    vector.print();

    #pragma endregion

    //Compilation example
    #pragma region CompilationExample

    Human human{ "Nikita", 80, 13, Down, 78 };
    cout << endl;
    human.print();

    #pragma endregion

    return 0;
}