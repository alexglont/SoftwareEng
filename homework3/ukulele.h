#include<string>

#ifndef UKULELE_H
#define UKULELE_H

class Circle {
private:
    float radius;
    std::string woodType = "";
public:
    Circle(float radius, std::string woodType);
    ~Circle();
    bool checkCircle();

    float getradius();
};

class Rectangle {
private:
    float length, width;
    std::string woodType = "";
public:
    Rectangle(float length, float width, std::string woodType);
    ~Rectangle();
    bool checkRectangle();
};

class Neck : public Rectangle{
private:
    float cost;
public:
    Neck(float cost, float length, float width, std::string woodType);
    ~Neck();
    bool checkNeck();
    float getcost();
};

class Top : public Rectangle{
private:
    float cost;
public:
    Top(float cost, float length, float width, std::string woodType);
    ~Top();
    bool checkTop();
    float getcost();
};

class Body{
private:
    Circle *smallCircle, *bigCricle;
    float distance;
    float cost;
    std::string woodType="";
public:
    Body(float smallRadius, float bigRadius, float distance, float cost, std::string woodType);
    ~Body();
    bool checkBody();
    float getcost();
};

class String{
private:
    float radius, length;
    std::string material="";
    float cost;
public:
    String(float radius, float length, std::string material, float cost);
    ~String();
    bool checkString();
    float getcost();
};

class Ukulele {
    Top *top;
    Neck *neck;
    Body *body;
    String *strings[4];
    float cost;
public:
    Ukulele(Top *top, Neck *neck, Body *body, String *string[], float cost);
    ~Ukulele();
    bool checkUkulele();
    void computeCost(float assamblationCost);
    void play();
};

#endif // UKULELE_H
