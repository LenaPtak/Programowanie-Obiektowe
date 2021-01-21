#include <iostream>
using namespace std;


//=========================================================================================================

template <typename T>
class X{
private:
    T x;

    template <>
    bool operator > (X<string> const &a, X<string> const &b) {
        return a.getX().size() > b.getX().size();
    }

public:

    //Dopisz przeciążenie operatora >, aby kod się skompilował.
    bool operator > (const X &obiekt2) const{
        return this->x > obiekt2.x;
    }


    X(){}
    X(T _x)
    {
        this->x = _x;
    }
    T getX() const
    {
        return x;
    }


friend ostream& operator << (ostream& os, X const &x)
    {
        os << x.x;
        return os;
    }
};

template <typename T>
bool operator > (X<T> const &a , X<T> const & b) {
    return a.getX() > b.getX();
}


//=========================================================================================================

auto maxLambda = [](auto a, auto b) 
{
    return a > b ? a:b;
};

bool b = maxLambda(3, 3.14);
auto c = maxLambda(3, 3.14);

//=========================================================================================================

template <typename T>

class A {
    typename T::id i;

public:
    void f()
    {
        i.g();
    }
};

//=========================================================================================================

class B {
    public:
        class id {
            public:
                void g()
                {
                    ;
                }
        };
};

//=========================================================================================================

template <typename T, typename C=X<T>>
class Y{
    T zmienna;
    C klasaX;
};

Y<int> y;
Y<int, double> y2;


//=========================================================================================================

template <typename M>
M maximum(M const &a, M const &b)
{
    return a>b ? a:b;
}

//=========================================================================================================

int main() {
    cout << maximum(6, 7) << endl; // dedukcja typu
    cout << maximum(6.3, 7.3) << endl;
    //cout << maximum(6.5, 7) << endl;      //Nie może porównać dwóch typów ze sobą. 6.5 interpretuje jako double, a 7 jako int.
    cout << maximum<double>(4, 5) << endl; // bez dedukcji typu
    cout << maximum<double>(4.1, 5.7) << endl;
    cout << maximum<int>(4.6, 3) << endl;
    cout << maximum<double>(4.6, 3) << endl;
    cout << maximum<bool>(4.6, 3) << endl;
    //cout << maximum<string>(4.6, 3) << endl;  //Nie można tak przekonwertować 4.6 i 3 na typ string.
    cout << maximum<string>("aaa", "bb") << endl;

    //cout << maximum(X(4), X(3));
    cout << maximum(X<int>(4) , X<int>(3)) << endl;
    cout << maximum(X<string>("aaa"), X<string>("bb")) << endl;

    A<B> ab;
    ab.f();
}