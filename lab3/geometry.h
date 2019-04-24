#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED



#endif // GEOMETRY_H_INCLUDED
class Point
{   int x,y;


public :

    Point (int xx =0,int yy =0)
    {   x=xx;
        y=yy ;}
    int getX () const{ return x;}
    int getY () const{ return y;}

    void setX ( const int xx){   x=xx ;}
    void setY ( const int yy){y=yy ;}
 };
class PointArray {
    int size; Point *points;
    void resize(int size);
public : PointArray(); PointArray( const Point pts[], const int size); PointArray( const PointArray &pv); ~PointArray();
    void clear();
    int getSize() const { return size;}
    void push_back( const Point &p);
    void insert( const int pos, const Point &p);
    void remove( const int pos);
    Point *get( const int pos);
    const Point *get( const int pos) const ;
};


//5.1.1
class Polygon
{
protected :
    static int numPolygons ;
    PointArray points ;
public :
    Polygon ( const PointArray &pa);
    Polygon ( const Point points [],const int numPoints );
    virtual double area () const = 0;
    static int getNumPolygons (){ return numPolygons ;}

    int getNumSides () const{ return points.getSize () ;}
    const PointArray *getPoints () const{ return &points ;}
    ~ Polygon (){--numPolygons ;}
 };

 //5.2.1
 class Rectangle : public Polygon {
public :
    Rectangle( const Point &a, const Point &b);
    Rectangle ( const int a, const int b, const int c, const int d);
    virtual double area () const ;
};

//5.2.1
class Triangle : public Polygon {
public :
    Triangle( const Point &a, const Point &b, const Point &c);
    virtual double area() const ;
};


