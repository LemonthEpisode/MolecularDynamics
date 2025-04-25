#include "Vec3D.hpp"

class Particle {

private:
    Vec3D pos;
    Vec3D prv;
    Vec3D acc;

    double mass;

public:

    Particle();
    ~Particle();
    
    void applyForce(Vec3D);
    void update();
    void keepWithinBounds();

};