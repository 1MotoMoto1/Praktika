#include <iostream>
#include <map>
#include <vector>
#include <GL/glut.h>

class Sprite {
public:
    Sprite(std::string name) : name(name) {}

    void draw() {

    }

    std::string name;
};

class Frame
{
public:
    Frame(std::string name) : name(name) {}

    void addChild(Frame* child)
    {
        children[child->name] = child;
    }

    Frame* getChild(std::string child_name)
    {
        return children[child_name];
    }

    void addObject(Sprite* object)
    {
        objects[object->name] = object;
    }

    Sprite* getObject(std::string object_name)
    {
        return objects[object_name];
    }

    void draw()
    {

    }

    std::map<std::string, Frame*> children;
    std::map<std::string, Sprite*> objects;
    std::string name;
};

Frame* root_frame;




class Skeleton {
public:
    Skeleton() {
        root_frame = new Frame("root");
        Frame* chest = new Frame("chest");
        Frame* left_hand = new Frame("left_hand");
        Frame* left_shoulder = new Frame("left_shoulder");
        Frame* left_foream = new Frame("left_foream");
        root_frame->addChild(chest);


        left_hand->addChild(left_shoulder);
        left_shoulder->addChild(left_foream);
        left_foream->addChild(chest);
        chest->addObject(new Sprite("left_arm"));


    }


};


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    root_frame->draw();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Chuvaker");

    glutDisplayFunc(display);

}