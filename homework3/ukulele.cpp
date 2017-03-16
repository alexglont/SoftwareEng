#include "ukulele.h"
#include<iostream>
using namespace std;


///Circle class

//constructor
Circle::Circle(float radius, string woodType){
    this->radius = radius;
    this->woodType = woodType;
}

//destructor
Circle::~Circle(){
    cout << "Destruct circle. \n";
}

//check function
bool Circle::checkCircle(){
    if(this->radius < 0){
        cout <<"Circle: invalid dimension. \n";
        return false;
    }
    if(this->woodType==""){
        cout << "Circle: unknown wood type. \n";
        return false;
    }
    return true;
}

//getters
float Circle::getradius(){
    return this->radius;
}

///Rectangle class

//constructor
Rectangle::Rectangle(float length, float width, string woodType){
    this->length = length;
    this->width = width;
    this->woodType = woodType;
}

//destructor
Rectangle::~Rectangle(){
    cout << "Destruct rectangle. \n";
}

//check function
bool Rectangle::checkRectangle(){
    if(this->length < 0){
        cout<<"Rectangle: invalid dimension \n";
        return false;
    }
    if(this->width < 0){
        cout<<"Rectangle: invalid dimension \n";
        return false;
    }
    if(this->woodType==""){
        cout<<"Rectangle: unknown wood type \n";
    }
    return true;
}

///Neck class

//constructor
Neck::Neck(float cost, float length, float width, string woodType)
            :Rectangle(length, width, woodType){
    this->cost = cost;
}

//destructor
Neck::~Neck(){
    cout<< "Destruct neck. \n";
}

//check function
bool Neck::checkNeck(){
    if(this->cost < 0){
        cout<<"Neck: invalid cost \n";
        return false;
    }
    if( !this->checkRectangle() ){
        cout<<"Neck error \n";
        return false;
    }
    return true;
}

//getters
float Neck::getcost(){
    return this->cost;
}

///Top class

//constructor
Top::Top(float cost, float length, float width, string woodType)
            :Rectangle(length, width, woodType){
    this->cost = cost;
}

//destructor
Top::~Top(){
    cout<<"Destruct top.";
}

//check function
bool Top::checkTop(){
    if(this->cost < 0){
        cout<<"Top: invalid cost \n";
        return false;
    }
    if(!this->checkRectangle()){
        cout<<"Top error \n";
        return false;
    }
    return true;
}

//getters
float Top::getcost(){
    return this->cost;
}

///Body class

//constructor
Body::Body(float smallRadius, float bigRadius, float distance, float cost, string woodType){
    this->smallCircle = new Circle(smallRadius, woodType);
    this->bigCricle = new Circle(bigRadius, woodType);
    this->distance = distance;
    this->cost = cost;
}

//destructor
Body::~Body(){
    cout<<"Destruct body";
}

//check function
bool Body::checkBody(){
    if(this->cost < 0){
        cout<<"Body: invalid cost \n";
        return false;
    }
    //the two circles should overlap but not be concentric
    if((this->distance <=0) || (this->distance >= (this->smallCircle->getradius() + this->bigCricle->getradius())) ){
        cout<<"Body: invalud distance \n";
        return false;
    }
    if(!this->smallCircle->checkCircle() || !this->bigCricle->checkCircle()){
        cout<<"Body error \n";
        return false;
    }
    return true;
}

//getters
float Body::getcost(){
    return this->cost;
}

///String class

//constructor
String::String(float radius, float length, string material, float cost){
    this->cost=cost;
    this->length=length;
    this->radius=radius;
    this->material=material;
}

//destructor
String::~String(){
    cout<<"Destroy String \n";
}

//check function
bool String::checkString(){
    if(this->cost<0){
        cout<<"String: invalid cost \n";
        return false;
    }
    if(this->length<0){
        cout<<"String: invalid length \n";
        return false;
    }
    if(this->radius<0){
        cout<<"String: invalid radius \n";
        return false;
    }
    if(this->material==""){
        cout<<"String: unknown material \n";
        return false;
    }
    return true;
}

//getters
float String::getcost(){
    return this->cost;
}

///Ukulele class

//constructor
Ukulele::Ukulele(Top *top, Neck *neck, Body *body, String *string[], float cost){
    this->body=body;
    this->cost=cost;
    this->neck=neck;
    this->top=top;

    for(int i=0; i<4; i++){
        this->strings[i]=string[i];
    }
}

//destructor
Ukulele::~Ukulele(){
    cout<<"Destroy ukulele \n";
}

//check function
bool Ukulele::checkUkulele(){
    if(this->cost<0){
        cout<<"Ukulele: invalid cost \n";
        return false;
    }
    if(!this->body->checkBody()){
        cout<<"Ukulele error \n";
        return false;
    }
    if(!this->neck->checkNeck()){
        cout<<"Ukulele error \n";
        return false;
    }
    if(!this->top->checkTop()){
        cout<<"Ukulele error \n";
        return false;
    }

    for(int i=0; i<4; i++){
        if(!this->strings[i]->checkString()){
            cout<<"Ukulele error \n";
            return false;
        }
    }
    return true;
}

//compute total cost
void Ukulele::computeCost(float assamblationCost){
    this->cost = assamblationCost;
    this->cost += this->body->getcost();
    this->cost += this->neck->getcost();
    this->cost += this->top->getcost();

    for(int i=0; i<4; i++){
        this->cost += this->strings[i]->getcost();
    }
}

//play your ukulele
void Ukulele::play(){
    cout << "Somewhere over the rainbow...\n";
}


