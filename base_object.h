#pragma once


class base_object
{
    public:
        ofPoint pos;
        ofPoint vel;
        ofColor col;
        float en_velfactor;
    
        
        void init(int id) {
        }
        
        void update() {
        }
        
        void draw() {
        }
        
        void moveTo(int x, int y) {
        }
};
